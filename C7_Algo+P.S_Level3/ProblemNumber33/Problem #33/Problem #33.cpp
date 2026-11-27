

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
	char arrVowel[] = { 'a', 'e', 'i', 'o', 'u' };
	for (int i = 0; i < 5; i++)
	{
		if (tolower(Letter) == arrVowel[i])
		{
			return true;
		}
	}

	return false;
}


short CountVowelCharacter(string Text)
{
	short Count = 0;
	for (int i = 0; i < Text.length(); i++)
	{
		if (IsVowel(Text.at(i)))
		{
			Count++;
		}
	}
	
	return Count;
}


int main()
{
	string Message = ReadString();
	int Num = CountVowelCharacter(Message);

	cout << "Number Of Vowel Letter : " << Num << endl;


	system("Pause > 0");

}

