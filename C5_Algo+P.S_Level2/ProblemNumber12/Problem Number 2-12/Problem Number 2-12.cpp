

#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Num;
	do
	{
		cout << Message;
		cin >> Num;

	} while (Num <= 0 );
	
	return Num;
}

void PrintInvertedPattern(int Number )
{
	for (int i = Number; i > 0; i--)
	{

		for (int j = 1; j <= i; j++)
		{
			cout << i;
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