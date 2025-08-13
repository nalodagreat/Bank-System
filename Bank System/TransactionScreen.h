#pragma once

#include"DepositScreen.h"
#include"WithdrawScreen.h"
#include"TotalBalancesScreen.h"
#include "TransferScreen.h"
#include "TransferLogScreen.h"
using namespace std;
class TransactionScreen : protected Screen
{
private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3,eTransfer = 4,eTransferLog=5,eShowMainMenue = 6
    };

    static short readTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = InputValidate::readShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }


    static void showDepositScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        depositScreen::showDepositScreen();
    }

    static void showWithdrawScreen()
    {
        //cout << "\n Withdraw Screen will be here.\n";
        WithdrawScreen::showTheWithDrawScreen();
    }

    static void showTotalBalancesScreen()
    {
       // cout << "\n Balances Screen will be here.\n";
        TotalBalancesScreen::ShowTotalBalances();
        goBackToTransactionsMenue();
    }
    static void showTransferScreen()
    {
         //cout << "\n Transfere Screen will be here.\n";
        TransferScreen::showTransferScreen();
    }
    static void showTransferLogScreen()
    {
        //cout << "\n TransfereLog Screen will be here.\n";
        TransferLogScreen::showTransferLogScreen();
        
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
        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            showTransferScreen();
            //when u arrive here transferhistory  will be enable on file 
            goBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTransferLog:
        {
            system("cls");
            showTransferLogScreen();
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
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[6] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        performTransactionsMenueOption((enTransactionsMenueOptions)readTransactionsMenueOption());
    }
};

