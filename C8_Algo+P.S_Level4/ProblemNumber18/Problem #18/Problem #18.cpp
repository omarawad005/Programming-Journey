#pragma warning(disable : 4996)

#include <iostream>
#include <limits>
#include <ctime>
#include <string>

using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

//================ INPUT =================//

short ReadYear()
{
    short Year = 0;

    do
    {
        cout << "\nPlease enter a Year To Check  : ";
        cin >> Year;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid Year! Please enter a Year To Check  : ";
            cin >> Year;
        }

    } while (Year <= 0);

    return Year;
}

short ReadMonth()
{
    short Month;

    do
    {
        cout << "\nPlease enter a Month To Check : ";
        cin >> Month;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid Month! Please enter a Month To Check : ";
            cin >> Month;
        }

    } while (Month <= 0 || Month > 12);

    return Month;
}

short ReadDay()
{
    short Day;

    cout << "\nPlease enter a Day To Check   : ";
    cin >> Day;

    return Day;
}

sDate ReadFullDate()
{
    sDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

//================ DATE LOGIC =================//

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

short NumberOfDaysInAYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (int i = 1; i < Month; i++)
        TotalDays += NumberOfADaysInAMonth(i, Year);

    TotalDays += Day;

    return TotalDays;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    if (Date1.Year < Date2.Year) return true;
    if (Date1.Year > Date2.Year) return false;

    if (Date1.Month < Date2.Month) return true;
    if (Date1.Month > Date2.Month) return false;

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


sDate GetSystemDate()
{
    sDate Date;

    time_t t = time(0);
    tm* now = localtime(&t);

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;

    return Date;

}

int main()
{
    sDate Date1, Date2;
 
    cout << "//===================Date1==================//\n";
    Date1 = ReadFullDate();
    Date2 = GetSystemDate();
    cout << "\nYour Age is : " << GetDifferanceInDay(Date1, Date2) << " Day(s).";

    system("pause > 0");
}