
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
	int Count = 0;
	cout << "The Following is Order Matrix :\n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "\t";
			
		}
		cout << endl;
	}
}

int main()
{
	int Marix[3][3];

	FillOrderMatrix(Marix, 3, 3);
	PrintOrderMatrix(Marix, 3, 3);

}

