#pragma once

#include <iostream>
#include "Screen.h"
#include <iomanip>
#include <fstream>
#include "User.h"

using namespace std;

class LoginRegisterScreen : protected Screen
{
private:
    static void printstUserLogLine(User::stUserLog stUserLog)
    {
        string dateTime =
            to_string(stUserLog.dateOfLogIn.day) + "/" +
            to_string(stUserLog.dateOfLogIn.month) + "/" +
            to_string(stUserLog.dateOfLogIn.year) + " ; " +
            stUserLog.timeOfLogIn;

        cout << setw(8) << left << ""
            << "| " << setw(35) << left << dateTime
            << "| " << setw(20) << left << stUserLog.userName
            << "| " << setw(20) << left << stUserLog.password
            << "| " << setw(10) << left << stUserLog.permissions
            << endl;
    }


public:
    static void showLoginRegisterScreen()
    {
        if (!Screen::isAccessAllowed(User::enPermissions::pShowLoginRegister))
			return;
        vector <User::stUserLog> vstUserLog = User::getLoginRegisterList();

        string title = "\tLogin Register List Screen";
        string subTitle = "\t\t(" + to_string(vstUserLog.size()) + ") Record(s).";

        drawScreenHeader(title, subTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time"
            << "| " << left << setw(20) << "UserName"
            << "| " << left << setw(20) << "Password"
            << "| " << left << setw(10) << "Permissions" << endl;

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        if (vstUserLog.size() == 0)
        {
            cout << "\t\t\t\tNo Logins Available In the System!";
        }
        else
        {
            for (User::stUserLog &record: vstUserLog)
            {
                printstUserLogLine(record);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
       
    }
};
