//
//	AccountManager.h
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 10/03/2024
//

#ifndef ACCOUNTMANAGER
#define ACCOUNTMANAGER

#include <iostream>
#include "../BankAccount/BankAccount.h"
#include "../Database/Database.h"

class AccountManager {
public:
	AccountManager(Database* database);
	~AccountManager();

	void createBankAccount();

	void loginBankAccount();

	std::string encryptPassword(const std::string& password);

	std::string decryptPassword(const std::string& encryptedPassword);

private:
	int managerId;
	BankAccount* bankAccount;
	Database* database;
};

#endif // !ACCOUNTMANAGER
