#pragma once
#include<string>
#include <iostream>
#include "BankClient.h"
#include "Screen.h"
class ClientListScreen : protected Screen
{
private:
	static void PrintClientRecordLine(BankClient Client)
	{



		cout << "| " << setw(15) << left << Client.getId();
		cout << "| " << setw(20) << left << Client.getFirstName();
		cout << "| " << setw(20) << left << Client.getLastName();
		cout << "| " << setw(12) << left << Client.getPhoneNumber();
		cout << "| " << setw(20) << left << Client.getEmail();
		cout << "| " << setw(10) << left << Client.getPin();
		cout << "| " << setw(12) << left << Client.getAccountBalance();
	}
public:
	static void ShowClientsList()
	{

		vector <BankClient> vClients = BankClient::getClientsList();
		string title = "show client screen", subTitle = to_string(vClients.size());
		drawScreenHeader(title, subTitle);

		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "ID";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(20) << "Client SureName";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (BankClient Client : vClients)
			{

				PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
	
};

