
#include <iostream>
#include <string>

using namespace std;

void ConvertTheFirstCharacter(string &S1)
{
	bool IsFirstCharacter = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1.at(i) != ' ' && IsFirstCharacter)
		{
			S1.at(i) = tolower(S1.at(i));
		}

		IsFirstCharacter = (S1.at(i) == ' ' ? true : false);
	}
}


void PrintStringAfterConvert()
{
	string text;

	cout << "Please Enter Your String? ";
	getline(cin, text);

	ConvertTheFirstCharacter(text);

	cout << "\n\nString after Convert :  ";
	cout << text;

}


int main()
{
	PrintStringAfterConvert();

	system("pause > 0 ");
}
