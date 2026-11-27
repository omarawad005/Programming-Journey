
#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillRandomMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}

	}
}

void PrintRandomMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%0*d  ", 2, arr[i][j]);
		}
		cout << "\n";

	}
}

int SumOfMatrix(int arr[3][3], short Rows, short Cols)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Sum += arr[i][j];
		}

	}
	return Sum;
}

bool IsEqual(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
	return (SumOfMatrix(arr1, Rows, Cols) == SumOfMatrix(arr2, Rows, Cols));
}



int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3], arr2[3][3];

	FillRandomMatrix(arr1, 3, 3);
	FillRandomMatrix(arr2, 3, 3);

	cout << "Matrix 1 : \n";
	PrintRandomMatrix(arr1, 3, 3);
	cout << "\n\nMatrix 2 : \n";
	PrintRandomMatrix(arr2, 3, 3);

	if (IsEqual(arr1,arr2, 3,3))
	{
		cout << "\nYes :  Matrix is Equal ";
	}
	else
	{
		cout << "\nNo:  Matrix is Not Equal ";
	}


	cout << '\n';

	return 0;
}
