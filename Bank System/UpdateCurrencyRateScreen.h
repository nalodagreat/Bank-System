#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Screen.h"
#include "Currency.h"
#include "InputValidate.h"
using namespace std;
class UpdateCurrencyRateScreen :protected Screen
{
    static string readCurrencyToUpdate()
    {
		string currencyCode="";
        cout<<"Enter Currency Code to update: ";
		currencyCode = InputValidate::readString();
		return currencyCode;
    }
    static void printCurrencyCard(Currency currency)
    {
        cout << "\n\t\t\t\t\t______________________________________\n";
        cout << "\t\t\t\t\t| Country: " << currency.getCountry() << endl;
        cout << "\t\t\t\t\t| Currency Code: " << currency.getCurrencyCode() << endl;
        cout << "\t\t\t\t\t| Currency Name: " << currency.getCurrencyName() << endl;
        cout << "\t\t\t\t\t| Currency Rate: " << currency.geturrencyRate() << endl;
        cout << "\t\t\t\t\t______________________________________\n\n";
	}
public:
   static void showUpdateCurrencyRateScreen()
    {
		drawScreenHeader("\tUpdate Currency Rate");

        string currencyCode = readCurrencyToUpdate();
        Currency currencyToUpdate=Currency::findCurrencyByCode(currencyCode);

        while (!Currency::isCurrencyExistUsingCode(currencyCode))
        {
            cout << "Currency with code '" << currencyCode << "' does not exist." << endl;
            currencyCode = readCurrencyToUpdate();
            currencyToUpdate = Currency::findCurrencyByCode(currencyCode);
        }
		cout << "Currency found!" << endl;
       printCurrencyCard(currencyToUpdate);
		cout << "are you sure you want to update the rate for this currency? (y/n): ";
        string confirm = InputValidate::readString();
        if (confirm == "n" || confirm == "N")
        {
            cout << "Update cancelled." << endl;
            return;
        }
		cout << "Updating rate for currency: " << currencyToUpdate.getCurrencyName() << endl;
        cout << "Enter New Rate: ";
	     double newRate = InputValidate::readDblNumber();
         currencyToUpdate.setCurrencyRte(newRate);
        cout << "Currency rate updated successfully!" << endl;
        cout << "New Rate: " << currencyToUpdate.geturrencyRate() << endl;	
    }

};

