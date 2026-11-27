#pragma once
#include <iostream>
#include <random>
#include "clsDate.h"
using namespace std;



class clsUtil
{
public:

	static enum enCharType
	{
		SmallLetter = 1,
		CapitalLetter = 2,
		SpecialCharacter = 3,
		Digit = 4,
		Mix = 5
	};


	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	static char GetRandomChar(enCharType Random)
	{
		switch (Random)
		{
		case enCharType::SmallLetter:
			return RandomNumber(97, 122);
			break;

		case enCharType::CapitalLetter:
			return RandomNumber(65, 90);
			break;

		case enCharType::SpecialCharacter:
			return RandomNumber(33, 47);
			break;

		case enCharType::Digit:
			return RandomNumber(48, 57);
			break;

		case enCharType::Mix:
			return GetRandomChar(enCharType(RandomNumber(1, 4)));

		default:
			return RandomNumber(97, 122);

			break;
		}

	}

	static string GenerateWord(enCharType CharType, short length)
	{
		string Word = "";
		for (int i = 1; i <= length; i++)
		{
			Word = Word + GetRandomChar(CharType);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";
		Key = GenerateWord(CharType,4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4);
		return Key;
	}

	static void GenerateKeys(short Num, enCharType CharType)
	{
		for (int i = 1; i <= Num; i++)
		{
			cout << "KEY [" << i << "] : " << GenerateKey(CharType) << endl;
		}
	}

	static void Swap(int &Num1, int &Num2)
	{
		int temp;
		temp = Num1;
		Num1 = Num2;
		Num2 = temp;
	}
	static void Swap(double &Num1, double &Num2)
	{
		double temp;
		temp = Num1;
		Num1 = Num2;
		Num2 = temp;
	}

	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(string &S1, string &S2)
	{
		string Temp = S1;
		S1 = S2;
		S2 = Temp;
	}

	static void Swap(clsDate &A, clsDate &B)
	{
		clsDate::SwapDates(A, B);
	}

	static void ShuffleArrayElement(int arr[100], int& arrlength)
	{
		for (int i = 0; i < arrlength; i++)
		{
			int Index1 = RandomNumber(1, arrlength) - 1;
			int Index2 = RandomNumber(1, arrlength) - 1;
			Swap(arr[Index1], arr[Index2]);
		}
	}

	static void ShuffleArrayElement(string arr[100], int& arrlength)
	{
		for (int i = 0; i < arrlength; i++)
		{
			int Index1 = RandomNumber(1, arrlength) - 1;
			int Index2 = RandomNumber(1, arrlength) - 1;
			Swap(arr[Index1], arr[Index2]);
		}
	}

	static void FillArrayElementWithRandomNumber(int arr[100], int arrlength, int From, int To)
	{
		for (int i = 0; i < arrlength; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayElementWithRandomWords(string arr[100], int arrlength, enCharType CharType, int Wordlength)
	{
		for (int i = 0; i < arrlength; i++)
		{
			 arr[i]  = GenerateWord(CharType, Wordlength);
		}
	}

	static void FillArrayElementWithRandomKeys(string arr[100], int arrlength, enCharType CharType)
	{
		for (int i = 0; i < arrlength; i++)
		{
			arr[i] = GenerateKey(CharType);
		}
	}

	static string Taps(short Num)
	{
		string t = "";
		for (int i = 0; i < Num; i++)
		{
			t = t + "\t";
			cout << t ;
		}
	}
	

	static string EncryptionText(string text, short EncryptionKey)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = char(int(text[i]) + EncryptionKey);
		}
		return text;
	}

	static string DecryptionText(string text, short EncryptionKey)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = char(int(text[i]) - EncryptionKey);
		}
		return text;
	}



};

