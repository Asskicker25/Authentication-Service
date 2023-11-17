#pragma once

// WinSock2 Windows Sockets
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <conio.h>
#include <map>
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <thread>
#include <queue>

#include "Events.h"
#include "MessageUtilities.h"

#pragma comment(lib, "Ws2_32.lib")


struct ClientToServerMessages
{
	std::string message;
};

class TCP_Client
{
private:


	SOCKET serverSocket;
	WSAData wsaData;

	Events cleanupEvents;

	bool serverConnected = false;

	int result, error;

	std::string ipAddress;
	std::string port;

	struct addrinfo* info = nullptr;
	struct addrinfo hints;

	std::queue<ClientToServerMessages> listOfMessagesToSend;

	void HandleCommandRecv();
	void HandleSendCommand();

public:
	TCP_Client();
	~TCP_Client();

	void ConnectToServer(const std::string& ipAddress, const std::string& port);

	void SendCommand(const Command& command, const google::protobuf::Message& message);

	std::function<void()> OnConnectedToServer = nullptr;
	std::function<void(Authentication::CommandAndData)> OnCommandReceived = nullptr;

};

