
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
	short Month  = 0;
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
	return (Month == 2) ? (IsLeapYear(Year) ? 29    : 28)    : NumOfDays[Month - 1];
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

bool IsLastDay(sDate Date)
{
	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}
bool IsLastMonth(short Month)
{
	return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
	if (IsLastDay(Date))
	{
		if (IsLastMonth(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;

}
sDate IncreasDateByXDay(short Days ,sDate Date)
{
	short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
	short MonthDays = 0;
	Date.Month = 1;
	while (true)
	{
		MonthDays = NumberOfDaysInMonth(Date.Month,Date.Year);
		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}
sDate IncreasDateByOneWeek(sDate Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}
sDate IncreasDateByXWeeks(short Weeks,sDate Date)
{
	for (int i = 0; i < Weeks; i++)
	{
		Date = IncreasDateByOneWeek(Date);
	}
	return Date;
}
sDate IncreasDateByOneMonth(sDate Date)
{
	Date.Month++;
	if (Date.Month  > 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}
sDate IncreasDateByXMonth(short Months,sDate Date)
{
	for (int i = 0; i < Months; i++)
	{
		Date = IncreasDateByOneMonth(Date);
	}

	return Date;
}
sDate IncreasDateByOneYear(sDate Date)
{
	Date.Year++;
	return Date;
}
sDate IncreasDateByXYears(short Years, sDate Date)
{
	for (int i = 1; i <= Years; i++)
	{
		Date = IncreasDateByOneYear(Date);
	}
	return Date;
}
sDate IncreasDateByXYearsFaster(short Years, sDate Date)
{
	Date.Year += Years;
	return Date;
}
sDate IncreasDateByOneDecade(sDate Date)
{
	Date.Year += 10;
	return Date;
}
sDate IncreasDateByXDecades(short Decades, sDate Date)
{
	for (int i = 1; i <= Decades ; i++)
	{
		Date = IncreasDateByOneDecade(Date);
	}

	return Date;
}
sDate IncreasDateByXDecadesFaster(short Decades, sDate Date)
{
	Date.Year += Decades * 10;
	return Date;
}
sDate IncreasDateByOneCentury(sDate Date)
{
	Date.Year += 100;
	return Date;
}
sDate IncreasDateByOneMillennium(sDate Date)
{
	Date.Year += 1000;
	return Date;
}

void PrintResult(sDate Date)
{
	cout << "\n\nDate after :\n\n";

	Date = IncreaseDateByOneDay(Date);
	cout << "01-Adding one day is            : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = IncreasDateByXDay(10, Date);
	cout << "02-Adding 10 days is            : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreasDateByOneWeek(Date);
	cout << "03-Adding One Week is           : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreasDateByXWeeks(10,Date);
	cout << "04-Adding 10 Weeks is           : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreasDateByOneMonth(Date);
	cout << "05-Adding One Month is          : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreasDateByXMonth(5,Date);
	cout << "06-Adding 5 Month is            : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreasDateByOneYear(Date);
	cout << "07-Adding One Year is           : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreasDateByXYears(10, Date);
	cout << "08-Adding 10 Year is            : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = IncreasDateByXYearsFaster(10, Date);
	cout << "09-Adding 10 Year(Faster) is    : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = IncreasDateByOneDecade(Date);
	cout << "10-Adding one Decade is         : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = IncreasDateByXDecades(10,Date);
	cout << "11-Adding 10  Decade is         : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = IncreasDateByXDecadesFaster(10,Date);
	cout << "12-Adding 10 Decade (faster) is : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	
	Date = IncreasDateByOneCentury(Date);
	cout << "13-Adding one Century           : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreasDateByOneMillennium(Date);
	cout << "14-Adding one Millennium        : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


}

int main()
{
	sDate Date;
	Date = ReadFullDate();
	PrintResult(Date);

	system("pause > 0");
}