

#include <iostream>
#include <cmath>
using namespace std;

int MyAbsFunction(int Number)
{
	if (Number > 0)
	{
		return Number;
	}
	else
	{
		return Number * - 1;
	}
}


int main()
{

	int Number = -10;
	cout << "My  abs Result : " << MyAbsFunction(Number) << endl;
	cout << "C++ abs Result : " << abs(Number);
	cout << "\n\n";
	return 0;
}
