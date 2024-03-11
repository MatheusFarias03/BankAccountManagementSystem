//
//	Database.h
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 10/03/2024
//

#ifndef DATABASE
#define DATABASE

#include <iostream>
#include "../../sqlite/sqlite3.h"

class Database {
public:
	Database();
	~Database();

	void makeQuery(const char* query);

	void checkError(const int request, const char* err);

private:
	sqlite3* db;
	sqlite3_stmt* stmt;
};

#endif // !DATABASE

