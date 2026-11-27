
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

float MyFloorFunction(float Number)
{
	if (Number > 0)
	{
		return int(Number);
	}
	else
	{
		return int(--Number);
	}
}

int main()
{
	
	float Number = ReadNumber();

	cout << "\nMy Floor Function : " << MyFloorFunction(Number);
	cout << "\nC++ Floor Function : " << floor(Number) << endl;

	return 0;
}
