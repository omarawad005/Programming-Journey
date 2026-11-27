

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

void CopyArrayElement(int arr[100],int copiedArray[100], int& arrlength)
{
	
	for (int i = 0; i < arrlength; i++)
		copiedArray[i] = arr[i];
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

	int originalArray[100], newArray[100], Length = 0;

	FillArrayData(originalArray, Length);
	CopyArrayElement(originalArray, newArray, Length);



	cout << "\nArray 1 Element : ";
	PrintArrayData(originalArray, Length);
	
	cout << "\nArray 2 Element : ";
	PrintArrayData(newArray, Length);
	


	return 0;
}