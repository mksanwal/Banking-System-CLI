#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

#include "Account.h"
#include <vector>
using namespace std;

class BankSystem {
private:
    vector<Account> accounts;
    void loadAccounts();
    void saveAccounts();

public:
    BankSystem();
    void createAccount();
    Account* login(int accountNumber, string pin);
    void updateAccount(const Account& acc);
    void showAllAccounts();
};

#endif
