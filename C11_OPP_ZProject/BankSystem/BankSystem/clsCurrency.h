#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"

using namespace std;


//Currencies_Current_2026.txt

class clsCurrency
{

private:
	
	enum enMode{ EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float  _Rate;


	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;
	}

	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1],
			vCurrencyData[2], stod(vCurrencyData[3]));
	}

	static vector <clsCurrency> _LoadCurrencysDataFromFile()
	{
		vector <clsCurrency> vCurrencys;

		fstream MyFile;
		MyFile.open("Currencies_Current_2026.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				vCurrencys.push_back(Currency);
			}

			MyFile.close();

		}

		return vCurrencys;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrency)
	{
		fstream MyFile;
		MyFile.open("Currencies_Current_2026.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency& C : vCurrency)
			{
				{
					DataLine = _ConverCurrencyObjectToLine(C);
					MyFile << DataLine << endl;
				}

			}
				MyFile.close();
		}
	}

		void _Update()
		{
			vector <clsCurrency> vCurrencys;

			vCurrencys = _LoadCurrencysDataFromFile();

				for (clsCurrency& Currency : vCurrencys)
				{
					if (Currency.CurrencyCode() == CurrencyCode())
					{
						Currency = *this;
						break;
					}
				}

			_SaveCurrencyDataToFile(vCurrencys);
		}

	public:

		//Constructor
		clsCurrency(enMode Mode, string Country, string CurrencyCode,
			string CurrencyName, float Rate) 
		{
			_Mode = Mode;
			_Country = Country;
			_CurrencyCode = CurrencyCode;
			_CurrencyName = CurrencyName;
			_Rate = Rate;
		}
		bool IsEmpty()
		{
			return (_Mode == enMode::EmptyMode);
		}

		//Read Only
		string Country()
		{
			return _Country;
		}
		//Read Only
		string CurrencyCode()
		{
			return _CurrencyCode;
		}
		//Read Only
		string CurrencyName()
		{
			return _CurrencyName;
		}

		void UpdateRate(float NewRate)
		{
			_Rate = NewRate;
			_Update();
		}

		float Rate()
		{
			return _Rate;
		}

		static clsCurrency FindByCode(string CurrencyCode)
		{
			CurrencyCode = clsString::UpperAllString(CurrencyCode);

			fstream Myfile;
			Myfile.open("Currencies_Current_2026.txt", ios::in); // Read Mode
			if (Myfile.is_open())
			{
				string Line;
				while (getline(Myfile, Line))
				{
					clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
					if (CurrencyCode == Currency.CurrencyCode())
					{
						Myfile.close();
						return Currency;
					}
				}
			}
			return clsCurrency(enMode::EmptyMode, "", "", "", 0);

		}

		static clsCurrency FindByCountry(string Country)
		{
			Country = clsString::UpperAllString(Country);

			fstream Myfile;
			Myfile.open("Currencies_Current_2026.txt", ios::in);

			if (Myfile.is_open())
			{
				string Line;

				while (getline(Myfile, Line))
				{
					clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

					if (Country == clsString::UpperAllString(Currency.Country()))
					{
						Myfile.close();
						return Currency;
					}
				}

				Myfile.close();
			}

			return clsCurrency(enMode::EmptyMode, "", "", "", 0);
		}

		static bool IsCurrencyIsExistByCode(string CurrencyCode)
		{
			clsCurrency C = clsCurrency::FindByCode(CurrencyCode);
			return (!C.IsEmpty());
		}
		static bool IsCurrencyIsExistByCountry(string CurrencyCountry)
		{
			clsCurrency C = clsCurrency::FindByCountry(CurrencyCountry);
			return (!C.IsEmpty());
		}

		static vector <clsCurrency> GetCurrenciesList()
		{
			return _LoadCurrencysDataFromFile();
		}

		float ConvertToUSD(float Amount)
		{
			return (float)(Amount / Rate());
		}

		float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
		{
			float AmountInUSD  = ConvertToUSD(Amount);

			if (Currency2.CurrencyCode() == "USD")
			{
				return AmountInUSD;
			}
			return (float)(Amount * Currency2.Rate());
		}
};
