
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
			arr[i][j] = RandomNumber(1, 20);
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

bool IsNumberInMatrix(int Num, int arr2[3][3],  short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Num == arr2[i][j])
			{
				return true;
			}
		}

	}
	return false;
}

void PrintRepeateNumber(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (IsNumberInMatrix(arr1[i][j], arr2,Rows,Cols))
			{
				cout << arr1[i][j] << "   ";
			}
		}

	}
}



int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3];
	int arr2[3][3];

	FillMatrixWithRandomNumber(arr1, 3, 3);
	FillMatrixWithRandomNumber(arr2, 3, 3);

	cout << "Matrix 1 : \n";
	PrintRandomMatrix(arr1, 3, 3);
	
	cout << "\nMatrix 2 : \n";
	PrintRandomMatrix(arr2, 3, 3);


	cout << "\nIntersected Nurnbers are: \n";
	PrintRepeateNumber(arr1, arr2, 3, 3);

	
	
	cout << "\n\n";

	return 0;

}
