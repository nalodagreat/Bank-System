#pragma once
#include <iostream>
#include "Screen.h"
#include "Currency.h"
#include "InputValidate.h"
using namespace std;
class ExchangeCurrencyCalculatorScreen : protected Screen
{
private:
	Currency readCurrency(string message)
	{
			
		cout << message;
		string currencyCode = InputValidate::readString();
		Currency currency = Currency::findCurrencyByCode(currencyCode);
		while (currency.getMode() == Currency::emptyCurrency)
		{
			cout << "Currency not found. Please enter a valid currency code: ";
			currencyCode = InputValidate::readString();
			currency = Currency::findCurrencyByCode(currencyCode);
		}
		return currency;
	}
	static double readAmountToExchange()
	{
		cout << "Enter the amount you want to exchange: ";		
		return InputValidate::readDblNumber();
	}
	static void printCurrencyExChangeInfo( Currency currency1,Currency currency2,double amountToExchange)
	{
		double exchangeValue = currency1.calculateExchangeCurrency(currency1, currency2, amountToExchange);
		cout<< "Currency Exchange Details:" << endl;
		cout << "-----------------" << endl;
		cout << "From Currency: " << currency1.getCurrencyCode() << " (" << currency1.getCurrencyName() << ")" << endl;
		cout << "To Currency: " << currency2.getCurrencyCode() << " (" << currency2.getCurrencyName() << ")" << endl;
		cout << "Exchange Rate: " << fixed << setprecision(4) <<exchangeValue << " " << currency2.getCurrencyCode() << " per 1 " << currency1.getCurrencyCode() << endl;
		
	}
public:
	void showExchangeCurrencyCalculatorScreen()
	{
		drawScreenHeader("Exchange Currency Calculator", "Calculate the exchange rate between two currencies");
		Currency currency1 = readCurrency("please enter the currency u want to exchange: ");
		Currency currency2 = readCurrency("please enter the currency u want to exchange to: ");
		double amountToExchange = readAmountToExchange();
		printCurrencyExChangeInfo(currency1, currency2, amountToExchange);
	}
};

