//
//	Menu.h
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 10/03/2024
//

#ifndef MENU
#define MENU

#include <iostream>
#include <conio.h>
#include <string>
#include "../AccountManager/AccountManager.h"

class Menu {
public:
	Menu(AccountManager& accountManager);
	~Menu();

	void showMenu();
	void clearScreen();

private:
	int option;
	AccountManager* accountManager;
};



#endif // !MENU
