#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card : ";

        cout << "\n-------------------------\n";

        cout << "\nUser  Name   : " << User.UserName;
        cout << "\nFirst Name   : " << User.FirstName;
        cout << "\nLast  Name   : " << User.LastName;
        cout << "\nFull  Name   : " << User.GetFullName();
        cout << "\nEmail        : " << User.Email;
        cout << "\nPhone        : " << User.Phone;
        cout << "\nPassword     : " << User.Password;
        cout << "\nPermissions  : " << User.Permissions;
        cout << "\n-------------------------\n";
    }
public:
	static void ShowDeleteUserScreen()
	{



        _DrawScreenHeader("\t  Delete User Screen");
        cout << "Enter User Name : ";
        string UserName;
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found,choose another one : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this User y/n?";
        char Answer;
        cin >> Answer;


        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }

	}

};

