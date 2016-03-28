#pragma once
#include "Enitty.h"
 class User
{
public:
protected:
	int id_user;
	string email;
	string password;
	string username;
	string date_of_birth;
	string sex;
	string time_register;
	string avatar;
	string status;
	string address;
public:
	User();
	~User();
public:

	void setIdUser(int _id_user)
	{
		id_user = _id_user;
	}
	void setEmail(string _email)
	{
		email = _email;
	}
	void setPassword(string _password)
	{
		password = _password;
	}
	void setDateOfBirth(string _date_of_birth)
	{
		date_of_birth = _date_of_birth;
	}
	void setSex(string _sex)
	{
		sex = _sex;

	}
	void setUsername(string _user_name)
	{
		username = _user_name;
	}
	void setTimerRegister(string _time_register)
	{
		time_register = _time_register;
	}
	void setAvatar(string _avatar)
	{
		avatar = _avatar;
	}
	void setStatus(string _status)
	{
		status = _status;
	}
	void setAddress(string _address)
	{
		address = _address;
	}

	string getEmail()
	{
		return email;
	}
	string getPassoword()
	{
		return password;
	}
	string getTimeRegister()
	{
		return time_register;
	}
	string getDate_of_birth()
	{
		return date_of_birth;
	}
	string getSex()
	{
		return sex;
	}
	int getIdUser()
	{
		return id_user;
	}
	string getUsername()
	{
		return username;
	}
	string getAvatar()
	{
		return avatar;
	}
	string getStatus()
	{
		return status;
	}
	string getAddress()
	{
		return address;
	}
};

