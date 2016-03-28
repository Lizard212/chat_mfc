#include "stdafx.h"
#include "Context.h"

Account Context::account = Account();
int  Context::id;
void Context::setAccount(Account _account)
{
	Context::account = _account;
}

Account Context::getAccount()
{
	return Context::account;
}

void Context::setIdAccount(int _id)
{
	Context::id = _id;
}

int Context::getIdAccount()
{
	return Context::id;
}

Context::Context()
{
}


Context::~Context()
{
}
