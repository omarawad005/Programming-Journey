/*

#include <iostream>
using namespace std;



bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short ReadYear()
{
	short Year = 0;

	cout << "Please enter a Year To Check : ";
	cin >> Year;
	while (cin.fail() || Year <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::min(), '\n');

		cout << "Please enter a Year To Check :  ";
		cin >> Year;
	}
	return Year;

}
short ReadMonth()
{
	short Month;
	do
	{
		cout << "\nPlease enter a Month To Check : ";
		cin >> Month;

	} while (Month <= 0 || Month > 12);



	return Month;
}

enum enMonth
{
	Jan = 1,
	Feb = 2,
	Mar = 3,
	Apr = 4,
	May = 5,
	Jun = 6,
	Jul = 7,
	Aug = 8,
	Sep = 9,
	Oct = 10,
	Nov = 11,
	Dec = 12
};

short CalaculateNumberInMonth(short Year, short Month)
{

	switch (enMonth(Month))
	{
		case Jan: case Mar:
		case May: case Jul:
		case Aug: case Oct:
		case Dec:
			return 31;
			break;
		case Apr: case Jun:
		case Sep: case Nov:
			return 30;
			break;
		case Feb:
			return (IsLeapYear(Year)) ? 29 : 28;
			break;
	}
}



short NumberOfDaysInAMonth(short Year, short Month)
{
	return CalaculateNumberInMonth(Year,Month);
}

short NumberOfHoursInAMonth(short Year, short Month)
{
	return NumberOfDaysInAMonth(Year, Month) * 24;
}

int NumberOfMinutesInAMonth(short Year, short Month)
{
	return NumberOfHoursInAMonth(Year, Month) * 60;
}

int NumberOfSecondsInAMonth(short Year, short Month)
{
	return NumberOfMinutesInAMonth(Year,Month) * 60;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days    in Month [" << Month << "] is : "
		<< NumberOfDaysInAMonth(Year,Month);
	cout << "\nNumber of Hours   in Month [" << Month << "] is : "
		<< NumberOfHoursInAMonth(Year,Month);
	cout << "\nNumber of Minutes in Month [" << Month << "] is : "
		<< NumberOfMinutesInAMonth(Year,Month);
	cout << "\nNumber of Seconds in Month [" << Month << "] is : "
		<< NumberOfSecondsInAMonth(Year,Month);


	system("pause > 0");
}


*/


#include <iostream>
using namespace std;



bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short ReadYear()
{
	short Year = 0;

	cout << "Please enter a Year To Check : ";
	cin >> Year;
	while (cin.fail() || Year <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::min(), '\n');

		cout << "Please enter a Year To Check :  ";
		cin >> Year;
	}
	return Year;

}
short ReadMonth()
{
	short Month;
	do
	{
		cout << "\nPlease enter a Month To Check : ";
		cin >> Month;

	} while (Month <= 0 || Month > 12);



	return Month;
}

short NumberOfDaysInAMonth(short Year, short Month)
{
	short days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2 && IsLeapYear(Year)) ? 29 : days[Month - 1];
}

short NumberOfHoursInAMonth(short Year, short Month)
{
	return NumberOfDaysInAMonth(Year, Month) * 24;
}

int NumberOfMinutesInAMonth(short Year, short Month)
{
	return NumberOfHoursInAMonth(Year, Month) * 60;
}

int NumberOfSecondsInAMonth(short Year, short Month)
{
	return NumberOfMinutesInAMonth(Year, Month) * 60;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days    in Month [" << Month << "] is : "
		<< NumberOfDaysInAMonth(Year, Month);
	cout << "\nNumber of Hours   in Month [" << Month << "] is : "
		<< NumberOfHoursInAMonth(Year, Month);
	cout << "\nNumber of Minutes in Month [" << Month << "] is : "
		<< NumberOfMinutesInAMonth(Year, Month);
	cout << "\nNumber of Seconds in Month [" << Month << "] is : "
		<< NumberOfSecondsInAMonth(Year, Month);


	system("pause > 0");
}

