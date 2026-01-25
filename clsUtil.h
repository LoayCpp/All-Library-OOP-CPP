#pragma once

#include <iostream>
#include <cstdlib>
#include"clsDate.h"
using namespace std;
class clsUtil
{
public:
	
	static void Srand() {

		srand((unsigned)time(NULL));

	}
	static int RandomNumber(int from, int to) {

		return rand() % (to - from + 1) + from;
	}
	enum enCharTayp { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 ,All=5};
	static char GetRandomCharacter(enCharTayp CharType) {

		switch (CharType)
		{
		case enCharTayp::SmallLetter:
		{
			return char(RandomNumber(97, 122)); // char( 110 ) = n
			break;
		}
		case enCharTayp::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharTayp::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharTayp::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		case enCharTayp::All:
			return char(RandomNumber(33, 122));
			break;


		}
	}
static string GenerateWord(enCharTayp CharType, short Length)
	{
		string Word="";
		for (int i = 1; i <= Length; i++) 
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}
static string GenerateKey(enCharTayp CharType, short LengthWord=4,short LengthKey=4) {

	string word="";
	for (short i = 1; i <= LengthKey; i++) {
		
		word += GenerateWord(CharType, LengthWord) + "-";
	}
	return word.substr(0,word.length() - 1);

}
static void GenerateKeys(short HowManyKeys,enCharTayp CharType, short LengthWord=4, short LengthKey=4) {

	for (int i = 1; i <= HowManyKeys; i++)
	{
		cout << "Key [" << i << "] = " << GenerateKey(CharType, LengthWord, LengthKey) << endl;

	}

}
static void FillArrayWithRandomNumbers(int arr[100], int arrLength,int from ,int to)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(from, to);

	}

}
static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharTayp Chartype, short Lengthword)
{

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = GenerateWord(Chartype, Lengthword);

	}

}
static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharTayp Chartype) {

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = GenerateKey(Chartype);

	}


}
static void PrintFillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";

	}

}

static void Swap(int& Num, int& Num2) {

	int temp=0;
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(float& Num, float& Num2) {

	float temp=0;
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(string& Num, string& Num2) {

	string temp="";
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(char& Num, char& Num2) {

	char temp = ' ';
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(double& Num, double& Num2) {

	double temp =0;
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(bool& Num, bool& Num2) {

	bool temp;
	temp = Num;
	Num = Num2;
	Num2 = temp;
}
static void Swap(clsDate& Date, clsDate& Date2) {


	clsDate::SwapDates(Date, Date2);
}
static void ShuffleArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
	}
}
static void ShuffleArray(string arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
	}
}
static string Tabs(int num) {

	string Tab = "";
	for (int i = 1; i <= num; i++)
	{
		Tab += "\t";
	}
	return Tab;
}
static string EncryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = (char)int(Text[i]) + EncryptionKey;
	}
	return Text;
}
static string DecryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = (char)int(Text[i]) - EncryptionKey;
	}
	return Text;
}
};

