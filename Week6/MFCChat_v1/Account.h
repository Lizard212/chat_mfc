#pragma once
#include"Entity.h"
#include<iostream>

using namespace std;
class Account :public Entity
{
protected:
	int id_account;
	string email;
	string phone_number;
	string password;
	string first_name;
	string last_name;
	string date_of_birth;
	string sex;
	string date_creation;
	string avatar;
	string status;
public:
	Account();
	Account(int, string, string, string, string, string, string, string, string, string, string);

	void setIdAccount(int _id_account)
	{
		id_account = _id_account;
	}
	void setEmail(string _email)
	{
		email = _email;
	}
	void setPhone(string _phone)
	{
		phone_number = _phone;
	}
	void setPassword(string _password)
	{
		password = _password;
	}
	void setFirstName(string _firstname)
	{
		first_name = _firstname;
	}
	void setLastName(string _lastName)
	{
		last_name = _lastName;
	}
	void setDateOfBirth(string _date_of_birth)
	{
		date_of_birth = _date_of_birth;
	}
	void setSex(string _sex)
	{
		sex = _sex;

	}

	void setDateCreation(string _date_creation)
	{
		date_creation = _date_creation;
	}
	void setAvatar(string _avatar)
	{
		avatar = _avatar;
	}
	void setStatus(string _status)
	{
		status = _status;
	}
	int getIdAccount()
	{
		return id_account;
	}

	string getEmail()
	{
		return email;
	}
	string getPhoneNumber()
	{
		return phone_number;
	}

	string getPassoword()
	{
		return password;
	}
	string getFirstName()
	{
		return first_name;
	}
	string getLastName()
	{
		return last_name;
	}
	string getDate_of_birth()
	{
		return date_of_birth;
	}
	string getSex()
	{
		return sex;
	}

	string getDateCreation()
	{
		return date_creation;
	}
	string getAvatar()
	{
		return avatar;
	}
	string getStatus()
	{
		return status;
	}

	~Account();
};




