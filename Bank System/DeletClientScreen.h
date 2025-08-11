#pragma once
#include <iostream>
#include "Screen.h"
#include "Person.h"
#include "BankClient.h"
#include "InputValidate.h"

class DeleteClientScreen :protected Screen
{

private:
    static void printClient(BankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.getFirstName();
        cout << "\nLastName    : " << Client.getLastName();
        cout << "\nEmail       : " << Client.getEmail();
        cout << "\nPhone       : " << Client.getPhoneNumber();
        cout << "\nAcc. Number : " << Client.getId();
        cout << "\nPassword    : " << Client.getPin();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteClientScreen()
    {
        if (!Screen::isAccessAllowed(User::enPermissions::pDeleteClient))
            return;
        drawScreenHeader("\tDelete Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = InputValidate::readString();
        while (!BankClient::isClietExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = InputValidate::readString();
        }

        BankClient Client1 = BankClient::find(AccountNumber);
        printClient(Client1);

        cout << "\nAre you sure you want to delete this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (Client1.deleteC())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                printClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }

};

