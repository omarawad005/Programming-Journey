

#include  <iostream>
#include  <string>
using namespace std;

string ReadString()
{
	string Text = "";
	cout << "Please enter your String : ";
	getline(cin, Text);

	return Text;
}

int CountEachWordInString(string S1)
{
	int Counter = 0;
	
	short Pos = 0;
	string delim = " ";
	string Word;

	while ((Pos = S1.find(delim)) != string::npos)
	{
		Word = S1.substr(0, Pos);
		if (Word != "")
		{
			Counter++;
		}
		S1.erase(0, Pos + delim.length());
	}
	if (S1!= "")
	{
			Counter++;

	}
	return Counter;
}

int main()
{
	string Message = ReadString();
	
	cout << "The number of words in your string is : " << CountEachWordInString(Message) << endl;

	return 0;
}