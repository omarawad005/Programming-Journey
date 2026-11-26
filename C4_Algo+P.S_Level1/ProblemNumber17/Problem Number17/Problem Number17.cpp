

#include <iostream>
#include <cmath>
using namespace std;

void ReadNumber(int& A, int& H)
{
	cout << "Please enter A : ";
	cin >> A;
	cout << "Please enter H : ";
	cin >> H;
}
float CalculateArea(int A, int H)
{
	float Area = (A / 2) * H;
	return Area;
}
void PrintArea(float Result)
{
	cout << "\nArea = " << Result << endl;
}

int main()
{

	int A, H;
	ReadNumber(A, H);
	PrintArea(CalculateArea(A, H));
	return 0;
}
