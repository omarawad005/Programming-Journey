
#include <iostream>
#include <cmath>

using namespace std;

enum enPrimeNotPrime{Prime, NotPrime };


float ReadPositiveNumber(string Message)
{ 
	float Num = 0;
	do
	{
		cout << Message;
		cin >> Num;

	} while (Num <= 0);

	return Num;
}

enPrimeNotPrime CheckPrimeNumber(int Number)
{
	int M = round(Number / 2);
	for (int i = 2; i <= M; i++)
	{
		if (Number % i == 0)
			return enPrimeNotPrime::NotPrime;
	}
			return enPrimeNotPrime::Prime;
}

void PrintResult(int Number)
{
	switch (CheckPrimeNumber(Number))
	{
	case enPrimeNotPrime::NotPrime:
		cout << "Number is Not Prime !\n";
		break;
	case enPrimeNotPrime::Prime:
		cout << "Number is Prime !\n";
		break;

	}
}

int main()
{

	PrintResult(ReadPositiveNumber("Please enter Positive Number : "));
	return 0;
}

