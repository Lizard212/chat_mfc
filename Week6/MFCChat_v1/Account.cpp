#include "stdafx.h"
#include "Account.h"



Account::Account()
{
	id_account = 0;
	email = "";
	phone_number = "";
	password = "";
	first_name = "";
	last_name = "";
	date_of_birth = "";
	sex = "";
	date_creation = "";
	avatar = "";
	status = "";
}

Account::Account(int _id_account, string _email, string _phone, string _password
	, string _firstname, string _lastname, string _date_of_birth, string _sex, string _date_creation, string _avatar, string _status)
{
	id_account = _id_account;
	email = _email;
	phone_number = _phone;
	password = _password;
	first_name = _firstname;
	last_name = _lastname;
	date_of_birth = _date_of_birth;
	sex = _sex;
	date_creation = _date_creation;
	avatar = _avatar;
	status = _status;

}


Account::~Account()
{
}
