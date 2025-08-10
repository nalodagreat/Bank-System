#pragma once
#include <iostream>
#include "Screen.h"
#include "Person.h"
#include "User.h"
#include "InputValidate.h"

using namespace std;

class DeleteUsersScreen : protected Screen
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
        cout << "\nUser Name   : " << user.getUserName();
        cout << "\nPassword    : " << user.getPassword();
        cout << "\nPermissions : " << user.getPermissions();
        cout << "\n___________________\n";
    }

public:
    static void showDeleteUserScreen()
    {
        drawScreenHeader("\tDelete User Screen");

        string userName = "";

        cout << "\nPlease Enter UserName: ";
        userName = InputValidate::readString();

        while (!User::isUserExist(userName))
        {
            cout << "\nUser is not found, choose another one: ";
            userName = InputValidate::readString();
        }

        User user1 = User::find(userName);
        printUser(user1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char answer = 'n';
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            if (user1.remove())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                printUser(user1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }
};
