#include <TCP_Client.h>


void OnClientCommandRecv(Authentication::CommandAndData commandData);
void OnClientConnectedToServer();

TCP_Client chatClient;

int main(int argc, char** argv)
{
	std::cout << "Chat Client" << std::endl << std::endl;
	std::cout << "*********************************" << std::endl << std::endl;

	chatClient.OnCommandReceived = OnClientCommandRecv;
	chatClient.OnConnectedToServer = OnClientConnectedToServer;

	chatClient.ConnectToServer("127.0.0.1", "1708");

	return 0;
}

void OnClientCommandRecv(Authentication::CommandAndData commandData)
{

}


void OnClientConnectedToServer()
{
	std::cout << "Client : Connected to Client Server " << std::endl;
}
