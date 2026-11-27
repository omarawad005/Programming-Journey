
#include <iostream>
#include <string>

using namespace std;

string RemovePunctuation(string S1)
{
	string NewString = "";
	for (int i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i])) 
		{
			NewString += S1[i];
		}
	}

	return NewString;
}



int main()
{
	string Text = "Welcome Every Body, ? All you ever was complain, you can fight: but you ;cant thinking, you cant do ethier ? ";
	
	cout << Text << endl << endl;
	cout << RemovePunctuation(Text);


	system("pause >0");
}
