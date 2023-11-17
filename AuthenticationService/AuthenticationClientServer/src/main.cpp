
#include <TCP_Client.h>
#include <TCP_Server.h>

TCP_Client client;
TCP_Server server;

void OnClientCommandRecv(Authentication::CommandAndData commandData);
void OnClientConnectedToServer();

void OnServerCommandRecv(Client* client, Authentication::CommandAndData commandData);
void OnServerClientConnected(Client* client);

int main(int argc, char** argv)
{
	std::cout << "Client Server" << std::endl << std::endl;
	std::cout << "*********************************" << std::endl << std::endl;

	client.OnCommandReceived = OnClientCommandRecv;
	client.OnConnectedToServer = OnClientConnectedToServer;

	server.OnCommandReceived = OnServerCommandRecv;
	server.OnClientConnected = OnServerClientConnected;


	std::thread addClientThread([]()
		{
			client.ConnectToServer("127.0.0.1", "8017");
		});

	server.InitializeAndRunServer("127.0.0.1", "1708");

	return 0;
}

void OnClientCommandRecv(Authentication::CommandAndData commandData)
{
	/*if (commandData.command() == REGISTER_SUCESS)
	{
		Authentication::CreateAccountWebSuccess registerSucess;
		registerSucess.ParseFromString(commandData.data());

		std::cout << "Register Success : " << registerSucess.userid() << std::endl;
	}*/
}

void OnClientConnectedToServer()
{
	/*Authentication::CreateAccountWeb createAcc;

	createAcc.set_email("surya@gmail.com");
	createAcc.set_plaintextpassword("password");

	client.SendCommand(REGISTER, createAcc);*/

	std::cout << "Client : Connected to Service Server " << std::endl;
}

void OnServerCommandRecv(Client* client, Authentication::CommandAndData commandData)
{

}

void OnServerClientConnected(Client* client)
{
	std::cout << "Server : Chat Client connected to server " << std::endl;
}
