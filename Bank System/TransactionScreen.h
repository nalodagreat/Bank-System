#pragma once
#pragma once
#include "BankClient.h"
#include "ClientListScreen.h"
using namespace std;
class TransactionScreen : protected Screen
{
private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eShowMainMenue = 4
    };

    static short readTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = InputValidate::readShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
        return Choice;
    }


    static void showDepositScreen()
    {
        cout << "\n Deposit Screen will be here.\n";
    }

    static void showWithdrawScreen()
    {
        cout << "\n Withdraw Screen will be here.\n";
    }

    static void showTotalBalancesScreen()
    {
        cout << "\n Balances Screen will be here.\n";
    }

    static void goBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        showTransactionsMenue();

    }

    static void performTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            showDepositScreen();
            goBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
           showWithdrawScreen();
            goBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            showTotalBalancesScreen();
            goBackToTransactionsMenue();
            break;
        }


        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }

public:

    static void showTransactionsMenue()
    {
        system("cls");
        drawScreenHeader("\t  Transactions Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        performTransactionsMenueOption((enTransactionsMenueOptions)readTransactionsMenueOption());
    }
};

