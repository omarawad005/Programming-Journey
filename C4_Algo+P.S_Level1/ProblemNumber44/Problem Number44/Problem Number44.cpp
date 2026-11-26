

#include <iostream>
using namespace std;


enum enWeekDay
{
	Sunday = 1,
	Monday = 2,
	Tuesday = 3,
	Wednesday = 4,
	Thursday = 5,
	Friday = 6,
	Saturday = 7
};

int ReadDayNumber(string Message)
{ 
	int Num;

	do
	{
		cout << Message;
		cin >> Num;

	} while (Num <= 0 || Num >= 8);

	return Num;
}

enWeekDay WeekDay()
{
	int Day = 0;
	cout << "------------Week Day------------\n";
	cout << "(1) Sunday " << endl;
	cout << "(2) Monday " << endl;
	cout << "(3) Tuesday " << endl;
	cout << "(4) Wednesday " << endl;
	cout << "(5) Thursday " << endl;
	cout << "(6) Friday " << endl;
	cout << "(7) Saturday " << endl;
	cout << "--------------------------------\n";
	Day = ReadDayNumber("Please enter Number Of Day From list : ");
	
	return enWeekDay(Day);
}

string CheckDay(enWeekDay Day)
{
	switch (Day)
	{
		case Sunday:
			return "Sunday";
		case Monday:
			return "Monday";
		case Tuesday:
			return "Tuesday";
		case Wednesday:
			return "Wednesday";
		case Thursday:
			return "Thursday";
		case Friday:
			return "Friday";
		case Saturday:
			return "Saturday";
		default:
				return "something is wrong?";
			
	}
}


int main()
{

	
	cout << "\nToday is : " << CheckDay(WeekDay()) << endl;
	return 0;
}