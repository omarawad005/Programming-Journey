#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputVaIidate.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.GetFullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }

    static string _ReadAccountNumber(string Message)
    {
        string AccountNumber;

        cout << Message;
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        return AccountNumber;
    }

    static float _ReadTransferAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount: ";
        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount <= 0 || Amount > SourceClient.AccountBalance)
        {
            if (Amount <= 0)
                cout << "\nAmount must be greater than zero.\n";
            else
                cout << "\nAmount exceeds the available balance.\n";

            cout << "\nEnter Transfer Amount: ";
            Amount = clsInputValidate::ReadFloatNumber();
        }

        return Amount;
    }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number To Transfer From: "));
        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number To Transfer To: "));

        while (SourceClient.AccountNumber() == DestinationClient.AccountNumber())
        {
            cout << "\nYou cannot transfer to the same account.\n";
            DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Another Account Number: "));
        }
        _PrintClient(DestinationClient);

        float Amount = _ReadTransferAmount(SourceClient);

        char Answer = 'N';

        cout << "\nAre you sure you want to perform this operation? (Y/N): ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient))
            {
                cout << "\nTransfer completed successfully.\n";
            }
            else
            {
                cout << "\nTransfer failed.\n";
            }

            cout << "\nSource Client After Transfer:";
            _PrintClient(SourceClient);

            cout << "\nDestination Client After Transfer:";
            _PrintClient(DestinationClient);
        }
        else
        {
            cout << "\nTransfer cancelled.\n";
        }
    }

};