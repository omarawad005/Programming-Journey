
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void JoinString(vector <string> vString, string delim)
{
	string Message = "";
	vector <string>::iterator iter;


	for (iter = vString.begin(); iter != vString.end(); iter++)
	{
		Message = Message + *iter + delim;
	}

	Message = Message.substr(0, Message.length() - delim.length());
	cout << Message << endl;

}


void JoinString(string arr[], string delim, int arrlength)
{
	string Message = "";


	for (int i = 0; i < arrlength; i++)
	{
		Message = Message + arr[i] + delim;
	}

	Message = Message.substr(0, Message.length() - delim.length());
	cout << Message << endl;

}



int main()
{
	vector <string> vString{ "omar", "awad", "jalal", "alking" };
	string arrofstring[] = {"omar", "awad", "jalal", "alking"};

	cout << "Vector AFter join : \n";
	JoinString(vString, " ");

	cout << "\nArray AFter join : \n";
	JoinString(arrofstring, " ", arrofstring->length());
}
