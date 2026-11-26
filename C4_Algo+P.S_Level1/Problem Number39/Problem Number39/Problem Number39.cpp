
#include <iostream>
using namespace std;

int ReadNumber(string Message)
{
	int Number;

	cout << "Please enter " << Message ;
	cin >> Number;

	return Number;
}

float CalculateTheReminder(float TotalBaill, float CashPaid)
{
	return CashPaid - TotalBaill;
}

void PrintResult(float Remainder)
{
	cout << "The Remainder ==> " << Remainder << endl;
}


int main()
{
  
	int TotalBill = ReadNumber("TotalBill : ");
	int CashPaid = ReadNumber("CashPaid  : ");
	

	cout << "\nTotalBill = " << TotalBill << endl;
	cout << "CashPaid  = " << CashPaid << endl;
	cout << "*************************************\n";
	PrintResult(CalculateTheReminder(TotalBill, CashPaid));


	return 0;
}

