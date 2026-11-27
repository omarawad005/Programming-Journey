
#include <iostream>
using namespace std;


void FillOrderMatrix(int arr[3][3], short Rows, short Cols)
{
	int Count = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arr[i][j] = ++Count;

		}

	}
}

void PrintOrderMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "\t";

		}
		cout << endl;
	}
}

void TransposeMatrix(int arr[3][3],int arrTranspos[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			arrTranspos[i][j] = arr[j][i];
		}

	}
}

int main()
{
	int Marix[3][3], arrTransposMatrix[3][3];

	FillOrderMatrix(Marix, 3, 3);
	TransposeMatrix(Marix, arrTransposMatrix, 3, 3);
	cout << "The Following is Order Matrix :\n";
	PrintOrderMatrix(Marix, 3, 3);
	cout << "The Following is TransPos Matrix :\n";
	PrintOrderMatrix(arrTransposMatrix, 3, 3);


}

