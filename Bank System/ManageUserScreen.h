#pragma once
#include <iostream>
#include "Screen.h"
#include "InputValidate.h"
#include <iomanip>

using namespace std;

class ManageUsersScreen : protected Screen
{

private:
    enum enManageUsersMenuOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
    };

    static short readManageUsersMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short choice = InputValidate::readShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return choice;
    }

    static void goBackToManageUsersMenu()
    {
        cout << "\n\nPress any key to go back to Manage Users Menu...";
        system("pause>0");
        showManageUsersMenu();
    }

    static void showListUsersScreen()
    {
        cout << "\nList Users Screen Will Be Here.\n";
    }

    static void showAddNewUserScreen()
    {
        cout << "\nAdd New User Screen Will Be Here.\n";
    }

    static void showDeleteUserScreen()
    {
        cout << "\nDelete User Screen Will Be Here.\n";
    }

    static void showUpdateUserScreen()
    {
        cout << "\nUpdate User Screen Will Be Here.\n";
    }

    static void showFindUserScreen()
    {
        cout << "\nFind User Screen Will Be Here.\n";
    }

    static void performManageUsersMenuOption(enManageUsersMenuOptions manageUsersMenuOption)
    {
        switch (manageUsersMenuOption)
        {
        case enManageUsersMenuOptions::eListUsers:
            system("cls");
            showListUsersScreen();
            goBackToManageUsersMenu();
            break;

        case enManageUsersMenuOptions::eAddNewUser:
            system("cls");
            showAddNewUserScreen();
            goBackToManageUsersMenu();
            break;

        case enManageUsersMenuOptions::eDeleteUser:
            system("cls");
            showDeleteUserScreen();
            goBackToManageUsersMenu();
            break;

        case enManageUsersMenuOptions::eUpdateUser:
            system("cls");
            showUpdateUserScreen();
            goBackToManageUsersMenu();
            break;

        case enManageUsersMenuOptions::eFindUser:
            system("cls");
            showFindUserScreen();
            goBackToManageUsersMenu();
            break;

        case enManageUsersMenuOptions::eMainMenu:
            // do nothing, main screen will handle it
            break;
        }
    }

public:

    static void showManageUsersMenu()
    {
        system("cls");
        drawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        performManageUsersMenuOption((enManageUsersMenuOptions)readManageUsersMenuOption());
    }

};
