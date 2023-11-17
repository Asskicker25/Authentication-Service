
#include <TCP_Client.h>

TCP_Client client;

void OnCommandRecv(Authentication::CommandAndData commandData);
void OnConnectedToServer();

int main(int argc, char** argv)
{
	client.OnCommandReceived = OnCommandRecv;

	client.OnConnectedToServer = OnConnectedToServer;

	client.ConnectToServer("127.0.0.1", "8017");

	return 0;
}

void OnCommandRecv(Authentication::CommandAndData commandData)
{
	if (commandData.command() == REGISTER_SUCESS)
	{
		Authentication::CreateAccountWebSuccess registerSucess;
		registerSucess.ParseFromString(commandData.data());

		std::cout << "Register Success : " << registerSucess.userid() << std::endl;
	}
}

void OnConnectedToServer()
{
	Authentication::CreateAccountWeb createAcc;
	createAcc.set_email("surya@gmail.com");
	createAcc.set_plaintextpassword("password");

	client.SendCommand(REGISTER, createAcc);
}
