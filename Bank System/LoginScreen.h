#pragma once

#include <iostream>
#include "Screen.h"
#include "User.h"
#include <iomanip>
#include "MainScreen.h"
#include "Global.h"

using namespace std;

class LoginScreen : protected Screen
{
private:
    static void login()
    {
        bool loginFailed = false;

        string username, password;
        do
        {
            if (loginFailed)
            {
                cout << "\nInvalid Username/Password!\n\n";
            }

            cout << "Enter Username? ";
            cin >> username;

            cout << "Enter Password? ";
            cin >> password;

            CurrentUser = User::find(username, password);

            loginFailed = CurrentUser.isEmpty();

        } while (loginFailed);

        MainScreen::showMainMenue();
    }

public:
    static void showLoginScreen()
    {
        system("cls");
        drawScreenHeader("\t  Login Screen");
        login();
    }
};
