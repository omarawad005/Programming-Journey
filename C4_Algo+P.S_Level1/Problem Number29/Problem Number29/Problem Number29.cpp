

#include <iostream>


using namespace std;

enum enOddEven
{
	Odd = 1, Even = 2
};

int ReadNumber()
{
	int Num;
	cout << "Enter Number : ";
	cin >> Num;
	return Num;
}

enOddEven CheckEvenNumber(int Num)
{
	if (Num % 2 == 0)
		return enOddEven::Even;
	else
		return enOddEven::Odd;

}

int SumEvenNumber(int Num)
{
	int Sum = 0;
	for (int i = 1; i <= Num; i++)
	{
		if (CheckEvenNumber(i) == enOddEven::Even)
			Sum += i;
	}
	return Sum;
}

void PrintResult(int N)
{
	cout << "Sum Of Even Number From (1) to (" << N << ")" << " is : ";
	cout << SumEvenNumber(N) << endl;
}

int main()
{


	PrintResult(ReadNumber());

	return 0;
}