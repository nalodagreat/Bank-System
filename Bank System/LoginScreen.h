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
    static bool login()
    {
		bool loginFailed = false; short triesCount = 0;

        string username, password;
        do
        {
            if (loginFailed)
            {

                cout << "\nInvalid Username/Password!\n\n";
                triesCount++;
                cout << "you have" << " " << (3 - triesCount) << " trial(s) left.\n";
            }
            if (triesCount == 3)
            {
                cout << "\nYou' have're Locked after entering wrong username/password 3 times, exiting...\n";
                return false; //exit from login screen
            }


                cout << "Enter Username? ";
                cin >> username;

                cout << "Enter Password? ";
                cin >> password;

                CurrentUser = User::find(username, password);

                loginFailed = CurrentUser.isEmpty();
            
            } while (loginFailed);
        
        //if arrived here then login is then succeesfully
        CurrentUser.logFileDetails();
        MainScreen::showMainMenue();
		return true; //login success
    }

public:
    static bool showLoginScreen()
    {
        system("cls");
        drawScreenHeader("\t  Login Screen");
        return login();
    }
};
