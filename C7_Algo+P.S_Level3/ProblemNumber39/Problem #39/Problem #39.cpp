
#include <iostream>
#include <vector>

using namespace std;

string JoinFunction(vector <string> MyVector, string delim)
{
	string Message = "";
	vector <string>::iterator iter;

	for (iter = MyVector.begin(); iter != MyVector.end(); iter++)
	{
		Message += *iter + delim;
	}

	return Message.substr(0,Message.length() - delim.length());
}

int main()
{

	vector <string> vTexts = { "omar", "awad", "Jalal", "Hello", "World" };
	vector <string>::iterator iter;

	cout << "Message Before join : \n";
	for (iter = vTexts.begin(); iter != vTexts.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << "\nMessage After  join : \n";
	cout << JoinFunction(vTexts, "#@#**#");


	system("pause > 0 ");
}