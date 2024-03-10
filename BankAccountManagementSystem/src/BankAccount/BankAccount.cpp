//
//	BankAccount.cpp
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 09/03/2024
//

#include "BankAccount.h"

BankAccount::BankAccount() {

	std::random_device rd; // A seed source for the random number engine.
	std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd().
	std::uniform_int_distribution<> dis(100000, 999999); // Range from 100000 to 999999.
	
	accountNumber = dis(gen);
	balance = 0.0;

	std::cout << "Account created.\naccountNumber: " << accountNumber << "\nbalance: " << balance << std::endl;
}

BankAccount::~BankAccount() {}

int BankAccount::getAccountNumber() {
	return accountNumber;
}

long double BankAccount::getBalance() {
	return balance;
}

void BankAccount::deposit(long double value) {
	balance += value;
	std::cout << "Deposit of " << value << " added to account " << accountNumber << std::endl;
}

void BankAccount::withdraw(long double value) {
	if (balance < value) {
		std::cout << "Invalid Operation: value of withdraw is greater than balance" << std::endl;
		return;
	}
	balance -= value;
	std::cout << "Withdraw of " << value << " from account " << accountNumber << std::endl;
}

void BankAccount::printInfo() {
	std::cout << "BankAccount(accountNumber:" << accountNumber << ", balance:" << balance << ")" << std::endl;
}