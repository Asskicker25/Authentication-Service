#include "SQL_WebAuth.h"
#include "SQLHandler.h"

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

void SQL_WebAuth::AddAccount(const char* email, const char* password)
{
	sql::PreparedStatement* stmt = sqlHandler->GetStatement(StatementType::CREATEACCOUNT);
	stmt->setString(1, email);
	stmt->setString(2, "Salt1");
	stmt->setString(3, password);
	stmt->setBigInt(4, "45");

	try 
	{
		stmt->execute();

		std::cout << "Account added successfully!" << std::endl;
	}
	catch (sql::SQLException& e) 
	{
		if (e.getErrorCode() == 1062) 
		{
			std::cout << "Error: Email address already exists." << std::endl;
		}
		else
		{
			std::cout << "SQL Error: " << e.what() << std::endl;
		}
	}

}
