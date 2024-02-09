#include <iostream>

using namespace std;

int main() {
    const double initialBalance = 100000;
    const double annualInterestRate = 6.5 / 100;

    double balance = initialBalance;

    for (int year = 1; year <= 6; ++year) {
        balance += balance * annualInterestRate;
        cout << "Year " << year << " Balance: " << balance << endl;
    }

    return 0;
}

