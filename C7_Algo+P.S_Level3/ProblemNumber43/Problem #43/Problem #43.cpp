
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ReadString()
{
	string Text = "";
	cout << "Enter Your String : ";
	getline(cin, Text);

	return Text;
}

vector <string> vSpiltWordsAndAddToVecoter(string S1, string delim)
{
	short pos = 0;
	string Word = " ";
	vector <string> vSplitWords;
	while ((pos = S1.find(delim)) != string::npos)
	{
		Word = S1.substr(0, pos);
		if (Word != "")
		{
			vSplitWords.push_back(Word);
		}

		S1.erase(0, pos + delim.length());
	}
	if (S1 != " ")
	{
		vSplitWords.push_back(S1);
	}
	return vSplitWords;
}

string ToLower(string s1)
{
	for (int i = 0; i < s1.length(); i++)
	{
		s1 = tolower(s1[i]);
	}

	return s1;
}

string ReplaceWord(string Text, string OldWord, string NewWord, bool MatchCase = true)
{
	vector <string> vWords = vSpiltWordsAndAddToVecoter(Text, " ");

	string NewString = "";

	for (string& Line : vWords)
	{
		if (MatchCase)
		{
			if (ToLower(Line) == ToLower(OldWord))
			{
				Line = NewWord;
			}
			NewString += Line + " ";
		}
		else
		{
			if (Line == OldWord)
			{
				Line = NewWord;
			}
			NewString += Line + " ";
		}
	}

	return NewString = NewString.substr(0, NewString.length() - 1);
}




int main()
{
	string S1 = ReadString();
	string OldWord, NewWord;
	cout << "Enter Word you want To Replace : ";
	cin >> OldWord;
	cout << "Enter Word you want To Add     : ";
	cin >> NewWord;

	cout << "\n\n";
	cout << "New string with    MatchCase :  " << ReplaceWord(S1, OldWord, NewWord,false);
	cout << "\n\nNew string without MatchCase : " << ReplaceWord(S1, OldWord, NewWord);


	system("pause > 0");
}

