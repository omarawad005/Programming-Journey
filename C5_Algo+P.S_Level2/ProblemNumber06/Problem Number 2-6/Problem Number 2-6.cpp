

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

int SumDigitNumber(int Num)
{
	int Sum = 0;
	int Reminder = 0;
	while (Num > 0)
	{

		Reminder = Num % 10;
		Num = round(Num / 10);
		Sum += Reminder;
	}

	return Sum;

}






int main()
{

	cout << "\nSum Of Digits : " 
		<<SumDigitNumber(ReadPositiveNumber("Please enter Positive Number : "))
		<< endl;
		
	return 0;
}