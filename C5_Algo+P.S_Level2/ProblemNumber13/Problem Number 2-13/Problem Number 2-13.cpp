

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
	
	for (int i = 1; i <= Number; i++)
	{
		for (int j = 1 ; j <= i ; j++)
		{
			cout << i;
		}
		cout << "\n";
	}


}


int main()
{
	int Number = ReadPositiveNumber("Please enter Positive Number : ");
	PrintInvertedPattern(Number);


	return 0;
}