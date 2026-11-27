
#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillRandomMatrix(int Marix[3][3], short Rows, short Cols)
{
	for (int  i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Marix[i][j] = RandomNumber(1, 100);
		}

	}
}

void PrintRandomMatrix(int Marix[3][3], short Rows, short Cols)
{
	cout << "The Following is a 3x3 Random Matrix : \n";
	for (int  i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << Marix[i][j] << "\t";
		}
		cout << "\n";

	}
}


int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillRandomMatrix(arr,3,3);
	PrintRandomMatrix(arr,3,3);




}
