#include <iostream>
#include <string>
using namespace std;

struct sDate 
{
    short Year;
    short Month;
    short Day;
};

short ReadDay() 
{ 
    short Day; cout << "\nPlease Enter A Day   : "; cin >> Day; return Day; 
}
short ReadMonth() 
{ 
    short Month;
    cout << "Please Enter A Month : "; cin >> Month; 
    return Month; 
}
short ReadYear() 
{ 
    short Year; 
    cout << "Please Enter A Year  : "; 
    cin >> Year; 
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


bool IsLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) 
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ?
            (Date1.Month < Date2.Month ? true :
                (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false))
            : false);
}
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}
bool IsLastDayInMonth(sDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}
bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

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

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false) {
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

short DayOfWeekOrder(short Day, short Month, short Year) {
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(sDate Date) 
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder) {
    string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}

bool IsEndOfWeek(sDate Date) { return DayOfWeekOrder(Date) == 6; }
bool IsWeekend(sDate Date) {
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6); // Fri & Sat
}
bool IsBusinessDay(sDate Date) { return !IsWeekend(Date); }

short DaysUntilTheEndOfWeek(sDate Date) { return 6 - DayOfWeekOrder(Date); }

short DaysUntilTheEndOfMonth(sDate Date) {
    sDate EndOfMonthDate = { NumberOfDaysInAMonth(Date.Month, Date.Year), Date.Month, Date.Year };
    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(sDate Date) {
    sDate EndOfYear = { 31, 12, Date.Year };
    return GetDifferenceInDays(Date, EndOfYear, true);
}

short CalculationVocationDays(sDate DateFrom, sDate DateTo)
{
    short NumOfVacationDays = 0;
    while (IsDate1BeforeDate2(DateFrom,DateTo))
    {
        if (IsBusinessDay(DateFrom))
        {
            NumOfVacationDays++;
        }
            DateFrom = IncreaseDateByOneDay(DateFrom);
        
    }
    return NumOfVacationDays;
}

void PrintVocationDetails(sDate Vacation)
{
    string DayName = DayShortName(DayOfWeekOrder(Vacation));
    cout << DayName << ", ";
    cout << Vacation.Day << "/" << Vacation.Month << "/" << Vacation.Year << endl;
}

int main() 
{
    sDate DateFrom, DateTo;

    cout << "Vacation Start : ";
    DateFrom = ReadFullDate();

    cout << "\n\nVacation End   : ";
    DateTo = ReadFullDate();


    cout << "\nVacation From : ";
    PrintVocationDetails(DateFrom);

    cout << "\nVacation To   : ";
    PrintVocationDetails(DateTo);


    short VacationDays = CalculationVocationDays(DateFrom,DateTo);
    cout << "\nActucal Vacation Days is : " << VacationDays;


    system("pause > 0");
}