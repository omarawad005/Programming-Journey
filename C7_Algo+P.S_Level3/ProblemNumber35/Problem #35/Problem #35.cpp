

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

void PrintEachWordInString(string S1)
{
	
	string delim = " "; // ==> Delimiter

	cout << "Your String Words are : \n";
	short Pos = 0;
	string Word;

	while ((Pos = S1.find(delim)) != string::npos)
	{
		Word = S1.substr(0, Pos);
		if (Word != "")
		{
			cout << Word << endl;
		}
		S1.erase(0, Pos + delim.length());
	}
	if (S1 != " ")
	{
		cout << S1 << endl;
	}

}

int main()
{
	string Message = ReadString();
	PrintEachWordInString(Message);

	return 0;
}