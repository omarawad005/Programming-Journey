
#include <iostream>

using namespace std;

struct  sDate
{
	short Day;
	short Month;
	short Year;
};

short ReadDay()
{
	short Day = 0;
	cout << "Please enter a Day   ? ";
	cin >> Day;
	return Day;
}
short ReadMonth()
{
	short Month = 0;
	do
	{
		cout << "Please enter a Month ? ";
		cin >> Month;

	} while (Month > 12 || Month <= 0);
	return Month;
}
short ReadYear()
{
	short Year = 0;
	do
	{
		cout << "Please enter a Year  ? ";
		cin >> Year;

	} while (Year <= 0);
	return Year;
}
sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month > 12 || Month < 1)
		return 0;

	short NumOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumOfDays[Month - 1];
}
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
	short TotalDays = 0;
	for (int i = 1; i < Month; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}
	TotalDays += Day;
	return TotalDays;
}

bool IsFirstDay(sDate Date)
{
	return (Date.Day == 1);
}
bool IsFirstMonth(short Month)
{
	return (Month == 1);
}



sDate DecreaseDateByOneDay(sDate Date)
{
	if (IsFirstDay(Date))
	{
		if (IsFirstMonth(Date.Month))
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}
	}
	else
	{
		Date.Day--;
	}
	return Date;

}
sDate DecreaseDateByXDay(short Days, sDate Date)
{
	for (int i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
sDate DecreaseDateByOneWeek(sDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
sDate DecreaseDateByXWeeks(short Weeks, sDate Date)
{
	for (int i = 0; i < Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}
sDate DecreaseDateByOneMonth(sDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}
	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}
sDate DecreaseDateByXMonth(short Months, sDate Date)
{
	for (int i = 0; i < Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}
sDate DecreaseDateByOneYear(sDate Date)
{
	Date.Year--;
	return Date;
}
sDate DecreaseDateByXYears(short Years, sDate Date)
{
	for (int i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}
sDate DecreaseDateByXYearsFaster(short Years, sDate Date)
{
	Date.Year -= Years;
	return Date;
}
sDate DecreaseDateByOneDecade(sDate Date)
{
	Date.Year -= 10;
	return Date;
}
sDate DecreaseDateByXDecades(short Decades, sDate Date)
{
	for (int i = 1; i <= Decades; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}

	return Date;
}
sDate DecreaseDateByXDecadesFaster(short Decades, sDate Date)
{
	Date.Year -= Decades * 10;
	return Date;
}
sDate DecreaseDateByOneCentury(sDate Date)
{
	Date.Year -= 100;
	return Date;
}
sDate DecreaseDateByOneMillennium(sDate Date)
{
	Date.Year -= 1000;
	return Date;
}

void PrintResult(sDate Date)
{
	cout << "\n\nDate after :\n\n";

	Date = DecreaseDateByOneDay(Date);
	cout << "01-Subtracting one day is            : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXDay(10, Date);
	cout << "02-Subtracting 10 days is            : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneWeek(Date);
	cout << "03-Subtracting One Week is           : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXWeeks(10, Date);
	cout << "04-Subtracting 10 Weeks is           : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneMonth(Date);
	cout << "05-Subtracting One Month is          : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXMonth(5, Date);
	cout << "06-Subtracting 5 Month is            : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneYear(Date);
	cout << "07-Subtracting One Year is           : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXYears(10, Date);
	cout << "08-Subtracting 10 Year is            : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXYearsFaster(10, Date);
	cout << "09-Subtracting 10 Year(Faster) is    : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneDecade(Date);
	cout << "10-Subtracting one Decade is         : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXDecades(10, Date);
	cout << "11-Subtracting 10  Decade is         : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXDecadesFaster(10, Date);
	cout << "12-Subtracting 10 Decade (faster) is : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneCentury(Date);
	cout << "13-Subtracting one Century           : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneMillennium(Date);
	cout << "14-Subtracting one Millennium        : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


}

int main()
{
	sDate Date;
	Date = ReadFullDate();
	PrintResult(Date);

	system("pause > 0");
}