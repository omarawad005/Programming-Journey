/*
	

#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Please enter a Number : ";
	cin >> Number;
	return Number;
	
}


float CalculateHalfNubmer(float Number)
{
	float HalfNumber = Number / 2;
	return HalfNumber;
}

void PrintHalfNumber(int Number)
{
	// My solution 
	//cout << "\nHalf of " << Number << " is ==> " << CalculateHalfNubmer(Number) << endl;
	string Result = "Half of " + to_string(Number) + " is " + to_string(CalculateHalfNubmer(Number)) ;
	cout << Result << endl;

}


int main()
{

	PrintHalfNumber(ReadNumber());

	return 0;
}
*/

#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Enter a Number  : ";
	cin >> Number;

	return Number;
}

float CalculateHalfofNumber(int Num)
{
	return (float) Num / 2;

}
void PrintNumber(int Num)
{
	string Result;
	Result = "Half Of [" + to_string(Num) + "] Is : " + to_string(CalculateHalfofNumber(Num))
		; cout << Result << endl;


}

int main()
{

	PrintNumber(ReadNumber());

	return 0;
}