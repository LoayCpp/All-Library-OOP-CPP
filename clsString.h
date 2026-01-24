#pragma once
#include<iostream>
#include <string>
#include <vector>
using namespace std;
class clsString
{
private:
	string _Value;
public:
	enum enWhatletter
	{
		Small = 0,
		Capital = 1,
		All = 2,
		Characters = 3
	};
	clsString() {

		_Value = " ";
	}
	clsString(string Value) {

		_Value = Value;
	}
	

	void setValue(string Value) {
		_Value = Value;
	}
	string GetValue() {


		return _Value;
	}

	
	
	__declspec(property(get = GetValue, put = setValue))string Value;
	static short Length(string name) {

		return name.length();
	}
	short Length() {


		return _Value.length();
	}
static	void PrintFirstlatter(string name) {

		bool firsnumber = true;
		for (short i = 0; i < name.length(); i++)
		{
			if (name[i] != ' ' && firsnumber) {

				cout << name[i] << endl;
			}
			firsnumber = name[i] == ' ' ? true : false;
		}

	}
void PrintFirstlatter() {


	PrintFirstlatter(_Value);
}
static short CountWords(string S1)
{

	string delim = " "; // delimiter  
	short Counter = 0;
	short pos = 0;
	string sWord; // define a string variable  

	// use find() function to get the position of the delimiters  
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word   
		if (sWord != "")
		{
			Counter++;
		}

		//erase() until positon and move to next word.
		S1.erase(0, pos + delim.length());
	}

	if (S1 != "")
	{
		Counter++; // it counts the last word of the string.
	}

	return Counter;

}
short CountWords() {


	return CountWords(_Value);
}
static string UpperFirstLetterOfEachWord(string name) {

	bool firsnumber = true;
	for (short i = 0; i < name.length(); i++)
	{
		if (name[i] != ' ' && firsnumber) {

			name[i] = toupper(name[i]);
		}
		firsnumber = name[i] == ' ' ? true : false;
	}
	return name;
}
void UpperFirstLetterOfEachWord() {

_Value=UpperFirstLetterOfEachWord(_Value);
}
static string SmallFirstLatter(string name) {

	bool firsnumber = true;
	for (short i = 0; i < name.length(); i++)
	{
		if (name[i] != ' ' && firsnumber) {

			name[i] = tolower(name[i]);
		}
		firsnumber = name[i] == ' ' ? true : false;
	}
	return name;
}
void SmallFirstLatter() {


	_Value= SmallFirstLatter(_Value);
}
static string  Allcapital(string name) {

	for (int i = 0; i < name.length(); i++)
	{
		name[i] = toupper(name[i]);
	}
	return name;
}
static string Allsmall(string name) {

	for (int i = 0; i < name.length(); i++)
	{
		name[i] = tolower(name[i]);
	}
	return name;
}
void  Allcapital() {

	_Value = Allcapital(_Value);
 }
void Allsmall() {

	_Value = Allsmall(_Value);
 }
static char Convert(char ch) {


	return isupper(ch) ? tolower(ch) : toupper(ch);
}

static bool IsVowelLatter(char Latter) {


	Latter = tolower(Latter);

	return ((Latter == 'a') || (Latter == 'e') || (Latter == 'o') || (Latter == 'i') || (Latter == 'u'));
}
static vector<string>split(string name, string delim) {
	vector<string> S;
	string word;
	short pos = 0;
	while ((pos = name.find(delim)) != std::string::npos)
	{

		word = name.substr(0, pos);
		if (word != "") {

			S.push_back(word);
		}
		name.erase(0, pos + delim.length());
	}
	if (name != "") {
		S.push_back(name);

	}
	return S;
}
vector<string> split(string Delim) {


	return split(_Value, Delim);

}
static string SmallToCapitalAndViceVarsa(string name) {

	for (int i = 0; i < name.length(); i++)
	{
		name[i] = Convert(name[i]);
	}
	return name;
}
string SmallToCapitalAndViceVarsa() {

	_Value = SmallToCapitalAndViceVarsa(_Value);
}

static short CountLetter(string name, enWhatletter what = enWhatletter::All) {
	short count = 0;
	if (what == enWhatletter::All) {

		return name.length();
	}

	for (short i = 0; i < name.length(); i++)
	{
		if (what == enWhatletter::Small && islower(name[i])) {

			count++;
		}
		if (what == enWhatletter::Capital && isupper(name[i])) {

			count++;
		}
		if (what == enWhatletter::Characters && !isupper(name[i]) && !islower(name[i]))
		{
			count++;
		}

	}


	return count;

}
short CountLetter(enWhatletter What=enWhatletter::All) {

	return CountLetter(_Value, What);

}
static short CoutnLatterInWord(string name, char ch, bool check = true) {
	short count = 0;
	for (short i = 0; i < name.length(); i++)
	{
		if (check) {
			if (ch == name[i]) {
				count++;
			}
		}
		else {

			if (tolower(name[i]) == tolower(ch)) {

				count++;
			}
		}
	}
	return count;
}
short CoutnLatterInWord(char ch,bool CheckCapitalOrSmall=true){

	return CoutnLatterInWord(_Value,ch,CheckCapitalOrSmall);
 }
 static short CountVowelLatter(string word) {
	short count = 0;
	for (short i = 0; i < word.length(); i++) {


		if (IsVowelLatter(word[i])) {


			count++;
		}




	}
	return count;

}
 short CountVowelLatter() {


	return  CountVowelLatter(_Value);
 }
 static void PrintVowelLatterInWord(string word) {

	 for (short i = 0; i < word.length(); i++) {


		 if (IsVowelLatter(word[i])) {


			 cout << word[i] << " ";
		 }




	 }


 }
 void PrintVowelLatterInWord() {

	  PrintVowelLatterInWord(_Value);
 }

 static void PrintWordInStirng(string word) {

	 for (short i = 0; i < word.length(); i++) {


		 word[i] != ' ' ? cout << word[i] : cout << endl;
	 }
 }
 void PrintWordInStirng() {

	 PrintWordInStirng(_Value);
 }
 static string leftTrim(string name) {

	 for (short i = 0; i < name.length(); i++) {

		 if (name[i] != ' ') {

			 return (name.substr(i, name.length() - i));
		 }


	 }
	 return "";


 }
 static string RightTrim(string name) {

	 for (short i = name.length() - 1; i >= 0; i--) {

		 if (name[i] != ' ') {

			 return (name.substr(0, i + 1));
		 }


	 }
	 return "";


 }
 static string Trim(string name) {


	 return (leftTrim(RightTrim(name)));
 }
 void leftTrim() { _Value = leftTrim(_Value); }
 void RightTrim() { _Value = RightTrim(_Value); }
 void Trim() { _Value = Trim(_Value); }
 
 static string JoinString(vector<string>word, string delim) {


	 string name = "";

	 for (string& line : word) {


		 name += line + delim;

	 }

	 return   name.substr(0, (name.length() - delim.length()));
 }
 
 static string JoinString(string arr[], short size, string delim) {

	 string name;
	 for (short i = 0; i < size; i++) {


		 name += arr[i] + delim;
	 }
	 return name.substr(0, name.length() - delim.length());

 }
 

 static string ReversWord(string name,string delim) {
    vector<string> Vname=split(name,delim);
    string S1 = "";
    vector<string>::iterator iter = Vname.end();

    while (iter != Vname.begin()) {

        --iter;
        S1 += *iter +delim;
       
       
    }
    return S1.substr(0,S1.length()-delim.length());
}
 void ReversWord(string Delim) {


	 _Value = ReversWord(_Value, Delim);
 }
 static string Replace(string name, string from, string to,string Delim, bool UseCase) {

	 vector<string>word = split(name,Delim);



	 for (string& line : word) {


		 if (UseCase) {
			 if (line == from) {


				 line = to;
			 }


		 }
		 else {

			 if (Allsmall(line) == Allsmall(from)) {

				 line = to;
			 }


		 }

	 }

	 return JoinString(word, " ");



 }
 void Replace(string from ,string to,string Delim,bool UseCase) {


	 _Value = Replace(_Value, from, to,Delim, UseCase);

 }
 static string Replace(string name, string from, string to) {

	 

	 short pos = name.find(from);
	 while (pos != string::npos) {


		 name.replace(pos, from.length(), to);
		 pos = name.find(from);
	 }


	 return name;
 }
 void Replace(string from,string to) {


	 _Value = Replace(_Value, from, to);
 }
 static string RemovePunctuation(string name) {


	 string S = "";
	 for (short i = 0; i < name.length(); i++)
	 {
		 if (!ispunct(name[i])) {

			 S += name[i];
		 }
	 }

	 return S;
 }
 void RemovePunctuation() {


	 _Value = RemovePunctuation(_Value);
 }

};

