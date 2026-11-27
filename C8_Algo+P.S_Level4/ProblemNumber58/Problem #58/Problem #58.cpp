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

bool IsOverLap(stPeriod P1, stPeriod P2)
{
    if (IsDate1BeforeDate2(P1.EndDate, P2.StartDate)) return false;
    if (IsDate1BeforeDate2(P2.EndDate, P1.StartDate)) return false;
    return true;
    /*
        bool IsOverLap(stPeriod P1, stPeriod P2)
        {
            return !(IsDate1BeforeDate2(P1.EndDate, P2.StartDate) ||
                     IsDate1BeforeDate2(P2.EndDate, P1.StartDate));
        }
    */
}


int main()
{
    stPeriod PeriodOne;
    stPeriod PeriodTwo;

    cout << "Period_1\n";
    PeriodOne = ReadPeriod();
    cout << "\nPeriod_2\n";
    PeriodTwo = ReadPeriod();

    if (IsOverLap(PeriodOne, PeriodTwo))
        cout << "\nYes, Period OverLap.\n";
    else
        cout << "\nNo, Period Not OverLap.\n";


    system("pause > 0");
}