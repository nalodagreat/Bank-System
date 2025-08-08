#pragma once
#include "BankClient.h"
#include "ClientListScreen.h"
using namespace std;
class AddNewClientScreen : protected Screen
{
    static void readClientInfo(BankClient& clientContainsNewInfo)
    {

        cout << "please enter the New Name of the client\n";
        clientContainsNewInfo.setFirstName(InputValidate::readString());
        cout << "please enter the New lastName of the client\n";
        clientContainsNewInfo.setLastName(InputValidate::readString());
        cout << "please enter the New email of the client\n";
        clientContainsNewInfo.setEmail(InputValidate::readString());
        cout << "please enter the New phone of the client\n";
        clientContainsNewInfo.setPhoneNumber(InputValidate::readString());
        cout << "please enter the New pin of the client\n";
        clientContainsNewInfo.setPin(InputValidate::readString());
        cout << "please enter the New accountBalance of the client\n";
        clientContainsNewInfo.setAccountBalance(InputValidate::readFloatNumber());
    }
public:
    static void addNewClient()
    {
        drawScreenHeader("add new client Screen");
        string id;
        cout << "plese enter the id of the new client: \n";
        id = InputValidate::readString();

        while (BankClient::isClietExist(id))
        {
            cout << "client with this id already exist,please enter the id of the new client: \n";
            id = InputValidate::readString();
        }
        BankClient newClient = BankClient::getNewClientAddMode(id);
        readClientInfo(newClient);
        BankClient::enSave saveMode = newClient.save();
    }
};

