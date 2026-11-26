/*
/*int ReadNumber()
{
    int Num;
    cout << "Please enter a number : ";
    cin >> Num;

    return Num;
}

string CheckOddEven(int Num)
{
    if (Num % 2 == 0)
        return "Even";
    else
        return "Odd";
}

void Printresult(int Num)
{

    cout << "\nThe Number [" << Num << "] is ==> " << CheckOddEven(Num) << endl;

}


int main()
{

    Printresult(ReadNumber());

    return 0;
}
    }



#include <iostream>
using namespace std;

enum enNumberType { Odd = 1, Even = 2 };

int ReadNumber()
{
    int Number;
    cout << "Please enter Number : ";
    cin >> Number;
    return Number;
}

enNumberType CheckNumber(int Number)
{
    int Result = Number % 2;
    if (Result == 0)
        return enNumberType::Even;
    else
        return enNumberType::Odd;

}

void PrintResult(enNumberType NumberType)
{
    if (NumberType == enNumberType::Even)
        cout << "\n Number is Even \n";
    else
        cout << "\n Number is Odd \n";
}

int main()
{
    PrintResult(CheckNumber(ReadNumber()));

    return 0;
}


*/

#include <iostream>
using namespace std;

enum enNumberType
{
    ODD,
    EVEN
};

int ReadNumber()
{
    int Num;
    cout << "Please enter Number : ";
    cin >> Num;
    return Num;
}

enNumberType CheckNumber(int Num)
{
    if (Num % 2 == 0)
        return enNumberType::EVEN;
    else
        return enNumberType::ODD;
    
}

void PrintResult(enNumberType type)
{
    if (type == enNumberType::EVEN)
    {
        cout << "Number is Even ? \n";
    }
    else
    {
        cout << "Number is Odd ? \n";
    }
}


int main()
{

    PrintResult(CheckNumber(ReadNumber()));

    return 0;
}