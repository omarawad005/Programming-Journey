#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Struct for Date
struct sDate {
    short Year;
    short Month;
    short Day;
};

// Check Leap Year
bool IsLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Compare Dates
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ?
            (Date1.Month < Date2.Month ? true :
                (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false))
            : false);
}

// Number of days in a month
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

// Check Last Day in Month
bool IsLastDayInMonth(sDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

// Check Last Month in Year
bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

// Increase Date by One Day
sDate IncreaseDateByOneDay(sDate Date) {
    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.Month)) {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        }
        else {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else {
        Date.Day++;
    }
    return Date;
}

// Difference in Days
int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false) {
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

// Day of Week Calculation
short DayOfWeekOrder(short Day, short Month, short Year) {
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(sDate Date) {
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

// Day Short Name
string DayShortName(short DayOfWeekOrder) {
    string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}

// Check End of Week, Weekend, Business Day
bool IsEndOfWeek(sDate Date) { return DayOfWeekOrder(Date) == 6; }
bool IsWeekend(sDate Date) {
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6); // Fri & Sat
}
bool IsBusinessDay(sDate Date) { return !IsWeekend(Date); }

// Days Until End of Week/Month/Year
short DaysUntilTheEndOfWeek(sDate Date) { return 6 - DayOfWeekOrder(Date); }

short DaysUntilTheEndOfMonth(sDate Date) {
    sDate EndOfMonthDate = { NumberOfDaysInAMonth(Date.Month, Date.Year), Date.Month, Date.Year };
    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(sDate Date) {
    sDate EndOfYear = { 31, 12, Date.Year };
    return GetDifferenceInDays(Date, EndOfYear, true);
}

// Read Date from User
short ReadDay() { short Day; cout << "\nEnter Day: "; cin >> Day; return Day; }
short ReadMonth() { short Month; cout << "\nEnter Month: "; cin >> Month; return Month; }
short ReadYear() { short Year; cout << "\nEnter Year: "; cin >> Year; return Year; }
sDate ReadFullDate() { sDate Date; Date.Day = ReadDay(); Date.Month = ReadMonth(); Date.Year = ReadYear(); return Date; }

// Get System Date
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

// Main
int main() {
    sDate Date = GetSystemDate();

    cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date)) << " , "
        << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    cout << "\nIs it End of Week? " << (IsEndOfWeek(Date) ? "Yes, it's Saturday." : "No, not End of Week.") << endl;
    cout << "\nIs it Weekend? " << (IsWeekend(Date) ? "Yes, it's Weekend." : "No, it's not Weekend.") << endl;
    cout << "\nIs it Business Day? " << (IsBusinessDay(Date) ? "Yes, it's Business Day." : "No, it's not Business Day.") << endl;

    cout << "\nDays Until End of Week: " << DaysUntilTheEndOfWeek(Date) << " Days." << endl;
    cout << "Days Until End of Month: " << DaysUntilTheEndOfMonth(Date) << " Days." << endl;
    cout << "Days Until End of Year: " << DaysUntilTheEndOfYear(Date) << " Days." << endl;

    system("pause>0");
    return 0;
}