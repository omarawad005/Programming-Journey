

#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From - 1) + From;
	return randNum;
}

void FillRandomMatrix(int arr[3][3], short Rows, short Cols)
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

	cout << "The Following is 3x3 Random Matrix : \n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int ColsSum(int arr[3][3], short Rows, short Cols)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		Sum += arr[i][Cols];
	}
	return Sum;
}

void PrintColsSum(int arr[3][3], short Rows, short Cols)
{
	cout << "\nThe following are the sum of each cols in the matrix :\n";
	for (int j = 0; j < Cols; j++)
	{
		cout << "Sum of Cols [" << j + 1 << "]  : " << ColsSum(arr,3,j) << endl;

	}
}



int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3], arrSumRows[3];

	FillRandomMatrix(Matrix, 3, 3);
	PrintRandomMatrix(Matrix, 3, 3);

	PrintColsSum(Matrix, 3, 3);

	return 0;
}