
#include <iostream>
#include <string>

using namespace std;

void ConvertTheFirstCharacterToUpper(string& S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
			S1.at(i) = toupper(S1.at(i));
	}
}

void ConvertTheFirstCharacterToLower(string& S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
			S1.at(i) = tolower(S1.at(i));
	}
}


void PrintStringAfterConvert()
{
	string text;

	cout << "Please Enter Your String? ";
	getline(cin, text);


	ConvertTheFirstCharacterToUpper(text);
	cout << "\n\nString after Convert To Upper :  ";
	cout << text;

	ConvertTheFirstCharacterToLower(text);
	cout << "\n\nString after Convert To Lower :  ";
	cout << text;

}


int main()
{
	PrintStringAfterConvert();

	system("pause > 0 ");
}
