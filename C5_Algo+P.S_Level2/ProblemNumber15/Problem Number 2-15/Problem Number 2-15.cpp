

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
	for (int i = 65; i <= Number + 65 - 1; i++)
	{

		for (int j = 65; j <= i; j++)
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