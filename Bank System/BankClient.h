#pragma once
#include "Person.h"
#include "clsString.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class BankClient : public Person
{
	enum enMode
	{
		emptyMode=1,upadteMode=2
	};
	enMode mode;
	string id;
	string pin;
	float accountBalance;
public:
	BankClient(enMode mode, string firstName, string lastName, string email, string phoneNumber, string id, string pin, float accountBalance)
		:Person(firstName, lastName, email, phoneNumber)
	{
		this->mode= mode;
		this->id= id;
		this->pin = pin;
		this->accountBalance = accountBalance;
	}
	void setMode(enMode mode)
	{
		this->mode = mode;
	}
	enMode getMode()
	{
		return mode;
	}
	string getId()
	{
		return id;
	}
	void setPin(string pin)
	{
		this->pin = pin;
	}
	string getPin()
	{
		return pin;
	}
	void setAccountBalance(float accountBalance)
	{
		this->accountBalance = accountBalance;
	}
	float getAccountBalance()
	{
		return accountBalance;
	}
	void print()
	{
		cout << "First Name: " << getFirstName() << endl;
		cout << "Last Name: " << getLastName() << endl;
		cout << "Email: " << getEmail() << endl;
		cout << "Phone Number: " << getPhoneNumber() << endl;
		cout << "ID: " << id << endl;
		cout << "Pin: " << pin << endl;
		cout << "Account Balance: " << accountBalance << endl;
	}
	bool isEmpty()
	{
		return(mode == emptyMode);
	}
private:
	static BankClient convertRecordToObj(string line,string delim="#//#")
	{
		vector <string> vRecordInfo;
		vRecordInfo = clsString::Split(line, delim);
		return BankClient(upadteMode, vRecordInfo[0], vRecordInfo[1], vRecordInfo[2], vRecordInfo[3], vRecordInfo[4], vRecordInfo[5],stof(vRecordInfo[6]));

	}
	static BankClient getemptyObj()
	{
		return BankClient(emptyMode, "", "", "", "", "", "", 0);
	}
public:
	static BankClient find(string id)
	{
		vector <BankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				BankClient client = convertRecordToObj(line);
				if (client.id == id)
				{
					MyFile.close();
					return client;
				}
				vClients.push_back(client);
			}
			MyFile.close();
		}
		return getemptyObj();
	}
	static BankClient find(string id,string pin)
	{
		vector <BankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				BankClient client = convertRecordToObj(line);
				if (client.id == id && client.pin==pin)
				{
					MyFile.close();
					return client;
				}
				vClients.push_back(client);
			}
			MyFile.close();
		}
		return getemptyObj();
	}
	static bool isClietExist(string id)
	{
		BankClient client = find(id);
		return !(client.isEmpty());
	}
};

