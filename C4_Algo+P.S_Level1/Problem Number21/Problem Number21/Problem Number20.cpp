

#include <iostream>
#include <cmath>
using namespace std;

void ReadNumber(int& L)
{
	cout << "Please enter L : ";
	cin >> L;
}

float CalculateArea(int L)
{
	float Pi = 3.14;
	float Area = (pow(L, 2)) / (Pi * 4);
	return Area;
}

void PrintArea(float Result)
{
	cout << "\nArea = " << Result << endl;
}

int main()
{

	int L;
	ReadNumber(L);
	PrintArea(CalculateArea(L));
	return 0;
}
