

#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SamallLetter:
	{
		return char(RandomNumber(97, 122));
		break;
	}
	case enCharType::CapitalLetter:
	{
		return char(RandomNumber(65, 90));
		break;
	}
	case enCharType::SpecialCharacter:
	{
		return char(RandomNumber(33, 47));
		break;
	}
	case enCharType::Digit:
	{
		return char(RandomNumber(48, 57));
		break;
	}
	}
}

string GenerateWord(enCharType CharType, short Length)
{
	string Word;

	for (int i = 1; i <= Length; i++)
		Word = Word + GetRandomCharacter(CharType);
	
	return Word;
}

string GenerateKey()
{
	string Key = "";
	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
	return Key;
}

void FillArrayElement(string arr[100], int& arrlength)
{
	cout << "Enter Number Of Keys : ";
	cin >> arrlength;
	for (int i = 0; i < arrlength; i++)
	{
		arr[i] = GenerateKey();
	}
}

void PrintArrayElement(string arr[100], int arrlength)
{
	cout << "\nArray Element : \n\n";
	for (int i = 0; i < arrlength; i++)
	{
		cout << "Array [" << i << "] : ";
		cout << arr[i] << endl; 
	}
}

int main()
{
	srand((unsigned)time(NULL));

	string Arr[100];
	int Length = 0;

	FillArrayElement(Arr, Length);
	PrintArrayElement(Arr, Length);

	return 0;
}