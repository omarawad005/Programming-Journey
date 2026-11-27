
#include <iostream>

using namespace std;

int ReadPoditiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message;
		cin >> Number;
	} while (Number < 0);
	return Number;
}

void ReadArrayData(int arr[100], int &length)
{

	cout << "Please enter Number Of Element : ";
	cin >> length;

	cout << "\nEnter Array Element : \n";
	for (int i = 0; i < length; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> arr[i];
	}
}

int TimeRepeated(int arr[], int length, int Number)
{
	int Fer = 0;
	for (int i = 0; i < length; i++)
	{
		if (Number == arr[i])
		{
			Fer++;
		}
	}
	return Fer;
}

void PrintArrayData(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i];
	}
	cout << "\n";

}


int main()
{
	int Arr[100], Length = 0, CheckNumber;

	ReadArrayData(Arr, Length);
	
	CheckNumber = ReadPoditiveNumber("\nPlease eneter Nuber To Check : ");
	
	cout << "\n";

	cout << "Original Array are : ";
	PrintArrayData(Arr, Length);

	cout << CheckNumber 
		<< " Is repeated "
		<< TimeRepeated(Arr, Length, CheckNumber)
		<< " time(s)\n";

	return 0;
}