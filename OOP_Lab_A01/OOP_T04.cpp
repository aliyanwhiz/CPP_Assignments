#include <iostream>
using namespace std;

class Account
{

protected:
    double balance;

public:
    Account(double b)
    {

        balance = b;
    }

    void deposit(double amount)
    {

        balance += amount;
    }

    double getBalance()
    {

        return balance;
    }
};

class SavingsAccount : public Account
{

private:
    double profitRate;

public:
    SavingsAccount(double b, double rate) : Account(b)
    {

        profitRate = rate;
    }

    void addProfit()
    {

        balance += balance * profitRate;
    }
};

int main()
{

    SavingsAccount sa(1000.0, 0.05);

    sa.deposit(500.0);
    sa.addProfit();
    cout << "Final Balance: " << sa.getBalance() << endl;

    return 0;
}