#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class clsString
{
private:
	string _Value;



public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return _Value.length();
	}

	static char ReadChar()
	{
		char L;
		cout << "Please enter Char : ";
		cin >> L;
		return L;
	}
	static bool IsMatchCase()
	{
		char Answer;
		cout << "You Want Math Case [Y/N] : ";
		cin >> Answer;
		return (toupper(Answer) == 'Y') ? true : false;
	}

	static char InvertLetterCase(char Char1)
	{
		return isupper(Char1) ? tolower(Char1) : toupper(Char1);
	}
	static bool IsVowel(char Letter)
	{
		char arrVowel[] = { 'a', 'e', 'i', 'o', 'u' };
		for (int i = 0; i < 5; i++)
		{
			if (tolower(Letter) == arrVowel[i])
			{
				return true;
			}
		}

		return false;
	}

	static int CountEachWordInString(string S1)
	{
		int Counter = 0;

		short Pos = 0;
		string delim = " ";
		string Word;

		while ((Pos = S1.find(delim)) != string::npos)
		{
			Word = S1.substr(0, Pos);
			if (Word != "")
			{
				Counter++;
			}
			S1.erase(0, Pos + delim.length());
		}
		if (S1 != "")
		{
			Counter++;

		}
		return Counter;
	}
	int CountEachWordInString()
	{
		return CountEachWordInString(_Value);
	}

	static string UperFirstLetterOfEachWord(string S1)
	{
		bool IsFirstCharacter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1.at(i) != ' ' && IsFirstCharacter)
			{
				S1[i] = toupper(S1[i]);
			}

			IsFirstCharacter = (S1.at(i) == ' ' ? true : false);
		}
		return S1;
	}
	void UperFirstLetterOfEachWord()
	{
		_Value = UperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool IsFirstCharacter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1.at(i) != ' ' && IsFirstCharacter)
			{
				S1[i] = tolower(S1[i]);
			}

			IsFirstCharacter = (S1.at(i) == ' ' ? true : false);
		}
		return S1;
	}
	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}


	static string InvertAllStringLetterCase(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	void InvertAllStringLetterCase()
	{
		_Value = InvertAllStringLetterCase(_Value);
	}

	static short CountCapitalLetters(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetters(string S1, char L)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] == L)
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountSpecificLetters()
	{
		return CountSpecificLetters(_Value, ReadChar());
	}

	static short CountSpecificLettersMatchCase(string S1, char L, bool MatchCase = true)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == L)
				{
					Counter++;
				}
			}
			else
			{
				if (tolower(S1[i]) == tolower(L))
				{
					Counter++;
				}
			}
		}
		return Counter;
	}
	short CountSpecificLettersMatchCase()
	{
		return CountSpecificLettersMatchCase(_Value, ReadChar(), IsMatchCase());
	}

	static short CountVowelCharacter(string S1)
	{
		short Count = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1.at(i)))
			{
				Count++;
			}
		}

		return Count;
	}
	short CountVowelCharacter()
	{
		return CountVowelCharacter(_Value);
	}

	static vector <string> SplitString(string S1, string delim)
	{
		vector <string> vSplitS1;
		int pos = 0;
		string sWord = "";
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				vSplitS1.push_back(sWord);
			}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			vSplitS1.push_back(S1);
		}
		return vSplitS1;
	}
	vector <string> SplitString(string Delim)
	{
		return SplitString(_Value, Delim);
	}

	static void PrintFirstLetterOfEachWord(string S1)
	{

		bool IsFirstCharacter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1.at(i) != ' ' && IsFirstCharacter)
			{
				cout << S1.at(i) << endl;
			}

			IsFirstCharacter = (S1.at(i) == ' ' ? true : false);
		}

	}
	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	string UpperAllString()
	{
		return UpperAllString(_Value);
	}

	static string LowerAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	string LowerAllString()
	{
		return LowerAllString(_Value);
	}

	static string JoinString(vector<string> vWords, string Delim = " ")
	{
		string S1 = "";

		for (string& s : vWords)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}
	static string JoinString(string arr[], string delim, int arrlength)
	{
		string S1 = "";


		for (int i = 0; i < arrlength; i++)
		{
			S1 = S1 + arr[i] + delim;
		}

		return S1.substr(0, S1.length() - delim.length());

	}

	static string ReverseString(string S1)
	{
		vector <string> vWords = SplitString(S1, " ");
		vector <string>::iterator iter = vWords.end();

		string NewString = "";

		while (iter != vWords.begin())
		{
			--iter;
			NewString += *iter + " ";
		}

		return NewString = NewString.substr(0, NewString.length() - 1);
	}
	void ReverseString()
	{
		_Value = ReverseString(_Value);
	}

	static string ReplaceString(string S1, string OldWord, string NewWord)
	{
		short Pos = S1.find(OldWord);

		while (Pos != string::npos)
		{
			S1 = S1.replace(Pos, OldWord.length(), NewWord);
			Pos = S1.find(OldWord);
		}
		return S1;
	}
	string ReplaceString(string OldValue, string NewValue)
	{
		return ReplaceString(_Value, OldValue, NewValue);
	}

	static string RemovePunctuation(string S1)
	{
		string NewString = "";
		for (int i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				NewString += S1[i];
			}
		}

		return NewString;
	}
	string RemovePunctuation()
	{
		return RemovePunctuation(_Value);
	}

	static void PrintAllVowelCharacter(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1.at(i)))
			{
				cout << S1.at(i) << " ";
			}
		}

	}
	void PrintAllVowelCharacter()
	{
		PrintAllVowelCharacter(_Value);
	}

	static void PrintEachWordInString(string S1)
	{

		string delim = " "; // ==> Delimiter

		cout << "Your String Words are : \n";
		short Pos = 0;
		string Word;

		while ((Pos = S1.find(delim)) != string::npos)
		{
			Word = S1.substr(0, Pos);
			if (Word != "")
			{
				cout << Word << endl;
			}
			S1.erase(0, Pos + delim.length());
		}
		if (S1 != " ")
		{
			cout << S1 << endl;
		}

	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static string TrimLeft(string S1)
	{
		if (S1.empty())
			return S1;

		int counter = 0;
		while (counter < S1.length() && S1[counter] == ' ')
			counter++;

		return S1.erase(0, counter);
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		if (S1.empty()) return S1;

		int counter = S1.length() - 1;
		while (counter >= 0 && S1[counter] == ' ')
			counter--;

		return S1.substr(0, counter + 1);
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string TrimRightAndLeft(string S1)
	{
		S1 = TrimLeft(TrimRight(S1));
		return S1;
	}
	void TrimRightAndLeft()
	{
		_Value = TrimRightAndLeft(_Value);
	}



};

