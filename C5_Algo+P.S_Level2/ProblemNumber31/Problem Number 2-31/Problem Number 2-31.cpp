

#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void SwapNumber(int &Num1, int &Num2)
{
	int Temp = 0;
	Temp = Num1;
	Num1 = Num2;
	Num2 = Temp;
}

void FillArrayElement(int arr[100], int& arrlength) 
{
	cout << "Enter Number Of Element : ";
	cin >> arrlength;

	for (int i = 0; i < arrlength; i++)
		arr[i] = i + 1;

}

void ShuffleArrayElement(int arr[100], int& arrlength) 
{
	for (int i = 0; i < arrlength; i++) 
	{
		int Index1 = RandomNumber(1, arrlength) - 1;
		int Index2 = RandomNumber(1, arrlength) - 1;
		SwapNumber(arr[Index1], arr[Index2]);
	}
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
	int Arr[100], Length = 0;
	
	FillArrayElement(Arr, Length);
	cout << "\nArray Element Before Shuffle : ";
	PrintArrayElement(Arr, Length);

	cout << "\nArray Element After  Shuffle : ";
	ShuffleArrayElement(Arr, Length);
	PrintArrayElement(Arr, Length);

	return 0;
}