/*
	

    #include <iostream>
    using namespace std;

    void ReadAge(unsigned short& Age)
    {
        cout << "Please enter your Age : ";
        cin >> Age;
    }

    string CheckAge(int Age)
    {
        if (Age >= 18 && Age <= 45)
            return "Valid Age.";
        else
            return "Invalid Age!";
    
    }
    void PrintResult(string Result)
    {
        cout << "\n" << Result << "\n" << endl ;
    }

    int main()
    {
    
        unsigned short Age;
        ReadAge(Age);
        PrintResult(CheckAge(Age));
        return 0;
    }

*/


#include <iostream>

using namespace std;

int ReadAge()
{
    int Age;

    cout << "Enter Your Age : ";
    cin >> Age;

    return Age;

}

bool IsValideAge(int age, int From, int To)
{
    return (age >= From && age <= To);
}

void PrintResult(int Age)
{
    if (IsValideAge(Age, 18, 45))
        cout << "\nValid Age ^-^  \n";
    else
        cout << "\nInValid Age ^+^  \n";

}




int main()
{


    PrintResult(ReadAge());

    return 0;
}