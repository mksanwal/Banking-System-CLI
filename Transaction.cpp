#include "Transaction.h"
#include <fstream>
#include <ctime>
#include <direct.h>  // For _mkdir on Windows
using namespace std;

void Transaction::logTransaction(int accountNumber, string type, double amount) {
    _mkdir("data");
    _mkdir("data/transactions");

    string filename = "data/transactions/" + to_string(accountNumber) + ".txt";
    ofstream file(filename, ios::app);

    time_t now = time(0);
    string dt = ctime(&now);
    dt.pop_back(); // remove newline

    file << dt << " | " << type << " | Amount: " << amount << endl;
    file.close();
}
