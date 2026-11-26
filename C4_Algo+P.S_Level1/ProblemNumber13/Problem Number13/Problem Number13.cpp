/*


#include <iostream>
using namespace std;

void ReadNumbers(int& N1, int& N2, int& N3)
{
    cout << "Please enter your Number 1 : ";
    cin >> N1;
    cout << "Please enter your Number 2 : ";
    cin >> N2;
    cout << "Please enter your Number 3 : ";
    cin >> N3;
}

float CheckMaxNumber(float N1, float N2, float N3)
{
    if (N1 > N2 && N1 > N3)
        return N1;
    else if (N2 > N3)
        return N2;
    else
        return N3;

    /*
        if (A > B)
        if (A > C)
            return A;
        else
            return C;

        else
            if(B > C)
                return B;
            else
                return C;


    //

}




void PrintAVE(float Max)
{
    cout << "\n--------------------------------------" << endl;
    cout << "\nThe Max Number is : " << Max << endl;
}


int main()
{
    int N1, N2, N3;
    ReadNumbers(N1, N2, N3);
    PrintAVE(CheckMaxNumber(N1, N2, N3));

    return 0;
}


*/
#include <iostream>

using namespace std;

struct stNumbers
{
    int num1;
    int num2;
    int num3;
};

stNumbers ReadNumbers()
{
    stNumbers N;
    cout << "Please enter Number1?\n";
    cin >> N.num1;
    cout << "Please enter Number2?\n";
    cin >> N.num2;
    cout << "Please enter Number3?\n";
    cin >> N.num3;

    return N;
}

int CheckMaxNumber(stNumbers Numbers)
{
    if (Numbers.num1 > Numbers.num2 && Numbers.num1 > Numbers.num3)
        return Numbers.num1;
    else if (Numbers.num2 > Numbers.num3)
        return Numbers.num2;
    else
        return Numbers.num3;
    
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
