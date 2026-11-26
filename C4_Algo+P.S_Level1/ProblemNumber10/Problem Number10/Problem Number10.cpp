

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
int SumOfNumbers(int N1, int N2, int N3)
{
    return N1 + N2 + N3;
}

float AveOfNumbers(float N1, float N2, float N3)
{
    return SumOfNumbers(N1 , N2 , N3) / 3;
}

void PrintAVE(float ave)
{
    cout << "\nThe Ave Of three Numbers is : " << ave << endl;
}


int main()
{
    int N1, N2, N3;
    ReadNumbers(N1, N2, N3);
    PrintAVE(AveOfNumbers(N1, N2, N3));



    return 0;
}
