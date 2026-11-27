

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

void AddArrayElement(int arr, int arr2[100], int &arr2length)
{
	arr2length++;
	arr2[arr2length - 1] = arr;
}



void CopyArrayElement(int arr[100], int arr2[100], int& arrlength, int &arr2length)
{

	for (int i = 0; i < arrlength; i++)
		AddArrayElement(arr[i], arr2, arr2length);
	
}


void PrintArrayData(int arr[], int arrlength)
{
	for (int i = 0; i < arrlength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

}


int main()
{
	srand((unsigned)time(NULL));

	int arr[100],      arrlength = 0 ;
	int arr2[100],  arr2length = 0 ;



	FillArrayData(arr, arrlength);
	cout << "\nArray 1 Element : ";
	PrintArrayData(arr, arrlength);



	CopyArrayElement(arr, arr2, arrlength, arr2length);
	cout << "\n\nArray 2 Element : ";
	PrintArrayData(arr2, arr2length);

	return 0;
}