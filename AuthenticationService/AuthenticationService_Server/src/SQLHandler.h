#pragma once

#include <sqlConnector/mysql/jdbc.h>

enum class StatementType
{
	CREATE_ACCOUNT = 0,
	AUTHENTICATE_ACCOUNT = 1,
	CREATE_USER = 2,
	UPDATE_WEB_AUTH_ID = 3,
	GET_LAST_INSERT = 4,
	UPDATE_LAST_LOGIN = 5,
	GET_CREATION_DATE = 6,
};

enum class ResultSetStatement
{
	GETLASTINSERT = 0,
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
	std::map<StatementType, sql::PreparedStatement*> listOfStatements;

	sql::Connection* GetConnection();

private:

	sql::mysql::MySQL_Driver* driver;
	sql::Connection* connection;
	sql::ResultSet* resultSet;
	sql::Statement* statement;

	bool isConnected;
};

