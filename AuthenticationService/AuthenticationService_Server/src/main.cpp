#include <TCP_Server.h>
#include "SQLHandler.h".
#include "SQL_WebAuth.h"
#include "SQL_User.h"

void OnCommandRecv(Client* client, Authentication::CommandAndData commandData);
void OnClientConnected(Client* client);

TCP_Server server;
SQLHandler sqlHandler;
SQL_WebAuth sqlWebAuth;
SQL_User sqlUser;

int main(int argc, char** argv)
{

	std::cout << "Authetication Service Server" << std::endl << std::endl;
	std::cout << "*********************************" << std::endl << std::endl;

	sqlWebAuth.AssignSQLDatabase(&sqlHandler);
	sqlUser.AssignSQLDatabase(&sqlHandler);

	sqlHandler.ConnectToDatabase("127.0.0.1:3306", "root", "password", "gdp");

	sqlHandler.AddPreparedStatement(StatementType::CREATEACCOUNT,
		"INSERT INTO web_auth ( email , salt , hashed_password, userId) VALUES(?, ?, ?, ?) ");

	sqlHandler.AddPreparedStatement(StatementType::UPDATEWEBAUTHID,
		"UPDATE web_auth SET userId = ? WHERE email = ?");

	sqlHandler.AddPreparedStatement(StatementType::CREATEUSER,
		"INSERT INTO user (last_login, creation_date) VALUES (NOW(), NOW())");

	/*sqlHandler.AddResultSetStatement(ResultSetStatement::GETLASTINSERT,
		"SELECT LAST_INSERT_ID()");*/

	//sqlWebAuth.AddAccount("sp@.com", "pwd");

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

		result = sqlWebAuth.AddAccount(registerAcc.email().c_str(), registerAcc.plaintextpassword().c_str());

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
	else if (commandData.command() == AUTHENTICATE)
	{
		Authentication::AuthenticateWeb authAccountWeb;
		authAccountWeb.ParseFromString(commandData.data());
		std::cout << "Authenticate : " << authAccountWeb.email() << std::endl;

	}
#pragma endregion

}

void OnClientConnected(Client* client)
{
	std::cout << "Client : Client Server Connected " << std::endl;
}
