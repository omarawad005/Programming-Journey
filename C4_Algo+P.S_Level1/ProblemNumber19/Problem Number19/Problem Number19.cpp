

#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
	float D;

	cout << "Please enter D : ";
	cin >> D;

	return D;
}

float CalculateArea(float D)
{
	float Pi = 3.141592653589793238;
	float Area = (pow(D, 2) * Pi) / 4;
	return Area;
}

void PrintArea(float Result)
{
	cout << "\nArea = " << Result << endl;
}

int main()
{
	PrintArea(CalculateArea(ReadNumber()));
	return 0;
}
