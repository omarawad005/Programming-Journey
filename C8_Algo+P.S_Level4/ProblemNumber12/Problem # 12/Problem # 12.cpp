#include <iostream>
#include <string>
#include <limits>

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

short ReadDay()
{
    short Day;

    cout << "\nPlease enter a Day To Check   : ";
    cin >> Day;

    return Day;
}

short ReadDaysToAdd()
{
    short Days;
    cout << "\nHow Many Days To Add : ";
    cin >> Days;
    return Days;
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

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (int i = 1; i < Month; i++)
        TotalDays += DaysInMonth(i, Year);

    TotalDays += Day;

    return TotalDays;
}

//================ ADD DAYS =================//

sDate DateAddDays(short Days, sDate Date)
{
    short RemainingDays =
        Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);


    Date.Month = 1;
    short MonthDays = 0;

    while (true)
    {
        MonthDays = DaysInMonth(Date.Month, Date.Year);

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

//================ OUTPUT =================//

void PrintDate(sDate Date)
{
    cout << "\nNew Date is : "
        << Date.Day << "/"
        << Date.Month << "/"
        << Date.Year << endl;
}

//================ MAIN =================//

int main()
{
    sDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();

    Date = DateAddDays(Days, Date);

    PrintDate(Date);

    system("pause > 0");
}