
#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
	string text;
	cout << "Please enter Your text : ";
	getline(cin, text);

	return text;
}

string TrimLeft(string text)
{
	if (text.empty()) 
		return text;

	int counter = 0;
	while (counter < text.length() && text[counter] == ' ')
		counter++;

	return text.erase(0, counter);
}

string TrimRight(string text)
{
	if (text.empty()) return text;

	int counter = text.length() - 1;
	while (counter >= 0 && text[counter] == ' ')
		counter--;

	return text.substr(0, counter + 1);
}

string TrimRightAndLeft(string& text)
{
	text = TrimLeft(TrimRight(text));
	return text;
}



int main()
{
	string Message = ReadText() ;
	
	cout << "\n";

	cout << "Message  : " << "[" << Message << "]" << endl;
	cout << "Trim L   : " << "[" << TrimLeft(Message) << "]" << endl;
	cout << "Trim R   : " << "[" << TrimRight(Message) << "]" << endl;
	cout << "Trim R&L : " << "[" << TrimRightAndLeft(Message) << "]" << endl;



	return 0;
}