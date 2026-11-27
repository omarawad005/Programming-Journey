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


bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ?
            (Date1.Month < Date2.Month ? true :
                (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false))
            : false);
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

bool IsDateInPeriod(stPeriod Period, sDate Date)
{
    if (IsDate1BeforeDate2(Period.EndDate, Date)) return false;
    if (IsDate1BeforeDate2(Date, Period.StartDate)) return false;
    return true;
}


int main()
{
    stPeriod PeriodOne;
    sDate Date;

    cout << "Period_1\n";
    PeriodOne = ReadPeriod();

    cout << "\nEnter Date : \n";
    Date = ReadFullDate();


    if (IsDateInPeriod(PeriodOne, Date))
        cout << "\nyes, Date In Period\n";
    else
        cout << "\nno, Date Not In Period\n";


    system("pause > 0");
}