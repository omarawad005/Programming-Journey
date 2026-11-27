#include <iostream>
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

void SwapDates(sDate& Date1, sDate& Date2)
{
    sDate TempDate;
    
    TempDate.Year = Date1.Year;
    TempDate.Month = Date1.Month;
    TempDate.Day = Date1.Day;

    Date1.Year = Date2.Year;
    Date1.Month = Date2.Month;
    Date1.Day = Date2.Day;


    Date2.Year = TempDate.Year;
    Date2.Month = TempDate.Month;
    Date2.Day = TempDate.Day;

}

int GetDifferanceInDay(sDate Date1, sDate Date2, bool IncloudEndDay = false)
{
    int Days = 0;
    int SwapFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }
    
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
   
   
   

    return IncloudEndDay ? (++Days)*SwapFlagValue : Days*SwapFlagValue;
}

int main()
{
    sDate Date1, Date2;
    cout << "//===================Date1==================//\n";
    Date1 = ReadFullDate();
    cout << "\n//===================Date2==================//\n";
    Date2 = ReadFullDate();


    cout << "\n\nDiffernce is "
        << GetDifferanceInDay(Date1, Date2);
    cout << "\nDiffernce (Include End Day ) : "
        << GetDifferanceInDay(Date1, Date2, true);

    system("pause > 0");
}