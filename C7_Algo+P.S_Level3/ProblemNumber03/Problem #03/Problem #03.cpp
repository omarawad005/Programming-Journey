

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
			cout << arr[i][j] << "\t" ;
		}
		cout << endl;
	}
}

int RowSum(int arr[3][3], short Rows, short Cols)
{
	int Sum = 0;
	for (int j = 0; j < Cols; j++)
	{
		Sum += arr[Rows][j];
	}
	return Sum;	
}

void SumMatrixRowsInArrays(int arr[3][3], int arrRows[3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		arrRows[i] = RowSum(arr, i, Cols);
	}
}

void PrintSumRows(int arrRows[3], int Rows)
{ 
	for (int i = 0; i < Rows; i++)
	{
		cout << "Sum of Rows [" << i + 1 << "]  : " << arrRows[i] << endl;

	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3], arrSumRows[3];

	FillRandomMatrix(Matrix, 3, 3);
	PrintRandomMatrix(Matrix, 3, 3);

	SumMatrixRowsInArrays(Matrix, arrSumRows, 3, 3);
	PrintSumRows(arrSumRows, 3);

	return 0;
}