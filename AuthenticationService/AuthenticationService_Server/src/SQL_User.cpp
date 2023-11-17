#include "SQL_User.h"
#include "SQLHandler.h"

SQL_User::SQL_User()
{
}

SQL_User::~SQL_User()
{
}

void SQL_User::AssignSQLDatabase(SQLHandler* sqlHandler)
{
	this->sqlHandler = sqlHandler;
}

int SQL_User::AddNewUser(int& userID)
{
	sql::PreparedStatement* stmt = sqlHandler->GetStatement(StatementType::CREATE_USER);

	try
	{
		stmt->execute();

		sql::ResultSet* resultUser = sqlHandler->
			GetStatement(StatementType::GET_LAST_INSERT)->executeQuery();

		while (resultUser->next())
		{
			userID = resultUser->getInt(1);
		}

		std::cout << "User Account added successfully!" << std::endl;

		return 1;
	}
	catch (sql::SQLException& e)
	{

		std::cout << "SQL Error: " << e.what() << std::endl;
		return -1;
	}

}

int SQL_User::UpdateLastLogin(const int& userID)
{
	sql::PreparedStatement* stmt = sqlHandler->GetStatement(StatementType::UPDATE_LAST_LOGIN);
	stmt->setInt(1, userID);

	try
	{
		stmt->execute();

		std::cout << "Updated Last Login Successfully " << std::endl;

		return 1;
	}
	catch (sql::SQLException& e)
	{

		std::cout << "SQL Error: " << e.what() << std::endl;
		return -1;
	}

	return 0;
}

