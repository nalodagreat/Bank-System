#pragma once
#include <iostream>
#include "Screen.h"
#include "Person.h"
#include "User.h"
#include "InputValidate.h"

using namespace std;

class FindUserScreen : protected Screen
{
private:
    static void printUser(User user)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << user.getFirstName();
        cout << "\nLastName    : " << user.getLastName();
        cout << "\nEmail       : " << user.getEmail();
        cout << "\nPhone       : " << user.getPhoneNumber();
        cout << "\nUserName    : " << user.getUserName();
        cout << "\nPassword    : " << user.getPassword();
        cout << "\nPermissions : " << user.getPermissions();
        cout << "\n___________________\n";
    }

public:
    static void showFindUserScreen()
    {
        drawScreenHeader("\t  Find User Screen");

        string userName;
        cout << "\nPlease Enter UserName: ";
        userName = InputValidate::readString();

        while (!User::isUserExist(userName))
        {
            cout << "\nUser is not found, choose another one: ";
            userName = InputValidate::readString();
        }

        User user1 = User::find(userName);

        if (!user1.isEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        printUser(user1);
    }
};
