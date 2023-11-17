#include <TCP_Client.h>
#include <sstream>

void OnClientCommandRecv(Authentication::CommandAndData commandData);
void OnClientConnectedToServer();

TCP_Client chatClient;

bool waitingForResponse = false;

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
	if (commandData.command() == REGISTER_SUCESS)
	{
		Authentication::CreateAccountWebSuccess registerSuccess;

		registerSuccess.ParseFromString(commandData.data());

		std::cout << "Register Success" << std::endl;

		waitingForResponse = false;

	}
	else if (commandData.command() == REGISTER_FAIL)
	{
		Authentication::CreateAccountWebFailure registerFail;

		registerFail.ParseFromString(commandData.data());

		std::cout << "Register Failed : " << registerFail.reason() <<std::endl;

		waitingForResponse = false;
	}
}


void OnClientConnectedToServer()
{
	std::cout << "Client : Connected to Client Server " << std::endl;

	std::string input;
	std::string email;
	std::string password;

	do
	{
		if (waitingForResponse) continue;

		std::cout << std::endl << std::endl;
		std::cout << "*********************************" << std::endl << std::endl;


		std::cout << "Choose An Option : " << std::endl;
		std::cout << "1. Create Account " << std::endl;
		std::cout << "2. Authenticate Account " << std::endl;

		std::cin >> input;

		int number;
		std::istringstream iss(input);

		if (iss >> number)
		{
			std::cout << "Enter your email ID : ";
			std::cin >> email;

			std::cout << "Enter your password : ";
			std::cin >> password;

			if (number == 1)
			{
				Authentication::CreateAccountWeb registerAcc;

				registerAcc.set_email(email);
				registerAcc.set_plaintextpassword(password);

				chatClient.SendCommand(REGISTER, registerAcc);

			}
			else if (number == 2)
			{
				Authentication::AuthenticateWeb authAcc;

				authAcc.set_email(email);
				authAcc.set_plaintextpassword(password);

				chatClient.SendCommand(AUTHENTICATE, authAcc);
			}

			waitingForResponse = true;
		}

	} while (true);
}
