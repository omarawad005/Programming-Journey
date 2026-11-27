#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputVaIidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:

    enum enManageUsersMenuOptions
    {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenu = 6
    };

	static short _ReadManageUsersMenuOptions()
	{
		cout << setw(37) << left << "\t\t\t\t\tChoose What do you want to do ? [1 to 6] ";
		short Choice = clsInputValidate::
			ReadShortNumberBetween(1, 6, "Enter Number Between [1 : 6 ]? ");
		return Choice;
	}

	static  void _GoBackToManageUsersMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to  Manage Users Menu...\n";

		system("pause>0");
		ShowManageUsersMenu();
	}

    static void _ShowUsersListScreen()
    {
        //cout << "\nUsers List Screen Will be here...\n";
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        //cout << "\nAdd New User Screen Will be here...\n";
        clsAddNewUserScreen::ShowAddNewUsersScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        //cout << "\nDelete User Screen Will be here...\n";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        //cout << "\nUpdate User Screen Will be here...\n";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        //cout << "\nFind User Screen Will be here...\n";
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformManageUsersMenuOptions(enManageUsersMenuOptions ManageUsersMenuOption)
    {
        switch (ManageUsersMenuOption)
        {
        case enManageUsersMenuOptions::eListUsers:
        {
            system("cls");
            _ShowUsersListScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenuOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenuOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenuOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenuOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enManageUsersMenuOptions::eMainMenu:
        {
            system("cls");
            break;
        }
        }
    }

public:

	static void ShowManageUsersMenu()
	{


        if (!CheckAccessRights(clsUser::enPermissions::eManage))
        {
            return;
        }

		system("cls");
		_DrawScreenHeader("\tManage Users Screen");
		cout << setw(37) << left << "" << "\t======================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Screen\n";
		cout << setw(37) << left << "" << "\t======================================\n";
		cout << setw(37) << left << "" << "\t\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "\t======================================\n";
		_PerformManageUsersMenuOptions((enManageUsersMenuOptions)_ReadManageUsersMenuOptions());
	}

};

