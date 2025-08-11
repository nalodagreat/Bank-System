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
        cout << setw(8) << left << "" << "| " << setw(12) << left << user.getUserName();
        cout << "| " << setw(12) << left << user.getPhoneNumber();
        cout << "| " << setw(20) << left << user.getEmail();
        cout << "| " << setw(10) << left << user.getPassword();
        cout << "| " << setw(12) << left << user.getPermissions();
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

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (users.empty())
            cout << "\t\t\t\tNo Users Available In the System!";
        else
            for (User& user : users)
            {
                printUserRecordLine(user);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
};
