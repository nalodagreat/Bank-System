#pragma once
#include<string>
#include<iostream>
using namespace std;
class Person
{
	string firstName;
	string lastName;
	string email;
	string phoneNumber;
public:
	Person(string firstName, string lastName, string email, string phoneNumber)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->email = email;
		this->phoneNumber = phoneNumber;
	}
	void setFirstName(string firstName)
	{
		this->firstName = firstName;
	}
	void setLastName(string lastName)
	{
		this->lastName = lastName;
	}
	void setEmail(string email)
	{
		this->email = email;
	}
	void setPhoneNumber(string email)
	{
		this->phoneNumber = phoneNumber;
	}
	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
	string getEmail()
	{
		return email;
	}
	string getPhoneNumber()
	{
		return phoneNumber;
	}

};

