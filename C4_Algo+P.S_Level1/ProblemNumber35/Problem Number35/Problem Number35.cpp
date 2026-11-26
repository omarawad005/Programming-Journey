

#include <iostream>
using namespace std;

struct stReadMoney
{
	float Penny;
	float Nickle;
	float Dime;
	float Quater;
	float Dollar;

};

stReadMoney ReadMoney()
{
	stReadMoney MoneyInput;
	cout << "Please enter Penny  : ";
	cin >> MoneyInput.Penny;
	
	cout << "Please enter Nickle : ";
	cin >> MoneyInput.Nickle;
	
	cout << "Please enter Dime   : ";
	cin >> MoneyInput.Dime;
	
	cout << "Please enter Quater : ";
	cin >> MoneyInput.Quater;
	
	cout << "Please enter Dollar : ";
	cin >> MoneyInput.Dollar;

	return MoneyInput;
}

float CalculatTotalPenny(stReadMoney Y)
{
	// TP ==> Total Penny : 
	float TP;
	TP = Y.Penny + Y.Nickle * 5 + Y.Dime * 10 + Y.Quater * 25 + Y.Dollar * 100;

	return TP;

}

void PrintResult(float TotalPenny)
{
	
	cout << "\nToTal Penny  ==> " << TotalPenny << endl;
	cout << "ToTal Dollar ==> " << TotalPenny / 100 << endl;

}


int main()
{
	
	PrintResult(CalculatTotalPenny(ReadMoney()));

	return 0;
}

