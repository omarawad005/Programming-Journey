
#include <iostream>
using namespace std;

void PrintLettersFormA_Z(int From,int To)
{
	for (int i = From; i < To; i++)
	{
		cout << char(i) << "-";
	}
}


int main()
{
	cout << "\n------------------------------------------------------------\n";
	cout << "Capital Letters : \n";
	PrintLettersFormA_Z(65, 91); 
	cout << "\n------------------------------------------------------------\n";
	cout << "Small Letters : \n";
	PrintLettersFormA_Z(97, 123);
	cout << "\n------------------------------------------------------------\n";

	return 0;
}

