#pragma once
#include <iostream>
#include "Screen.h"
#include "InputValidate.h"
#include <iomanip>
#include "ClientListScreen.h"
#include "AddNewClientScreen.h"
#include "DeletClientScreen.h"
#include "UpdateClientScreen.h"
#include "FindClientScreen.h"
#include "TransactionScreen.h"
#include "ManageUsersScreen.h"
#include "Global.h"
#include "LoginRegisterSceen.h"
#include "CurrencyExchangeScreen.h"
using namespace std;

class MainScreen :protected Screen
{
private:
    enum enMainMenueOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7,eLoginRegister ,eCurrencyExchange,eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = InputValidate::readShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        showMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        ClientListScreen::ShowClientsList();
        _GoBackToMainMenue();

    }

    static void _ShowAddNewClientsScreen()
    {
        AddNewClientScreen::addNewClient();
        _GoBackToMainMenue();
    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        DeleteClientScreen::ShowDeleteClientScreen();
        _GoBackToMainMenue();
    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        UpdateClientScreen::updateClient();
        _GoBackToMainMenue();
    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        FindClientScreen::ShowFindClientScreen();
        _GoBackToMainMenue();
    }

    static void _ShowTransactionsMenue()
    {
        //cout << "\nTransactions Menue Will be here...\n";
        TransactionScreen::showTransactionsMenue();
        _GoBackToMainMenue();
    }

    static void _ShowManageUsersMenue()
    {
       // cout << "\nUsers Menue Will be here...\n";
		ManageUsersScreen::showManageUsersMenu();
        _GoBackToMainMenue();
    }

   /* static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }*/
    static void _ShowCurrencyExchange()
    {
        CurrencyExchangeScreen::showCurrencyExchangeScreen();
        _GoBackToMainMenue();
    }
    static void _Logout()
    {
		CurrentUser = User::find("", "");
		//after logout stack will finish and back to main function

    }
    static void _ShowLoginRegister()
    {
        //cout << "\nLogin Register Screen Will be here...\n";
		LoginRegisterScreen::showLoginRegisterScreen();
        _GoBackToMainMenue();
    }

    static void _PerfromMainMenueOption(enMainMenueOptions mainMenueOption)
    {
        switch (mainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            break;
		case enMainMenueOptions::eLoginRegister:
			system("cls");
			_ShowLoginRegister();
          
            
        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchange();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            //Login();

            break;
        }

    }



public:


    static void showMainMenue()
    {

        system("cls");
        drawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

