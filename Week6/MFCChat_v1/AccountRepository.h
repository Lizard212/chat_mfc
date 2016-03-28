#pragma once
#include "Repository.h"
#include"sqlite3.h"
#include"Account.h"
#include<string>
#include<string.h>
class AccountRepository :
	public Repository
{
protected:
	 char * error;
	 int rc;
public:
	 bool Check(string _email, string _password);
	 bool checkEmail(string _email);
	 Account Select(string _email);
	 void Insert(Account);

	 string selectEmail(int _id);
	AccountRepository();
	~AccountRepository();
};

