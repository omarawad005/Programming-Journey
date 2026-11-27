
#include <iostream>
#include <string>

using namespace std;

void PrintFirstCharacter(string Word)
{
	cout << Word.at(0) << endl;
	for (int i = 0; i < Word.length(); i++)
	{
		if (Word.at(i) == ' ' && i + 1 < Word.length())
		{
			cout << Word.at(i + 1) << endl;
		}
	}

}

void PrintFirstLetterOfEachWord(string S1)
{
	
	bool IsFirstCharacter = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1.at(i) != ' ' && IsFirstCharacter)
		{
			cout << S1.at(i) << endl;
		}

		IsFirstCharacter = (S1.at(i) == ' ' ? true : false);
	}

}



int main()
{

	string Text;

	cout << "Pleas enter your Text : ";
	getline(cin,Text);

	cout << "\nPrint FirstCharacters :\n";
	PrintFirstCharacter(Text);
	cout << "\nPrint FirstCharacters :\n";
	PrintFirstLetterOfEachWord(Text);

	system("pause > 0");
}
