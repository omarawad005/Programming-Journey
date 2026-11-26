
#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Enter Number : ";
	cin >> Num;

	return Num;

}

int ReadPower()
{
	int Pow;

	cout << "Enter Power : ";
	cin >> Pow;

	return Pow;

}

int CalculatePowerWithMathFunction(int Num, int Pow)
{
	return pow(Num, Pow);
}

int CalculatePowerWithFunction(int Num, int Pow)
{
	

	int x = 1;

	if (Pow == 0)
	{
		return 1;
	}

	for (int i = 0; i < Pow; i++)
	{
		x *= Num;
	}

	return x;

}

void PrintNumber(int Num, int Pow)
{
	cout << "---------------------------------------------\n";
	cout << "Result with Math Function : " << CalculatePowerWithMathFunction(Num, Pow) << endl;
	cout << "---------------------------------------------\n";
	cout << "Result without Math Function : " << CalculatePowerWithFunction(Num, Pow) << endl;

}


int main()
{

	PrintNumber(ReadNumber(), ReadPower());


	return 0;
}