

#include <iostream>
#include <string>
using namespace std;



string ReadString()
{
	string Text;
	cout << "Please Enter a Character : ";
	getline(cin, Text);

	return Text;
}

bool IsVowel(char Letter)
{
	char arrVowel[] = { 'a', 'e', 'i', 'o', 'u', };
	for (int i = 0; i < 5; i++)
	{
		if (tolower(Letter) == arrVowel[i])
		{
			return true;
		}
	}

	return false;
}


void PrintAllVowelCharacter(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{ 
		if (IsVowel(Text.at(i)))
		{
			cout << Text.at(i) << " ";
		}
	}

}


int main()
{
	string Message = ReadString();
	cout << "All Of Vowel Letter : " ;
	PrintAllVowelCharacter(Message);



	system("Pause > 0");

}

