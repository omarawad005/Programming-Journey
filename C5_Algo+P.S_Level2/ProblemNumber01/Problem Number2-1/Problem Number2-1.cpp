

#include <iostream>

using namespace std;

void PrintTableHeader()
{
	cout << "\t\t\tMultiPlication Table From 1 To 10 ? \t\t\n";
	for (int i = 1; i <= 10; i++)
	{
		cout << "\t" << i;
	}
	cout << "\n____________________________________________________________________________________\n";
}

string ColumSperator(int i)
{
	if (i < 10)
		return "   |";
	else
		return "  |";
}

void PrintMultiplicationTable()
{
	PrintTableHeader();

	for (int i = 1; i <= 10; i++)
	{
		cout <<" " << i << ColumSperator(i);
		for (int j = 1; j <= 10; j++)
		{
			cout << "\t" << i * j;
		}
		cout << endl;
	}
}


int main()
{
	PrintMultiplicationTable();

	return 0;
}