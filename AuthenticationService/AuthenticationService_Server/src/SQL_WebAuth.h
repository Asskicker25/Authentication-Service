#pragma once

class SQLHandler;

class SQL_WebAuth
{
public:
	SQL_WebAuth();
	~SQL_WebAuth();

	void AssignSQLDatabase(SQLHandler* sqlHandler);
	int AddAccount(const char* email, const char* password);

private:
	SQLHandler* sqlHandler;
};

