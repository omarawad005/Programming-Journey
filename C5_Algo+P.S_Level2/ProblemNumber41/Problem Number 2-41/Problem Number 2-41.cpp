

#include <iostream>
using namespace std;

void FillArrayElement(int arr[100], int& arrlength)
{
	arrlength = 6;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;
}

void PrintArrayElement(int arr[100], int arrlength)
{
	for (int i = 0; i < arrlength; i++)
	{
		cout << arr[i] << " ";
	}
}

bool IsPalindrom(int arr[100], int arrlength)
{
	for (int i = 0; i < arrlength; i++)
	{
		if (arr[i] != arr[arrlength - 1 - i])
		{
			return false;
		}
	}
			return true;
}


int main()
{
	int arr[100], Length = 0;

	FillArrayElement(arr, Length);
	cout << "\nArray Element are : \n";
	PrintArrayElement(arr, Length);

	if (IsPalindrom(arr,Length))
		cout << "\nYes, array Is Palindrom?\n";
	else	
		cout << "\n\nNo, array Is Not Palindrom?\n";

	return 0;
}