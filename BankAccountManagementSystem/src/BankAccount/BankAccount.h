//
//	BankAccount.h
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 09/03/2024
//

#ifndef BANKACCOUNT
#define BANKACCOUNT

#include <iostream>
#include <string>
#include <cstdlib>
#include <random>

class BankAccount {
public:
	BankAccount(std::string name, std::string address, std::string ssn);
	~BankAccount();

	int getAccountNumber();
	long double getBalance();

	void withdraw(long double value);
	void deposit(long double value);
	
	void printInfo();

private:
	std::string name;
	std::string address;
	std::string ssn;

	int accountNumber;
	long double balance;
};

#endif // !BANKACCOUNT
