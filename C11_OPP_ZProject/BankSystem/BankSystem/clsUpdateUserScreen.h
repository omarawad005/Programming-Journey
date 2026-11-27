
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputVaIidate.h"

using namespace std;



class clsUpdateUserScreen : protected clsScreen
{
private:

    static bool _CheckPermission(string Message)
    {
        char Answer;
        cout << Message;
        cin >> Answer;

        return (Answer == 'Y' || Answer == 'y');
    }

    static short _ReadPermission()
    {
        short Permission = 0;

        if (_CheckPermission("\nDo you want to give full access? y/n? "))
            return -1;

        cout << "\nDo you want to give access to :\n";
        if (_CheckPermission("\nShow Client List y/n? "))
            Permission |= clsUser::enPermissions::eShow;

        if (_CheckPermission("\nAdd New Client y/n? "))
            Permission |= clsUser::enPermissions::eAdd;

        if (_CheckPermission("\nDelete Client y/n? "))
            Permission |= clsUser::enPermissions::eDelete;

        if (_CheckPermission("\nUpdate Client y/n? "))
            Permission |= clsUser::enPermissions::eUpdate;

        if (_CheckPermission("\nFind Client y/n? "))
            Permission |= clsUser::enPermissions::eFind;

        if (_CheckPermission("\nTransactions y/n? "))
            Permission |= clsUser::enPermissions::eTransactions;

        if (_CheckPermission("\nManage User y/n? "))
            Permission |= clsUser::enPermissions::eManage;

        if (_CheckPermission("\nLogin Register y/n? "))
            Permission |= clsUser::enPermissions::eLogRegister;

        return Permission;
    }

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter First Name : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Last Name : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password : ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions : ";
        User.Permissions = _ReadPermission();

    }

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

    static void ShowUpdateUserScreen ()
    {
       

      
        
        _DrawScreenHeader("\t  Update User Screen. ");

        cout << "Enter User Name : ";

        string UserName = clsInputValidate::ReadString();

        cout << "\n___________________\n";

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not already used, choose another one : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User =
            clsUser::Find(UserName);

        _PrintUser(User);

       

        cout << "\nAre you sure you want to Update this User y/n?";
        char Answer;
        cin >> Answer;
        

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\nUpdate User Info";
            cout << "\n___________________\n";
            
            _ReadUserInfo(User);
            clsUser::enSaveResults SaveResult;
            SaveResult = User.Save();

            switch (SaveResult)
            {
            case clsUser::svSucceeded:
            {
                cout << "\n\nUser Added Successfully :-)\n";
                _PrintUser(User);
                break;
            }

            case clsUser::svFaildEmptyObject:
            {
                cout << "\n\nError User was not saved because it's Empty.\n";
                break;
            }

            case clsUser::svFaildUserExists:
            {
                cout << "\n\nFailed because User Name is already used.\n";
                break;
            }
            }
        }
    }

};

