/*
#include <iostream>
using namespace std;

void ReadNumbers(int& N1, int& N2)
{
    cout << "Please enter your Number 1 : ";
    cin >> N1;
    cout << "Please enter your Number 2 : ";
    cin >> N2;
}

int CheckMaxNumber(int N1, int N2)
    {

        if (N1 > N2)
            return N1;
        else
            return N2;
 
    }

void PrintAVE(int Max)
    {
        cout << "\n--------------------------------------" << endl;
        cout << "\nThe Max Number is : " << Max << endl;
    }

int main()
{
    int N1, N2;
    ReadNumbers(N1, N2);
    PrintAVE(CheckMaxNumber(N1,N2));

    return 0;
}*/
#include <iostream>

using namespace std;

struct stNumbers
{
    int num1;
    int num2;
};

stNumbers ReadNumbers()
{
    stNumbers N;
    cout << "Please enter Number1?\n";
    cin >> N.num1;
    cout << "Please enter Number2?\n";
    cin >> N.num2;

    return N;
}

int CheckMaxNumber(stNumbers Numbers)
{
    if (Numbers.num1 > Numbers.num2)
        return Numbers.num1;
    else
        return Numbers.num2;
}

void PrintMaxNumber(int Num)
{
    
        cout << "\nMax Number Is : " << Num << endl;
}


int main()
{

    PrintMaxNumber(CheckMaxNumber(ReadNumbers()));


    return 0;
}


