#pragma once
#include "DataAccess.h"
#include "User.h"
class AccountRepository:public DataAccess
{

public:
	bool Check(string _email, string _password);
	bool CheckEmail(string _email, string _username);
	User Select(string _email);
	bool CheckUsername(string _username);

	void Insert(User);
	void Delete(int _id);
	string SelectEmail(int _id);
	int SelectId(string _username);
public:
	AccountRepository();
	~AccountRepository();
};

