
#include <TCP_Client.h>
#include <TCP_Server.h>

TCP_Client authClient;
TCP_Server server;

void OnClientCommandRecv(Authentication::CommandAndData commandData);
void OnClientConnectedToServer();

void OnServerCommandRecv(Client* client, Authentication::CommandAndData commandData);
void OnServerClientConnected(Client* client);

int clientRequestId = 1;

int main(int argc, char** argv)
{
	std::cout << "Client Server" << std::endl << std::endl;
	std::cout << "*********************************" << std::endl << std::endl;

	authClient.OnCommandReceived = OnClientCommandRecv;
	authClient.OnConnectedToServer = OnClientConnectedToServer;

	server.OnCommandReceived = OnServerCommandRecv;
	server.OnClientConnected = OnServerClientConnected;


	std::thread addClientThread([]()
		{
			authClient.ConnectToServer("127.0.0.1", "8017");
		});

	server.InitializeAndRunServer("127.0.0.1", "1708");

	return 0;
}

void OnClientCommandRecv(Authentication::CommandAndData commandData)
{
#pragma region REGISTER

	if (commandData.command() == REGISTER_SUCESS)
	{
		Authentication::CreateAccountWebSuccess registerSucess;
		registerSucess.ParseFromString(commandData.data());

		server.SendCommand(server.GetClientWithRequestID(registerSucess.requestid()), REGISTER_SUCESS, registerSucess);

		std::cout << "Register Successful " << std::endl;
	}
	else if (commandData.command() == REGISTER_FAIL)
	{
		Authentication::CreateAccountWebFailure registerFail;
		registerFail.ParseFromString(commandData.data());

		server.SendCommand(server.GetClientWithRequestID(registerFail.requestid()), REGISTER_FAIL, registerFail);

		std::cout << "Register Failed " << std::endl;
	}
#pragma endregion

#pragma region AUTHENTICATE

	else if (commandData.command() == AUTHENTICATE_SUCESS)
	{
		Authentication::AuthenticateWebSuccess authSucess;
		authSucess.ParseFromString(commandData.data());

		server.SendCommand(server.GetClientWithRequestID(authSucess.requestid()), AUTHENTICATE_SUCESS, authSucess);

		std::cout << "Authentication Successful " << std::endl;

	}
	else if (commandData.command() == AUTHENTICATE_FAIL)
	{
		Authentication::AuthenticateWebFailure authFail;
		authFail.ParseFromString(commandData.data());

		server.SendCommand(server.GetClientWithRequestID(authFail.requestid()), AUTHENTICATE_FAIL, authFail);
	}

#pragma endregion

	
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
	if (commandData.command() == REGISTER)
	{
		Authentication::CreateAccountWeb registerAcc;

		registerAcc.ParseFromString(commandData.data());
		registerAcc.set_requestid(clientRequestId);

		client->requestId = clientRequestId;

		std::cout << "Email : " << registerAcc.email() << std::endl;
		std::cout << "Password : " << registerAcc.plaintextpassword() << std::endl;

		authClient.SendCommand(REGISTER, registerAcc);

		clientRequestId++;
	}
	else if (commandData.command() == AUTHENTICATE)
	{
		Authentication::AuthenticateWeb authAcc;

		authAcc.ParseFromString(commandData.data());
		authAcc.set_requestid(clientRequestId);

		client->requestId = clientRequestId;

		std::cout << "Email : " << authAcc.email() << std::endl;
		std::cout << "Password : " << authAcc.plaintextpassword() << std::endl;

		authClient.SendCommand(AUTHENTICATE, authAcc);

		clientRequestId++;
	}
}

void OnServerClientConnected(Client* client)
{
	std::cout << "Server : Chat Client connected to server " << std::endl;
}
