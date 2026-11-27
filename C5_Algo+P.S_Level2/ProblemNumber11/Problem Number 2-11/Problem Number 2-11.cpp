

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

int ReverseNumber(int Num)
{
	int NewNumber = 0;
	int Reminder = 0;
	
	while (Num > 0) 
	{
		Reminder = Num % 10;
		Num = Num / 10;
		NewNumber = NewNumber * 10 + Reminder;
	}

	return NewNumber;
}

bool IsPalindrome(int Num)
{
	return (ReverseNumber(Num) == Num);
}


int main()
{
	int Num = ReadPositiveNumber("Please enter Positive Number : ");

	if (IsPalindrome(Num))
		cout << "\nYes, it is a Palindrome Number" << endl;
	else
		cout << "\nNo, it is Not a Palindrome Number" << endl;
	
	
	return 0;
}