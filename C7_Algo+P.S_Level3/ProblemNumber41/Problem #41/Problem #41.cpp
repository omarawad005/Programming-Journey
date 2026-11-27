
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string text = "";
	cout << "Enter Yout String : ";
	getline(cin, text);

	return text;
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

string RevesedString(string S1)
{
	vector <string> vWords = vSpiltWordsAndAddToVecoter(S1, " ");
	vector <string>::iterator iter = vWords.end();

	string NewString = "";

	while (iter != vWords.begin())
	{
		--iter;
		NewString += *iter + " ";
	}
		
	return NewString = NewString.substr(0,NewString.length()-1);
}

int main()
{
	string Text = ReadString();
	cout << "\nString After Revesed  : " << RevesedString(Text);
}
