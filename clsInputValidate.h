#pragma once
#include <iostream>
#include"clsDate.h"
#include<string>
#include"clsString.h"
using namespace std;
class clsInputValidate
{
public:
	static bool IsNumberBetween(int Num, int from, int to) {

		return (Num >= from && Num <= to);
	}
	static bool IsNumberBetween(short Num, short from, short to) {

		return (Num >= from && Num <= to);
	}
	static bool IsNumberBetween(float Num, float from, float to) {

		return (Num >= from && Num <= to);
	}
	static bool IsNumberBetween(double Num, double from, double to) {

		return (Num >= from && Num <= to);
	}
	static bool  IsDateBetween(clsDate Date, clsDate From, clsDate To) {


		if ((Date.IsDateBeforeDate2(To) || Date.IsDateEqualDate2(To)) && (Date.IsDateAfterDate2(From) || Date.IsDateEqualDate2(From)))
			return true;

		else if ((Date.IsDateBeforeDate2(From) || Date.IsDateEqualDate2(From)) && (Date.IsDateEqualDate2(To) || Date.IsDateAfterDate2(To)))
			return true;

		return false;
	}
	static int ReadIntNumber(string ErrorMessage= "Invalid Number, Enter again : \n") {
		int Num=0;
		while (!(cin >> Num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
			
		}
		return Num;
	}
	static int ReadIntNumberBetween(int from, int to, string message="Number is not within range, Enter again") {
		int Num = ReadIntNumber();
		
		
		while (!IsNumberBetween(Num, from, to)) {
			cout << message;
			Num = ReadIntNumber();

		}
		return Num;
		
	}
	static double ReadDblNumber(string message= "Invalid Number, Enter again : \n") {
		double Num =0;
		
		while (!(cin >> Num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
		
		}
		return Num;
	}
	static double ReadDblNumberBetween(double from, double to, string message="Number is not within range, Enter again") {
		double Num = ReadDblNumber();
		
		while (!IsNumberBetween(Num, from, to)) {

			cout << message;
			Num = ReadDblNumber();

		}
		return Num;

	}
	static bool IsValidDate(clsDate Date) {


	return	clsDate::IsValidDate(Date);
	}
};

