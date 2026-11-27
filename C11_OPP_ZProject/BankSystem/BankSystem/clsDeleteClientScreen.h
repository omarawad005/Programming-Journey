#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputVaIidate.h"

class clsDeleteClientScreen : protected clsScreen
{
private:

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
    static void ShowDeleteClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::eDelete))
        {
            return;
        }

        _DrawScreenHeader("\t  Delete Client Screen");
        cout << "Enter Account Number : ";
        string AccountNumber;
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found,choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nAre you sure you want to delete this client y/n?";
        char Answer;
        cin >> Answer;


        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nCLient Deleted Successfully :-)\n";
                _PrintClient(Client);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }

    }
};

