#pragma once
#include<iostream>
#include"clsperson.h"
#include<fstream>
#include<string>
#include"clsString.h"
#include<vector>
using namespace std;
class clsBankClient :public clsperson
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1};
	string _AccountNumber;
	string _PinCode;
	double _Balance;
	enMode _Mode;
	static clsBankClient _ConvertLineClientToObject(string Line,string Delim="#//#") {

		vector<string> vClientData = clsString::Split(Line,Delim);
		return clsBankClient(UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

	}
	static clsBankClient _GetEmptyClientObject() {

		return clsBankClient(enMode::EmptyMode, " ", " ", " ", " ", " ", " ",0);

	}

public:
	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode,double  Balance)
		:clsperson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_Balance = Balance;
	}
	bool IsEmpty() {

		return _Mode == enMode::EmptyMode;
	}
	string GetAccountNumber() {

		return _AccountNumber;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string  GetPinCode() { return _PinCode; }

	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;


	void SetBalance(double Balance) {
		_Balance = Balance;
	}

	double GetBalance() { return _Balance; }
	__declspec(property(get = GetBalance, put = SetBalance))double Balance;

	void Print() {

		cout << "\n-----Info Client----------\n";
		cout << "FirstName        :"<< GetFirstName() << endl;
		cout << "LastName         :" << GetLastName() << endl;
		cout << "Email            :" << GetEmail() << endl;
		cout << "Phone            :" << GetPhone() << endl;
		cout << "AccountNumber    :" << _AccountNumber << endl;
		cout << "PinCode          :" << _PinCode << endl;
		cout << "Balance          :" << _Balance << endl;
		cout << "----------------------------------------\n";



	}

	static clsBankClient Find(string AccountNumber) {


		fstream myfile;
		string Line;
		vector<clsBankClient> Vclient;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open()) {

			while (getline(myfile, Line)) {

				clsBankClient Client = _ConvertLineClientToObject(Line);

				if (Client.GetAccountNumber() == AccountNumber) {
					myfile.close();
					return Client;

				}
			}
			myfile.close();
		}
		

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber,string PinCode) {


		fstream myfile;
		string Line;
		vector<clsBankClient> Vclient;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open()) {

			while (getline(myfile, Line)) {

				clsBankClient Client = _ConvertLineClientToObject(Line);

				if (Client._AccountNumber == AccountNumber && Client.PinCode==PinCode) {
					myfile.close();
					return Client;

				}
			}
			myfile.close();
		}


		return _GetEmptyClientObject();
	}

	static bool IsExitsClient(string AccountNumber) {

		clsBankClient Client =clsBankClient::Find(AccountNumber);

		return (!Client.IsEmpty());
	}


};

