
#include <iostream>
#include <cstdlib>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Num;

	do
	{
		cout << Message;
		cin >> Num;
	} while (Num <= 0);

	return Num;	
}

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

enum enCharType
{
	SmallLetter = 1,
	CapitalLetter = 2,
	SpecialCharacter = 3,
	Digit = 4

};

char GetCharType(enCharType Random)
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

	default:
		return RandomNumber(97, 122);

		break;
	}

}

string GenratedWord(enCharType charType, short length)
{
	string Word = "";
	for (int i = 1; i <= length; i++)
	{
		Word += GetCharType(charType);
	}
	return Word;
}

string GenrateKey()
{
	string Key = "";
	Key = GenratedWord(enCharType::CapitalLetter, 4) + "-"
		+ GenratedWord(enCharType::CapitalLetter, 4) + "-"
		+ GenratedWord(enCharType::CapitalLetter, 4) + "-"
		+ GenratedWord(enCharType::CapitalLetter, 4);

	return Key;
}

void PrintKeys(int Number)
{
	cout << "\n";
	for (int  i = 1; i <= Number; i++)
	{
		cout << "Key [" << i << "] : " << GenrateKey() << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int Number = ReadPositiveNumber("Please enter Positive Number : ");
	PrintKeys(Number);

	return 0;
}