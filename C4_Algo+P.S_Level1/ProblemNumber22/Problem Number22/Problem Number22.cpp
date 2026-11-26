
#include <iostream>
#include <cmath>
using namespace std;

void ReadNumber(float& A, float& B)
{
	cout << "Please enter A : ";
	cin >> A;
	
	cout << "Please enter B : ";
	cin >> B;

}

float CalculateArea(float A, float B)
{
	float Pi = 3.14;
	float Area;
	Area = Pi * (pow(B, 2) / 4) * (2 * A - B) / (2 * A + B);
	return Area;

}

void PrfloatArea(float Result)
{
	cout << "\nArea ==> " << Result << endl;
}


int main()
{

	float A, B;
	ReadNumber(A, B);
	PrfloatArea(CalculateArea(A, B));

	return 0;
}