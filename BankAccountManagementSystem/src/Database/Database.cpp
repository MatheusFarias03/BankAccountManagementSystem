//
//	Database.cpp
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 10/03/2024
//

#include "Database.h"

Database::Database() {

	sqlite3_open("database.db", &db);

	std::string query = "CREATE TABLE IF NOT EXISTS user("
						"name varchar(100), " 
						"address varchar(255), " 
						"ssn varchar(50), "
						"accountNumber INT, "
						"balance TEXT"
						"); ";

	makeQuery(query.c_str());
}

Database::~Database() {
	db = nullptr;
	stmt = nullptr;
}

void Database::checkError(const int request, const char* err) {
	if (request != SQLITE_OK) {
		std::cout << "\nError: " << err << std::endl;
	}
}

void Database::makeQuery(const char* query) {
	char* err;
	int request = sqlite3_exec(db, query, NULL, NULL, &err);
	checkError(request, err);
}