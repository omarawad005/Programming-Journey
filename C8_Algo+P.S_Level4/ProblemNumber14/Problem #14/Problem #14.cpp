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

short DaysInMonth(short Month, short Year)
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
        DayNumberInYear += DaysInMonth(i, Year);

    DayNumberInYear += Day;

    return DayNumberInYear;
}

//================ Problem#13 =================//

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return
        (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) ? true : false : false) : false;
}
int main()
{
    sDate Date1, Date2;
    cout << "//===================Date1==================//\n";
    Date1 = ReadFullDate();
    cout << "\n//===================Date2==================//\n";
    Date2 = ReadFullDate();

    if (IsDate1EqualDate2(Date1, Date2))
    {
        cout << "\nYes, Date1 is Eqaul Date2.";
    }
    else
    {
        cout << "\nNo, Date1 is Not Equla than Date2.";
    }

    system("pause > 0");
}