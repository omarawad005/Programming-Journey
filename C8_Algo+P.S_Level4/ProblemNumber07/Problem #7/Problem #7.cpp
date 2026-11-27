
#include <iostream>
#include <string>
using namespace std;


bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
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
short ReadDay()
{
	short Day;
	do
	{
		cout << "\nPlease enter a Day   : ";
		cin >> Day;

	} while (Day <= 0 || Day > 31);



	return Day;
}

short CalculateOrderd(short Year, short Month, short Day)
{
	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;

	short Order = 0;

	Order = ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);

	return Order;

}

void PrintResult(short Year, short Month, short Day, short Order)
{
	string days[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	cout << "\n\nDate      : " << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order : " << Order << endl;
	cout << "Day Name  : " << days[Order] << endl;
}

int main()
{

	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();
	short Order = CalculateOrderd(Year, Month,Day);

	PrintResult(Year, Month, Day, Order);


	system("pause > 0");


}

