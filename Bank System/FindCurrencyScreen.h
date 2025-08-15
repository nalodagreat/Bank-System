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
		bool currencyFound = true; Currency currencyToFind(Currency::enMode::emptyCurrency, "", "", "", 0);
		drawScreenHeader("\tFind Currency Screen");
		do
		{

			if (readFindCurrencyMode() == 1)
			{
				string country = readInput("enter the CurrencyCountry:");
				currencyToFind = Currency::findCurrencyByCountry(country);
				currencyFound = Currency::isCurrencyExistUsingCountry(country);
				if (!currencyFound)
					cout << "Currency not found :(\n";
			}
			else if (readFindCurrencyMode() == 2)
			{
				string code = readInput("enter the CurrencyCode:");
				currencyToFind = Currency::findCurrencyByCode(readInput(code));
				currencyFound = Currency::isCurrencyExistUsingCode(readInput(code));
				if (!currencyFound)
					cout << "Currency not found :(\n";
			}
		} while (!currencyFound);
		if (currencyFound)
		{
			cout << "CurrencyFound :)\n\n";
			printCurrencyCard(currencyToFind);
		}
	}
};