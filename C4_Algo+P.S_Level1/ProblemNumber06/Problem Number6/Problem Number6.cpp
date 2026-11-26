/*
        #include <iostream>
        using namespace std;
        void ReadName(string &FirstName, string &LastName)
    {
        cout << "Please enter First Name : ";
        cin >> FirstName;
    
        cout << "Please enter Last Name : ";
        cin >> LastName;

    }
    string GetFullName(string FirstName, string LastName)
    {
        return FirstName + " " + LastName;
    }

    void PrintFullName(string FullName)
    {
        cout << "________________________________________________\n";
        cout << "\nYour Full Name is : " << FullName << endl;
    }

    int main ()
    {
      string First_Name, Last_Name;
    ReadName(First_Name, Last_Name);
    PrintFullName(GetFullName(First_Name, Last_Name));
        return 0;
    }


#include <iostream>

using namespace std;

struct stInfo
{
    string FirstName;
    string LastName;
};

stInfo ReadInfo()
{
    stInfo Info;

    cout << "Please enter your First_Name : ";
    cin >> Info.FirstName;

    cout << "Please enter your Last_Name  : ";
    cin >> Info.LastName;

    return Info;
}

string GetFullName(stInfo Info)
{
    string FullName = "";

    FullName = Info.FirstName + " " + Info.LastName;
    return FullName;
}

void PrintFullName(string FullName)
{
    cout << "\nYour Name : " << FullName << endl;
}

int main()
{
    

    PrintFullName(GetFullName(ReadInfo()));
    

    return 0;
}
*/
#include <iostream>
using namespace std;

struct stInfo
{
    string FirstName;
    string LastName;
};

stInfo ReadInfo()
{
    stInfo Info;
    cout << "Please enter your First Name : ";
    cin >> Info.FirstName;
    cout << "Please enter your Last Name : ";
    cin >> Info.LastName;

    return Info;
}

string GetFullName(stInfo Info)
{
    string FullName;

    FullName = Info.FirstName + " " + Info.LastName;

    return FullName;
}

void PrintFullName(string FullName)
{
    cout << "\nFull Name Is : " << FullName << endl;
}

int main()
{

    PrintFullName(GetFullName(ReadInfo()));

    return 0;
}