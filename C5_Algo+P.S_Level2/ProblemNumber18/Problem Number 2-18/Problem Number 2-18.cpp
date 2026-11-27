
#include <iostream>
#include <string>
using namespace std;

string ReadName(string Message)
{
	string Name;
	cout << Message;
	 getline(cin, Name);
	return Name;
}

string EncryptionName(string Name, short EncryptionKey)
{
	for (int i = 0; i < Name.length(); i++)
	{
		Name[i] = char(int(Name[i]) + EncryptionKey);
	}
	return Name;
}

string DecryptionName(string Name, short EncryptionKey)
{
	for (int i = 0; i < Name.length(); i++)
	{
		Name[i] = char(int(Name[i]) - EncryptionKey);
	}
	return Name;
}





int main()
{
	const short EncryptionKey = 3;
	string Name = ReadName("Please enter Name : ");

	string EnName = EncryptionName(Name, EncryptionKey);
	string DeName = DecryptionName(EnName, EncryptionKey);

	cout << "\nText Before Encryption : " << Name << endl;
	cout << "Text After Encryption  : " << EnName << endl;
	cout << "Text After Decryption  : " << DeName << endl;


	
	
	return 0;
}
