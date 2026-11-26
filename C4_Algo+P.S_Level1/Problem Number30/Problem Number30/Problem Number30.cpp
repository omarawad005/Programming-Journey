
#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please enter Number : ";
	cin >> Number;

	return Number;

}

int FactorialOfNumber(int Number)
{
	int Fact = 1;

	for (int i = Number; i >= 1; i--)
	{
		
			Fact *= i;
	}

	return Fact;
}

void PrintFactorialNumber(int Num)
{
	cout << "\nFactorial = " << FactorialOfNumber(Num) << endl;
}

int main()
{
	PrintFactorialNumber(ReadNumber());
	return 0;
}