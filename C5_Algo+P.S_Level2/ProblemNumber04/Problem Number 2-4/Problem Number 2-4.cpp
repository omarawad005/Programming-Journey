
#include <iostream>

using namespace std;

enum enPrefectNotPerfect { Prefect, NotPerfect };

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

bool IsPrefectNumber(int Num)
{
	int HalfNum = round(Num / 2);
	int Sum = 0;
	for (int i = 1; i <= HalfNum; i++)
	{
		if (Num % i == 0)
		{
			Sum += i;
		}
	}
	return (Num == Sum);
}


void PrintResult(int Num)
{
	cout << "\nPrefect Number From 1 to " << Num  << " Are : " << endl;
	for (int i = 1; i <= Num; i++)
	{
		if (IsPrefectNumber(i)) 
		{
			cout << i << endl;
		}
	}
}


int main()
{

	PrintResult(ReadPositiveNumber("Please enter A Positive Number : "));




	return 0;
}