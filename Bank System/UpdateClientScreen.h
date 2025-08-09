#pragma once
#pragma once
#include "BankClient.h"
#include "InputValidate.h"
#include <iostream>
#include <iomanip>
#include "Screen.h"

class UpdateClientScreen :protected Screen
{
    static void readClientInfo(BankClient &client)
    {
        cout << "please enter the New Name of the client\n";
       client.setFirstName(InputValidate::readString());
        cout << "please enter the New lastName of the client\n";
       client.setLastName(InputValidate::readString());
        cout << "please enter the New email of the client\n";
       client.setEmail(InputValidate::readString());
        cout << "please enter the New phone of the client\n";
       client.setPhoneNumber(InputValidate::readString());
        cout << "please enter the New pin of the client\n";
       client.setPin(InputValidate::readString());
        cout << "please enter the New accountBalance of the client\n";
       client.setAccountBalance(InputValidate::readFloatNumber());
    }
public:
    static void updateClient()
    {
        drawScreenHeader("update Client Screen\n");
        string id = "";
        cout << "please enter the id of the client\n";
        id = InputValidate::readString();
        while (!BankClient::isClietExist(id))
        {
            cout << "please enter the id of the client\n";
            id = InputValidate::readString();
        }
        BankClient client = BankClient::find(id);
        client.print();
        cout << endl << "update client Info\n";
         readClientInfo(client);
        BankClient::enSave saveMode = client.save();
        if (saveMode == BankClient::enSave::savedSucssefully)
        {
            cout << "data was saved succeccfully:)\n";
            client.print();
        }
        else
        {
            cout << "data was not saved due to some problem\n";
        }
    }

};

