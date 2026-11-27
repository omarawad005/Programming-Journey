#include <iostream>
#include <string>
using namespace std;
short DaysInMonth(short Month, short Year);

struct sDate
{
    short Year = 0;
    short Month = 0;
    short Day = 0;
};

short ReadYear()
{
    short Year = 0;

    do
    {
        cout << "Please enter a Year To Check  : ";
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
short ReadDay(short Month, short Year)
{
    short Day;
    do
    {
        cout << "\nPlease enter a Day To Check   : ";
        cin >> Day;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid day! Please enter a valid day for month " << Month << ": ";
            cin >> Day;
        }

    } while (Day <= 0 || Day > DaysInMonth(Month, Year));



    return Day;
}

bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short DaysInMonth(short Month, short Year)
{
    short days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (Month == 2 && IsLeapYear(Year))
        return 29;

    return days[Month - 1];
}


short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{

    short DayNumberInYear = 0;
    for (int i = 1; i < Month; i++)
    {
        DayNumberInYear += DaysInMonth(i, Year);
    }
    DayNumberInYear += Day;

    return DayNumberInYear;

}

sDate GetDateFromDayOrderInAYear(short Year, short Days)
{
    sDate Date;
    Date.Year = Year;

    short RemainsDay = Days;
    short MonthDays;
    Date.Month = 1;
    while (true)
    {
        MonthDays = DaysInMonth(Date.Month, Year);
        if (RemainsDay > MonthDays)
        {
            RemainsDay -= MonthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = RemainsDay;
            break;
        }
    }
    return Date;
}

void PrintDayOfYear(short Day, short Month, short Year)
{
    short TotalDays = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
    cout << "\nThe date is day number [" << TotalDays
        << "] of the year.\n";
    sDate Date = GetDateFromDayOrderInAYear(Year, TotalDays);
    
    cout << "The Date For [" << TotalDays << "] is : ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

}


int main()
{
    short Year, Month, Day;

    Year = ReadYear();
    Month = ReadMonth();
    Day = ReadDay(Month, Year);

    PrintDayOfYear(Day, Month, Year);

    system("pause > 0");
}
