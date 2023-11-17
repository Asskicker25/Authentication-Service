#pragma once

#include <sqlConnector/mysql/jdbc.h>

enum class StatementType
{
	CREATEACCOUNT = 0,
};

class SQLHandler
{
public:


	SQLHandler();
	~SQLHandler();

	void ConnectToDatabase(const char* host, const char* username, const char* password, const char* schema);
	void Disconnect();


	sql::ResultSet* Select(const char* query);
	int Update(const char* query);
	int Insert(const char* query);

	void AddPreparedStatement(const StatementType& key, const char* query);
	sql::PreparedStatement* GetStatement(const StatementType& key);

private:

	sql::mysql::MySQL_Driver* driver;
	sql::Connection* connection;
	sql::ResultSet* resultSet;
	sql::Statement* statement;

	std::map<StatementType, sql::PreparedStatement*> listOfStatements;

	bool isConnected;
};

