#include "BankClient.h"
#include "InputValidate.h"
#include <iostream>
#include <iomanip>
#include "MainScreen.h"
#include "ClientListScreen.h"
#include "AddNewClientScreen.h"
using namespace std;


void PrintClientBalance(BankClient Client)
{

    cout << "| " << setw(15) << left << Client.getId();
    cout << "| " << setw(20) << left << Client.getFirstName();
    cout << "| " << setw(20) << left << Client.getLastName();
    cout << "| " << setw(12) << left << Client.getPhoneNumber();
    cout << "| " << setw(12) << left << Client.getAccountBalance();
    cout << "_____________________________________________n";
    cout << "clients total balance:  " << setw(20) << left << BankClient::getTotalBalnceOfallClients();
}
void ShowClientsBalnces()
{
    vector <BankClient> vClients = BankClient::getClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "ID";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (BankClient Client : vClients)
        {

            /*PrintClientBalance(Client);*/
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

int main()
{
   
    AddNewClientScreen::addNewClient();
}
