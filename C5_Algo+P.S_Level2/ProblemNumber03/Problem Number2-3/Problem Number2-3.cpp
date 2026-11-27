
#include <iostream>

using namespace std;

enum enPrefectNotPerfect{ Prefect, NotPerfect};

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
	cout << endl;
	if (IsPrefectNumber(Num))
		cout << Num << " Is Prefect Number ?\n";
	else
		cout << Num << " Is Not Prefect Number ?\n";
}


int main() 
{

	PrintResult(ReadPositiveNumber("Please enter A Positive Number : "));




	return 0;
}