

#include <iostream>

using namespace std;

int ReadNumberOFHourse(string Message)
{

	int NumOfHourse;
	do
	{
		cout << Message;
		cin >> NumOfHourse;
	} while (NumOfHourse < 0);

	return NumOfHourse;
}

float CalculateNumberOfWeeks(float Number)
{
	return float(Number / (24 * 7));
}

float CalculateNumberOfDays(float Number)
{
	return float(Number / 24);

}


int main()
{
	float NumOfHourse = ReadNumberOFHourse("Please enter Number oF Hourse : ");
	cout <<"\n" << CalculateNumberOfWeeks(NumOfHourse) << " Weeks ";
	cout <<"\n" << CalculateNumberOfDays(NumOfHourse) << " Days ";
	
	


	return 0;
}