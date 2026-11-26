

#include <iostream>
using namespace std;

void ReadNumbers(int &N1, int &N2, int &N3)
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

void PrintSUM(int sum)
{
    cout << "\nThe Sum Of three Numbers is : " << sum << endl;
}


int main()
{
    int N1,N2,N3;
    ReadNumbers(N1, N2, N3);
    PrintSUM(SumOfNumbers(N1, N2, N3));



    return 0;
}
