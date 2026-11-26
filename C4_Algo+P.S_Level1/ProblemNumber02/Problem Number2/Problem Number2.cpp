
/*
	
/*
#include <iostream>
#include <string>
using namespace std;

void ReadName(string& Name)
{
	cout << "Please enter Your name : ";
	getline(cin, Name);
}
void PrintName(string Name)
{
	cout << "\nNice to meet you, " << Name << endl;
}


int main()
{
	string Name;
	ReadName(Name);
	PrintName(Name);
		
	return 0;
}


#include <iostream>
#include <string> 
using namespace std;

string ReadName(string& Name)
{
	cout << "Please enter yout Name : ";
	getline(cin, Name);
	return Name;
}

void PrintName(string Name)
{
	cout << "Your Name is : " << Name << endl;

}


int main()
{
	string Name;
	PrintName(ReadName(Name));
	return 0;
}



*/

#include <iostream>
#include <string>

using namespace std;

string ReadName()
{
	string Name;
	cout << "Please enter Your Name : ";
	getline(cin, Name);
	return Name;
}

void PrintName(string Name)
{
	cout << "Your Name : " << Name << endl;
}


int main()
{

	
	PrintName(ReadName());

	return 0;
}