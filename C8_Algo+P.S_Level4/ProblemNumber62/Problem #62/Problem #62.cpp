#include <iostream>
#include <string>
using namespace std;

struct sDate
{
    short Year;
    short Month;
    short Day;
};

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DayInMonth(short Year, short Month)
{
	if (Month < 0 || Month > 12) return 0;
	int NumOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumOfDays[Month - 1];
}

short ReadYear()
{
	short Year = 0;
	cout << "\nPlease enter a Year  : ";

	cin >> Year;
	while (cin.fail() || Year <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::min(), '\n');

		cout << "Please enter a Year  : ";
		cin >> Year;
	}
	return Year;

}
short ReadMonth()
{
	short Month;
	do
	{
		cout << "\nPlease enter a Month : ";
		cin >> Month;

	} while (Month <= 0 || Month > 12);



	return Month;
}
short ReadDay(sDate Date)
{
	short Day;
	do
	{
		cout << "\nPlease enter a Day   : ";
		cin >> Day;

	} while (Day <= DayInMonth(Date.Month,Date.Year) && Day > 0);



	return Day;
}




int main()
{
    sDate Date;

	Date.Day = ReadDay(Date);
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

    system("pause > 0");
}