#include <iostream>
#include <string>
using namespace std;

struct sDate
{
    short Year;
    short Month;
    short Day;
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

// «· Õﬁﬁ „‰ «·”‰… «·ﬂ»Ì”…
bool IsLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// ⁄œœ «·√Ì«„ ›Ì «·‘Â—
short NumberOfDaysInAMonth(short Month, short Year) {
    int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

// “Ì«œ… ÌÊ„ Ê«Õœ ·· «—ÌŒ
sDate IncreaseDateByOneDay(sDate Date) {
    if (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year)) {
        Date.Day = 1;
        if (Date.Month == 12) {
            Date.Month = 1;
            Date.Year++;
        }
        else {
            Date.Month++;
        }
    }
    else {
        Date.Day++;
    }
    return Date;
}

//  — Ì» √Ì«„ «·√”»Ê⁄ (0=Sun, ..., 6=Sat)
short DayOfWeekOrder(sDate Date) {
    short a = (14 - Date.Month) / 12;
    short y = Date.Year - a;
    short m = Date.Month + 12 * a - 2;
    return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
}

// «”„ «·ÌÊ„ «·„Œ ’—
string DayShortName(short DayOfWeekOrder) {
    string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}

// «· Õﬁﬁ ≈–« ﬂ«‰ ÌÊ„ ⁄ÿ·… ‰Â«Ì… «·√”»Ê⁄
bool IsWeekend(sDate Date) {
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6); // Fri & Sat
}

// Õ”«»  «—ÌŒ ‰Â«Ì… «·≈Ã«“… „⁄  Ã«Ê“ ⁄ÿ·«  ‰Â«Ì… «·√”»Ê⁄
sDate GetVacationEndDate(sDate DateFrom, short VacationDays) 
{
    sDate CurrentDate = DateFrom;
    short DaysLeft = VacationDays;
    while (IsWeekend(CurrentDate))
    {
        CurrentDate = IncreaseDateByOneDay(CurrentDate);
    }

    while (DaysLeft > 0) 
    {
        CurrentDate = IncreaseDateByOneDay(CurrentDate);
        if (!IsWeekend(CurrentDate)) 
        { // ›ﬁÿ «·√Ì«„ «·⁄«œÌ…  ıŒ’„
            DaysLeft--;
        }
    }
    return CurrentDate;
}

// ÿ»«⁄…  ›«’Ì· ‰Â«Ì… «·≈Ã«“…
void PrintVocationDetails(sDate Vacation) {
    string DayName = DayShortName(DayOfWeekOrder(Vacation));
    cout << DayName << ", ";
    cout << Vacation.Day << "/" << Vacation.Month << "/" << Vacation.Year << endl;
}

int main() {
    sDate DateFrom;
    cout << "Vacation : ";
    DateFrom = ReadFullDate();

    short VacationDays;
    cout << "\nPlease enter vacation days? ";
    cin >> VacationDays;

    cout << "\nReturn Date : ";
    sDate DateTo = GetVacationEndDate(DateFrom, VacationDays);
    PrintVocationDetails(DateTo);

    system("pause > 0");
}