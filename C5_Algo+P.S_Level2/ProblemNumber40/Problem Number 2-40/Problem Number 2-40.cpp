
#include <iostream>

using namespace std;


void FillArrayElement(int Arr[100], int& arrlength)
{
	arrlength = 10;
	Arr[0] = 10;
	Arr[1] = 10;
	Arr[2] = 10;
	Arr[3] = 50;
	Arr[4] = 50;
	Arr[5] = 70;
	Arr[6] = 70;
	Arr[7] = 70;
	Arr[8] = 70;
	Arr[9] = 90;

}

void PrintArrayElement(int Arr[100], int arrlength)
{
	for (int i = 0; i < arrlength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n\n";
}

void AddArrayElement(int Num, int arr[100], int &arrlength)
{
	arrlength++;
	arr[arrlength - 1] = Num;
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
			return i;
	}
	return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
	return (FindNumberPositionInArray(Number, arr, arrLength) != -1);
}


void CopyArrayElement(int arrSource[100], int arrDestnation[100], int Sourcelength, int& Destnationlength)
{
	for (int i = 0; i < Sourcelength; i++)
	{
		if (!IsNumberInArray(arrSource[i], arrDestnation, Destnationlength))
		{
			AddArrayElement(arrSource[i], arrDestnation, Destnationlength);
		}
	}
}


int main()
{

	int arr1[100], arr1length = 0;
	int arr2[100], arr2length = 0;


	FillArrayElement(arr1, arr1length);
	cout << "Array 1 Element : ";
	PrintArrayElement(arr1, arr1length);


	CopyArrayElement(arr1,arr2, arr1length, arr2length);
	cout << "Array 2 Element : ";
	PrintArrayElement(arr2, arr2length);


	return 0;
}
