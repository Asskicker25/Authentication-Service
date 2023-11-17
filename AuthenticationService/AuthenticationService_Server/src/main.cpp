#include <TCP_Server.h>

void OnCommandRecv(Client* client, Authentication::CommandAndData commandData);
void OnClientConnected(Client* client);

int main(int argc, char** argv)
{
	TCP_Server server("127.0.0.1", "8017");

	server.OnClientConnected = OnClientConnected;
	server.OnCommandReceived = OnCommandRecv;

	server.InitializeAndRunServer();

	return 0;
}

void OnCommandRecv(Client* client, Authentication::CommandAndData commandData)
{
	if (commandData.command() == REGISTER)
	{
		Authentication::CreateAccountWeb newAccountWeb;
		newAccountWeb.ParseFromString(commandData.data());

		std::cout << "Register : " << newAccountWeb.email() << std::endl;
	}
	else if(commandData.command() == AUTHENTICATE)
	{
		Authentication::AuthenticateWeb authAccountWeb;
		authAccountWeb.ParseFromString(commandData.data());
		std::cout << "Authenticate : " << authAccountWeb.email() << std::endl;

	}
}

void OnClientConnected(Client* client)
{
	std::cout << "Client Connected " << std::endl;
}
