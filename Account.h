
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    string name;
    double balance;
    string pin;

public:
    Account(int accNo, string name, double bal, string pin);
    int getAccountNumber() const;
    string getName() const;
    double getBalance() const;
    bool validatePIN(string inputPin) const;
    void deposit(double amount);
    bool withdraw(double amount);
    string toCSV() const;
};

#endif
