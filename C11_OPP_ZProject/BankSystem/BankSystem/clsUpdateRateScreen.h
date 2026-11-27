#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputVaIidate.h"
using namespace std;

class clsUpdateRateScreen : protected clsScreen
{
private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";

        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$)   : " << Currency.Rate();

        cout << "\n_____________________________\n";
    }

    static void _UpdateCurrency(clsCurrency& Currency)
    {
        cout << "\nUpdate Currency Rate\n";
        cout << "\n____________________________________\n";

        cout << "\nEnter New Rate : ";

        float NewRate = clsInputValidate::ReadFloatNumber();

        Currency.UpdateRate(NewRate);

        cout << "\n____________________________________\n";
    }

    static void _ShowResults(clsCurrency& Currency, char Answer)
    {
        if (toupper(Answer) == 'Y')
        {
            _UpdateCurrency(Currency);

            cout << "\nCurrency Rate Updated Successfully :-)\n";

            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Rate Update Cancelled :-(\n";
        }
    }

public:

    static void ShowUpdateRateScreen()
    {
        _DrawScreenHeader("\tUpdate Rate Screen");

        cout << "\nPlease Enter Currency Code: ";
        string CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyIsExistByCode(CurrencyCode))
        {
            cout << "\nCurrency Is not Found Choose another one : ";
            CurrencyCode = clsInputValidate::ReadString();
        }


        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        char Answer;
        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
        cin >> Answer;

        _ShowResults(Currency, Answer);
    }
     

};

