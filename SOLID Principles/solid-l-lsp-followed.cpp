#include <iostream>
#include <vector>
using namespace std;

class DepositOnlyAccount {
public:
    virtual void depost(double amount) = 0;
};

class WithdrawOnlyAccount : public DepositOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public WithdrawOnlyAccount {
private:
    double balance;
public:
    SavingsAccount(double initialBalance) : balance(initialBalance) {}

    void depost(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << " to Savings Account. New balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds in Savings Account." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Savings Account. New balance: $" << balance << endl;
        }
    }
};

class CurrentAccount : public WithdrawOnlyAccount {
private:
    double balance;
public:
    CurrentAccount(double initialBalance) : balance(initialBalance) {}

    void depost(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << " to Current Account. New balance: $" << balance << endl;
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds in Current Account." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Current Account. New balance: $" << balance << endl;
        }
    }
};

class FixedTermAccount : public DepositOnlyAccount {
private:
    double balance;
public:
    FixedTermAccount(double initialBalance) : balance(initialBalance) {}

    void depost(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << " to Fixed Term Account. New balance: $" << balance << endl;
    }
};

class BankClient {
private:
    vector<DepositOnlyAccount *> depositAccounts;
    vector<WithdrawOnlyAccount *> withdrawAccounts;

public:
    BankClient(vector<DepositOnlyAccount *> depositAccounts, vector<WithdrawOnlyAccount *> withdrawAccounts)
        : depositAccounts(depositAccounts), withdrawAccounts(withdrawAccounts) {}

    void processTransactions() {
        for (auto account : depositAccounts) {
            account->depost(100.0);
        }

        for (auto account : withdrawAccounts) {
            account->depost(100.0);
            account->withdraw(50.0);
        }
    }
};

int main() {
    SavingsAccount savings(500.0);
    CurrentAccount current(1000.0);
    FixedTermAccount fixedTerm(2000.0);

    vector<DepositOnlyAccount *> depositAccounts = { &fixedTerm };
    vector<WithdrawOnlyAccount *> withdrawAccounts = { &savings, &current };

    BankClient client(depositAccounts, withdrawAccounts);
    client.processTransactions();

    return 0;
}