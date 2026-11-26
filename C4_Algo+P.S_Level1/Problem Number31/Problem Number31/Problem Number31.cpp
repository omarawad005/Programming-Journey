

#include <iostream>
#include <cmath>

using namespace std;

int ReadNumber()
{
	int Num;
	cout << "Please enter a Number :  ";
	cin >> Num;

	return Num;
}

void PowerOfNumberWithMathFunction(int Num)
{
	cout << Num << " ^" << " 2" << " ==> " << pow(Num, 2) << endl;
	cout << Num << " ^" << " 3" << " ==> " << pow(Num, 3) << endl;
	cout << Num << " ^" << " 4" << " ==> " << pow(Num, 4) << endl;
}

void PowerOfNumberWithFunction(int Num)
{
	cout << Num << " ^" << " 2" << " ==> " << Num * Num << endl;
	cout << Num << " ^" << " 3" << " ==> " << Num * Num * Num << endl;
	cout << Num << " ^" << " 4" << " ==> " << Num * Num * Num * Num << endl;
}

void PrintResult(int Num)
{
	cout << "Power Of Number With Math Function : \n";
	PowerOfNumberWithMathFunction(Num);
	cout << "----------------------------------";
	cout << "\nPower Of Number Without Math Function : \n";
	PowerOfNumberWithFunction(Num);

}


int main()
{


	PrintResult(ReadNumber());


	return 0;
}