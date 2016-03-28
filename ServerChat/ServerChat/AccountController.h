#pragma once
#include"Controller.h"

class AccountController:public Controller
{
private:
	Bus bus;
public:
	string Respond(string _request);
private:
	string SelectUser(string _request);
	string InsertUser(string _request);
	string UpdateUser(string _request);
	string DeleteUser(string _request);
	string SelectUsers(string _request);
	string Logout(string _request);
public:
	AccountController();
	~AccountController();
};

