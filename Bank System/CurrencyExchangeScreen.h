#pragma once
#include <iostream>
#include "Screen.h"
#include "Currency.h"
#include <iomanip>
#include <vector>
using namespace std;
class CurrencyExchangeScreen : protected Screen
{
public:
    static void showCurrencyExchangeScreen()
    {
        system("cls");
        drawScreenHeader("\t\tCurrency Exchange");
        // display choices
		cout << setw(37) << left << "" << "1. Show All Currencies\n";
		cout << setw(37) << left << "" << "2. Find Currency\n";
		cout << setw(37) << left << "" << "3. Update Currency Rate\n";
		cout << setw(37) << left << "" << "4. Exchange Currency\n";
		cout << setw(37) << left << "" << "5. Go Back to Main Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
		
    }
};

