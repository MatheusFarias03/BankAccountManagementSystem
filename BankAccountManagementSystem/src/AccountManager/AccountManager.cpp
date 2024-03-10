//
//	AccountManager.cpp
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 10/03/2024
//

#include "AccountManager.h"

AccountManager::AccountManager() {
	managerId = 0;
	bankAccount = nullptr;
}

AccountManager::~AccountManager() {
	if (bankAccount != nullptr) {
		delete bankAccount;
		bankAccount = nullptr;
	}
}

void AccountManager::createBankAccount() {
	
	std::string name;
	std::string address;
	std::string ssn;
	std::string password;

	std::cout << "\nAccount Creation.\nInsert your full name: ";
	std::getline(std::cin, name);

	std::cout << "\nInsert your address: ";
	std::getline(std::cin, address);

	std::cout << "\nInsert your social security number (SSN): ";
	std::getline(std::cin, ssn);
	std::cout << std::endl;

	// TODO: Check if the ssn is already in the database.

	bankAccount = new BankAccount(name, address, ssn);
}

void AccountManager::loginBankAccount() {

	std::string accountNumberStringInput;
	int accountNumberIntInput;
	bool correctInputType = false;
	
	while (!correctInputType) {
		try {
			std::cout << "\nInsert your account number: ";
			std::cin >> accountNumberStringInput;
			accountNumberIntInput = std::stoi(accountNumberStringInput);
			correctInputType = true;
		}
		catch (const std::invalid_argument& e) {
			std::cout << "Invalid input. Please enter a valid account number.\n";
		}
		std::cin.clear();
	}
	
	// TODO: Search somewhere for the account number - password combination in the datbase.
}

std::string AccountManager::encryptPassword(const std::string& password) {
	
	std::string cipherText = password;
	const int shift = 7;
	const int strLen = password.length();
	int digit;

	for (int i = 0; i < strLen; i++) {
		
		// Encrypt uppercase letters.
		if (std::isupper(cipherText[i])) {
			cipherText[i] = (cipherText[i] - 'A' + shift) % 26 + 'A';
		}

		// Encrypt lowercase letters.
		else if (std::islower(cipherText[i])) {
			cipherText[i] = (cipherText[i] - 'a' + shift) % 26 + 'a';
		}

		// Encrypt digits.
		else if (std::isdigit(cipherText[i])) {
			digit = (int(cipherText[i] - '0') + shift) % 10;
			cipherText[i] = char(digit + '0');
		}
	}

	return cipherText;
}

std::string AccountManager::decryptPassword(const std::string& encryptedPassword) {
	std::string decryptedPassword = encryptedPassword;
	const int shift = 7;
	const int strLen = encryptedPassword.length();
	int digit;

	for (int i = 0; i < strLen; i++) {
		// Decrypt uppercase letters.
		if (std::isupper(decryptedPassword[i])) {
			decryptedPassword[i] = (decryptedPassword[i] - 'A' - shift + 26) % 26 + 'A';
		}

		// Decrypt lowercase letters.
		else if (std::islower(decryptedPassword[i])) {
			decryptedPassword[i] = (decryptedPassword[i] - 'a' - shift + 26) % 26 + 'a';
		}

		// Decrypt digits.
		else if (std::isdigit(decryptedPassword[i])) {
			digit = (int(decryptedPassword[i] - '0') - shift + 10) % 10;
			decryptedPassword[i] = char(digit + '0');
		}
	}

	return decryptedPassword;
}