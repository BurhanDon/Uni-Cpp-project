#include <iostream>
#include <string>

using namespace std;

int main()
{
    string userName;
    cout << "Enter Your Name: ";
    cin >> userName;
    cout << "Welcome " << userName << " to Bank Al Habib." << endl;
    int currentBalance, amountWithDrawl, amountDeposit, userOpt, userAge, userId;
    currentBalance = 0;
    cout << "Your Current Balance is " << currentBalance << endl;
    cout << "[1] Deposit to your Account " << endl
         << "[2] Withdrawl from your Account" << endl
         << "[3] View History" << endl
         << "[4] Change my Details" << endl;
    cin >> userOpt;
    if (userOpt == 1)
    {
        cout << "Enter Amount to Deposit: ";
        cin >> amountDeposit;
        currentBalance += amountDeposit;
    }
    else if (userOpt == 2)
    {
        cout << "Enter Amount to Withdrawal: ";
        cin >> amountWithDrawl;

        if (currentBalance == 0)
        {
            cout << "Sorry, you don't have enough money to withdraw " << endl;
        }
        else if (amountWithDrawl > currentBalance)
        {
            cout << "Sorry, you cannot withdraw more than the current balance" << endl;
        }
        else
        {
            currentBalance = currentBalance - amountWithDrawl;
            cout << "New Balance: " << currentBalance << endl;
        }
    }
    else if (userOpt == 3)
    {
        cout << userName << endl;
        cout << "Wanna Change your details?" << endl;
        cout << "[1] Yes" << endl;
        cout << "[2] No" << endl;
        cin >> userOpt;
        if (userOpt == 1)

        {
            cout << "[1] Change my Name " << endl
                 << "[2] Change my Age" << endl;
        }
    }
    else
    {
        cout << "Invalid option" << endl;
    }
    cout << "Current Balance:" << currentBalance << endl;

    return 0;
}
