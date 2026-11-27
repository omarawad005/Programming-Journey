
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

enum enWhatToCount{ SmallLeter, CapitalLeter, All};

short CountLetter(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{

    int Counter = 0;
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length();
    }

    for (int i = 0; i < S1.length(); i++)
    {
        if(WhatToCount == enWhatToCount::CapitalLeter && isupper(S1.at(i)))
             Counter++;
   
        if(WhatToCount == enWhatToCount::SmallLeter && islower(S1.at(i)))
             Counter++;

    }
    return Counter;
}


short CountCapitalLetter(string S1)
{
    short Count = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1.at(i)))
            Count++;
    }
    return Count;
}
short CountSmallLetter(string S1)
{
    short Count = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (islower(S1.at(i)))
            Count++;
    }
    return Count;
}


void PrintResult(string S1)
{
    short CountLower = CountSmallLetter(S1);
    short CountUpper = CountCapitalLetter(S1);
    cout << "\n---------------------------------------\n";
    cout << "\nString Length : " << S1.length() << endl;
    cout << "Number Of Lower Character : " << CountLower << endl;
    cout << "Number Of Upper Character : " << CountUpper << endl;
    cout << "\n---------------------------------------\n";


     CountLower = CountLetter(S1, enWhatToCount::SmallLeter);
     CountUpper = CountLetter(S1,enWhatToCount::CapitalLeter);
    cout << "\n---------------------------------------\n";
    cout << "\nString Length : " << S1.length() << endl;
    cout << "Number Of Lower Character : " << CountLower << endl;
    cout << "Number Of Upper Character : " << CountUpper << endl;



}




int main()
{
    string S1 = ReadText();

    PrintResult(S1);
    
    system("Pause > 0");
}
