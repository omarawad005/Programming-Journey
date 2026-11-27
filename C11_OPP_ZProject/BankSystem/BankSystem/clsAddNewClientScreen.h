#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputVaIidate.h"
#include <iostream>
using namespace std;

class clsAddNewClientScreen :protected clsScreen
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


    static void ShowAddNewClietsScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::eAdd))
        {
            return;
        }
        
        _DrawScreenHeader("\t  Add New Client Screen. ");

        cout << "Enter Account Number : ";

        string AccountNumber = clsInputValidate::ReadString();

        cout << "\n___________________\n";

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is already used, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient =
            clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::svSucceeded:
        {
            cout << "\n\nAccount Added Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }

        case clsBankClient::svFaildEmptyObject:
        {
            cout << "\n\nError account was not saved because it's Empty.\n";
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

