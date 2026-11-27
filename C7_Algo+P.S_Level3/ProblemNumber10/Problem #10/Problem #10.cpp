
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

int SumMatrixElement(int arr[3][3], short Rows, short Cols)
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




int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillRandomMatrix(arr, 3, 3);

	cout << "Matrix 1 : \n";
	PrintRandomMatrix(arr, 3, 3);

	cout << "\nSum of Matrixl is : " << SumMatrixElement(arr, 3, 3);


	cout << '\n';

	return 0;
}
