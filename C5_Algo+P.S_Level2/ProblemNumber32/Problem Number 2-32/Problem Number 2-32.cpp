

#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}


void FillArrayElement(int arr[100], int& arrlength)
{
	cout << "Enter Number Of Element : ";
	cin >> arrlength;

	for (int i = 0; i < arrlength; i++)
		arr[i] = RandomNumber(1,100);

}


void CopyArrayInReverseOrder(int arr1[100], int arr2[100], int& arrlength)
{

	for (int i = 0; i < arrlength; i++)
		arr2[i] = arr1[arrlength - 1 - i];

}


void PrintArrayElement(int arr[100], int& arrlength)
{
	for (int i = 0; i < arrlength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}


int main()
{
	srand((unsigned)time(NULL));
	int Arr1[100], Arr2[100], Length = 0;

	FillArrayElement(Arr1, Length);
	cout << "\nArray 1 Element : ";
	PrintArrayElement(Arr1, Length);

	CopyArrayInReverseOrder(Arr1, Arr2, Length);
	cout << "\nArray 2 Element : ";
	PrintArrayElement(Arr2, Length);

	return 0;
}