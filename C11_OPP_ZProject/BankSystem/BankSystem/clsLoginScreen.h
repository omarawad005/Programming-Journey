#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

using namespace std;


class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;
		short FailedLoginAttempts = 0;


		string UserName, Password;

		do
		{
			if (LoginFaild)
			{
				++FailedLoginAttempts;
				cout << "\nInvlaid Username/Password ! \n";
				cout << "You have " << (3 - FailedLoginAttempts) << " attempt(s) remaining.\n\n";
			}
			if (FailedLoginAttempts == 3)
			{
				cout << "\nYour are Locked after 3 faild trails\n\n";
				return false;
			}
			cout << "Enter User Name : ";
			cin >> UserName;
			cout << "Enter Password  : ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName,Password);


			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenu();

		return true;

	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();

	}

};

