
#include <iostream>
#include <cmath>

using namespace std;

void ReadNumber(int& a,int& b,int& c)
{
	cout << "Please enter a : ";
	cin >> a;
	
	cout << "Please enter b : ";
	cin >> b;
	
	cout << "Please enter c : ";
	cin >> c;

}

float CalculateArea(int a, int b, int c)
{
	float P;
	P = (a + b + c) / 2;

	float Pi = 3.14;

	float X;
	X = (a * b * c) / (4 * sqrt(P * (P - a) * (P - b) * (P - c)));
	// X *= X;

    float Area = Pi * pow(X, 2);

	return Area;

	

}

void PrintResult(float Result)
{
	cout << "\n Area = " << Result << endl;
}


int main()
{
	int a, b, c;
	ReadNumber(a, b, c);
	PrintResult(CalculateArea(a, b, c));


	return 0;
}

