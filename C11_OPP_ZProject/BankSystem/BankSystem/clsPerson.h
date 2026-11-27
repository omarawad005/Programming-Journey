#pragma once
#include <iostream>
#include <string>
using namespace std;
class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public:

	clsPerson(string FN, string LN, string Email, string Phone) 
		: _FirstName(FN), _LastName(LN), _Email(Email), _Phone(Phone)
	{

	}

	// FirstName Set & Get
	// Set
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}
	// Get
	string GetFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	// LastName Set & Get
	// Set
	void SetLastName(string LastName)
	{
		_LastName  = LastName;
	}
	// Get
	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	// Email Set & Get
	// Set
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	// Get
	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	// Phone Set & Get
	// Set
	void SetPhone(string Phone)
	{
		_Phone  = Phone;
	}
	// Get
	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;


	//FullName 
	string GetFullName() 
	{
		return _FirstName + " " + _LastName;
	}
	__declspec(property(get = GetFullName)) string FullName;
	

};