

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

void ReversedNumber(int Num)
{
	cout << "\nReversed Number : \n";

	int Reminder = 0;
	while (Num > 0)
	{
		Reminder = Num % 10;
		cout << Reminder << endl;;
		Num = round(Num / 10);
	}

}






int main()
{

	ReversedNumber(ReadPositiveNumber("Please enter Positive Number : "));

	return 0;
}