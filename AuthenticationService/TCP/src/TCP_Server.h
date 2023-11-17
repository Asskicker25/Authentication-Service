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


struct Client
{
	int requestId;
	SOCKET clientSocket;
	bool terminateThread;
};

struct ServerToClientMessages
{
	Client* client;
	std::string message;
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
	std::queue<ServerToClientMessages> listOfMessagesToSend;

	void AddNewClient();
	void HandleCommandRecv(Client* client);
	void HandleSendCommand();

public:
	TCP_Server();
	~TCP_Server();

	void InitializeAndRunServer(const std::string& ipAddress, const std::string& port);

	void SendCommand(Client* client, const Command& command, const google::protobuf::Message& message);

	std::vector<Client*> GetAllClients();

	std::function<void(Client*)> OnClientConnected = nullptr;
	std::function<void(Client*, Authentication::CommandAndData)> OnCommandReceived = nullptr;
};

