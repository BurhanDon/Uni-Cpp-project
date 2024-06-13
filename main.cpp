#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;
string getCurrentDateTime()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    return dt;
}

int main()
{
    string userName;
    cout << "Enter Your Name: ";
    getline(cin, userName);
    while (userName.empty() || userName.find_first_not_of(' ') == string::npos)
    {
        cout << "Enter Your Name Correctly: ";
        getline(cin, userName);
    }
    cout << endl;
    cout << "Welcome " << userName << " to Bank Al Habib. " << endl;
    cout << endl;
    int currentBalance = 0, amountWithDrawl, amountDeposit, userOpt, userAge, userId;
    time_t now = time(0);
    userId = static_cast<int>(now);
    vector<string> transactionHistory;
    while (true)
    {
        cout << "[1] Deposit to your Account " << endl
             << "[2] Withdrawl from your Account" << endl
             << "[3] View Transaction History" << endl
             << "[4] Change my Details" << endl
             << "[5] View Balance" << endl
             << "[6] Exit" << endl;
        cout << endl;
        cin >> userOpt;
        if (userOpt == 1)
        {

            cout << "Press 0 to cancel or Exit" << endl;
            cout << "Enter Amount to Deposit: ";
            cin >> amountDeposit;
            cout << endl;
            if (amountDeposit < 0)
            {
                cout << "Insaan k bache bano! " << endl;
                cout << endl;
            }
            else if (amountDeposit == 0)
            {
                cout << "Transaction Cancelled" << endl;
                cout << endl;
                continue;
            }
            else
            {
                if (amountDeposit > 100)
                {
                    double tax = amountDeposit * 0.025;
                    amountDeposit -= tax;
                    cout << " NOTE: tax of 2.5% will be applied on the amount greater than 100" << endl;
                    cout << endl;
                }

                currentBalance += amountDeposit;
                cout << "New Balance: " << currentBalance << endl;
                cout << endl;
                transactionHistory.push_back(userName + " Deposited: " + to_string(amountDeposit) + " on " + getCurrentDateTime());
            }
        }
        else if (userOpt == 2)
        {
            cout << "Press 0 to Exit or Cancel " << endl;
            cout << "Enter Amount to Withdrawal: ";
            cin >> amountWithDrawl;
            cout << endl;
            if (amountWithDrawl >= currentBalance)
            {
                cout << "Sorry, you cannot withdraw more than the current balance" << endl;
                cout << "Your Current Balance is " << currentBalance << endl;
                continue;
            }
            else if (amountWithDrawl == 0)
            {
                cout << "Transaction Cancelled" << endl;
                cout << endl;
                continue;
            }
            else
            {
                if (amountDeposit > 100)
                {
                    double tax = amountDeposit * 0.025;
                    amountDeposit -= tax;
                    cout << " NOTE: tax of 2.5% will be applied on the amount greater than 100" << endl;
                    cout << endl;
                }
                currentBalance -= amountWithDrawl;
                cout << "New Balance: " << currentBalance << endl;
                cout << endl;
                transactionHistory.push_back(userName + " Withdrew: " + to_string(amountWithDrawl) + " on " + getCurrentDateTime());
            }
        }
        else if (userOpt == 3)
        {
            for (int i = 0; i < transactionHistory.size(); i++)
            {
                cout << transactionHistory[i] << endl;
            }
        }
        else if (userOpt == 4)
        {
            int userOpt1;
            cout << endl;
            cout << "Your User Id is " << userId << endl;
            cout << "[1] Change Name " << endl
                 << "[2] Change Age" << endl
                 << "[0] Cancel" << endl;
            cout << endl;
            cin >> userOpt1;
            if (userOpt1 == 1)
            {
                cout << "Current Name: " << userName << endl;
                cout << "Enter New Name: ";
                getline(cin, userName);
                while (userName.empty() || userName.find_first_not_of(' ') == string::npos)
                {
                    cout << "Enter Your Name Correctly: ";
                    getline(cin, userName);
                }
                cout << "Your Name Updated to: " << userName << endl;
                cout << endl;
            }
            else if (userOpt1 == 2)
            {
                cout << "Enter Your Age: ";
                cin >> userAge;
                cout << "Age Updated to " << userAge << endl;
                cout << endl;
            }
            else if (userOpt1 == 0)
            {
                cout << endl;
                cout << "Exited " << endl;
                cout << endl;
                continue;
            }
        }
        else if (userOpt == 5)
        {
            cout << "Your Current Balance is " << currentBalance << endl;
            cout << endl;
        }
        else if (userOpt == 6)
        {
            cout << "Thank you for using Bank Al Habib " << endl;
            cout << endl;
            break;
        }
        else
        {
            cout << "Invalid option" << endl;
            cout << endl;
        }
    }
    return 0;
}
