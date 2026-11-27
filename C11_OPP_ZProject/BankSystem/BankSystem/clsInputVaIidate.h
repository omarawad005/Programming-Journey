#pragma once
#include <iostream>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
private:

public:
	static  bool IsNumberBetween(int Num, int From, int To)
	{
		return (Num >= From && Num <= To);
	}
	static  bool IsNumberBetween(double Num, double From, double To)
	{
		return (Num >= From && Num <= To);
	}
	static bool IsDateBetween(clsDate D1, clsDate DFrom, clsDate DTo)
	{
		if (clsDate::IsDate1AfterDate2(DFrom, DTo))
		{
			clsDate::SwapDates(DFrom, DTo);
		}

		return (
			(clsDate::IsDate1AfterDate2(D1, DFrom) || clsDate::IsDate1EqualDate2(D1, DFrom))
			&&
			(clsDate::IsDate1BeforeDate2(D1, DTo) || clsDate::IsDate1EqualDate2(D1, DTo))
			);
	}
	
	
	static int ReadIntNumber(string Message)
	{
		int Number;
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
	static short ReadShortNumber(string Message)
	{
		short Number;
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

	static double ReadDoubleNumber(string Message)
	{
		double Number;
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
	static float ReadFloatNumber()
	{
		float Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> Number;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string Message)
	{
		int Number = ReadIntNumber(Message);

		while (!(IsNumberBetween(Number, From, To)))
		{
			cout << Message;
			Number = ReadIntNumber(Message);
		}


		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string Message)
	{
		short Number = ReadIntNumber(Message);

		while (!(IsNumberBetween(Number, From, To)))
		{
			cout << Message;
			Number = ReadShortNumber(Message);
		}


		return Number;
	}

	static double ReadDoubleNumberBetween(double From, double To, string Message)
	{
		double Number = ReadDoubleNumber(Message);

		while (!(IsNumberBetween(Number, From, To)))
		{
			cout << Message;
			Number = ReadDoubleNumber(" ");
		}


		return Number;
	}

	static bool IsValidDate(clsDate D1)
	{
		return clsDate::IsValidDate(D1);
	}

	static string ReadString()
	{
		string  S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}

	static double ReadPositiveDoubleNumber(string Message)
	{
		double Number = ReadDoubleNumber(Message);

		while (Number <= 0)
		{
			cout << "\nNumber must be greater than zero.\n";
			Number = ReadDoubleNumber(Message);
		}

		return Number;
	}

};

