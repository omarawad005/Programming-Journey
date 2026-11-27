#include <iostream>
#include <string>
using namespace std;

bool IsLeapYear(int Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int DaysInMonth(int Month, int Year)
{
    int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (Month == 2 && IsLeapYear(Year))
        return 29;

    return days[Month - 1];
}

int DayOrder(int Day, int Month, int Year)
{
    int a = (14 - Month) / 12;
    int y = Year - a;
    int m = Month + 12 * a - 2;

    return (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

string MonthName(int Month)
{
    string months[] =
    {
        "Jan","Feb","Mar","Apr","May","Jun",
        "Jul","Aug","Sep","Oct","Nov","Dec"
    };

    return months[Month - 1];
}

void PrintMonthCalendar(int Month, int Year)
{
    cout << "\n---------------- " << MonthName(Month) << " ----------------\n";
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int Current = DayOrder(1, Month, Year);
    int NumberOfDays = DaysInMonth(Month, Year);

    int i = 0;

    // ãÓÇÝÇÊ ÞÈá Ãæá íæã
    for (i = 0; i < Current; i++)
        printf("%5s", "");

    // ØÈÇÚÉ ÇáÃíÇã
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            cout << "\n";
        }
    }

    // áæ ÇáÔåÑ ÇäÊåì æáÓå Ýí äÕ ÇáÓØÑ
    if (i != 0)
        cout << "\n";

    cout << "-------------------------------------\n";
}

void PrintYearCalendar(short Year)
{
    printf("\n\n-----------------------------------\n");
    cout << "\tCalendar-" << Year << endl;
    printf("-----------------------------------\n");

    for (int i = 1; i <= 12; i++)
    {
        cout << "\n";
        PrintMonthCalendar(i, Year);
        cout << "\n";
    }
}

int main()
{
    int Year;

    cout << "Please enter a year? ";
    cin >> Year;

    PrintYearCalendar(Year);


    return 0;
}
