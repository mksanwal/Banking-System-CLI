// g++ Account.cpp BankSystem.cpp Transaction.cpp main.cpp -o banking
// g++ Account.cpp BankSystem.cpp Transaction.cpp main.cpp -o banking.exe
// .\banking.exe


#include "BankSystem.h"
#include "Transaction.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

BankSystem::BankSystem() {
    loadAccounts();
}

void BankSystem::loadAccounts() {
    accounts.clear();
    ifstream file("data/accounts.csv");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() == 4) {
            int accNo = stoi(tokens[0]);
            string name = tokens[1];
            double balance = stod(tokens[2]);
            string pin = tokens[3];
            accounts.emplace_back(accNo, name, balance, pin);
        }
    }

    file.close();
}

void BankSystem::saveAccounts() {
    ofstream file("data/accounts.csv");
    for (const auto& acc : accounts) {
        file << acc.toCSV() << endl;
    }
    file.close();
}

void BankSystem::createAccount() {
    int accNo;
    string name, pin;
    double initialDep;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter 4-digit PIN: ";
    cin >> pin;
    cout << "Enter Initial Deposit: ";
    cin >> initialDep;

    accounts.emplace_back(accNo, name, initialDep, pin);
    saveAccounts();
    cout << "Account created successfully.\n";
}

Account* BankSystem::login(int accNo, string pin) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo && acc.validatePIN(pin)) {
            return &acc;
        }
    }
    return nullptr;
}

void BankSystem::updateAccount(const Account& updated) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == updated.getAccountNumber()) {
            acc = updated;
            saveAccounts();
            break;
        }
    }
}

void BankSystem::showAllAccounts() {
    cout << "\n--- All Accounts ---\n";
    for (const auto& acc : accounts) {
        cout << "Account #" << acc.getAccountNumber()
             << " | Name: " << acc.getName()
             << " | Balance: ₹" << acc.getBalance() << endl;
    }
}
