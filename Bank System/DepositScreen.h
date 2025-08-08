#pragma once

#include <iostream>
#include "Screen.h"
#include "BankClient.h"
#include "InputValidate.h"

class depositScreen : protected Screen
{

private:

    static void printClient(BankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.getFirstName();
        cout << "\nLastName    : " << Client.getLastName();
      ;
        cout << "\nEmail       : " << Client.getEmail();
        cout << "\nPhone       : " << Client.getPhoneNumber();
        cout << "\nAcc. Number : " << Client.getId();
        cout << "\nPassword    : " << Client.getPin();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";

    }

    static string readAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void showDepositScreen()
    {
        drawScreenHeader("\t   Deposit Screen");

        string AccountNumber = readAccountNumber();


        while (!BankClient::isClietExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = readAccountNumber();
        }

        BankClient Client1 = BankClient::find(AccountNumber);
        printClient(Client1);

        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = InputValidate::readDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.getAccountBalance();

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};

