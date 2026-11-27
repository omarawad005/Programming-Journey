#include <iostream>
#include <string>
using namespace std;

struct sDate
{
    short Year;
    short Month;
    short Day;
};
enum enCompareDate
{
    Before = -1,
    Equal = 0,
    After = 1

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
bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return Date1.Year == Date2.Year &&
        Date1.Month == Date2.Month &&
        Date1.Day == Date2.Day;
}
bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
}

enCompareDate CompareDate(sDate Date1,sDate Date2)
{
    return  (IsDate1AfterDate2(Date1, Date2))?
        enCompareDate::After :(IsDate1BeforeDate2)? enCompareDate::Before:enCompareDate::Equal;
    
}

void PrintResult(sDate Date1, sDate Date2)
{
    enCompareDate CompareResult = CompareDate(Date1, Date2);
    
    switch (CompareResult)  
    {
    case Before:
        cout << "\n\nCompare Result = " << enCompareDate::Before << endl;
        break;
    case Equal:
        cout << "\n\nCompare Result = " << enCompareDate::Equal << endl;
        break;
    case After:
        cout << "\n\nCompare Result = " << enCompareDate::After << endl;
        break;
    }

}

int main()
{

    sDate Date1, Date2;

    Date1 = ReadFullDate();
    Date2 = ReadFullDate();

    PrintResult(Date1, Date2);


    system("pause > 0");
}