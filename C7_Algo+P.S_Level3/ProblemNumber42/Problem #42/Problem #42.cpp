
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
	while((pos = S1.find(delim)) != string::npos)
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

string ReplaceWord(string Text, string OldWord, string NewWord )
{ 
	vector <string> vWords = vSpiltWordsAndAddToVecoter(Text, " ");

	string NewString = "";
	
	for (string &Line : vWords)
	{
		if (Line == OldWord)
		{
			Line = NewWord;
		}
		NewString += Line + " ";
	}

	return NewString = NewString.substr(0, NewString.length() - 1);
}

string ReplaceWord2(string Text, string OldWord, string NewWord)
{
	short Pos = Text.find(OldWord);

	while(Pos != string::npos)
	{ 
		Text = Text.replace(Pos, OldWord.length(), NewWord);
		Pos = Text.find(OldWord);
	}
	return Text;
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
	cout << "New string After Edit is : " << ReplaceWord2(S1,OldWord,NewWord);


	system("pause > 0");
}

