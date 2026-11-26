
#include <iostream>
#include <cmath>
using namespace std;

struct stRectangle
{
	int Length;
	int Diagnal;
};

stRectangle  ReadRectangle()
{

	stRectangle R;

	cout << "Please enter Length  : ";
	cin >> R.Length;
	
	cout << "Please enter Diagnal : ";
	cin >> R.Diagnal;

	return R;

}

float CalculateArea(stRectangle R)
{
	float Area;

	Area = R.Length * (sqrt(pow(R.Diagnal, 2) - pow(R.Length, 2)));
	return Area;
}

void PrintArea(float Area)
{
	cout << "Area of Rectangle Is : " << Area << endl;
}



int main()
{

	
	PrintArea(CalculateArea(ReadRectangle()));


	return 0;
}