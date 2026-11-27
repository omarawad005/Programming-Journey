
#include <iostream>
#include <cstdlib>
using namespace std;


int RandomNumber(int From, int To)
{
	int randNumber = rand() % (To - From + 1) + From;

	return randNumber;
}

void FillArrayElement(int Arr[100], int& arrlength)
{
	cout << "Please enter Number : ";
	cin >> arrlength;

	for (int i = 0; i < arrlength; i++)
	{
		Arr[i] = RandomNumber(1, 100);
	}

}

void PrintArrayElement(int Arr[100], int arrlength)
{
	for (int i = 0; i < arrlength; i++)
	{
		cout << Arr[i] << " ";

	}
}

int CountOddNumber(int Arr[100], int arrlength)
{
	int Counter = 0;
	for (int i = 0; i < arrlength; i++)
	{
		if (Arr[i] % 2 != 0)
		{
			Counter++;
		}
	}
	return Counter;
}


int main()
{
	srand((unsigned)time(NULL));

	int ArrSource[100], length = 0;

	FillArrayElement(ArrSource, length);

	cout << "\nArray 1 Element :  \n";
	PrintArrayElement(ArrSource, length);


	cout << "\n\nOdd Number Count is : ";
	cout << CountOddNumber(ArrSource, length);
	
	
	cout << endl;
	cout << endl;
	return 0;
}
