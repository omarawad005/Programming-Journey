

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

	for (int i = 0; i < arrlength; i++)
		arr[i] = RandomNumber(1, 100);

}


void SumArray(int arrSum[100],int arr1[100],int arr2[100], int& arrlength)
{

	for (int i = 0; i < arrlength; i++)
		arrSum[i] = arr1[i] + arr2[i];
	
}


void PrintArrayData(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

}


int main()
{
	srand((unsigned)time(NULL));

	int Arr1[100], Arr2[100], SumArr[100], Length = 0;

	cout << "Enter Number Of Elements : ";
	cin >> Length;


	FillArrayData(Arr1, Length);
	FillArrayData(Arr2, Length);
	SumArray(SumArr, Arr1, Arr2, Length);


	cout << "\nArray 1 Element : ";
	PrintArrayData(Arr1, Length);

	cout << "\nArray 2 Element : ";
	PrintArrayData(Arr2, Length);

	cout << "\nSum arr1 + arr2 : ";
	PrintArrayData(SumArr, Length);






	return 0;
}