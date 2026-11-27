#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{

private:

    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| ";
        cout << setw(30) << left << Currency.Country();

        cout << "| ";
        cout << setw(8) << left << Currency.CurrencyCode();

        cout << "| ";
        cout << setw(40) << left << Currency.CurrencyName();

        cout << "| ";
        cout << setw(12) << left << Currency.Rate();

        cout << "|";
    }


public:

    static void ShowListCurrenciesScreen()
    {

        vector<clsCurrency> vCurrencies =
            clsCurrency::GetCurrenciesList();


        string Title = "\t  Currency List Screen";
        string SubTitle =
            "\t    (" + to_string(vCurrencies.size()) + ") Currency(s).";


        _DrawScreenHeader(Title, SubTitle);


        // Top Line
        cout << setw(8) << left << "" << "\n";
        cout << setw(8) << left << ""
            << "___________________________________________________________________________________________________\n";


        // Table Header
        cout << setw(8) << left << "" << "| ";
        cout << setw(30) << left << "Country";

        cout << "| ";
        cout << setw(8) << left << "Code";

        cout << "| ";
        cout << setw(40) << left << "Name";

        cout << "| ";
        cout << setw(12) << left << "Rate/(1$)";

        cout << "|";


        // Header Line
        cout << "\n";
        cout << setw(8) << left << ""
            << "___________________________________________________________________________________________________\n";


        // Currency Records
        if (vCurrencies.size() == 0)
        {
            cout << "\t\t\t\tNo Currencies Available In the System!";
        }
        else
        {
            for (clsCurrency& Currency : vCurrencies)
            {
                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }
        }


        // Bottom Line
        cout << setw(8) << left << "" << "\n";
        cout << setw(8) << left << ""
            << "___________________________________________________________________________________________________\n";

    }

};