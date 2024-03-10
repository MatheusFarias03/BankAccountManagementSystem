//
//	main.cpp
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 09/03/2024
//

#include <iostream>
#include "BankAccount/BankAccount.h"

int main() {

	BankAccount myAccount;

	long double depositValue = 350.00;
	myAccount.deposit(depositValue);

	long double withdrawValue = 1000.00;
	myAccount.withdraw(withdrawValue);

	myAccount.withdraw(100.00);

	myAccount.printInfo();

	return 0;
}