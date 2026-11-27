

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

const string FileName = "File.txt";

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	int AccountBalance = 0;

};

vector <string> SplitString(string Line, string Separator)
{
	vector <string> vString;
	short pos = 0;
	string vWord = "";

	while ((pos = Line.find(Separator)) != string::npos)
	{
		vWord = Line.substr(0, pos);
		if (vWord != "")
		{
			vString.push_back(vWord);
		}
		Line.erase(0, pos + Separator.length());
	}
	if (Line != "")
	{
			vString.push_back(Line);
	}
	return vString;
}

stClient ConvertLineToRecord(string Line, string Separator = "#//#")
{
	vector <string> vClinentData = SplitString(Line,Separator);
	stClient Client;

	Client.AccountNumber = vClinentData[0];
	Client.PinCode = vClinentData[1];
	Client.Name = vClinentData[2];
	Client.Phone = vClinentData[3];
	Client.AccountBalance = stoi(vClinentData[4]);

	return Client;
}

vector <stClient> LoadDataFromFile(string FName)
{
	vector <stClient> vClients;

	fstream MyFile;

	MyFile.open(FName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}

	return vClients;
}

bool FineClientByAccountNumber(string AccountNumber, stClient &Client)
{
	vector <stClient> vClient;
	vClient = LoadDataFromFile(FileName);

	for (stClient &C: vClient)
	{
		if (AccountNumber == C.AccountNumber)
		{
			Client = C;
			return true;
		}

	}
	return false;
}

string ReadAccountNumber()
{	
	string Account_Number;
	cout << "\nPlease enter AccountNumber : ";
	cin >> Account_Number;
	return Account_Number;
}

void PrintClientRecord(stClient Client)
{
	cout << "\nThe Following is the extracted Client Recorded : \n";
 	cout << endl << "Account Number  : " << Client.AccountNumber;
	cout << endl << "PinCode         : " << Client.PinCode;
	cout << endl << "Name            : " << Client.Name;
	cout << endl << "Phone           : " << Client.Phone;
	cout << endl << "Account Balance : " << Client.AccountBalance;
}

void PrintResult()
{
	string AccountNumber = ReadAccountNumber();
	stClient Client;

	if (FineClientByAccountNumber(AccountNumber,Client))
	{
		PrintClientRecord(Client);
	}
	else
	{

		cout << "Clinet with Account Number (" << AccountNumber << ") Is Not Found";
	}

}

int main()
{


	PrintResult();


	system("pause > 0");
	return 0;
}
