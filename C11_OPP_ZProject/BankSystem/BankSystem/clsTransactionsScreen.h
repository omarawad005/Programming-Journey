#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputVaIidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"
#include "clsTransfersLogScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:

	enum enTransactionsMenuOptions {
		eDeposit = 1, eWithdraw = 2, eShowTotalBalances = 3,
		eTransfer = 4,	eTransferLog = 5, eShowMainMenue = 6
	};

	static short _ReadTransactionsMenuOptions()
	{
		cout << setw(37) << left << "\t\t\t\t\tChoose What do you want to do ? [1 to 6] ";
		short Choice = clsInputValidate::
			ReadShortNumberBetween(1, 6, "Enter Number Between [1 : 6 ]? ");
		return Choice;
	}

	static  void _GoBackToTransactionsMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transactions Menu...\n";

		system("pause>0");
		clsTransactionsScreen::ShowTransactionsScreen();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransfersLogScreen::ShowTransfersLogScreen();
	}

	static void _PerformTransactionsMenuOptions(enTransactionsMenuOptions TransactionsMenuOptions)
	{
		switch (TransactionsMenuOptions)
		{
		case enTransactionsMenuOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eShowTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::eShowMainMenue:
		{
			////do nothing here the main screen wilt handle It :-) ;
		}
		}
	}



public	:

	static void ShowTransactionsScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::eTransactions))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\tTransactions Screen");

		cout << setw(37) << left << "" << "\t======================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
		cout << setw(37) << left << "" << "\t======================================\n";
		cout << setw(37) << left << "" << "\t\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t\t[3] TotalBalances.\n";
		cout << setw(37) << left << "" << "\t\t[4] Tranfer.\n";
		cout << setw(37) << left << "" << "\t\t[5] Tranfer Log.\n";
		cout << setw(37) << left << "" << "\t\t[6] MainMenue.\n";
		cout << setw(37) << left << "" << "\t======================================\n";
		_PerformTransactionsMenuOptions((enTransactionsMenuOptions)_ReadTransactionsMenuOptions());
	}

};

