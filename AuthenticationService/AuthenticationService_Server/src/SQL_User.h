#pragma once

class SQLHandler;

class SQL_User
{
public:
	SQL_User();
	~SQL_User();

	void AssignSQLDatabase(SQLHandler* sqlHandler);

	int AddNewUser(int& userID);
	int UpdateLastLogin(const int& userID);

private:
	SQLHandler* sqlHandler = nullptr;
};

