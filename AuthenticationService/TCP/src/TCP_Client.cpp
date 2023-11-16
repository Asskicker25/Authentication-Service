#include "TCP_Client.h"



TCP_Client::TCP_Client(const std::string& ipAddress, const std::string& port)
{
	this->ipAddress = ipAddress;
	this->port = port;
}

TCP_Client::~TCP_Client()
{
}

void TCP_Client::ConnectToServer()
{

	if (serverConnected) return;

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
}

void TCP_Client::HandleSendCommand()
{
}
