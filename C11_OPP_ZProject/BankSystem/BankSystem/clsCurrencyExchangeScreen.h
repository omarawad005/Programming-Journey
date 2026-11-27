#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputVaIidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
private:

	enum enCurrencyExchangeOption
	{
		eListCurrencies = 1,
		eFindCurrency = 2,
		eUpdateRate = 3,
		eCurrencyCalculator = 4,
		eMainMenu = 5
	};

	static void _GoBackToCurrencyExchangeMenu()
	{
		cout << setw(37) << left << ""
			<< "\nPress any key to go back to Currency Exchange Menu...";

		system("pause>0");

		ShowCurrencyExchangeScreen();
	}

	static short _ReadCurrencyExchangeOption()
	{
		cout << setw(37) << left
			<< "\t\t\t\t\tChoose What do you want to do ? [1 to 5] ";

		short Choice = clsInputValidate::
			ReadShortNumberBetween(1, 5, "Enter Number Between [1 : 5]? ");

		return Choice;
	}

	static void _ShowListCurrenciesScreen()
	{

		clsCurrenciesListScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		 clsUpdateRateScreen::ShowUpdateRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{

		 clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrencyExchangeOption(enCurrencyExchangeOption CurrencyExchangeOption)
	{
		switch (CurrencyExchangeOption)
		{
		case enCurrencyExchangeOption::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}

		case enCurrencyExchangeOption::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}

		case enCurrencyExchangeOption::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}

		case enCurrencyExchangeOption::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;
		}

		case enCurrencyExchangeOption::eMainMenu:
		{
		}
		}
	}

public:

	static void ShowCurrencyExchangeScreen()
	{
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange  Screen");
		cout << setw(37) << left << "" << "\t======================================\n";
		cout << setw(37) << left << "" << "\t  Currency Exchange Main Screen\n";
		cout << setw(37) << left << "" << "\t======================================\n";
		cout << setw(37) << left << "" << "\t\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t\t[2] Fid Currency.\n";
		cout << setw(37) << left << "" << "\t\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "\t======================================\n";
		_PerformCurrencyExchangeOption((enCurrencyExchangeOption)_ReadCurrencyExchangeOption());
	}

};

