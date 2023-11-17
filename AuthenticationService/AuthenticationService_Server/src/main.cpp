#include <TCP_Server.h>
#include "SQLHandler.h".
#include "SQL_WebAuth.h"

void OnCommandRecv(Client* client, Authentication::CommandAndData commandData);
void OnClientConnected(Client* client);

TCP_Server server;
SQLHandler sqlHandler;
SQL_WebAuth sqlWebAuth;

int main(int argc, char** argv)
{

	std::cout << "Authetication Service Server" << std::endl << std::endl;
	std::cout << "*********************************" << std::endl << std::endl;

	sqlWebAuth.AssignSQLDatabase(&sqlHandler);

	sqlHandler.ConnectToDatabase("127.0.0.1:3306", "root", "password", "gdp");

	sqlHandler.AddPreparedStatement(StatementType::CREATEACCOUNT,
		"INSERT INTO web_auth ( email , salt , hashed_password, userId) VALUES(?, ?, ?, ?) ");

	//sqlWebAuth.AddAccount("sp@.com", "pwd");

	server.OnClientConnected = OnClientConnected;
	server.OnCommandReceived = OnCommandRecv;

	server.InitializeAndRunServer("127.0.0.1", "8017");

	return 0;
}

void OnCommandRecv(Client* client, Authentication::CommandAndData commandData)
{
	/*if (commandData.command() == REGISTER)
	{
		Authentication::CreateAccountWeb newAccountWeb;
		newAccountWeb.ParseFromString(commandData.data());

		std::cout << "Register : " << newAccountWeb.email() << std::endl;

		Authentication::CreateAccountWebSuccess registerSucess;

		registerSucess.set_requestid(0);
		registerSucess.set_userid(0);

		server.SendCommand(client, REGISTER_SUCESS, registerSucess);
	}
	else if(commandData.command() == AUTHENTICATE)
	{
		Authentication::AuthenticateWeb authAccountWeb;
		authAccountWeb.ParseFromString(commandData.data());
		std::cout << "Authenticate : " << authAccountWeb.email() << std::endl;

	}*/
}

void OnClientConnected(Client* client)
{
	std::cout << "Client : Client Server Connected " << std::endl;
}
