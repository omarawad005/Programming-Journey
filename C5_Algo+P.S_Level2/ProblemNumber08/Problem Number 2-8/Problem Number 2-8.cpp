

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

int CountDigitFerquency(int Num, short Digit)
{
	int Reminder = 0;
	int Counter = 0;
	while (Num > 0)
	{
		Reminder = Num % 10;
		Num = (Num / 10);
		if (Digit == Reminder)
		{
			Counter++;
		}
	}

	return Counter;
}


int main()
{
	int Number =          ReadPositiveNumber("Please enter Positive Number : ");
	int FerquencyNumber = ReadPositiveNumber("Enter the digit you want to count: ");

	cout << "\nDigit " << FerquencyNumber << " Ferquency "
		<< CountDigitFerquency(Number, FerquencyNumber)
		<< " Time(s)\n";



	return 0;
}