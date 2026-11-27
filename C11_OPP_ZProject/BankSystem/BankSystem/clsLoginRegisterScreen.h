#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;


class clsLoginRegisterScreen : protected clsScreen
{
private:

    static void _PrintLoginRegisterRecord(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(25) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(15) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
        cout << endl;
    }

public:

	static void ShowLoginRegisterScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::eLogRegister))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "\tLogin Register List Screen\n";
        string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Date / Time";
        cout << "| " << left << setw(25) << "User Name ";
        cout << "| " << left << setw(15) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Login Register Available In the System!";
        else
            for (clsUser::stLoginRegisterRecord &Record : vLoginRegisterRecord)
            {

                _PrintLoginRegisterRecord(Record);
            }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
	}

};

