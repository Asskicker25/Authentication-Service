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
	sql::PreparedStatement* stmt = sqlHandler->GetStatement(StatementType::CREATEUSER);

	try
	{
		stmt->execute();

		sql::Statement* statement = sqlHandler->GetConnection()->createStatement();
		
		sql::ResultSet* resultUser = statement->executeQuery("SELECT LAST_INSERT_ID()");

		//sql::ResultSet* resultUser = sqlHandler->GetResultSetStatement(ResultSetStatement::GETLASTINSERT);

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

