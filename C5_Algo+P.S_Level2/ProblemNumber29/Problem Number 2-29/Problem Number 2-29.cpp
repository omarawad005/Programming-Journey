

#include <iostream>
#include <cstdlib>

using namespace std;

enum enPrimeNotPrime { Prime , NotPrime };

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

enPrimeNotPrime CheckPrimeNumber(int Number)
{
	short HalfNum = Number / 2;
	for (int i = 2; i <= HalfNum ; i++)
	{
		if (Number % i == 0)
			return enPrimeNotPrime::NotPrime;
	}
			return enPrimeNotPrime::Prime;
}

void FillArrayData(int arr[100], int& arrlength)
{
	cout << "Enter Number Of Elements : ";
	cin >> arrlength;

	for (int i = 0; i < arrlength; i++)
		arr[i] = RandomNumber(1, 100);

}

void CopyArrayElement(int arr[100], int copiedArray[100], int arrlength, int& copiedLength)
{
	copiedLength = 0;
	for (int i = 0; i < arrlength; i++)
	{
		if (CheckPrimeNumber(arr[i]) == enPrimeNotPrime::Prime)
			copiedArray[copiedLength++] = arr[i];
	}
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

	int originalArray[100], newArray[100], Length = 0, copiedLength = 0;

	FillArrayData(originalArray, Length);
	CopyArrayElement(originalArray, newArray, Length, copiedLength);



	cout << "\nArray 1 Element : ";
	PrintArrayData(originalArray, Length);

	cout << "\nArray 2 Element : ";
	PrintArrayData(newArray, copiedLength);



	return 0;
}