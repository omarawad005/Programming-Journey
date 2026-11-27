
#include <iostream>
#include "clsString.h"
#include "clsDate.h"
using namespace std;




int main()
{

	clsString String1("Omar awad jalal");
	clsDate Date1;

	cout << String1.ReplaceString("jalal", "galal") << endl;

	system("pause > 0");
	return 0;
}
