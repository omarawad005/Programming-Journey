
#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}

	}

}

void PrintRandomNumber(int arr[3][3], short Rows, short Cols)
{

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
		printf("%0*d   ", 2, arr[i][j]);
		}
		cout << endl;
	}

}

bool IsNumberExite(int arr[3][3],int Number, short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Number == arr[i][j])
			{
				return true;
			}
		}
	}
				return false;
}



int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrixWithRandomNumber(arr, 3, 3);

	cout << "Matrix 1 : \n";
	PrintRandomNumber(arr, 3, 3);

	int Num;
	cout << "\nPlease Enter the number to look for in matrix? ";
	cin >> Num;

	if (IsNumberExite(arr, Num, 3,3))
		cout << "\nYes Number is There :-)\n";
	else
		cout << "\nNo Number is  not There :-(\n";
	


	return 0;

}
