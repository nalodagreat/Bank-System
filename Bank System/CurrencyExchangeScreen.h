#pragma once
#include <iostream>
#include "Screen.h"
#include "Currency.h"
#include <iomanip>
#include <vector>
#include "CurrencyListScreen.h"
using namespace std;
class CurrencyExchangeScreen : protected Screen
{
    static void _goBackTocurrencyExchangeScreen()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        showCurrencyExchangeScreen();
    }
    static void _showAllCurrencies()
    {
        //cout << "currencies list will be here";
        CurrencyListScreen::showCurrencyList();
        _goBackTocurrencyExchangeScreen();

    }
    static void _findCurrencyByCode()
    {
        cout << "findCurrencyByCode will be here";
        _goBackTocurrencyExchangeScreen();

    }
    static void _updateCurrencyRate()
    {
        cout << "updateCurrencyRate will be here";
        _goBackTocurrencyExchangeScreen();
    }
    static void _exchangeCurrency()
    {
        cout << "updateCurrencyRate will be here";
        _goBackTocurrencyExchangeScreen();
    }
    enum enExchangeMenuOptions
    {
        eShowAllCurrencies = 1,
        eFindCurrency = 2,
        eUpdateCurrencyRate = 3,
        eExchangeCurrency = 4,
        eGoBackToMainMenu = 5
	};
    static short _ReadExchangeMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = InputValidate::readShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }
    static void _PerformExchangeMenuOption(enExchangeMenuOptions option)
    {
        switch (option)
        {
        case eShowAllCurrencies:
            system("cls");
            _showAllCurrencies();
            break;
        case eFindCurrency:
            system("cls");
            _findCurrencyByCode();
            break;
        case eUpdateCurrencyRate:
            system("cls");
            _updateCurrencyRate();
            break;
        case eExchangeCurrency:
            system("cls");
            _exchangeCurrency();
            break;
        case eGoBackToMainMenu:
                
            break;
        }
	}
public:
    static void showCurrencyExchangeScreen()
    {
        system("cls");
        drawScreenHeader("\t\tCurrency Exchange");
        // display choices
		cout <<endl <<setw(37) << left << "" << "1. Show All Currencies\n";
		cout << setw(37) << left << "" << "2. Find Currency\n";
		cout << setw(37) << left << "" << "3. Update Currency Rate\n";
		cout << setw(37) << left << "" << "4. Exchange Currency\n";
		cout << setw(37) << left << "" << "5. Go Back to Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformExchangeMenuOption((enExchangeMenuOptions)_ReadExchangeMenuOption());
    }
};

