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


struct Client
{
	int requestId;
	SOCKET clientSocket;
	bool terminateThread;
};

class TCP_Server
{
private:

	WSAData wsaData;
	SOCKET listenSocket;

	int result;

	bool serverInitialized = false;

	struct addrinfo* info = nullptr;
	struct addrinfo hints;

	std::string ipAddress;
	std::string port;

	Events cleanupEvents;

	std::vector<Client*> listOfClients;
	std::vector <std::thread> listOfClientThreads;


	void AddNewClient();
	void HandleCommandRecv(Client* client);
	void HandleSendCommand();
	//void HandleCommand(const Authentication::CommandAndData& commandData);

public:
	TCP_Server(const std::string& ipAddress, const std::string& port);
	~TCP_Server();

	void InitializeAndRunServer();

	std::function<void(Client*, Authentication::CommandAndData)> OnCommandReceived = nullptr;
};

