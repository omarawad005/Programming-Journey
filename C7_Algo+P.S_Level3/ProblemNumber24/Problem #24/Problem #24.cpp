

#include <iostream>
#include <string>
using namespace std;


void TheFirstCharacter(string & Message)
{

    bool ISFirstCharacter = true;

	for (int i = 0; i < Message.length(); i++)
	{

		if (Message.at(i) != ' ' && ISFirstCharacter)
		{
			Message.at(i) = toupper(Message.at(i));
			
		}
			ISFirstCharacter = (Message.at(i) == ' ' ? true : false);

	}


}

void MakeFirstCharacterToUpperCase()
{
	string Text; 
	cout << "Enter text you need : ";
	getline(cin, Text);

	TheFirstCharacter(Text);

	cout << '\n';
	cout << Text << endl;

}


int main()
{
 
	MakeFirstCharacterToUpperCase();



	system("pause > 0");
}
