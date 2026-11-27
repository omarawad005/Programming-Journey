

#include <iostream>
#include <cstdlib>

using namespace std;




int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillArrayData(int arr[100], int& arrlength)
{
	cout << "Enter Number Of Elements : ";
	cin >> arrlength;

	for (int i = 0; i < arrlength; i++)
		arr[i] = RandomNumber(1, 100);

}

int SumElementInArray(int arr[], int arrlength)
{
	int Sum = 0;
	for (int i = 0; i < arrlength; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}

float AverageOfArray(int arr[], int arrlength)
{
	
	return (float(SumElementInArray(arr, arrlength)) / arrlength);
	
}

void PrintArrayData(int arr[], int length)
{
	cout << "Array Element : ";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Length = 0;

	FillArrayData(Arr, Length);
	cout << endl;

	PrintArrayData(Arr, Length);
	cout << endl;
	cout << endl;

	cout << "Average of all Number is : " << AverageOfArray(Arr, Length);
	cout << endl;
	

	return 0;
}