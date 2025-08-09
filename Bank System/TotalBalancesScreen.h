#pragma once
#include <iostream>
#include "Screen.h"
#include "BankClient.h"
#include <iomanip>


class TotalBalancesScreen : protected Screen
{

private:

    static void PrintClientRecordBalanceLine(BankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.getId();
        cout << "| " << setw(40) << left << Client.getFirstName();
        cout << "| " << setw(12) << left << Client.getAccountBalance();
    }

public:

    static void ShowTotalBalances()
    {

        vector <BankClient> vClients = BankClient::getClientsList();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        drawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        double TotalBalances = BankClient::getClientsBalnces();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (BankClient Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
    }

};

