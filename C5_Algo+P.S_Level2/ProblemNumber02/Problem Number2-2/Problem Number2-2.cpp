

#include <iostream>
using namespace std;


enum enPrimeNotPrime{Prime = 1, NotPrime = 2};

int ReadPostiveNumber(string Message)
{
	int Num;
	
	do
	{
		cout << Message;
		cin >> Num;

	} while (Num <= 0);

	return Num;
}


enPrimeNotPrime CheckPrime(int Num)
{

	int HalfNum = round(Num / 2);
	for (int i = 2; i <= HalfNum; i++)
	{
		if (Num % i == 0)
		{
			return enPrimeNotPrime::NotPrime;
		}
	}

	return enPrimeNotPrime::Prime;
}

//bool IsPrime(int Num)
//{
//	return (CheckPrime(Num) == enPrimeNotPrime::Prime);
//}


void PrintPrimeNumbers(int Num)
{
	cout << "\nPrint From 1 to " << Num << " are :" << endl;
	for (int i = 1; i <= Num; i++)
	{
		if ((CheckPrime(i) == enPrimeNotPrime::Prime))
		{
			cout << i << endl;
		}
	}
}


int main()
{

	PrintPrimeNumbers(ReadPostiveNumber("Please enter Positive Number : "));

	return 0;
}

