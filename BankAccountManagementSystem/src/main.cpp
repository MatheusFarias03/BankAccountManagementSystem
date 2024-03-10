//
//	main.cpp
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 10/03/2024
//

#include <iostream>
#include "AccountManager/AccountManager.h"

int main() {

	AccountManager accountManager;

	accountManager.createBankAccount();

	std::string password = "myPassword123";
	std::string passwordEncrypted = accountManager.encryptPassword(password);
	std::string passwordDecrypted = accountManager.decryptPassword(passwordEncrypted);
	std::cout << "\nOriginal Password: " << password
		<< "\nEncrypted Password: " << passwordEncrypted
		<< "\nDecrypted Password: " << passwordDecrypted
		<< std::endl;

	return 0;
}