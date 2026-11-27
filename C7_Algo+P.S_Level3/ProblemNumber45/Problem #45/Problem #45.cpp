

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stClient 
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	int AccountBalance = 0;
};

stClient ReadClientData()
{
	stClient Client;
	cout << "Please enter Client Data:\n\n";

	cout << "Enter Account Number  : ";
	getline(cin >> ws, Client.AccountNumber);
	cout << "Enter Pin Code        : ";
	getline(cin, Client.PinCode);
	cout << "Enter Name            : ";
	getline(cin, Client.Name);
	cout << "Enter Phone           : ";
	getline(cin, Client.Phone);
	cout << "Enter Account Balance : ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLien(stClient Client, string Separator = "#//#")
{
	string LineRecord = "";

	LineRecord += Client.AccountNumber + Separator;
	LineRecord += Client.PinCode + Separator;
	LineRecord += Client.Name + Separator;
	LineRecord += Client.Phone + Separator;
	LineRecord += to_string(Client.AccountBalance) ;

	return LineRecord;

}


int main()
{
	stClient Client = ReadClientData();

	cout << "\nClient Record for Saving is : \n";
	cout << ConvertRecordToLien(Client, "#//#");

	system("pause > 0");
}

