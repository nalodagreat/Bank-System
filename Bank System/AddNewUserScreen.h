#pragma once

#include <iostream>
#include <iomanip>
#include "Screen.h"
#include "User.h"
#include "InputValidate.h"

using namespace std;


class AddNewUserScreen : protected Screen
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
            return -1;

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

    static void showAddNewUserScreen()
    {
        drawScreenHeader("\t  Add New User Screen");

        string userName = "";

        cout << "\nPlease Enter UserName: ";
        userName = InputValidate::readString();

        while (User::isUserExist(userName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            userName = InputValidate::readString();
        }

        User newUser = User::getAddNewUserObject(userName);

        readUserInfo(newUser);

        User::enSaveResults saveResult = newUser.save();

        switch (saveResult)
        {
        case User::enSaveResults::svSucceeded:
            cout << "\nUser Added Successfully :-)\n";
            printUser(newUser);
            break;

        case User::enSaveResults::svFailedEmptyObject:
            cout << "\nError: User was not saved because it's Empty";
            break;

        case User::enSaveResults::svFailedUserExists:
            cout << "\nError: User was not saved because UserName is used!\n";
            break;
        }
    }
};
