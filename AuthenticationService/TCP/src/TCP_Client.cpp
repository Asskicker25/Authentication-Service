#include "TCP_Client.h"


TCP_Client::TCP_Client()
{

}

TCP_Client::~TCP_Client()
{
}

void TCP_Client::ConnectToServer(const std::string& ipAddress, const std::string& port)
{
	if (serverConnected) return;

	this->ipAddress = ipAddress;
	this->port = port;

#pragma region Winsock_StartUp

	result = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (result != 0)
	{
		std::cout << "Winsock initialization failed with error : " << result << std::endl;
		return;
	}

	std::cout << "Winsock Initialized Successfully" << result << std::endl;

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
		cleanupEvents.Addfunction("WSACleanup", WSACleanup);
		cleanupEvents.Invoke();

		return;
	}
	std::cout << "Address fetched Successfully" << std::endl;

	serverSocket = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
	if (serverSocket == INVALID_SOCKET)
	{
		std::cout << "Socket creation failed with error : " << WSAGetLastError() << std::endl;
		cleanupEvents.Addfunction("Free Address", [this]()
			{
				freeaddrinfo(info);
			});
		cleanupEvents.Invoke();
		return;
	}

	std::cout << "Address fetched Successfully" << std::endl;

#pragma endregion

#pragma region ConnectToServer

	result = connect(serverSocket, info->ai_addr, (int)info->ai_addrlen);
	if (result == INVALID_SOCKET)
	{
		std::cout << "Connecting to Server failed with error : " << WSAGetLastError() << std::endl;
		cleanupEvents.Addfunction("Close Socket", [this]()
			{
				closesocket(serverSocket);
			});
		cleanupEvents.Invoke();
		
		return;
	}

	serverConnected = true;

	std::cout << "Connected to Server Successfully"<< std::endl;

#pragma endregion

#pragma region Threads

	std::thread serverRecvThread([this]()
		{
			HandleCommandRecv();
		});

	serverRecvThread.detach();

	std::thread serverSendThread([this]()
		{
			HandleSendCommand();
		});

	serverSendThread.detach();

#pragma endregion

	while (true)
	{
	}

	cleanupEvents.Invoke();
	return;
}


void TCP_Client::HandleCommandRecv()
{
	int result, error;

	while (serverConnected)
	{
		char buffer[5];

		int32_t messageLength;

		result = recv(serverSocket, buffer, 5, 0);

		if (result == SOCKET_ERROR)
		{
			error = WSAGetLastError();

			if (error == WSAECONNRESET || error == ECONNRESET)
			{

				std::cout << "Disconnected from server : "<< std::endl;
				closesocket(serverSocket);
			}
			else
			{
				std::cout << "Receiving message from Server failed with error : " << WSAGetLastError() << std::endl;
			}
		}
		else
		{
			Authentication::LengthPrefix lengthPrefix;

			lengthPrefix.ParseFromArray(buffer, 5);

			std::string serializedMessageData(lengthPrefix.messagelength(), '\0');

			result = recv(serverSocket, &serializedMessageData[0], lengthPrefix.messagelength(), 0);

			if (result > 0)
			{
				Authentication::CommandAndData commnadData;

				if (commnadData.ParseFromString(serializedMessageData))
				{
					OnCommandReceived(commnadData);
				}
				else
				{
					std::cout << "Message Parsing failed " << std::endl;
				}
			}
		}
	}
}

void TCP_Client::HandleSendCommand()
{
	int result, error;


	while (serverConnected)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(5));

		if (listOfMessagesToSend.size() > 0)
		{
			ClientToServerMessages message = listOfMessagesToSend.front();
			listOfMessagesToSend.pop();

			result = send(serverSocket, message.message.c_str(), message.message.size(), 0);

			if (result == SOCKET_ERROR)
			{
				std::cout << "Sending message to Server failed with error : " << WSAGetLastError() << std::endl;
			}
		}

	/*	Authentication::CreateAccountWeb createAccountWeb;
		createAccountWeb.set_requestid(0);
		createAccountWeb.set_email("surya@gmail,com");
		createAccountWeb.set_plaintextpassword("Password");

		std::string buffer = SerializeWithCommandAndLengthPrefix(Command::AUTHENTICATE, createAccountWeb);*/

	/*	std::string lengthString = buffer.substr(0, 5);
		Authentication::LengthPrefix length;
		length.ParseFromString(lengthString);

		std::cout << length.messagelength() << std::endl;

		std::string commandString = buffer.substr(5, length.messagelength());

		Authentication::CommandAndData commandData;
		commandData.ParseFromString(commandString);

		Authentication::CreateAccountWeb newAccount;
		newAccount.ParseFromString(commandData.data());


		std::cout << newAccount.email() << std::endl;*/
		
	}
}

void TCP_Client::SendCommand(const Command& command, const google::protobuf::Message& message)
{
	std::string serializedString = SerializeWithCommandAndLengthPrefix(command, message);

	listOfMessagesToSend.push(ClientToServerMessages{ serializedString });
}
