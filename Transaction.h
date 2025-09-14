#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
public:
    static void logTransaction(int accountNumber, string type, double amount);
};

#endif
