#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Person.h"
#include "clsString.h"
#include "LoginScreen.h"
#include "Date.h"
using namespace std;

class User : public Person
{
private:

    enum enMode { emptyMode = 0, updateMode = 1, addNewMode = 2 };
    enMode mode;
    string userName;
    string password;
    int permissions;
    bool markedForDelete = false;

    static User convertLineToUserObject(string line, string separator = "#//#")
    {
        vector<string> vUserData = clsString::Split(line, separator);

        return User(enMode::updateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
    }

    static string convertUserObjectToLine(User user, string separator = "#//#")
    {
        string userRecord = "";
        userRecord += user.getFirstName() + separator;
        userRecord += user.getLastName() + separator;
        userRecord += user.getEmail() + separator;
        userRecord += user.getPhoneNumber() + separator;
        userRecord += user.getUserName() + separator;
        userRecord += user.getPassword() + separator;
        userRecord += to_string(user.getPermissions());

        return userRecord;
    }

    static vector<User> loadUsersDataFromFile()
    {
        vector<User> vUsers;

        fstream myFile;
        myFile.open("Users.txt", ios::in); // read mode

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                User user = convertLineToUserObject(line);
                vUsers.push_back(user);
            }
            myFile.close();
        }

        return vUsers;
    }

    static void saveUsersDataToFile(vector<User> vUsers)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::out); // overwrite

        if (myFile.is_open())
        {
            for (User& u : vUsers)
            {
                if (!u.isMarkedForDelete())
                {
                    string dataLine = convertUserObjectToLine(u);
                    myFile << dataLine << endl;
                }
            }
            myFile.close();
        }
    }

    void update()
    {
        vector<User> vUsers = loadUsersDataFromFile();

        for (User& u : vUsers)
        {
            if (u.userName == userName)
            {
                u = *this;
                break;
            }
        }

        saveUsersDataToFile(vUsers);
    }

    void addNew()
    {
        addDataLineToFile(convertUserObjectToLine(*this));
    }

    void addDataLineToFile(string dataLine)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::out | ios::app);

        if (myFile.is_open())
        {
            myFile << dataLine << endl;
            myFile.close();
        }
    }

    static User getEmptyUserObject()
    {
        return User(enMode::emptyMode, "", "", "", "", "", "", 0);
    }
    public:
        struct stUserLog
        {
            string userName;
            string password;
            Date::systemDate dateOfLogIn;
			int permissions;
            string timeOfLogIn;
        };
        private:
         string convertLogstructToLine(stUserLog userLog, string seperator = "#//#")
        {
              string line="";
              line+=userLog.userName+seperator;
              line+= userLog.password+seperator;
              line+= to_string(userLog.dateOfLogIn.day) + "/" + to_string(userLog.dateOfLogIn.month) + "/" + to_string(userLog.dateOfLogIn.month) + "/"+seperator;
              line+= userLog.timeOfLogIn+seperator;
			  line += to_string(userLog.permissions);
              return line;
        }
         void writeLogHistoryOnfile(string dataLine)
        {
            fstream myFile;
            myFile.open("UserLogHistory.txt", ios::out | ios::app);
            if (myFile.is_open())
            {
                myFile << dataLine << endl;
                myFile.close();
            }
		}

public:
    enum enPermissions { eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64 };
    User(enMode mode, string firstName, string lastName,
        string email, string phone, string userName, string password,
        int permissions) : Person(firstName, lastName, email, phone)
    {
        mode = mode;
        userName = userName;
        password = password;
        permissions = permissions;
    }

    bool isEmpty()
    {
        return (mode == enMode::emptyMode);
    }

    bool isMarkedForDelete()
    {
        return markedForDelete;
    }

    string getUserName()
    {
        return userName;
    }

    void setUserName(string userName)
    {
        this->userName = userName;
    }

    string getPassword()
    {
        return  password;
    }

    void setPassword(string password)
    {
        this->password = password;
    }

    int getPermissions()
    {
        return permissions;
    }

    void setPermissions(int permissions)
    {
        this->permissions = permissions;
    }

    static User find(string userName)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::in);

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                User user = convertLineToUserObject(line);
                if (user.userName == userName)
                {
                    myFile.close();
                    return user;
                }
            }
            myFile.close();
        }

        return getEmptyUserObject();
    }

    static User find(string userName, string password)
    {
        fstream myFile;
        myFile.open("Users.txt", ios::in);

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                User user = convertLineToUserObject(line);
                if (user.userName == userName && user.password == password)
                {
                    myFile.close();
                    return user;
                }
            }
            myFile.close();
        }
        return getEmptyUserObject();
    }

    enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedUserExists = 2 };

    enSaveResults save()
    {
        switch (mode)
        {
        case enMode::emptyMode:
            if (isEmpty())
                return enSaveResults::svFailedEmptyObject;
            break;

        case enMode::updateMode:
            update();
            return enSaveResults::svSucceeded;

        case enMode::addNewMode:
            if (User::isUserExist(userName))
                return enSaveResults::svFailedUserExists;
            else
            {
                addNew();
                mode = enMode::updateMode;
                return enSaveResults::svSucceeded;
            }
        }
        return enSaveResults::svFailedEmptyObject; // fallback
    }

    static bool isUserExist(string userName)
    {
        User user = User::find(userName);
        return !user.isEmpty();
    }

    bool remove()
    {
        vector<User> vUsers = loadUsersDataFromFile();

        for (User& u : vUsers)
        {
            if (u.userName == userName)
            {
                u.markedForDelete = true;
                break;
            }
        }

        saveUsersDataToFile(vUsers);
        *this = getEmptyUserObject();

        return true;
    }

    static User getAddNewUserObject(string userName)
    {
        return User(enMode::addNewMode, "", "", "", "", userName, "", 0);
    }

    static vector<User> getUsersList()
    {
        return loadUsersDataFromFile();
    }
    bool checkAccessPermession(enPermissions permission)
    {
        if (permission == eAll)
            return true;
        return ((permission & this->permissions) == permission);
        //short hand if
        // return (permission == eAll) ? true : ((permission & this->permissions) == permission)? true:false
    }
   
    void logFileDetails()
    {
        stUserLog userLog;
        userLog.userName = this->userName;
        userLog.password = this->password;
        userLog.dateOfLogIn = Date::getSystemDate();
        userLog.permissions = this->permissions;
        userLog.timeOfLogIn = Date::getSystemTime();

        writeLogHistoryOnfile(convertLogstructToLine(userLog));
    }
};
