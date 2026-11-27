
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

float MyCeilFunction(float Number)
{
	if (Number > 0)
	{
		return int(++Number);
	}
	else
	{
		return int(Number);
	}
}

int main()
{

	float Number = ReadNumber();

	cout << "\nMy Ceil Function : " << MyCeilFunction(Number);
	cout << "\nC++ Ceil Function : " << ceil(Number) << endl;

	return 0;
}
