//
//	main.cpp
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 10/03/2024
//

#include <iostream>
#include "AccountManager/AccountManager.h"
#include "Database/Database.h"
#include "Menu/Menu.h"

int main() {

	Database* database = new Database();
	AccountManager* manager = new AccountManager(database);
	Menu mainMenu(*manager);
	
	mainMenu.showMenu();

	return 0;
}