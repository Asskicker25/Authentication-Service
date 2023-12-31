#include "TCP_Server.h"


TCP_Server::TCP_Server()
{
}

TCP_Server::~TCP_Server()
{
}

void TCP_Server::InitializeAndRunServer(const std::string& ipAddress, const std::string& port)
{

	this->ipAddress = ipAddress;
	this->port = port;

#pragma region Winsock_Startup

	result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (result != 0)
	{
		std::cout << " Server : Winsock initialization failed with error : " << result << std::endl;

		system("Pause");

		return;
	}

	serverInitialized = true;

#pragma endregion

#pragma region SocketCreation

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	result = getaddrinfo(ipAddress.c_str(), port.c_str(), &hints, &info);

	if (result != 0)
	{
		std::cout << "Server : Getting Address failed with error : " << result << std::endl;
		system("Pause");
		cleanupEvents.Addfunction("WSACleanup", WSACleanup);
		cleanupEvents.Invoke();
		return;
	}

	listenSocket = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
	if (listenSocket == INVALID_SOCKET)
	{
		std::cout << "Server : Socket creation failed with error : " << WSAGetLastError() << std::endl;
		cleanupEvents.Addfunction("Free Address", [this]()
			{
				freeaddrinfo(info);
			});

		cleanupEvents.Invoke();
		return;
	}

	std::cout << "Server : Socket created Successfully" << std::endl;

#pragma endregion

#pragma region BindAndListen

	result = bind(listenSocket, info->ai_addr, (int)info->ai_addrlen);

	if (result == SOCKET_ERROR)
	{
		std::cout << "Server : Binding socked failed with error : " << WSAGetLastError() << std::endl;
		cleanupEvents.Addfunction("Close Socket", [this]()
			{
				closesocket(listenSocket);
			});
		cleanupEvents.Invoke();
		return;
	}

	std::cout << "Server : Binding socket successful " << std::endl;


	result = listen(listenSocket, SOMAXCONN);
	if (result == SOCKET_ERROR)
	{
		std::cout << "Server : Listening socked failed with error : " << WSAGetLastError() << std::endl;
		cleanupEvents.Invoke();
		return;
	}

	std::cout << "Server : Listening socket successful " << std::endl;

#pragma endregion

#pragma region Threads

	std::thread addClientThread([this]()
		{
			AddNewClient();
		});

	addClientThread.detach();

	std::thread sendMessagesToClient([this]()
		{
			HandleSendCommand();
		});

	sendMessagesToClient.detach();

#pragma endregion

	while (true)
	{
	}

	cleanupEvents.Invoke();

	return;
}


void TCP_Server::AddNewClient()
{
	while (true)
	{
		SOCKET newClientSocket = accept(listenSocket, NULL, NULL);

		if (newClientSocket != INVALID_SOCKET)
		{

			Client* newClient = new Client();
			newClient->requestId = -1;
			newClient->clientSocket = newClientSocket;

			OnClientConnected(newClient);

			std::thread newClientThread([newClient, this]()
				{
					HandleCommandRecv(newClient);
				});

			listOfClients.push_back(newClient);
			listOfClientThreads.push_back(std::move(newClientThread));
		}
	}

	std::cout << "Server : Thread Closed" << std::endl;

}

void TCP_Server::HandleCommandRecv(Client* client)
{
	int result, error;

	while (!client->terminateThread)
	{
		char buffer[5];

		int32_t messageLength;

		result = recv(client->clientSocket, buffer, 5, 0);

		if (result == SOCKET_ERROR)
		{
			error = WSAGetLastError();

			if (error == WSAECONNRESET || error == ECONNRESET)
			{

				printf("Server :  %s has disconnected from the room\n", "Client");

				client->terminateThread = true;
				closesocket(client->clientSocket);

				listOfClients.erase(std::remove(listOfClients.begin(), listOfClients.end(), client), listOfClients.end());
			}
			else
			{
				std::cout << "Server : Receiving message from Client failed with error : " << WSAGetLastError() << std::endl;
			}
		}
		else
		{
			Authentication::LengthPrefix lengthPrefix;

			lengthPrefix.ParseFromArray(buffer, 5);

			std::string serializedMessageData(lengthPrefix.messagelength(), '\0');

			result = recv(client->clientSocket, &serializedMessageData[0], lengthPrefix.messagelength(), 0);

			if (result > 0)
			{
				Authentication::CommandAndData commnadData;

				if (commnadData.ParseFromString(serializedMessageData))
				{
					OnCommandReceived(client, commnadData);
				}
				else
				{
					std::cout << "Server : Message Parsing failed " << std::endl;
				}
			}
		}
	}
}

void TCP_Server::HandleSendCommand()
{
	int result, error;

	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(5));

		if (listOfMessagesToSend.size() > 0)
		{
			ServerToClientMessages message = listOfMessagesToSend.front();
			listOfMessagesToSend.pop();

			result = send(message.client->clientSocket, message.message.c_str(), message.message.size(), 0);

			if (result == SOCKET_ERROR)
			{
				std::cout << "Server : Sending message to Client failed with error : " << WSAGetLastError() << std::endl;
			}
		}
	}
}

void TCP_Server::SendCommand(Client* client, const Command& command, const google::protobuf::Message& message)
{
	std::string serializedString = SerializeWithCommandAndLengthPrefix(command, message);

	listOfMessagesToSend.push(ServerToClientMessages{ client, serializedString });
}

std::vector<Client*> TCP_Server::GetAllClients()
{
	return listOfClients;
}

Client* TCP_Server::GetClientWithRequestID(int requestID)
{
	for (Client* client : listOfClients)
	{
		if (client->requestId == requestID)
			return client;
	}

	return nullptr;
}

