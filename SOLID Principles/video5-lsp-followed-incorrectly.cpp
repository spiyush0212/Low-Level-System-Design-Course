#include <iostream>
#include <vector>
using namespace std;

class Account
{
public:
    virtual void depost(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public Account
{
private:
    double balance;

public:
    SavingsAccount(double initialBalance) : balance(initialBalance) {}

    void depost(double amount) override
    {
        balance += amount;
        cout << "Deposited $" << amount << " to Savings Account. New balance: $" << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount > balance)
        {
            cout << "Insufficient funds in Savings Account." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Savings Account. New balance: $" << balance << endl;
        }
    }
};

class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount(double initialBalance) : balance(initialBalance) {}

    void depost(double amount) override
    {
        balance += amount;
        cout << "Deposited $" << amount << " to Current Account. New balance: $" << balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount > balance)
        {
            cout << "Insufficient funds in Current Account." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Current Account. New balance: $" << balance << endl;
        }
    }
};

class FixedTermAccount : public Account
{
private:
    double balance;

public:
    FixedTermAccount(double initialBalance) : balance(initialBalance) {}

    void depost(double amount) override
    {
        balance += amount;
        cout << "Deposited $" << amount << " to Fixed Term Account. New balance: $" << balance << endl;
    }

    void withdraw(double amount) override
    {
        throw runtime_error("Withdrawals are not allowed from a Fixed Term Account until maturity.");
    }
};

class BankClient
{
private:
    vector<Account *> accounts;

public:
    BankClient(const vector<Account *> &accounts) : accounts(accounts) {}

    void processTransactions()
    {
        for (auto account : accounts)
        {
            account->depost(100);

            if (dynamic_cast<FixedTermAccount *>(account))
            {
                cout << "Cannot withdraw from a Fixed Term Account." << endl;
            }
            else
            {
                try
                {
                    account->withdraw(50);
                }
                catch (const runtime_error &e)
                {
                    cout << e.what() << endl;
                }
            }
        }
    }
};

int main()
{
    SavingsAccount savings(500);
    CurrentAccount current(1000);
    FixedTermAccount fixedTerm(2000);
    vector<Account *> accounts = {&savings, &current, &fixedTerm};

    BankClient client(accounts);
    client.processTransactions();

    return 0;
}