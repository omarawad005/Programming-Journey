

#include <iostream>

using namespace std;

struct stTaskDuration
{
	int Day, Hour, Minute, Second;
};

int ReadTotalSecond(string Message)
{
	int NumOfSecond;
	do
	{
		cout << Message;
		cin >> NumOfSecond;
	} while (NumOfSecond <= 0);
	return NumOfSecond;
}

stTaskDuration CalculateTaskDuration(int TotalSecond)
{
	stTaskDuration NumberOf;
	const int
		Second_In_Day = 24 * 60 * 60,
	    Second_In_Hour = 60 * 60,
		Second_In_Minute = 60;
	int Reminder = 0;
	
	NumberOf.Day = floor(TotalSecond / Second_In_Day);
	Reminder = TotalSecond % Second_In_Day;

	NumberOf.Hour = floor(Reminder / Second_In_Hour);
	Reminder = Reminder % Second_In_Hour;

	NumberOf.Minute = floor(Reminder / Second_In_Minute);
	Reminder = Reminder % Second_In_Minute;

	NumberOf.Second = Reminder;

	return NumberOf;
	
}

void PrintResutl(stTaskDuration NumberOf)
{
	cout << NumberOf.Day << ":" << NumberOf.Hour << ":" << NumberOf.Minute << ":" << NumberOf.Second;
}

int main()
{
	int TotalSecond = ReadTotalSecond("Please enter Total Second : ");

	cout << "\n****************************\n";
	cout << "The Result is ==> ";
	PrintResutl(CalculateTaskDuration(TotalSecond));
	cout << "\n****************************\n";



	return 0;
}