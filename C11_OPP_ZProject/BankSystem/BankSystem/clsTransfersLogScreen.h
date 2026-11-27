#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"


class clsTransfersLogScreen : protected clsScreen
{
private:

    static void _PrintTransferLogRecord(clsBankClient::stTransferLog Log)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << Log.DateTime;
        cout << "| " << left << setw(10) << Log.SourceAccountNumber;
        cout << "| " << left << setw(10) << Log.DestinationAccountNumber;
        cout << "| " << left << setw(12) << Log.Amount;
        cout << "| " << left << setw(15) << Log.SourceBalance;
        cout << "| " << left << setw(15) << Log.DestinationBalance;
        cout << "| " << left << setw(10) << Log.UserName;
    } 
    

public:

    static void ShowTransfersLogScreen()
    {
        vector<clsBankClient::stTransferLog> vLogs =clsBankClient::GetTransferLogList();

        string Title = "\t  Transfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vLogs.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\t_______________________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << setw(25) << left << "Date/Time";
        cout << "| " << left << setw(10) << "From";
        cout << "| " << left << setw(10) << "To";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(15) << "Src Balance";
        cout << "| " << left << setw(15) << "Dst Balance";
        cout << "| " << left << setw(10) << "User";
        cout << endl;

        cout << "\t_______________________________________________________________________________________________________________\n\n";

        if (vLogs.empty())
        {
            cout << "\t\t\tNo Transfer Logs Available.\n";
        }
        else
        {
            for (clsBankClient::stTransferLog & Log : vLogs)
            {
                _PrintTransferLogRecord(Log);
                cout << endl;
            }
        }

        cout << "\t_______________________________________________________________________________________________________________\n";

    }



};

