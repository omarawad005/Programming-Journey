#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputVaIidate.h"




class clsUpdateClientScreen :protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance : ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}


	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card : ";

		cout << "\n-------------------------\n";

		cout << "\nFirst Name   : " << Client.FirstName;
		cout << "\nLast  Name   : " << Client.LastName;
		cout << "\nFull  Name   : " << Client.GetFullName();
		cout << "\nEmail        : " << Client.Email;
		cout << "\nPhone        : " << Client.Phone;
		cout << "\nAcc. Number  : " << Client.AccountNumber();
		cout << "\nPinCode      : " << Client.PinCode;
		cout << "\nAcc. Balance : " << Client.AccountBalance;
		cout << "\n-------------------------\n";
	}
public:
	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eUpdate))
		{
			return;
		}
		
		_DrawScreenHeader("\t    Update Client Scrren");
		
		string AccountNumber;

		cout << "Please enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		cout << "\nUpdate Client Info";
		cout << "\n___________________\n";

		_ReadClientInfo(Client1);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client1.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
		{
			cout << "\n\nError account was not saved because it's Empty :-(\n";
			break;
		}

		case clsBankClient::svSucceeded:
		{
			cout << "\n\nAccount Updated Successfully :-)\n";
			_PrintClient(Client1);
			break;
		}

		case clsBankClient::svFaildAccountNumberExists:
		{
			cout << "\n\nFailed because Account Number is already used.\n";
			break;
		}
		}
	}
};

