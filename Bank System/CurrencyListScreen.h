#pragma once
#include "Screen.h"
#include "Currency.h"
class CurrencyListScreen :protected Screen
{
	static void dispplayCurrency(Currency currency)
	{
		cout << "| " << setw(25) << left << currency.getCountry();
		cout << "| " << setw(15) << left << currency.getCurrencyCode();
		cout << "| " << setw(20) << left << currency.getCurrencyName();
		cout << "| " << setw(15) << left << currency.geturrencyRate();
	}
public:
	static void showCurrencyList()
	{
		vector<Currency> vCurrencies = Currency::getAllCurrenciesToDisplay();
		drawScreenHeader("CurrencyListScreen", to_string(vCurrencies.size()));

		cout << "\n\t\t\t\t\tClient List (" << vCurrencies.size() << ") Currency(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(25) << "Country";
		cout << "| " << left << setw(15) << "C.Code";
		cout << "| " << left << setw(20) << "C.Name";
		cout << "| " << left << setw(15) << "Value$";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (Currency C : vCurrencies)
			{

				dispplayCurrency(C);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};

