//
//	Menu.cpp
//	BankAccountManagementSystem
//
//	Created by Matheus Matsumoto on 10/03/2024
//

#include "Menu.h"

Menu::Menu(AccountManager& accountManager) {
    this->accountManager = &accountManager;
    this->option = 0;
}

Menu::~Menu() {
    if (accountManager != nullptr) {
        delete accountManager;
        accountManager = nullptr;
    }
    option = NULL;
}

void Menu::clearScreen() {
    // For Windows.
#ifdef _WIN32
    system("cls");
    // For Unix-like systems.
#else
    system("clear");
#endif
}

void Menu::showMenu() {

    bool menuRunning = true;
    std::string optionInput;
    do
    {
        clearScreen();
        std::cout << "Welcome to the bank!\nChoose an option:"
            "\n1. Create account"
            "\n2. Login"
            "\n3. Exit\n";
        
        std::cout << "\nInput your command: " << std::endl;
        std::getline(std::cin, optionInput);
        option = std::stoi(optionInput);

        switch (option)
        {
        case 1:
            accountManager->createBankAccount();
            std::cout << "Press any key to continue." << std::endl;
            std::getchar();
            break;
        case 2:
            accountManager->loginBankAccount();
            std::cout << "Press any key to continue." << std::endl;
            std::getchar();
            break;
        case 3:
            menuRunning = false;
            break;
        default:
            break;
        }
    } while (menuRunning == true);
}