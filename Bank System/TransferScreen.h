#pragma once
#include "Screen.h"
#include "InputValidate.h"

#include "BankClient.h"
class TransferScreen :protected Screen
{
	static bool ConfirmTransfer(string message)
	{

		cout << message << endl;
		string adminConfirmation = InputValidate::readString();
		if (adminConfirmation == "y" || adminConfirmation == "Y")
		{
			return true;
		}
		return false;
	}
	static bool isAmountToTransferExeedTheAccountBalance(string idClientToTransferFrom, double amountToTransfer)
	{
		BankClient clientToTransferFrom = BankClient::find(idClientToTransferFrom);
		return (clientToTransferFrom.getAccountBalance() < amountToTransfer);
	}
	static void _Transfer()
	{
		//from
		bool isClientToTransferFromFounded = false; string idClientToTransferFrom; double amountToTransfer = 0;
			cout << "plese enter the id of the user that yo want to transfer from\n";
			idClientToTransferFrom = InputValidate::readString();
			BankClient clientToTransferFrom = BankClient::find(idClientToTransferFrom);
			while(!clientToTransferFrom.isClietExist(idClientToTransferFrom))
			{
				cout << "client id with: " << idClientToTransferFrom << " " << "does not exist\n";
				cout << "plese enter the id of the user that yo want to transfer from\n";
				idClientToTransferFrom = InputValidate::readString();
			}

		/////to

		bool isClientToTransferToFounded = false; string idClientToTransferTo;
		
			cout << "plese enter the id of the user that yo want to transfer To\n";
			idClientToTransferTo = InputValidate::readString();
			BankClient clientToTransferTo = BankClient::find(idClientToTransferTo);
			while (!clientToTransferTo.isClietExist(idClientToTransferTo))
			{
				cout << "client id with: " << idClientToTransferTo << " " << "does not exist\n";
				cout << "plese enter the id of the user that yo want to transfer To\n";
				idClientToTransferTo = InputValidate::readString();
			}
		
		bool isAccoutBalanceIsNotEnough;
		do
		{
			
			cout << "\nplese inser amount you desire to transfer from " << idClientToTransferFrom << "to " << idClientToTransferTo << endl;
			amountToTransfer = InputValidate::readDblNumber();
		    isAccoutBalanceIsNotEnough = isAmountToTransferExeedTheAccountBalance(idClientToTransferFrom, amountToTransfer);
			if (isAccoutBalanceIsNotEnough)
			{
				cout << "Amount balnce of the client " << idClientToTransferFrom << " is not enough to transfer " << amountToTransfer << endl;
			}
		} while (isAccoutBalanceIsNotEnough);
		if (ConfirmTransfer("are you sure you want to continue this operation[y/n]:"))
		{
			if(clientToTransferFrom.transfer(clientToTransferTo, amountToTransfer))
			{
				cout << "transfer  proceded successfully\n";
				printDetails(clientToTransferFrom, clientToTransferTo);
				//when arrive here transferhistory will start 
				clientToTransferFrom.transferFileDetails(clientToTransferTo, amountToTransfer);
			}
		}
		else
		{
			cout << "transfer did not proceded\n";
		}
	}
	static void printDetails(BankClient client1, BankClient client2)
	{
		cout << "--------------------------------------------\n\n\n";
		cout << "\t\t\t\t" << client1.getFirstName() << endl;
		cout << "\t\t\t\t" << client1.getLastName() << endl;
		cout << "\t\t\t\t" << client1.getAccountBalance() << endl;
		cout << "--------------------------------------------\n\n\n";
		cout << "--------------------------------------------\n\n\n";
		cout << "\t\t\t\t" << client2.getFirstName() << endl;
		cout << "\t\t\t\t" << client2.getLastName() << endl;
		cout << "\t\t\t\t" << client2.getAccountBalance() << endl;
		cout << "--------------------------------------------\n\n\n";
	}
	
public:
	static void showTransferScreen()
	{
		drawScreenHeader("\tTransfer screen\n");
		_Transfer();

	}
};

