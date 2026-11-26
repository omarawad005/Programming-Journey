

#include <iostream>
#include <string>

using namespace std;

int ReadNumber(string Message)
{
	int Number;
	cout << Message;
	cin >> Number;

	return Number;
}

float SumNumber()
{
	int Sum = 0, Num = 0, Counter = 1;

	do
	{
		Num = ReadNumber("Please enter Number " + to_string(Counter) + " : ");
		if (Num == -99)
		{
			break;
		}
		Sum += Num;
		Counter++;

	} while (Num != -99);

	return Sum;

}


int main()
{
	cout << "\nResult = " << SumNumber() << endl;


	return 0;
}