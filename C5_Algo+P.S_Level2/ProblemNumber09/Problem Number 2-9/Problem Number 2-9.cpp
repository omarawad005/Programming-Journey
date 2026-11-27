

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

int CountDigitFerquency(int Num, int Digit)
{
	int Reminder = 0;
	int Counter = 0;
	while (Num > 0)
	{
		Reminder = Num % 10;
		Num = Num / 10;
		if (Digit == Reminder)
		{
			Counter++;
		}
	}
	return Counter;

}

void PrintAllDigitFrequency(int Num)
{
	cout << '\n';
	for (int i = 0; i < 10; i++)
	{
		int Fer = 0;
		Fer = CountDigitFerquency(Num, i);
		if ( Fer > 0) 
		{
			cout << "Digit " << i << " Frequency is " 
				<< Fer << " Time(s) \n";
		}
	}
}


int main()
{

	PrintAllDigitFrequency(ReadPositiveNumber("Please enter Positive Number : "));




	return 0;
}