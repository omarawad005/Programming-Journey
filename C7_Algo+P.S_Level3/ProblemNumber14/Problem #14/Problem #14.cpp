
#include <iostream>
#include <cstdlib>

using namespace std;


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

bool IsScalerMatrix(int arr[3][3], short Rows, short Cols)
{

		int FirstDiagonalElement = arr[0][0];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i == j && arr[i][j] != FirstDiagonalElement)
				return false;
			else if (i != j && arr[i][j] != 0)
				return false;
		}
	}
	return true;

}




int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3] =
	{
		{1,0,0},
		{0,7,0},
		{0,0,7}
	};

	cout << "Matrix 1 : \n";
	PrintRandomMatrix(arr1, 3, 3);

	cout << '\n';
	if (IsScalerMatrix(arr1, 3, 3))
	{
		cout << "Yes: its a Scaler Matrix";
	}
	else
	{
		cout << "No: its Not a Scaler Matrix";
	}



	cout << '\n';

	return 0;
}
