

#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;	
}

void AddArrayElemnet(int arr[100], int Number, int &arrlength)
{
	arrlength++;
	arr[arrlength - 1] = Number;
}


void CopayArrayElement(int arr[100], int arr1length, int arr2[100], int &arr2length)
{
	for (int i = 0; i < arr1length; i++)
	{
		if (arr[i] % 2 != 0)
		{
			AddArrayElemnet(arr2, arr[i], arr2length);
		}
	}
}


void FillArrayElement(int arr[100], int& arrlength)
{
	cout << "Enter Number Of Element : ";
	cin >> arrlength;

	for (int i = 0; i < arrlength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArrayElement(int arr[100], int arrlength)
{
	for (int i = 0; i < arrlength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int arr[100],  Length = 0;
	srand((unsigned)time(NULL));

	int arr2[100], arr2Length = 0;

	FillArrayElement(arr, Length);
	cout << "\nArray 1 Element : ";
	PrintArrayElement(arr, Length);

	CopayArrayElement(arr,Length, arr2, arr2Length);
	cout << "\nArray 2 Element : ";
	PrintArrayElement(arr2, arr2Length);


	return 0;
}