#pragma once

class SQLHandler;

class SQL_WebAuth
{
public:
	SQL_WebAuth();
	~SQL_WebAuth();

	void AssignSQLDatabase(SQLHandler* sqlHandler);
	void AddAccount(const char* email, const char* password);

private:
	SQLHandler* sqlHandler;
};

