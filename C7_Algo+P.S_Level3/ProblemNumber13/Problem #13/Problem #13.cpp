
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

bool IsIdentiyMatrix(int arr[3][3], short Rows, short Cols)
{ 

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i == j && arr[i][j] != 1)
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
		{0,1,0}, 
		{0,0,1} 
	};

	cout << "Matrix 1 : \n";
	PrintRandomMatrix(arr1, 3, 3);

	cout << '\n';
	if (IsIdentiyMatrix(arr1, 3,3))
	{
		cout << "Yes: its a Identiy Matrix";
	}
	else
	{
		cout << "No: its Not a Identiy Matrix";
	}



	cout << '\n';

	return 0;
}
