#include <iostream>
#include <string>
using namespace std;

struct sDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriod
{
    sDate StartDate;
    sDate EndDate;
};

// ﬁ—«¡… «· «—ÌŒ »«·ﬂ«„·
short ReadDay() {
    short Day; cout << "\nPlease Enter A Day   : "; cin >> Day; return Day;
}
short ReadMonth() {
    short Month; cout << "Please Enter A Month : "; cin >> Month; return Month;
}
short ReadYear() {
    short Year; cout << "Please Enter A Year  : "; cin >> Year; return Year;
}
sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

stPeriod ReadPeriod()
{
    stPeriod Period;

    cout << "Enter Start Date : \n";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End  Date : \n";
    Period.EndDate = ReadFullDate();

    return Period;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfADaysInAMonth(short Month, short Year)
{
    short days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (Month == 2 && IsLeapYear(Year))
        return 29;

    return days[Month - 1];
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    if (Date1.Year < Date2.Year) return true;
    if (Date1.Year > Date2.Year) return false;

    if (Date1.Month < Date2.Month) return true;
    if (Date1.Month > Date2.Month) return true;

    return Date1.Day < Date2.Day;
}

bool IsLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfADaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
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

int GetDifferanceInDay(sDate Date1, sDate Date2, bool IncloudEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncloudEndDay ? ++Days : Days;
}

short CalCulatePeriodLength(stPeriod Period, bool IncloudEndDay = false)
{
    return GetDifferanceInDay(Period.StartDate, Period.EndDate, IncloudEndDay);
}


int main()
{
    stPeriod PeriodOne;

    cout << "Period_1\n";
    PeriodOne = ReadPeriod();

    cout << "\nPeriod Length is : ";
    cout << CalCulatePeriodLength(PeriodOne);

    cout << "\nPeriod Length (Includ End Day) is : ";
    cout << CalCulatePeriodLength(PeriodOne, true);

    system("pause > 0");
}