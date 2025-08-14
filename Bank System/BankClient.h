#pragma once
#include "Person.h"
#include "clsString.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "InputValidate.h"
#include "Util.h"
#include "Date.h"
#include "Global.h"
using namespace std;
class BankClient : public Person
{
	enum enMode
	{
		emptyMode=1,upadteMode=2,addNew=3
	};
	enMode mode;
	string id;
	string pin;
	float accountBalance;
	bool markForDelet = false;
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
		return BankClient(upadteMode, vRecordInfo[0], vRecordInfo[1], vRecordInfo[2], vRecordInfo[3], vRecordInfo[4], Util::decryptText(vRecordInfo[5],2),stof(vRecordInfo[6]));

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
	enum enSave
	{
		savedSucssefully=1,failedTosave=2
	};
private:
	static vector <BankClient> loadDataFromFile()
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
				vClients.push_back(client);
			}
			MyFile.close();
			return  vClients;
		}
	}
	static string convertClientObjToLine(BankClient clientObj,string separator="#//#")
	{
		string dataLine = "";
		dataLine += clientObj.getFirstName()+separator;
		dataLine += clientObj.getLastName()+separator;
		dataLine += clientObj.getEmail()+separator;
		dataLine += clientObj.getPhoneNumber() + separator;
		dataLine += clientObj.getId() + separator;
		dataLine += Util::encryptText(clientObj.getPin(),2) + separator;
		dataLine += to_string(clientObj.getAccountBalance());
		return dataLine;
	}
	void addDataLineToFile(string  dataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << dataLine << endl;

			MyFile.close();
		}

	}

	static void saveClientsDataToFile(vector <BankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite Mode

		if (MyFile.is_open())
		{
			string dataLine;
			for (BankClient c : vClients)
			{
				dataLine = convertClientObjToLine(c);
				MyFile << dataLine<<endl;
			}
			MyFile.close();
		}
	}
public:
	void update()
	{
		vector <BankClient> vClients = loadDataFromFile();
		for (BankClient &c : vClients)
		{
			if (c.id == id)
			{
				c = *this;
				break;
			}
		}
		saveClientsDataToFile(vClients);
	}
public:
	enSave save()
	{
		if (mode == enMode::emptyMode)
		{
			return failedTosave;
		}
		else if(mode == enMode::upadteMode)
		{
			update();
			return savedSucssefully;
		}
		else if (mode == enMode::addNew)
		{
			if(BankClient::isClietExist(id))
				return failedTosave;
			else
			{
				add();
				mode = upadteMode;
				return savedSucssefully;
			}
		}
	}
	static BankClient getNewClientAddMode(string id)
	{
		return BankClient(addNew, "", "", "", "", id, "", 0);
	}
	void add()
	{
		addDataLineToFile(convertClientObjToLine(*this));
	}
	static bool deleteClientFromTheList(BankClient &clientToDelete)
	{
		//loadadtafromfile
		vector<BankClient> vClients = loadDataFromFile();
		for (BankClient &c : vClients)
		{
			if (c.id == clientToDelete.id)
			{
				c.markForDelet = true;
			}
			else
			vClients.push_back(c);
		}
		//print vector that only not need to be delete markfordelet
		saveClientsDataToFile(vClients);
		//clear the deleted client
		clientToDelete = getemptyObj();
		return true;
	}
	bool deleteC()
	{
		return (deleteClientFromTheList(*this));
		
	}
	static vector<BankClient> getClientsList()
	{
		return loadDataFromFile();
	}
	static double getTotalBalnceOfallClients()
	{
		double totalBalnceOfallClients = 0;
		vector <BankClient> vClients = loadDataFromFile();
		for (BankClient c : vClients)
		{
			totalBalnceOfallClients += c.accountBalance;
		}
		return  totalBalnceOfallClients;

	}
	
	 void deposit(double balanceToDeposit)
	{
		
		accountBalance += balanceToDeposit;
		save();
	}
	 bool withDraw(int amount)
	 {
		 if(amount < accountBalance)
		 {
			 accountBalance -= amount;
			 save();
			 return true;
		 }
		 return false;
	}
	 
	 
	 static double  getClientsBalnces()
	 {
		 vector <BankClient> vClients = BankClient::getClientsList();
		 double totalBalances = 0;
		 for(BankClient c : vClients)
		 {
			 totalBalances+= c.accountBalance;
		 }
		 return totalBalances;

	 }
	 bool transfer(BankClient &clinetToTransferTo, double amountToTtransfer)
	 {
		 if(accountBalance> amountToTtransfer)
		 {
			 this->withDraw(amountToTtransfer);
			 clinetToTransferTo.deposit(amountToTtransfer);
			 return true;
		 }
		 return false;
	 }
	 private:
		 void writeLogHistoryOnfile(string dataLine)
		 {
			 fstream myFile;
			 myFile.open("TransferHistory.txt", ios::out | ios::app);
			 if (myFile.is_open())
			 {
				 myFile << dataLine << endl;
				 myFile.close();
			 }
		 }
	 public:
	   void transferFileDetails(BankClient clientTo,double amount)
	 {
		 string dateAndTime = Date::convertDateOfLoginstructToString(Date::getSystemDate()) + " - " + Date::getSystemTime();
		 string idClientFrom = this->getId();
		 string idClienTo = clientTo.getId();
		 double amountToTransfer = amount;
		 double newBalanceClientFrom = this->getAccountBalance();
		 double newBalanceAmountTo = clientTo.getAccountBalance();
		 string userNmae = CurrentUser.getUserName();
		 writeLogHistoryOnfile(dateAndTime + "#//#" + idClientFrom + "#//#" + idClienTo + "#//#" + to_string(amountToTransfer) + "#//#" + to_string(newBalanceClientFrom) + "#//#" + to_string(newBalanceAmountTo) + "#//#" + userNmae);
	 }
	   struct stTransferInfo
	   {
		   string dateAndTime;
		   string idClientFrom;
		   string IdClientTo;
		   double amountTransfered;
		   double BalanceOfClientTranferdFrom;
		   double BalanceOfClientTranferdTo;
		   string usernameOfAdminWhoMadeOp;
	   };
	   vector <stTransferInfo> static getTransferList()
	   {
		   vector<stTransferInfo> vTransfers;
		   fstream myFile;
		   myFile.open("TransferHistory.txt", ios::in);
		   if (myFile.is_open())
		   {
			   string line;
			   while (getline(myFile, line))
			   {
				   vector<string> vData = clsString::Split(line, "#//#");
				   stTransferInfo transfer;
				   transfer.dateAndTime= vData[0];
				   transfer.idClientFrom = vData[1];
				   transfer.IdClientTo = vData[2];
				   transfer.amountTransfered = stod(vData[3]);
				   transfer.BalanceOfClientTranferdFrom = stod(vData[4]);
				   transfer.BalanceOfClientTranferdTo = stod(vData[5]);
				   transfer.usernameOfAdminWhoMadeOp = vData[6];
				   vTransfers.push_back(transfer);
			   }
			   myFile.close();
		   }
		   return vTransfers;
	   }

};

