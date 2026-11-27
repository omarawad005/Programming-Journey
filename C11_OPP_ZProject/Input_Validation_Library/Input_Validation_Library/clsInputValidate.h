#pragma once
#include <iostream>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

template <class T>
class clsInputValidate
{
private:

public:

    static bool IsNumberBetween(T Num, T From, T To)
    {
        return (Num >= From && Num <= To);
    }

    static bool IsDateBetween(clsDate D1, clsDate DFrom, clsDate DTo)
    {
        if (clsDate::IsDate1AfterDate2(DFrom, DTo))
        {
            clsDate::SwapDates(DFrom, DTo);
        }

        return
            (
                (clsDate::IsDate1AfterDate2(D1, DFrom) ||
                    clsDate::IsDate1EqualDate2(D1, DFrom))
                &&
                (clsDate::IsDate1BeforeDate2(D1, DTo) ||
                    clsDate::IsDate1EqualDate2(D1, DTo))
                );
    }

    static T ReadNumber(string Message)
    {
        T Number;

        cin >> Number;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << Message;
            cin >> Number;
        }

        return Number;
    }

    static T ReadNumberBetween(T From, T To, string Message)
    {
        T Number = ReadNumber(Message);

        while (!IsNumberBetween(Number, From, To))
        {
            cout << Message;
            Number = ReadNumber(Message);
        }

        return Number;
    }

    static bool IsValidDate(clsDate D1)
    {
        return clsDate::IsValidDate(D1);
    }
};