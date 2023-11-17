#include "SQL_WebAuth.h"
#include "SQLHandler.h"
#include "sha256.h"

SQL_WebAuth::SQL_WebAuth()
{
}

SQL_WebAuth::~SQL_WebAuth()
{
}

void SQL_WebAuth::AssignSQLDatabase(SQLHandler* sqlHandler)
{
	this->sqlHandler = sqlHandler;
}

int SQL_WebAuth::AddAccount(const char* email, const char* salt, const char* password)
{
	sql::PreparedStatement* stmt = sqlHandler->GetStatement(StatementType::CREATE_ACCOUNT);
	stmt->setString(1, email);
	stmt->setString(2, salt);
	stmt->setString(3, password);
	stmt->setBigInt(4, "45");

	try 
	{
		stmt->execute();

		std::cout << "Account added successfully!" << std::endl;

		return 1;
	}
	catch (sql::SQLException& e) 
	{
		if (e.getErrorCode() == 1062) 
		{
			std::cout << "Error: Email address already exists." << std::endl;
			
			return 0;
		}
		else
		{
			std::cout << "SQL Error: " << e.what() << std::endl;
			return -1;
		}

		return -1;
	}

}

int SQL_WebAuth::UpdateUserID(const char* email, const int& userID)
{
	sql::PreparedStatement* stmt = sqlHandler->GetStatement(StatementType::UPDATE_WEB_AUTH_ID);
	stmt->setBigInt(1, std::to_string(userID));
	stmt->setString(2, email);

	try
	{
		stmt->execute();

		std::cout << "User ID updated successfully!" << std::endl;

		return 1;
	}
	catch (sql::SQLException& e)
	{

		std::cout << "SQL Error: " << e.what() << std::endl;
		return -1;
	}
}

int SQL_WebAuth::AuthenticateAccount(const char* email, const char* password, int& userId)
{
	sql::PreparedStatement* stmt = sqlHandler->GetStatement(StatementType::AUTHENTICATE_ACCOUNT);
	stmt->setString(1, email);


	try
	{
		sql::ResultSet* result = stmt->executeQuery();

		if (result->next()) 
		{

			SHA256 hasher;

			std::string passwordDB = result->getString("hashed_password");
			std::string salt = result->getString("salt");
			userId = result->getInt("userId");

			std::string hashedPassword = hasher(salt + password);

			if (passwordDB == hashedPassword)
			{
				std::cout << "Valid Password" << std::endl;
				return 1;
			}
			else
			{
				std::cout << "Invalid Password" << std::endl;
				return 2;
			}
		}
		else
		{
			std::cout << "Email ID not in database " << std::endl;
			return 0;
		}
	}
	catch (sql::SQLException& e)
	{
		std::cout << "SQL Error: " << e.what() << std::endl;
		return -1;
	}



}
