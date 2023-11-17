#include <TCP_Server.h>

void OnCommandRecv(Client* client, Authentication::CommandAndData commandData);
void OnClientConnected(Client* client);

TCP_Server server;

int main(int argc, char** argv)
{
	server.OnClientConnected = OnClientConnected;
	server.OnCommandReceived = OnCommandRecv;

	server.InitializeAndRunServer("127.0.0.1", "8017");

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

	Authentication::CreateAccountWebSuccess registerSucess;

	registerSucess.set_requestid(0);
	registerSucess.set_userid(0);

	server.SendCommand(client, REGISTER_SUCESS, registerSucess);

}
