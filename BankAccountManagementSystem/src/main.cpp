//
//	main.cpp
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 10/03/2024
//

#include <iostream>
#include "AccountManager/AccountManager.h"
#include "Database/Database.h"

int main() {

	Database* database = new Database();
	delete database;
	database = nullptr;

	return 0;
}