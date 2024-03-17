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
						"balance TEXT, "
						"password varchar(255)"
						"); ";

	makeQuery(query.c_str());
}

Database::~Database() {
	sqlite3_close(db);
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

bool Database::checkSSNExists(const std::string ssn) {
	int count = 0;
	std::string query;
	query = "SELECT COUNT(*) FROM user WHERE ssn = '";
	query += ssn + "';";

	int result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
	if (result == SQLITE_OK) {
		if (sqlite3_step(stmt) == SQLITE_ROW) {
			count = sqlite3_column_int(stmt, 0);
		}
	}
	sqlite3_finalize(stmt);

	return count > 0;
}

bool Database::checkLogin(const int accountNum, const std::string encryptedPassword) {
	int count = 0;
	std::string query;

	query = "SELECT COUNT(*) FROM user WHERE accountNumber = ";
	query += std::to_string(accountNum) + " AND password = '" + encryptedPassword + "';";

	int result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
	if (result == SQLITE_OK) {
		if (sqlite3_step(stmt) == SQLITE_ROW) {
			count = sqlite3_column_int(stmt, 0);
		}
	}
	sqlite3_finalize(stmt);

	return count > 0;
}