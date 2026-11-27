
#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;

	} while (!(Number > 0));

	return Number;
}

int ReverseNumber(int Number)
{
	int Reaminder = 0, NewNumber = 0;

	while (Number > 0)
	{
		Reaminder = Number % 10;
		Number = Number / 10;

		NewNumber = NewNumber * 10 + Reaminder;
	
	}
	return NewNumber;
}

void PrintResult(int Num)
{
	int Reaminder = 0;

	while (Num > 0)
	{
		Reaminder = Num % 10;
		Num = Num / 10;
		cout << Reaminder << endl;
	}
}



int main()
{
	int Number = ReadPositiveNumber("Please enter a Number : ");
	PrintResult(ReverseNumber(Number));

	return 0;
}

