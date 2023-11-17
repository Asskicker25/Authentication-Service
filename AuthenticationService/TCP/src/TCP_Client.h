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

#include "Events.h"
#include "MessageUtilities.h"

#pragma comment(lib, "Ws2_32.lib")
class TCP_Client
{
private:


	SOCKET serverSocket;
	WSAData wsaData;

	Events cleanupEvents;

	bool serverConnected = false;
	bool messageSent = false;

	int result, error;

	std::string ipAddress;
	std::string port;

	struct addrinfo* info = nullptr;
	struct addrinfo hints;

	void HandleCommandRecv();
	void HandleSendCommand();

public:

	TCP_Client(const std::string& ipAddress, const std::string& port);
	~TCP_Client();

	void ConnectToServer();
};

