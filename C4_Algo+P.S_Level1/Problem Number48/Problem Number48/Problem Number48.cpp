
#include <iostream>
using namespace std;

int ReadFromUser(string Message)
{
    // harrram
    int Number = 0;

    do
    {
        cout << Message;
        cin >> Number;
    } while (!(Number > 0));

    return Number;
}

float CalcualteMonthlyPayment(int LoanAmount, int Month)
{
    return LoanAmount / Month;
}

int main()
{
    int LoanAmount = ReadFromUser("Please enter Loan Amount :  ");
    int Month = ReadFromUser("Please enter Number of Months :  ");

    cout << "\nMonthly Payment : "
         << CalcualteMonthlyPayment(LoanAmount, Month);
    cout << endl;

    return 0;
}

