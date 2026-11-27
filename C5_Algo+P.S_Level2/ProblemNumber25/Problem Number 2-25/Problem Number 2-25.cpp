

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

int MinNumberInArray(int arr[], int arrlength)
{
	int MinNumber = arr[0];

	for (int i = 0; i < arrlength; i++)
	{
		if (MinNumber > arr[i])
			MinNumber = arr[i];
	}
	return MinNumber;
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

	cout << "Min Number Is : " << MinNumberInArray(Arr, Length);
	cout << endl;

	return 0;
}