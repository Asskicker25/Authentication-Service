#include "SQLHandler.h"

SQLHandler::SQLHandler()
	: isConnected{ false }
	, connection{ nullptr }
	, driver{ nullptr}
	, resultSet{ nullptr }
	, statement{ nullptr }
{

}

SQLHandler::~SQLHandler()
{
	if (connection != nullptr)
		delete connection;

	if (resultSet != nullptr)
		delete resultSet;

	if (statement != nullptr)
		delete statement;
}

void SQLHandler::ConnectToDatabase(const char* host, const char* username, const char* password, const char* schema)
{
	if (isConnected) return;

	try
	{
		driver = sql::mysql::get_mysql_driver_instance();
		connection = driver->connect(host, username, password);
		statement = connection->createStatement();

		connection->setSchema(schema);
	}
	catch (sql::SQLException& e)
	{
		
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;

		printf("Failed to connect to the Database! :( \n");
		return;
	}

	printf("Successfully connected to the Database! :D \n");

	isConnected = true;

}

void SQLHandler::Disconnect()
{
	if (!isConnected) return;

	connection->close();

	isConnected = false;
}

sql::ResultSet* SQLHandler::Select(const char* query)
{
	return nullptr;
}

int SQLHandler::Update(const char* query)
{
	return 0;
}

int SQLHandler::Insert(const char* query)
{
	return 0;
}

void SQLHandler::AddPreparedStatement(const StatementType& key, const char* query)
{
	listOfStatements[key] = connection->prepareStatement(query);
}

void SQLHandler::AddResultSetStatement(const ResultSetStatement& key, const char* query)
{
	listOfResultSetStatements[key] = connection->createStatement()->executeQuery(query);
}

sql::PreparedStatement* SQLHandler::GetStatement(const StatementType& key)
{
	return listOfStatements[key];
}

sql::ResultSet* SQLHandler::GetResultSetStatement(const ResultSetStatement& key)
{
	return listOfResultSetStatements[key];
}

sql::Connection* SQLHandler::GetConnection()
{
	return connection;
}
