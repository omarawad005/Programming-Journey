

#include <iostream>
using namespace std;

float ReadNumberFromUser(string Message)
{
	float Num;
	cout << Message;
	cin >> Num;
	return Num;
}

float CalculateNumberOFMonth(float LA, float MP)
{
	return float(LA / MP);
}


int main()
{

	float LoanAmount = ReadNumberFromUser("Please enter Loan Amount : ");
	float MonthlyPayment = ReadNumberFromUser("Please enter Monthly Payment : ");
	cout << "\n" << CalculateNumberOFMonth(LoanAmount, MonthlyPayment) << " Months ? \n";

	return 0;
}