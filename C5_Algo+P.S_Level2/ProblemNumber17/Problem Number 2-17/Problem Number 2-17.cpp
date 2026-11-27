

#include <iostream>

using namespace std;

string ReadPassword(string Message)
{
	string Password = "";
	cout << Message;
	cin >> Password;

	return Password;
}

void FoundPassword(string Password)
{
	string Word = "";
	int counter = 1;

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				Word = Word + char(i);
				Word = Word + char(j);
				Word = Word + char(k);

				cout << "Trial [" << counter << "] : " << Word << endl;

				if (Password == Word)
				{
					cout << "\n\nPassword is : " << Word << endl;
					cout << "Found after " << counter << " Trial(s) \n";
					return;
				}

				counter++;
				Word = "";
				
				
				
			}
		}

	}
}

int main()
{
	string Pass = ReadPassword("Please enter Password : ");
	FoundPassword(Pass);

	return 0;
}