# Inheritance Activity

## main.cpp
```cpp
#include <iostream>
#include "checkingAccount.h"
#include "savingsAccount.h"

using namespace std;

// Menu for checking account
void checkingMenu(checkingAccount &account) {
    int input;
    double amount;

    do {
        cout << "\n===== Checking Account Menu =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Print balance status\n";
        cout << "4. Print account details\n";
        cout << "5. Print daily interest\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> input;

        switch (input) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Service charge applies if amount > $500 (" 
                     << account.getServiceCharges() << "%)\n";
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                if (account.verifyBalance()) {
                    cout << "Your account balance is positive.\n";
                } else {
                    cout << "Your balance is below the minimum.\n";
                }
                break;

            case 4:
                account.print();
                break;

            case 5:
                account.postInterest();
                break;

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (input != 0);
}

// Menu for savings account
void savingsMenu(savingsAccount &account) {
    int input;
    double amount;

    do {
        cout << "\n===== Savings Account Menu =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Post interest\n";
        cout << "4. Print account details\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> input;

        switch (input) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.postInterest();
                cout << "Interest posted.\n";
                break;

            case 4:
                account.print();
                break;

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (input != 0);
}

// Main
int main() {
    int accountType;
    int accountNumber;
    double balance;
    double interestRate;
    double minBalance;
    double serviceCharges;

    cout << "===== Bank Account Program =====\n";
    cout << "Choose account type:\n";
    cout << "1. Checking Account\n";
    cout << "2. Savings Account\n";
    cout << "Enter choice: ";
    cin >> accountType;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter starting balance (USD): ";
    cin >> balance;

    if (accountType == 1) {
        // Checking account creation
        cout << "Enter interest rate (%): ";
        cin >> interestRate;

        cout << "Enter minimum balance: ";
        cin >> minBalance;

        cout << "Enter service charges (%): ";
        cin >> serviceCharges;

        checkingAccount c(accountNumber, balance, interestRate, minBalance, serviceCharges);
        checkingMenu(c);
    }
    else if (accountType == 2) {
        // Savings account creation
        cout << "Enter interest rate (%): ";
        cin >> interestRate;

        savingsAccount s(accountNumber, balance, interestRate);
        savingsMenu(s);
    }
    else {
        cout << "Invalid account type selected. Exiting...\n";
    }

    cout << "\nThank you for using the banking system!\n";
    return 0;
}
```

## bankAccount.cpp
```cpp
#include "bankAccount.h"
#include <iostream>

void bankAccount::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}
int bankAccount::getAccountNumber() const {
    return this->accountNumber;
}
double bankAccount::getAccountBalance() const {
    return this->balance;
}
void bankAccount::deposit(double amount) {
    balance += amount; // balance = balance + amount
}
void bankAccount::withdraw(double amount) {
    balance -= amount;
}
void bankAccount::print() const {
    std::cout << "Account Number: " << this->accountNumber << std::endl;
    std::cout << "Balance (USD): " << this->balance << std::endl;
}
bankAccount::bankAccount() = default;

bankAccount::bankAccount(int accountNumber, double balance) :
                         accountNumber(accountNumber), balance(balance) {}
```

## bankAccount.h
```cpp
#pragma once

class bankAccount {
private:
    int accountNumber = 0;
    double balance = 0;
public:
    void setAccountNumber(int accountNumber);
    int getAccountNumber() const;
    double getAccountBalance() const;
    void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void print() const;
    bankAccount();
    bankAccount(int accountNumber, double balance);
};
```

## checkingAccount.cpp
```cpp
#include "checkingAccount.h"

#include <iomanip>
#include <iostream>

void checkingAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}
double checkingAccount::getInterestRate() const {
    return interestRate;
}
void checkingAccount::setMinBalance(double minBalance) {
    this->minBalance = minBalance;
}
double checkingAccount::getMinBalance() const {
    return minBalance;
}
void checkingAccount::setServiceCharges(double serviceCharges) {
    this->serviceCharges = serviceCharges;
}
double checkingAccount::getServiceCharges() const {
    return serviceCharges;
}
void checkingAccount::postInterest() const {
    std::cout << "Your daily interest is: " << std::fixed << std::setprecision(2)
                << "USD " << getAccountBalance() * (interestRate / 100.0 / 365.0) << std::endl;
}
bool checkingAccount::verifyBalance() const {
    if (getAccountBalance() >= minBalance) {
        std::cout << "Your balance is: " << getAccountBalance() << std::endl;
        return true;
    } else {
        std::cout << "Your balance is: " << getAccountBalance() << std::endl;
        return false;
    }
}
void checkingAccount::deposit(double amount) {
    bankAccount::deposit(amount);
}
void checkingAccount::withdraw(double amount) {
    double fee;
    if (amount > bankAccount::getAccountBalance()) {
        std::cout << "Not enough balance to withdraw: " << amount << std::endl;
        std::cout << "Your current balance is: " << bankAccount::getAccountBalance() << std::endl;
    } else if (amount > 500) {
        fee = amount * (serviceCharges/100.0);
        amount = amount + fee;
        bankAccount::withdraw(amount);
        std::cout << "Your new balance is " << bankAccount::getAccountBalance();
    } else if (amount <= 500) {
        bankAccount::withdraw(amount);
        std::cout << "Your new balance is " << bankAccount::getAccountBalance();
    }

}
void checkingAccount::print() const {
    bankAccount::print();
    std::cout << "Interest Rate %: " << getInterestRate() << std::endl;
    std::cout << "Min Balance $: " << getMinBalance() << std::endl;
    std::cout << "Service Charges %: " << getServiceCharges() << std::endl;
}
checkingAccount::checkingAccount() = default;
checkingAccount::checkingAccount(int accountNumber, double balance,
                                double interestRate, double minBalance, double serviceCharges) :
                                bankAccount(accountNumber, balance), interestRate(interestRate),
                                minBalance(minBalance), serviceCharges(serviceCharges) {}
```

## checkingAccount.h
```cpp
#pragma once
#include "bankAccount.h"

class checkingAccount : public bankAccount {
private:
    double interestRate = 0.0;
    double minBalance = 0.0;
    double serviceCharges = 0.0;
public:
    void setInterestRate(double interestRate);
    double getInterestRate() const;
    void setMinBalance(double minBalance);
    double getMinBalance() const;
    void setServiceCharges(double serviceCharges);
    double getServiceCharges() const;
    void postInterest() const;
    bool verifyBalance() const;
    void deposit(double amount);
    void withdraw(double amount);
    void print() const;
    checkingAccount();
    checkingAccount(int accountNumber, double balance, double interestRate,
                    double minBalance, double serviceCharges);
};

```

## savingsAccount.cpp
```cpp
#include "savingsAccount.h"
#include <iostream>
#include <iomanip>

// Set / Get interest rate
void savingsAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}

double savingsAccount::getInterestRate() const {
    return interestRate;
}

// Post daily interest
void savingsAccount::postInterest() {
    double dailyInterest = getAccountBalance() * (interestRate / 100.0 / 365.0);
    std::cout << std::fixed << std::setprecision(2)
              << "Daily interest: USD " << dailyInterest << std::endl;
    deposit(dailyInterest);  // Add daily interest to balance
}

// Withdraw money
void savingsAccount::withdraw(double amount) {
    if (amount > getAccountBalance()) {
        std::cout << "Insufficient funds. Withdrawal denied.\n";
    } else {
        bankAccount::withdraw(amount);
        std::cout << "Withdrawal successful. New balance: "
                  << getAccountBalance() << "\n";
    }
}

// Print account details
void savingsAccount::print() const {
    bankAccount::print();
    std::cout << "Interest Rate (%): " << interestRate << std::endl;
    std::cout << "Daily interest: USD "
              << std::fixed << std::setprecision(2)
              << getAccountBalance() * (interestRate / 100.0 / 365.0) << std::endl;
}

// Constructors
savingsAccount::savingsAccount() = default;

savingsAccount::savingsAccount(int accountNumber, double balance, double interestRate)
    : bankAccount(accountNumber, balance), interestRate(interestRate) {}
```

## savingsAccount.h
```cpp
#pragma once
#include "bankAccount.h"

class savingsAccount : public bankAccount {
private:
    double interestRate = 0.0;

public:
    void setInterestRate(double interestRate);
    double getInterestRate() const;

    void postInterest();
    void withdraw(double amount) override;
    void print() const override;

    savingsAccount();
    savingsAccount(int accountNumber, double balance, double interestRate);
};
```
