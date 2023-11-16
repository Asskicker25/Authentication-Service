#include "TCP_Server.h"


TCP_Server::TCP_Server(const std::string& ipAddress, const std::string& port)
{
	this->ipAddress = ipAddress;
	this->port = port;
}

TCP_Server::~TCP_Server()
{
}

void TCP_Server::InitializeServer()
{

#pragma region Winsock_Startup

	result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (result != 0)
	{
		std::cout << "Winsock initialization failed with error : " << result << std::endl;

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
		std::cout << "Getting Address failed with error : " << result << std::endl;
		system("Pause");
		cleanupEvents.Addfunction("WSACleanup", WSACleanup);
		cleanupEvents.Invoke();
		return;
	}

	listenSocket = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
	if (listenSocket == INVALID_SOCKET)
	{
		std::cout << "Socket creation failed with error : " << WSAGetLastError() << std::endl;
		cleanupEvents.Addfunction("Free Address", [this]()
			{
				freeaddrinfo(info);
			});

		cleanupEvents.Invoke();
		return;
	}

	std::cout << "Socket created Successfully" << std::endl;

#pragma endregion

#pragma region BindAndListen

	result = bind(listenSocket, info->ai_addr, (int)info->ai_addrlen);

	if (result == SOCKET_ERROR)
	{
		std::cout << "Binding socked failed with error : " << WSAGetLastError() << std::endl;
		cleanupEvents.Addfunction("Close Socket", [this]()
			{
				closesocket(listenSocket);
			});
		cleanupEvents.Invoke();
		return;
	}

	std::cout << "Binding socket successful " << std::endl;


	result = listen(listenSocket, SOMAXCONN);
	if (result == SOCKET_ERROR)
	{
		std::cout << "Listening socked failed with error : " << WSAGetLastError() << std::endl;
		cleanupEvents.Invoke();
		return;
	}

	std::cout << "Listening socket successful " << std::endl;

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
			newClient->clientSocket = newClientSocket;

			std::thread newClientThread([newClient, this]()
				{
					HandleCommandRecv(newClient);
				});

			listOfClients.push_back(newClient);
			listOfClientThreads.push_back(std::move(newClientThread));

			std::cout << "Client Connected" << std::endl;

		}
	}

	std::cout << "Thread Closed" << std::endl;

}

void TCP_Server::HandleCommandRecv(Client* client)
{
	int result, error;
	const int bufferSize = 512;

	while (!client->terminateThread)
	{
		char buffer[bufferSize];

		result = recv(client->clientSocket, buffer, bufferSize, 0);

	}
}

void TCP_Server::HandleSendCommand()
{

}
