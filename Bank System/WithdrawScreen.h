#pragma once
#include "BankClient.h"
#include "Screen.h"
#include "InputValidate.h"
class WithdrawScreen :protected Screen
{
	static int  readTheAmountToWithDraw()
	{
		cout << "please enter the amount To Withdraw\n";
		return InputValidate::readIntNumber();
	}
	static void displayResult(bool isWithdrawOPSuccefuly, int amount,double accountBalance)
	{
		if (isWithdrawOPSuccefuly)
		{
			cout << "witdraw procced scuccefully ur new balance is : " << accountBalance;
		}
		else 
		{
			cout << "could not withdraw ur accoutbalance " << accountBalance << "is less then : " << amount << endl;
		}
	}
	static bool isClientConfirmWithDraw()
	{
		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			return true;

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
			return false;
		}
	}
public:
	static void showTheWithDrawScreen()
	{
		drawScreenHeader("WithDrw Screen\n");

		cout << "please enter the id of the client\n";
		string id=InputValidate::readString();
		while (!BankClient::isClietExist(id))
		{
			cout << "please enter the id of an existing client\n";
			string id = InputValidate::readString();
		}
		BankClient client = BankClient::find(id);
		int amount=readTheAmountToWithDraw();
		if(isClientConfirmWithDraw())
		{
			bool isWithdrawOPSucceeded = client.withDraw(amount);
			displayResult(isWithdrawOPSucceeded, amount, client.getAccountBalance());
		}
	}

};

