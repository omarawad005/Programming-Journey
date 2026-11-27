

#include <iostream>

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

void PrintInvertedPattern(int Number)
{
	for (int i = Number + 64; i > 64; i--)
	{

		for (int j = 64; j < i; j++)
		{
			cout << char(i);
		}
		cout << endl;

	}
}


int main()
{
	int Number = ReadPositiveNumber("Please enter Positive Number : ");
	PrintInvertedPattern(Number);


	return 0;
}