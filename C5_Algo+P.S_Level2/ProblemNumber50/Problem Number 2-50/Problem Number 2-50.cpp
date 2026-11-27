
#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber()
{
	float Number = 0;

	cout << "Please enter Number : ";
	cin >> Number;

	return Number;

}

float MySqrtFunction(float Number)
{
	return pow(Number, 0.5);

}

int main()
{

	float Number = ReadNumber();

	cout << "\nMy Sqrt Function : " << MySqrtFunction(Number);
	cout << "\nC++ Sqrt Function : " << sqrt(Number) << endl;

	return 0;
}
