#pragma once
#include <iostream>
#include "Screen.h"
#include "Person.h"
#include "User.h"
#include "InputValidate.h"

using namespace std;

class UpdateUserScreen : protected Screen
{
private:
    static void readUserInfo(User& user)
    {
        cout << "\nEnter FirstName: ";
        user.setFirstName(InputValidate::readString());

        cout << "\nEnter LastName: ";
        user.setLastName(InputValidate::readString());

        cout << "\nEnter Email: ";
        user.setEmail(InputValidate::readString());

        cout << "\nEnter Phone: ";
        user.setPhoneNumber(InputValidate::readString());

        cout << "\nEnter Password: ";
        user.setPassword(InputValidate::readString());

        cout << "\nEnter Permission: ";
        user.setPermissions(readPermissionsToSet());
    }

    static void printUser(User user)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << user.getFirstName();
        cout << "\nLastName    : " << user.getLastName();
        cout << "\nEmail       : " << user.getEmail();
        cout << "\nPhone       : " << user.getPhoneNumber();
        cout << "\nUser Name   : " << user.getUserName();
        cout << "\nPassword    : " << user.getPassword();
        cout << "\nPermissions : " << user.getPermissions();
        cout << "\n___________________\n";
    }

    static int readPermissionsToSet()
    {
        int permissions = 0;
        char answer = 'n';

        cout << "\nDo you want to give full access? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += User::enPermissions::pListClients;

        cout << "\nAdd New Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += User::enPermissions::pAddNewClient;

        cout << "\nDelete Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += User::enPermissions::pDeleteClient;

        cout << "\nUpdate Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += User::enPermissions::pUpdateClients;

        cout << "\nFind Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += User::enPermissions::pFindClient;

        cout << "\nTransactions? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += User::enPermissions::pTranactions;

        cout << "\nManage Users? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
            permissions += User::enPermissions::pManageUsers;

        return permissions;
    }

public:
    static void showUpdateUserScreen()
    {
        drawScreenHeader("\tUpdate User Screen");

        string userName = "";

        cout << "\nPlease Enter User UserName: ";
        userName = InputValidate::readString();

        while (!User::isUserExist(userName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            userName = InputValidate::readString();
        }

        User user1 = User::find(userName);

        printUser(user1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char answer = 'n';
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";

            readUserInfo(user1);

            User::enSaveResults saveResult = user1.save();

            switch (saveResult)
            {
            case User::enSaveResults::svSucceeded:
                cout << "\nUser Updated Successfully :-)\n";
                printUser(user1);
                break;

            case User::enSaveResults::svFailedEmptyObject:
                cout << "\nError User was not saved because it's Empty";
                break;
            }
        }
    }
};
