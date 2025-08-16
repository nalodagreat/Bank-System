#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "BankClient.h"
#include "Screen.h"

using namespace std;

class ClientListScreen : protected Screen
{
private:
    static void PrintClientRecordLine(BankClient Client)
    {
        cout << "| " << setw(15) << left << Client.getId()
            << "| " << setw(20) << left << Client.getFirstName()
            << "| " << setw(20) << left << Client.getLastName()
            << "| " << setw(12) << left << Client.getPhoneNumber()
            << "| " << setw(25) << left << Client.getEmail()
            << "| " << setw(10) << left << Client.getPin()
            << "| " << setw(12) << left << fixed << setprecision(2) << Client.getAccountBalance()
            << " |" << endl;
    }

    static void PrintDivider()
    {
        cout << string(126, '_') << endl;  
    }

public:
    static void ShowClientsList()
    {
        vector<BankClient> vClients = BankClient::getClientsList();
        string title = "Show Client Screen", subTitle = to_string(vClients.size());
        drawScreenHeader(title, subTitle);

        cout << "\n\t\t\tClient List (" << vClients.size() << ") Client(s).\n" << endl;

        PrintDivider();
        cout << "| " << setw(15) << left << "ID"
            << "| " << setw(20) << left << "First Name"
            << "| " << setw(20) << left << "Last Name"
            << "| " << setw(12) << left << "Phone"
            << "| " << setw(25) << left << "Email"
            << "| " << setw(10) << left << "Pin Code"
            << "| " << setw(12) << left << "Balance"
            << " |" << endl;
        PrintDivider();

        if (vClients.size() == 0)
            cout << "\t\t\tNo Clients Available in the System!" << endl;
        else
            for (const BankClient& Client : vClients)
                PrintClientRecordLine(Client);

        PrintDivider();
    }
};
