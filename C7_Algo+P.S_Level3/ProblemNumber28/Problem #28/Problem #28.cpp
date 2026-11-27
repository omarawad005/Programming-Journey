
#include <iostream>
#include <string>

using namespace std;

string ReadText()
{
    string Message;
    cout << "Enter text : ";
    getline(cin, Message);

    return Message;
}

char InvertCharacter(char c)
{

    return (islower(c) ? toupper(c) : tolower(c));

}


string InvertedAllCharacter(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1.at(i) = InvertCharacter(S1.at(i));
    }
    return S1;
}




int main()
{
    string S1 = ReadText();

    S1 = InvertedAllCharacter(S1);
    cout << "\nText after Invert : " << S1 << endl;
    system("Pause > 0");
}
