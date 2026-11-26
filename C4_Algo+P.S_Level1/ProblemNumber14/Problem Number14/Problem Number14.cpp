
#include <iostream>
using namespace std;

void ReadNubmer(int &Num1, int &Num2)
{
	cout << "Please enter Number 1 : ";
	cin >> Num1;
	cout << "Please enter Number 2 : ";
	cin >> Num2;

}

void PrintNumber(int N1, int N2)
{
	cout << "--------------------------------\n";
	cout << N1 << endl;
	cout << N2 << endl;
	cout << "--------------------------------\n";
}

void Swap(int &N1, int &N2)
{
	int Temp;
	Temp = N1;
	N1 = N2;
	N2 = Temp;

}




int main()
{
	int N1, N2;
	ReadNubmer(N1, N2);
	cout << "\nNumber Before Swap : \n";
	PrintNumber(N1, N2);
	Swap(N1, N2);
	cout << "\nNumber After  Swap : \n";
	PrintNumber(N1, N2);


	return 0;
}