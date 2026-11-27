
#include <iostream>
#include <random>
#include "clsUtil.h"

using namespace std;

int main()
{
	clsUtil::Srand();

	string Name = clsUtil::EncryptionText("Omar awad jalal ", 8);
	cout << "Name Before Enc : Omar awad jalal \n";
	cout << "Name after  Enc : " << Name << endl;
	cout << "Name after  Dec : " << clsUtil::DecryptionText(Name, 8);
	 

	 cout << "\n\n\n";
	return 0;
}


