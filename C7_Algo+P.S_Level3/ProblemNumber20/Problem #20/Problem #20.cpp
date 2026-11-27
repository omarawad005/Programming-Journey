
#include <iostream>
#include <cstdlib>
using namespace std;


void PrintMatrix(int arr[3][3], short Rows, short Cols)
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

bool IsPalindromMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols / 2; j++)
		{
			if (arr[i][j] != arr[i][Cols-1-j])
			{
				return false;
			}
		}
	}
	return true;
}




int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3] = { {1,2,1},{5,5,5},{7,8,7} };

	PrintMatrix(arr, 3, 3);

	if (IsPalindromMatrix(arr, 3, 3))
		cout << "\nYes: Matrix is Palindrome\n";
	else
		cout << "\nNo: Matrix is Not Palindrome\n";


	return 0;

}
