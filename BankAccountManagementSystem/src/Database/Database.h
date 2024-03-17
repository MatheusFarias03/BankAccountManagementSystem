//
//	Database.h
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 10/03/2024
//

#ifndef DATABASE
#define DATABASE

#include <iostream>
#include <string>
#include "../../sqlite/sqlite3.h"

class Database {
public:
	Database();
	~Database();

	void makeQuery(const char* query);

	void checkError(const int request, const char* err);

	bool checkSSNExists(const std::string ssn);

	bool checkLogin(const int accountNum, const std::string password);

private:
	sqlite3* db;
	sqlite3_stmt* stmt;
};

#endif // !DATABASE

