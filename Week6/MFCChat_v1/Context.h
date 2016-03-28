#pragma once
#include"Account.h"

class Context
{
private:
	static Account account;
	static int id;
public:
	static void setAccount(Account);
	static Account getAccount();
	static void setIdAccount(int id);
	static int getIdAccount();
	Context::Context();
	Context::~Context();
};

