
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

void PrintRandomMatrix(int arr[3][3], short Rows, short Cols)
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

int MaxNumberInMatrix(int arr[3][3], short Rows, short Cols)
{
	int MaxNumber = arr[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr[i][j] > MaxNumber)
			{
				MaxNumber = arr[i][j];
			}
		}
	}

	return MaxNumber;
}

int MinNumberInMatrix(int arr[3][3], short Rows, short Cols)
{
	int MinNumber = arr[0][0];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (arr[i][j] < MinNumber)
			{
				MinNumber = arr[i][j];
			}
		}
	}

	return MinNumber;
}




int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrixWithRandomNumber(arr, 3, 3);

	cout << "Matrix 1 : \n";
	PrintRandomMatrix(arr, 3, 3);

	cout << "\nMin Number in Matrix : " << MinNumberInMatrix(arr, 3, 3);
	cout << "\nMax Number in Matrix : " << MaxNumberInMatrix(arr, 3, 3);

	cout << "\n\n";

	return 0;

}
