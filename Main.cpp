#include "BankSystem.h"
#include "Transaction.h"
#include <iostream>
#include <fstream>

using namespace std;
int main() {
    BankSystem system;
    int choice;

    while (true) {
        cout << "\n==== Bank System ====\n";
        cout << "1. Create Account\n2. Login\n3. Show All Accounts\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            system.createAccount();
        } else if (choice == 2) {
            int accNo;
            string pin;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter PIN: ";
            cin >> pin;

            Account* acc = system.login(accNo, pin);
            if (!acc) {
                cout << "Invalid credentials.\n";
                continue;
            }

            cout << "Welcome, " << acc->getName() << "!\n";
            int opt;
            do {
                cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. View Transactions\n5. Logout\n";
                cin >> opt;

                if (opt == 1) {
                    cout << "Current Balance: ₹" << acc->getBalance() << endl;
                } else if (opt == 2) {
                    double amt;
                    cout << "Enter amount to deposit: ";
                    cin >> amt;
                    acc->deposit(amt);
                    Transaction::logTransaction(acc->getAccountNumber(), "Deposit", amt);
                    system.updateAccount(*acc);
                } else if (opt == 3) {
                    double amt;
                    cout << "Enter amount to withdraw: ";
                    cin >> amt;
                    if (acc->withdraw(amt)) {
                        Transaction::logTransaction(acc->getAccountNumber(), "Withdraw", amt);
                        system.updateAccount(*acc);
                    } else {
                        cout << "Insufficient balance!\n";
                    }
                } else if (opt == 4) {
                    string file = "data/transactions/" + to_string(acc->getAccountNumber()) + ".txt";
                    ifstream tfile(file);
                    if (!tfile.is_open()) {
                        cout << "No transactions found.\n";
                    } else {
                        string line;
                        cout << "\n--- Transactions ---\n";
                        while (getline(tfile, line)) {
                            cout << line << endl;
                        }
                        tfile.close();
                    }
                }
            } while (opt != 5);

        } else if (choice == 3) {
            system.showAllAccounts();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
