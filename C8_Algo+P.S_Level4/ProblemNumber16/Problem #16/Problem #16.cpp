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

short NumberOfDaysInMonth(short Month, short Year)
{
    short days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (Month == 2 && IsLeapYear(Year))
        return 29;

    return days[Month - 1];
}

short GetDayNumberInYear(short Day, short Month, short Year)
{
    short DayNumberInYear = 0;

    for (int i = 1; i < Month; i++)
        DayNumberInYear += NumberOfDaysInMonth(i, Year);

    DayNumberInYear += Day;

    return DayNumberInYear;
}

//================ Problem#16 =================//
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
            Date.Day++;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}




int main()
{
    sDate Date1, Date2;
    cout << "//===================Date1==================//\n";
    Date1 = ReadFullDate();

    Date1 = IncreaseDateByOneDay(Date1);

    cout << "\nNew Date is : " << Date1.Day
        << "/" << Date1.Month << "/"
        << Date1.Year << endl;

    
    system("pause > 0");
}