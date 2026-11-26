
/*
#include <iostream>
using namespace std;

void ReadNumber(float& A, float& B)
{
	cout << "Please enter A : ";
	cin >> A;
	cout << "Please enter B : ";
	cin >> B;
}
float CalculateArea(float A, float B)
{
	float Area = A * B;
	return Area;
}
void PrintArea(float Result)
{
	cout << "\nArea = " << Result << endl;
}

int main()
{
   
	float A, B;
	ReadNumber(A, B);
	PrintArea(CalculateArea(A, B));
	return 0;
}*/

#include <iostream>

using namespace std;

struct stRectangle
{
	int length;
	int width;
};

stRectangle RectangleInfo()
{
	stRectangle R;
	cout << "Please enter Rectangle Length : ";
	cin >> R.length;
	cout << "Please enter Rectangel Width  : ";
	cin >> R.width;

	return R;
}

int CalculateRectangleArea(stRectangle R)
{
	return (R.length * R.width);
}

void PrintArea(stRectangle R)
{
	cout << "\nArea of Rectangle Is : " << CalculateRectangleArea(R) << endl;
}


int main()
{


	PrintArea(RectangleInfo());


	return 0;
}