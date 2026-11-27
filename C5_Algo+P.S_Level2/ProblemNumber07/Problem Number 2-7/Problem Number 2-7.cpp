

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

int ReversedNumber(int Num)
{

	int NewNumber = 0;
	int Reminder = 1;

	while (Num > 0)
	{
		Reminder = Num % 10;
		Num = (Num / 10);
		NewNumber = NewNumber * 10 + Reminder;
	}
	return NewNumber;
}






int main()
{

	cout << "\nReversed Number is : " 
		<< ReversedNumber(ReadPositiveNumber("Please enter Positive Number : "))
		<< endl;

	return 0;
}