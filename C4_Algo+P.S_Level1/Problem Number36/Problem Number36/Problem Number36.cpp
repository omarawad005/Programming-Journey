

#include <iostream>

using namespace std;

float ReadNumber(string Message)
{
	float Num;

	cout << Message ;
	cin >> Num;

	return Num;

}

enum enOperation
{
	Addition = '+',
	Subtaction = '-',
	Multiplication = '*',
	Division = '/',
};

enOperation ReadOperation()
{
	char Operate;
	cout << "\nPlease enter Num of Operation ? \n";
	cout << "*********************\n";
	cout << "Addition       (+) \n";
	cout << "Subtaction     (-) \n";
	cout << "Multiplication (*) \n";
	cout << "Division       (/) \n";
	cout << "*********************\n";
	cin >> Operate;

	return enOperation(Operate);
}

float CalculateOperation(int Num1, int Num2,enOperation Operate)
{
	switch (Operate)
	{
	case enOperation::Addition:
		return (Num1 + Num2);
		break;
	case enOperation::Subtaction:
		return (Num1 - Num2);
		break;
	case enOperation::Multiplication:
		return (Num1 * Num2);
		break;
	case enOperation::Division:
		return (Num1 / Num2);
		break;
	default:
		return 0;
		break;
	}

}


int main()
{

	float Num1 = ReadNumber("Please enter Number1 : ");
	float Num2 = ReadNumber("Please enter Number2 : ");
	enOperation Operate = ReadOperation();

	float Result = CalculateOperation(Num1, Num2, Operate);

	cout << "\nThe Result is :  " << Result << endl;

	return 0;
}