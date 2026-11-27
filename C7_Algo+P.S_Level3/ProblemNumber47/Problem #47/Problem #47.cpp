#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct stClientData
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    double AccountPalance = 0;
};

stClientData ReadClinetData()
{
    stClientData ClientData;

    cout << "Please enter Account Number   : ";
    getline(cin >> ws, ClientData.AccountNumber);

    cout << "Please enter PinCode Number   : ";
    getline(cin, ClientData.PinCode);

    cout << "Please enter Name             : ";
    getline(cin, ClientData.Name);

    cout << "Please enter Phone            : ";
    getline(cin, ClientData.Phone);

    cout << "Please enter Account Palance  : ";
    cin >> ClientData.AccountPalance;


    return ClientData;
}

string JoinString(stClientData Client, string delim)
{
    string NewString = "";

    NewString += Client.AccountNumber + delim;
    NewString += Client.PinCode + delim;
    NewString += Client.Name + delim;
    NewString += Client.Phone + delim;
    NewString += to_string(Client.AccountPalance) + delim;

    return NewString;
}

void AddDataToFile(string FillName, string Record)
{
    fstream MyFile;

    MyFile.open(FillName, ios::out | ios::app); 

    if (MyFile.is_open())
    {
        MyFile << Record << endl;
        MyFile.close();
    }
}

void AddNewClients()
{
    stClientData Client;

    Client = ReadClinetData();
    AddDataToFile("File.txt", JoinString(Client, "#//#"));

}


void AddClients()
{
    char AddMore = 'y';

    do
    {
        system("cls");

        cout << "Adding New Client : \n\n";
        AddNewClients();

        cout << "\nClient Added Successfully, do you want to add more clients? (y/n): ";
        cin >> AddMore;

    } while (AddMore == 'Y' || AddMore == 'y');
}

int main()
{
    AddClients();

    system("pause>0");
}
