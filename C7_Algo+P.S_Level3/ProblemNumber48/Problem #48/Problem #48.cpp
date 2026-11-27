
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>

using namespace std;

const string ClientFileName = "File.txt";

struct stClientData
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0.0;
};

vector <string> SpiltLine(string Line, string Seperator)
{
	vector <string> vWords;
	short Pos = 0;
	string Words = "";

	while ((Pos = Line.find(Seperator)) != string::npos)
	{
		Words = Line.substr(0, Pos);
		if (Words != "")
		{
			vWords.push_back(Words);
		}
		Line.erase(0, Pos + Seperator.length());
	}
	if (Line != "")
	{
		vWords.push_back(Line);
	}
	
	return vWords;

}

stClientData ConvertLineToRecord(string Line, string Seperator)
{
	stClientData Clinet;

	vector <string> vString = SpiltLine(Line, Seperator);

	Clinet.AccountNumber = vString[0];
	Clinet.PinCode = vString[1];
	Clinet.Name = vString[2];
	Clinet.Phone = vString[3];
	Clinet.AccountBalance = stod(vString[4]);

	return Clinet;

}

vector <stClientData> LoadCleintsDataFromFile(string FillName)
{
	vector <stClientData> vClients;
	
	string Line;
	stClientData Client;

	fstream MyFile;
	MyFile.open(FillName, ios::in);

	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line, "#//#");
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;

}

void PrintClientData(stClientData Client)
{
	cout << "| " << left << setw(18) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(30) << Client.Name;
	cout << "| " << left << setw(15) << Client.Phone;
	cout << "| " << left << setw(15) << Client.AccountBalance << "|\n";
}

void ShowAllClients(vector <stClientData> vClients)
{
;

	cout << "\t\t\t\tClients(" << vClients.size() << ") Client(s)\n";
	cout << "\n----------------------------------------------------";
	cout << "----------------------------------------------------- \n";
	cout << "| " << left << setw(18) << "AccountNumber";
	cout << "| " << left << setw(10) << "PinCode";
	cout << "| " << left << setw(30) << "Name";
	cout << "| " << left << setw(15) << "Phone";
	cout << "| " << left << setw(15) << "Account Balance" << "|\n";
	cout << "----------------------------------------------------";
	cout << "----------------------------------------------------- \n";
	for (int i = 0; i < vClients.size(); i++)
	{
		PrintClientData(vClients[i]);
	}

	cout << "----------------------------------------------------";
	cout << "----------------------------------------------------- \n";


}

int main()
{
	vector <stClientData> vClients;
	vClients = LoadCleintsDataFromFile(ClientFileName);

	ShowAllClients(vClients);

	

	system("pause > 0");
}

