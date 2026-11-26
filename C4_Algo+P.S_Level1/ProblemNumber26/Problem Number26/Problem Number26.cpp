
#include <iostream>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please enter a Number : ";
	cin >> Number;

	return Number;
}

void PrintNumbers_UsingforLoop(int Number)
{
	cout << "\n-----------------------------------\n";
	cout << "Solve with for loop : " << endl;

		for (int i = 1; i <= Number; i++)
		{
			cout << i << endl;
		}
	cout << "-----------------------------------\n";
    

}

void PrintNumbers_UsingWhileLoop(int Number)
{
	cout << "\n-----------------------------------\n";

	cout << "Solve with while loop : " << endl;
		int i = 1;

		while (i <= Number)
		{
			cout << i << endl;

			i++;
		}
		cout << "-----------------------------------\n";

}

void PrintNumbers_UsingDo_WhileLoop(int Number)
{
	cout << "\n-----------------------------------\n";

	cout << "Solve with do_while loop : " << endl;

	
		int i = 1;
		do
		{
			cout << i << endl;
			i++;

		} while (i <= Number);

		cout << "-----------------------------------\n";

}

int main()
{
	int N = ReadNumber();

	// For Loop
	PrintNumbers_UsingforLoop(N);

	// While Loop
	PrintNumbers_UsingWhileLoop(N);

	// Do_While Loop
	PrintNumbers_UsingDo_WhileLoop(N);

	return 0;
}






