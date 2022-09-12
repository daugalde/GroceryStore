#pragma once
#include <iostream>
#include <string>
using namespace std;

class Client : public Object {

private:
	int id = 0;
	string name = "";
	string phone = "";
	string mail = "";


public:  // Constructors

	Client() {}

	Client(int clientId, string clientName , string clientPhone, string clientMail )
	{
		id = clientId;
		name = clientName;
		phone = clientPhone;
		mail = clientMail;
	}

	string getPhone() {
		return this->phone;
	};

	void setPhone(string phone) {
		this->phone = phone;
	};

	string getEmail() {
		return this->name;
	};

	void setEmail(string mail) {
		this->mail = mail;
	};

	friend class List;
	//friend class FileLoader;
};
