/*
		#include <iostream>
	using namespace std;

	int ReadNumber()
	{
		int Number;

		cout << "Please enter Number : ";
		cin >> Number;

		return Number;

	}

	int SumOfOddNumberUsing_ForLoop(int Number)
	{
		cout << "\n-----------------------------------------\n";
		cout << "Sum Of Odd Number Using [ For Loop ] \n";
		int Sum = 0;

		for (int i = 1; i <= Number; i++)
		{
			if (i % 2 == 1)
				Sum += i;
		}

		return Sum;
	}

	int SumOfOddNumberUsing_WhileLoop(int Number)
	{
		cout << "\n-----------------------------------------\n";
		cout << "Sum Of Odd Number Using [ While Loop ] \n";
		int i = 1;

		int sum = 0;
		while (i <= Number)
		{
			if (i % 2 == 1)
			{
				sum += i;
			}
			i++;


		}

		return sum;
	}

	int SumOfOddNumberUsing_Do_WhileLoop(int Number)
	{
		cout << "\n-----------------------------------------\n";
		cout << "Sum Of Odd Number Using [ Do_While Loop ]\n";
		int i = 1;

		int sum = 0;

		do
		{
			if (i % 2 == 1)
				sum += i;
			i++;

		

		} while (i <= Number);

		return sum;
	}

	void PrintSumOddNumber(int sum)
	{
		cout << "Sum Odd Nubmer = " << sum << endl;
		cout << "-----------------------------------------\n";
	}

	int main()
	{
		int N = ReadNumber();

		PrintSumOddNumber(SumOfOddNumberUsing_ForLoop(N));
		PrintSumOddNumber(SumOfOddNumberUsing_WhileLoop(N));
		PrintSumOddNumber(SumOfOddNumberUsing_Do_WhileLoop(N));
		return 0;
	}
*/

#include <iostream>

using namespace std;

enum enOddEven
{
	Odd,
	Even
};

int ReadNumber()
{
	int Num;
	cout << "Enter Number : ";
	cin >> Num;
	return Num;
}

enOddEven CheckOddNumber(int Num)
{
	if (Num % 2 == 1)
		return enOddEven::Odd;
	else
		return enOddEven::Even;

}

int SumOddNumber(int Num)
{
	int Sum = 0;
	for (int i = 1; i <= Num; i++)
	{
		if (CheckOddNumber(i) == enOddEven::Odd)
			Sum += i;
	}
	return Sum;
}

void PrintResult(int N)
{
	cout << "Sum Of Odd Number From (1) to (" << N << ")" << " is : ";
	cout << SumOddNumber(N) << endl;
}

int main()
{


	PrintResult(ReadNumber());

	return 0;
}