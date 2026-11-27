

#include <iostream>
#include <string>
using namespace std;



char ReadLetter()
{
	char letter;
	cout << "Please Enter a Character : ";
	cin >> letter;

	return letter;
}

bool IsVowel(char Letter)
{
	char arrVowel[] = { 'a', 'e', 'i', 'o', 'u' };
	for (int i = 0; i < 5; i++)
	{
		if ( tolower(Letter) == arrVowel[i])
		{
			return true;
		}
	}

			return false;
}


void PrintResult(char Letter)
{
	cout << endl;
	if (IsVowel(Letter))
	{
		cout << "YES Letter '" << Letter << "' is Vowel.\n";
	}
	else
	{
		cout << "No Letter '" << Letter << "' is Not Vowel.\n";
	}

}


int main()
{
	char letter = ReadLetter();
	PrintResult(letter);

	system("Pause > 0");

}

