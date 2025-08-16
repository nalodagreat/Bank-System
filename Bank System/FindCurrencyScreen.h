#pragma once
#include "Screen.h"
#include "Currency.h"
#include "InputValidate.h"
class FindCurrencyScreen :protected Screen
{
	static void printCurrencyCard(Currency currencyToFind)
	{
		cout << "-------------------------------------\n";
		cout << "Country: " << currencyToFind.getCountry()<<endl;
		cout << "CurrencyCode: " << currencyToFind.getCurrencyCode() << endl;
		cout << "CurrencyName: " << currencyToFind.getCurrencyName() << endl;
		cout << "CurrencyValue(1$): " << currencyToFind.geturrencyRate() << endl;

		cout << "-------------------------------------\n";

	}
	static short readFindCurrencyMode()
	{
		cout << "\n\n\t\t\tenter[1] to find currency by Country/enter[2] to find currency by Code:";
		return InputValidate::readShortNumberBetween(1, 2);
	}
	static string readInput(string message)
	{
		cout << "\t\t\t" << message ;
		return InputValidate::readString();
	}

public:
	static void showFindCurrencyScreen()
	{
	 Currency currencyToFind(Currency::enMode::emptyCurrency, "", "", "", 0);
		drawScreenHeader("\tFind Currency Screen");
		short currencyFindMode = readFindCurrencyMode();
		do
		{

			if (currencyFindMode == 1)
			{
				string country = readInput("enter the CurrencyCountry:");
				currencyToFind = Currency::findCurrencyByCountry(country);
				/*currencyFound = Currency::isCurrencyExistUsingCountry(country);*/
				if (currencyToFind.getMode() == Currency::enMode::emptyCurrency)
				{
					cout << "\nCurrency not found :(\n";
				}
			}
			else if (currencyFindMode == 2)
			{
				string code = readInput("enter the CurrencyCode:");
				currencyToFind = Currency::findCurrencyByCode(code);
				/*currencyFound = Currency::isCurrencyExistUsingCode(code);*/
				if (currencyToFind.getMode() == Currency::enMode::emptyCurrency)
				{
					cout << "\nCurrency not found :(\n";
				}
			}
		} while (currencyToFind.getMode() == Currency::enMode::emptyCurrency);

		cout << "CurrencyFound :)\n\n";
		printCurrencyCard(currencyToFind);

	}
};