
#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
    string S1;
    cout << "Enter Text : ";
    getline(cin, S1);

    return S1;
}

short CountCharacter(string S1, char C, bool MathCase = true)
{
    short Counter = 0;

    for (int i = 0; i < S1.length(); i++)
    {
        if (MathCase)
        {
            if (C == S1.at(i))
            {
              Counter++;

            }
        }
        else
        {
            if (tolower(C) == tolower(S1.at(i)))
            {
                Counter++;
            }
        }
    }

    return Counter;
}




void PrintResult(string S1)
{

    char c;
    cout << "\nPlease Enter a Character : ";
    cin >> c;

    short Counter = CountCharacter(S1, c);
    cout << "Letter '" << c << "' Count = " << Counter << endl;

    Counter = CountCharacter(S1, c, false);
    cout << "Letter '" << char(toupper(c)) << " Or " << char(tolower(c)) << "' Count = " << Counter << endl;



}


int main()
{
    string S1 = ReadText();

    PrintResult(S1);

    system("Pause > 0");
}
