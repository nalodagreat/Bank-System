#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "Screen.h"
#include "User.h"

using namespace std;

class ListUsersScreen : protected Screen
{
private:
    static void printUserRecordLine(User user)
    {
        cout << setw(8)  << left << "" << "| "
             << setw(12) << left << user.getUserName()
             << "| " << setw(12) << left << user.getFirstName()
             << "| " << setw(12) << left << user.getLastName()
             << "| " << setw(12) << left << user.getPhoneNumber()
             << "| " << setw(20) << left << user.getEmail()
             << "| " << setw(10) << left << user.getPassword()
             << "| " << setw(12) << left << user.getPermissions()
             << endl;
    }

public:
    static void showUsersList()
    {
        if (!Screen::isAccessAllowed(User::enPermissions::pListClients))
            return;

        vector<User> users = User::getUsersList();

        string title = "\t  User List Screen";
        string subTitle = "\t    (" + to_string(users.size()) + ") User(s).";

        drawScreenHeader(title, subTitle);

        cout << setw(8)  << left << "" << "\n\t";
        cout << "___________________________________________________________________________________________________________\n" << endl;

        cout << setw(8)  << left << "" << "| "
             << setw(12) << left << "UserName"
             << "| " << setw(12) << left << "First Name"
             << "| " << setw(12) << left << "Last Name"
             << "| " << setw(12) << left << "Phone"
             << "| " << setw(20) << left << "Email"
             << "| " << setw(10) << left << "Password"
             << "| " << setw(12) << left << "Permissions"
             << endl;

        cout << setw(8)  << left << "" << "\n\t";
        cout << "___________________________________________________________________________________________________________\n" << endl;

        if (users.empty())
            cout << "\t\t\t\tNo Users Available In the System!";
        else
            for (User& user : users)
            {
                printUserRecordLine(user);
            }

        cout << setw(8)  << left << "" << "\n\t";
        cout << "___________________________________________________________________________________________________________\n" << endl;
    }
};
