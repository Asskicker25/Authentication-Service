#pragma once

#include <sqlConnector/mysql/jdbc.h>

enum class StatementType
{
	CREATEACCOUNT = 0,
	AUTHENTICATEACCOUNT = 1,
	CREATEUSER = 2,
	UPDATEWEBAUTHID = 3,
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
	void AddResultSetStatement(const ResultSetStatement& key, const char* query);

	sql::PreparedStatement* GetStatement(const StatementType& key);
	sql::ResultSet* GetResultSetStatement(const ResultSetStatement& key);
	std::map<StatementType, sql::PreparedStatement*> listOfStatements;

	sql::Connection* GetConnection();

private:

	sql::mysql::MySQL_Driver* driver;
	sql::Connection* connection;
	sql::ResultSet* resultSet;
	sql::Statement* statement;

	std::map<ResultSetStatement, sql::ResultSet*> listOfResultSetStatements;

	bool isConnected;
};

