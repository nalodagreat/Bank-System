#pragma once
#include "Person.h"
class User : public Person
{
	enum enMode
	{
		emptyMode = 1, upadteMode = 2, addNew = 3
	};
	int permession;
	string password;
	string userName;
	bool markForeDelete = false;
	enMode mode;
public:
	User(enMode mode, string firstName, string lastName, string email, string phoneNumber, string password, string userName, int permession)
		:Person(firstName, lastName, email, phoneNumber)
	{
		this->permession = permession;
		this->password = password;
		this->userName = userName;
		this->mode = mode;
	}
	void setMode(enMode mode)
	{
		this->mode = mode;
	}
	enMode getMode()
	{
		return mode;
	}
	string getUserName()
	{
		return userName;
	}
	void setUserName(string userName)
	{
		this->userName = userName;
	}
	void setPassword(string password)
	{
		this->password = password;
	}
	string getPassword()
	{
		return password;
	}
	int getPermession()
	{
		return permession;
	}
	void setPermession(int permession)
	{
		this->permession = permession;
	}
	/*void print()
	{
		cout << "First Name: " << getFirstName() << endl;
		cout << "Last Name: " << getLastName() << endl;
		cout << "Email: " << getEmail() << endl;
		cout << "Phone Number: " << getPhoneNumber() << endl;
		cout << "User Name: " << userName << endl;
		cout << "Password: " << password << endl;
		cout << "Permession: " << permession << endl;
	}*/
};

