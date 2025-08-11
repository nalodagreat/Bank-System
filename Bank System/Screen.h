#pragma once
#include <iostream>
#include "User.h"
#include "Global.h"


using namespace std;

class Screen
{
protected:
    static void drawScreenHeader(string title, string subTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << title;
        if (subTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << subTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }
    static bool isAccessAllowed(User::enPermissions permession)
    {
        if (CurrentUser.checkAccessPermession(permession))
        {
            return true;
        }
        else
        {
            cout << "\t\t\t\t\t______________________________________\n\n"<<
             "\t\t\t\t\t Access Denied!Contact Your Admin :)";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
    }

};

