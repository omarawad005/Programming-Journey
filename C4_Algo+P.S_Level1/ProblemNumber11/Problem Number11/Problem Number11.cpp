

#include <iostream>
using namespace std;

enum enPassFail
{
    Pass,
    Fail 
};

void ReadNumbers(int& N1, int& N2, int& N3)
{
    cout << "Please enter your Number 1 : ";
    cin >> N1;
    cout << "Please enter your Number 2 : ";
    cin >> N2;
    cout << "Please enter your Number 3 : ";
    cin >> N3;
}

float SumOfNumbers(float N1, float N2, float N3)
{
    return (N1 + N2 + N3)  ;
}

float CalculateAverage(float N1, float N2, float N3)
{
    return SumOfNumbers(N1, N2, N3) / 3;
}

enPassFail CheckPassOrFail(float ave)
{
    if (ave >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void PrintAVE(float ave)
{
    cout << "Your Ave Is : " << ave << endl;
    if (CheckPassOrFail(ave) == enPassFail::Pass)
        cout << "Passed\n";
    else
        cout << "Failed\n";

} 


int main()
{
    int N1, N2, N3;

    ReadNumbers(N1, N2, N3);

    PrintAVE((CalculateAverage(N1, N2, N3)));
   


    return 0;
}
