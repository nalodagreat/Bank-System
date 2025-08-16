#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "clsString.h"
using namespace std;
class Currency
{
public:enum enMode
	{
		emptyCurrency = 1, updatedCurrency = 2
	};
private:
	enMode mode;
	string country;
	string currencyCode;
	string currencyName;
	float curencyRate;
	bool MarkForRateUpdate = false;
	static Currency getEmptyCurrencyObj()
	{
		return Currency(enMode::emptyCurrency, "", "", "", 0);
	}
	static Currency convertRecordToObj(string line)
	{
		vector <string> curencyInfo=clsString::Split(line, "#//#");
		return Currency(updatedCurrency, curencyInfo[0], curencyInfo[1], curencyInfo[2], stof(curencyInfo[3]));
	}
	static string convertObjTostring(Currency currency, string separator = "#//#")
	{
		string line = "";
		line += currency.country + separator;
		line += currency.currencyCode + separator;
		line += currency.currencyName + separator;
		line += to_string(currency.curencyRate) + separator;
	}
	void addCurrenciesToFile(vector<Currency> vCurrencies)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			for (Currency c : vCurrencies)
			{
				string line = convertObjTostring(c);
				MyFile << line << endl;
			}
			MyFile.close();
		}
	}
	void addDataLineToFile(string  dataLine)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << dataLine << endl;

			MyFile.close();
		}

	}
public:
	//constractor
	static vector<Currency> loadDataFromFile()
	{
		vector <Currency> vCurrencies;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				Currency currenccy = convertRecordToObj(line);
				vCurrencies.push_back(currenccy);
			}
			MyFile.close();
			return  vCurrencies;
		}
	}
	Currency(enMode mode,string country,string currencyCode,string currencyName,float curencyRate)
	{
		this->mode = mode;
		this->country = country;
		this->currencyCode=currencyCode;
		this->currencyName = currencyName;
		this->curencyRate = curencyRate;
	}
	//read only proprities
	string getCountry()
	{
		return country;
	}
	string getCurrencyCode()
	{
		return currencyCode;
	}
	string getCurrencyName()
	{
		return currencyName;
	}
	float geturrencyRate()
	{
		return curencyRate;
	}
	enMode getMode()
	{
		return mode;
	}
	//set currency rate
	void setCurrencyRte(float newCurrencyRate)
	{
		this->curencyRate = newCurrencyRate;
		updateRateCurrencyInfile();
	}
	static Currency findCurrencyByCode(string currencyCode)
	{
		currencyCode = clsString::UpperAllString(currencyCode);
		//get all curencies from file
		vector<Currency> vCurrencies=loadDataFromFile();
		for (Currency c : vCurrencies)
		{
			if (currencyCode == c.currencyCode)
			{
				return Currency(updatedCurrency, c.country, c.currencyCode, c.currencyName, c.curencyRate); //objCurrency
			}
		}
		return getEmptyCurrencyObj();
	}
	static Currency findCurrencyByCountry(string country)
	{
		country = clsString::UpperAllString(country);
		//get all curencies from file
		vector<Currency> vCurrencies = loadDataFromFile();
		for (Currency c : vCurrencies)
		{
			if (country == clsString::UpperAllString(c.country))
			{
				//return c;
				return Currency(updatedCurrency, c.country, c.currencyCode, c.currencyName, c.curencyRate); //objCurrency
			}
		}
		return getEmptyCurrencyObj();
	}
	static vector<Currency> getAllCurrenciesToDisplay()
	{
		return loadDataFromFile();
	}
	void updateRateCurrencyInfile()
	{
		vector<Currency> vCurrencies = loadDataFromFile();
		for (Currency &c : vCurrencies)
		{
			if (c.currencyCode == this->currencyCode)
			{
				c = *this;
				break;
			}
		}
		addCurrenciesToFile(vCurrencies);
	}
	double calculateExchangeCurrency(Currency currencyFrom, Currency currencyTo, double amount)
	{
		double amountInBase = amount * currencyFrom.curencyRate;
		double amountInTarget = amountInBase / currencyTo.curencyRate;
		return amountInTarget;
	}
	static bool isCurrencyExistUsingCode(string currencyCode)
	{
		Currency c=findCurrencyByCode(currencyCode);
		return (c.mode != emptyCurrency);
	}
	static bool isCurrencyExistUsingCountry(string currencyCountry)
	{
		Currency c=findCurrencyByCountry(currencyCountry);
		return (c.mode != emptyCurrency);
	}
};

