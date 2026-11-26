
#include <iostream>

using namespace std; 

int ReadTotalSales()
{
	// TS ==> Total Sales
	int TS;
	cout << "Please enter your Toatal Sales : ";
	cin >> TS;

	return TS;
}

float GetCommissionPercentage(int TS)
{
	if (TS > 1000000)
		return .01;
	else if (TS > 500000)
		return .02;
	else if (TS > 100000)
		return .03;
	else if (TS > 50000)
		return .05;
	else
		return 0;
}

float CalculateToatalCommission(int TS)
{
	return (GetCommissionPercentage(TS) * TS);
}


int main()
{

	float ToatalSalse = ReadTotalSales();

	cout << "\nCommission Percentage : " << GetCommissionPercentage(ToatalSalse) << endl;
	cout << "\nTotal Commission : " << CalculateToatalCommission(ToatalSalse) << endl;

	return 0;
}