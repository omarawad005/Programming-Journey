

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stClientData
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
};

vector <string> vSpiltRecords(string Line, string Seperoator)
{
	vector <string> vSpiltWords;

	short pos = 0;
	string Words = "";


	while ((pos = Line.find(Seperoator)) != string::npos)
	{
		Words = Line.substr(0, pos);
		if (Words != "")
		{
			vSpiltWords.push_back(Words);
		}

		Line.erase(0, pos + Seperoator.length());
	}
	if (Line != "")
	{
		vSpiltWords.push_back(Line);
	}
	
	return vSpiltWords;
}

stClientData ConvertLineToRecords(string Line, string Seperoator)
{
	vector <string> vRecords;
	vRecords = vSpiltRecords(Line, Seperoator);

	stClientData Client;

	Client.AccountNumber = vRecords[0];
	Client.PinCode = vRecords[1];
	Client.Name = vRecords[2];
	Client.Phone = vRecords[3];
	Client.AccountBalance = stod(vRecords[4]);


	return Client;
}

void PrintClientRecord(stClientData Client) 
{ 
	cout << "\n\nThe following is the extracted client record:\n";     
	cout << "\nAccout Number  : " << Client.AccountNumber;     
	cout << "\nPin Code       : " << Client.PinCode;     
	cout << "\nName           : " << Client.Name;     
	cout << "\nPhone          : " << Client.Phone;     
	cout << "\nAccount Balance: " << Client.AccountBalance; 
}

int main()
{
	string Text = "A150#//#1234#//#Omar awad #//#0124478569#//#1200#//#";

	stClientData Client = ConvertLineToRecords(Text, "#//#");

	PrintClientRecord(Client);

	system("pause > 0");

}
