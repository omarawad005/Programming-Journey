
#include <iostream>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%0*d   ", 2, arr[i][j]);
		}
		cout << "\n";
	}

}

short CountNumberInMatrix(int arr[3][3], short Num, short Rows, short Cols)
{
	short Counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Num == arr[i][j])
			{
				Counter++;
			}
		}
		
	}
	return Counter;
}

bool IsParseMatrix(int arr[3][3], short Rows, short Cols)
{
	float ArraySize = Rows * Cols;
	return (CountNumberInMatrix(arr, 0, 3, 3) >= ceil(float(ArraySize / 2)));
}


int main()
{
	int arr[3][3] = { {8,7,5,},{0,1,6},{2,0,0} };


	PrintMatrix(arr, 3, 3);

	cout << '\n';
	if (IsParseMatrix(arr,3,3))
		cout << "Yes, Matrix Is a Parse Matix ? ";
	else
		cout << "No, Matrix Is Not a Parse Matix ? ";

	system("pause");

}
