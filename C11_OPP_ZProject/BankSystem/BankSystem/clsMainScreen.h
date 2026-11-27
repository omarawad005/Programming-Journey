#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputVaIidate.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "Global.h"
#include "clsUser.h"
#include "clsCurrencyExchangeScreen.h"

using namespace std;


class clsMainScreen :protected clsScreen
{
private:
	enum enMainMenuOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
	};

	static short _ReadMainMenuOptions()
	{
		cout << setw(37) << left << "\t\t\t\t\tChoose What do you want to do ? [1 to 10] ";
		short Choice = clsInputValidate::
			ReadShortNumberBetween(1, 10, "Enter Number Between [1 : 10 ]? ");
		return Choice;
	}

	static  void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowAllClientsScreen()
	{
		clsClientsListScreen::ShowClientsList();
	}

	static void _ShowAddNewClietsScreen()
	{
		clsAddNewClientScreen::ShowAddNewClietsScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();

	}

	static void _ShowTransactionsMenu()
	{
		clsTransactionsScreen::ShowTransactionsScreen();
	}

	static void _ShowManageUsersMenu()
	{
		clsManageUsersScreen::ShowManageUsersMenu();

	}
	
	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	
	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}

	static void _LogOut()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenuOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClietsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eShowTransactionsMenu:
		{
			system("cls");
			_ShowTransactionsMenu();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eExit:
		{
			system("cls");
			_LogOut();
			break;
		}
		default:
		{
			system("cls");
			_GoBackToMainMenu();
			break;
		}
		}
	}

public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "\t======================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Screen\n";
		cout << setw(37) << left << "" << "\t======================================\n";
		cout << setw(37) << left << "" << "\t\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t\t[10] Logout.\n";
		cout << setw(37) << left << "" << "\t======================================\n";
		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOptions());
	}

};

