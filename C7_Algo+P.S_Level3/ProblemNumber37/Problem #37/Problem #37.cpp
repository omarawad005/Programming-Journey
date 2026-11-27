
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
	string text;
	cout << "Enter your String : ";
	getline(cin, text);
	return text;
}

vector <string> vSplit(string S1, string delim)
{
	vector <string> vSplitText;
	int pos = 0;
	string sWord = "";
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vSplitText.push_back(sWord);
		}
		S1.erase(0, pos + delim.length());
	}
	if (S1 != "")
	{
			vSplitText.push_back(S1);
	}
	return vSplitText;
}


int main()
{
	string Message = ReadString();

	vector <string> vSplitEachWord = vSplit(Message, " ");
	vector <string>::iterator iter;

	cout << "\n";
	cout << "Token = " << vSplitEachWord.size() << endl<< endl;
	for (string &word : vSplitEachWord )
	{
		cout << word << endl;
	}
	cout << "\n--------------------";
	cout << "\nPrint With iterator \n\n";
	cout << "Token = " << vSplitEachWord.size() << endl<< endl;
	for (string &word : vSplitEachWord )
	{
		cout << word << endl;
	}


	return 0;
}

