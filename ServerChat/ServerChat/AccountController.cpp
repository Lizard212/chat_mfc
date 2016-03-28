#include "stdafx.h"
#include "AccountController.h"


string AccountController::Respond(string _request)
{
	Document d;
	d.Parse(_request.c_str());
	int temp_type = d["type"].GetInt();
	switch (temp_type)
	{
	case SELECT_USER:
		return "{\"type\":0,\"result\":\"" + SelectUser(_request) + "\"}";

	case INSERT_USER:
		           return "{\"type\":1,\"result\":\"" + InsertUser(_request) + "\"}";
	case LOGOUT:
		          return "logout";

	default:
		break;
	}

	return "false";
}

string AccountController::SelectUser(string _request)
{
	Document d;
	d.Parse(_request.c_str());
	assert(d["username"].GetString());
	string temp_user = d["username"].GetString();
	string temp_pass = d["password"].GetString();

	if (bus.CheckUser(temp_user, temp_pass))
	{
		return "true";
	}
	else
	{
		return "false";
	}

	
}

string AccountController::InsertUser(string _request)
{
	Document d;
	User u;
	d.Parse(_request.c_str());
	string temp_user = d["username"].GetString();
	string temp_email = d["email"].GetString();
	if (bus.CheckEmailUser(temp_user, temp_email ) == false)
	{
		return "false";
	}

	else
	{
		string temp_pass = d["password"].GetString();
		
		string temp_date_of_birth = d["date_of_birth"].GetString();
		string temp_sex = d["sex"].GetString();
		string temp_address = d["address"].GetString();

		u.setUsername(temp_user);
		u.setPassword(temp_pass);
		u.setEmail(temp_email);
		u.setSex(temp_sex);
		u.setDateOfBirth(temp_date_of_birth);
		u.setAddress(temp_address);
		bus.InsertUser(u);
		
		return "true";
	}
	
}

string AccountController::UpdateUser(string _request)
{
	return string();
}

string AccountController::DeleteUser(string _request)
{
	return string();
}

string AccountController::SelectUsers(string _request)
{

	return string();
}

string AccountController::Logout(string _request)
{
	return string();
}

AccountController::AccountController()
{
}


AccountController::~AccountController()
{
}
