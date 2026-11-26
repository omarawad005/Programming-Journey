

#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
	float R;
	cout << "Please enter R : ";
	cin >> R;
	return R;
}

float CalculateArea(int R)
{
	float Pi = 3.141592653589793238;
	float Area = pow(R, 2) * Pi;
	return Area;
}

void PrintArea(float R)
{
	cout << "\nArea = " << R << endl;
}

int main()
{

	PrintArea(CalculateArea(ReadNumber()));

	return 0;
}
