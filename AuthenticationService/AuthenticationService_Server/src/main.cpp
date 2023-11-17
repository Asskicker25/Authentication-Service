#include <TCP_Server.h>
#include "SQLHandler.h".
#include "SQL_WebAuth.h"
#include "SQL_User.h"
#include "sha256.h"
#include "SaltGenerator.h"

void OnCommandRecv(Client* client, Authentication::CommandAndData commandData);
void OnClientConnected(Client* client);

TCP_Server server;
SQLHandler sqlHandler;
SQL_WebAuth sqlWebAuth;
SQL_User sqlUser;
SHA256 hasher;
SaltGenerator saltGen;

int main(int argc, char** argv)
{

	std::cout << "Authetication Service Server" << std::endl << std::endl;
	std::cout << "*********************************" << std::endl << std::endl;

	sqlWebAuth.AssignSQLDatabase(&sqlHandler);
	sqlUser.AssignSQLDatabase(&sqlHandler);

	sqlHandler.ConnectToDatabase("127.0.0.1:3306", "root", "password", "gdp");

	sqlHandler.AddPreparedStatement(StatementType::CREATE_ACCOUNT,
		"INSERT INTO web_auth ( email , salt , hashed_password, userId) VALUES(?, ?, ?, ?) ");

	sqlHandler.AddPreparedStatement(StatementType::AUTHENTICATE_ACCOUNT,
		"SELECT hashed_password, salt, userId FROM web_auth WHERE email = ?");

	sqlHandler.AddPreparedStatement(StatementType::UPDATE_WEB_AUTH_ID,
		"UPDATE web_auth SET userId = ? WHERE email = ?");

	sqlHandler.AddPreparedStatement(StatementType::CREATE_USER,
		"INSERT INTO user (last_login, creation_date) VALUES (NOW(), NOW())");

	sqlHandler.AddPreparedStatement(StatementType::GET_LAST_INSERT,
		"SELECT LAST_INSERT_ID()");

	sqlHandler.AddPreparedStatement(StatementType::UPDATE_LAST_LOGIN,
		"UPDATE user SET last_login = NOW() WHERE id = ?");

	server.OnClientConnected = OnClientConnected;
	server.OnCommandReceived = OnCommandRecv;

	server.InitializeAndRunServer("127.0.0.1", "8017");

	return 0;
}

void OnCommandRecv(Client* client, Authentication::CommandAndData commandData)
{
	int result;

#pragma region REGISTER
	if (commandData.command() == REGISTER)
	{
		Authentication::CreateAccountWeb registerAcc;
		registerAcc.ParseFromString(commandData.data());

		// 1 = Success
		// 0 = Email exists
		// -1 = Exception not handled

		std::string salt = saltGen.GenerateSalt();

		std::string hashPassword = hasher(salt + registerAcc.plaintextpassword());


		result = sqlWebAuth.AddAccount(registerAcc.email().c_str(), salt.c_str(), hashPassword.c_str());

		if (result == 1)
		{
			int userId;

			result = sqlUser.AddNewUser(userId);

			result = sqlWebAuth.UpdateUserID(registerAcc.email().c_str(), userId);

			Authentication::CreateAccountWebSuccess registerSucess;

			registerSucess.set_requestid(registerAcc.requestid());
			registerSucess.set_userid(0);

			server.SendCommand(client, REGISTER_SUCESS, registerSucess);
		}
		else
		{
			Authentication::CreateAccountWebFailure registerFail;

			registerFail.set_requestid(registerAcc.requestid());

			if (result == 0)
			{
				registerFail.set_reason(
					Authentication::CreateAccountWebFailure::Reason::CreateAccountWebFailure_Reason_ACCOUNT_ALREADY_EXISTS);

			}
			else if (result == -1)
			{
				registerFail.set_reason(
					Authentication::CreateAccountWebFailure::Reason::CreateAccountWebFailure_Reason_INTERNAL_SERVER_ERROR);
			}

			server.SendCommand(client, REGISTER_FAIL, registerFail);
		}

	}
#pragma endregion

#pragma region AUTHENTICATE

		// 1 = Success
		// 0 = Email not exists
		// -1 = Exception not handled
	else if (commandData.command() == AUTHENTICATE)
	{
		Authentication::AuthenticateWeb authAccountWeb;
		authAccountWeb.ParseFromString(commandData.data());
		
		int userID;

		result = sqlWebAuth.AuthenticateAccount(authAccountWeb.email().c_str(), authAccountWeb.plaintextpassword().c_str(), userID);

		if (result == 1)
		{
			sqlUser.UpdateLastLogin(userID);

			Authentication::AuthenticateWebSuccess authSuccess;

			authSuccess.set_requestid(authAccountWeb.requestid());
			authSuccess.set_userid(userID);

			server.SendCommand(client, AUTHENTICATE_SUCESS, authSuccess);
		}
		else 
		{
			Authentication::AuthenticateWebFailure authFail;

			authFail.set_requestid(authAccountWeb.requestid());


			if (result == 2 || result == 0)
			{
				authFail.set_reason(Authentication::AuthenticateWebFailure::INVALID_CREDENTIALS);
			}
			else if (result == -1)
			{
				authFail.set_reason(Authentication::AuthenticateWebFailure::INTERNAL_SERVER_ERROR);
			}

			server.SendCommand(client, AUTHENTICATE_FAIL, authFail);
		}
	}
#pragma endregion

}

void OnClientConnected(Client* client)
{
	std::cout << "Client : Client Server Connected " << std::endl;
}
