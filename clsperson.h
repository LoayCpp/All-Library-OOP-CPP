#pragma once
#include<iostream>
using namespace std;
class clsperson
{

	private:
		string _FirstName;
		string _LastName;
		string _Email;
		string _Phone;

public:

	clsperson(string FirsName, string LastName, string Email, string Phone) {

		_FirstName = FirsName;
		_LastName = LastName;
		_Email = Email;
		_Phone =Phone;
	}
	//Set and Get FirstName
	void SetFirsName(string FirstName) {
		_FirstName = FirstName;
	}
	string GetFirstName() {
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetLastName))string FirstName;


	//Set and Get LastName
	void SetLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName))string LastName;



	//Set and Get Email
	void SetEmail(string Email) {
		_Email = Email;
	}
	string GetEmail() {
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail))string Email;

	//Set and Get Phone
	void SetPhone(string phone) {
		_Phone = phone;
	}
	string GetPhone() {
		return _Phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone))string Phone;



};
