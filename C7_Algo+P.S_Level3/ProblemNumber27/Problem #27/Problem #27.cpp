
#include <iostream>
#include <string>

using namespace std;

char ReadCharacter()
{
    char c;
    cout << "Enter Character : ";
    cin >> c;

    return c;
}

char InvertCharacter(char c)
{
    
    return (islower(c) ? toupper(c) : tolower(c) );

}



int main()
{
    char c = ReadCharacter();
    cout << "\nCharacter after Invert : " << InvertCharacter(c) << endl;
    system("Pause > 0");
}
