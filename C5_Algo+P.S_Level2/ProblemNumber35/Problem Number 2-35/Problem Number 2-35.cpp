

#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int ReadPositiveNumber(string Message)
{
	int Num = 0;
	do
	{
		cout << Message;
		cin >> Num;
	} while (Num < 0);
	return Num;
}

void FillArrayElement(int arr[100], int arrlength)
{


	for (int i = 0; i < arrlength; i++)
		arr[i] = RandomNumber(1, 100);

}

bool FindPositionNumberInArray(int arr[100], int Number, int arrlength)
{


	for (int i = 0; i < arrlength; i++)
	{
		if (Number == arr[i])
		{
			return true;
		}
	}

	return false;

}

void PrintResult(int arr[100], int Number, int arrlength)
{
	bool IsFound = FindPositionNumberInArray(arr, Number, arrlength);
	if (IsFound)
	{
		cout << "\nNumber You Looking For is ==> " << Number << endl;
		cout << "Yes, The Number Is Found :-) \n";
	}
	else
	{
		cout << "\nNumber You Looking For is ==> " << Number << endl;
		cout << "No, The Number Not Found :-( \n";
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
	srand((unsigned)time(NULL));
	int Arr1[100], Length = 0, NumberToCheck;

	Length = ReadPositiveNumber("Enter Number Of Element : ");

	FillArrayElement(Arr1, Length);
	cout << "\nArray 1 Element : ";
	PrintArrayElement(Arr1, Length);

	NumberToCheck = ReadPositiveNumber("\n\nEnter Number To search for : ");
	PrintResult(Arr1, NumberToCheck, Length);

	return 0;
}