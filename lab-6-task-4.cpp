#include <iostream>

using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;

public:
    Account(int accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

    virtual void displayDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int accountNumber, float balance, float interestRate)
        : Account(accountNumber, balance), interestRate(interestRate) {}

    void displayDetails() const override {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int accountNumber, float balance, float overdraftLimit)
        : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    void displayDetails() const override {
        Account::displayDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main() {
    int accountNumber;
    float balance, interestRate, overdraftLimit;

    cout << "Enter Savings Account Number: ";
    cin >> accountNumber;
    cout << "Enter Savings Account Balance: ";
    cin >> balance;
    cout << "Enter Savings Account Interest Rate: ";
    cin >> interestRate;

    SavingsAccount savingsAccount(accountNumber, balance, interestRate);

    cout << "\nSavings Account Details:\n";
    savingsAccount.displayDetails();

    cout << "\nEnter Checking Account Number: ";
    cin >> accountNumber;
    cout << "Enter Checking Account Balance: ";
    cin >> balance;
    cout << "Enter Checking Account Overdraft Limit: ";
    cin >> overdraftLimit;

    CheckingAccount checkingAccount(accountNumber, balance, overdraftLimit);

    cout << "\nChecking Account Details:\n";
    checkingAccount.displayDetails();

    return 0;
}