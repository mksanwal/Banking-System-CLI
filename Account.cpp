#include "Account.h"

Account::Account(int accNo, string name, double bal, string pin)
    : accountNumber(accNo), name(name), balance(bal), pin(pin) {}

int Account::getAccountNumber() const {
    return accountNumber;
}

string Account::getName() const {
    return name;
}

double Account::getBalance() const {
    return balance;
}

bool Account::validatePIN(string inputPin) const {
    return inputPin == pin;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > balance) return false;
    balance -= amount;
    return true;
}

string Account::toCSV() const {
    return to_string(accountNumber) + "," + name + "," + to_string(balance) + "," + pin;
}
