
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

int CountNumberInMatrix(int arr[3][3],int Number, short Rows, short Cols)
{
	int Counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Number == arr[i][j])
			{
				Counter++;
			}
		}
	}
	return Counter;
}




int main()
{
	srand((unsigned)time(NULL));
	int Number;
	int arr1[3][3] =
	{
		{1,0,0},
		{0,7,0},
		{0,0,7}
	};

	cout << "Matrix 1 : \n";
	PrintRandomMatrix(arr1, 3, 3);

	cout << "\nEnter the number to count in matrix? ";
	cin >> Number;


	cout << "\nNumber " << Number << " count in matrix is : " << CountNumberInMatrix(arr1, Number, 3, 3);


	cout << '\n';

	return 0;
}
