#include "stdafx.h"
#include "AccountRepository.h"


bool AccountRepository::Check(string _email, string _password)
{


	ConnectDB();

	string _query = "SELECT email,password FROM Account WHERE email = \'"
		+ _email + "\' AND password = \'" + _password + "\'";
	const char *query = _query.c_str();

	char **results = NULL;
	int rows, columns;

	sqlite3_get_table(filename, query, &results, &rows, &columns, &error);

	if (rows == 0) { DisconnectDB(); return false; }
	else { DisconnectDB(); return true; }

	return false;
}

bool AccountRepository::checkEmail(string _email)
{

	ConnectDB();

	string _query = "SELECT email,password FROM Account WHERE email = \'"
		+ _email + "\'";
	const char *query = _query.c_str();

	char **results = NULL;
	int rows, columns;
	sqlite3_get_table(filename, query, &results, &rows, &columns, &error);

	if (rows == 0) { DisconnectDB(); return false; }

	else { DisconnectDB(); return true; }

	return false;
}

Account AccountRepository::Select(string _email)
{
	ConnectDB();

	string _query = "SELECT * FROM Account WHERE email = \'" + _email + "'\;";
	const char *query = _query.c_str();

	char **results = NULL;
	int rows, columns;
	sqlite3_get_table(filename, query, &results, &rows, &columns, &error);
	int col = columns -1;
	int id = stoi(string(results[10 + 1]));

	Account account;
	account.setIdAccount(id);
	account.setEmail(string(results[col + 2]));
	account.setPhone(string(results[col + 3]));
	account.setPassword(string(results[col + 4]));
	account.setFirstName(string(results[col + 5]));
	account.setLastName(string(results[col + 6]));

	account.setDateOfBirth(string(results[col + 7]));
	account.setSex(string(results[col + 8]));
	account.setDateCreation(string(results[col + 9]));
	account.setAvatar(string(results[col + 10]));
	account.setStatus(string(results[col + 11]));
	


	return account;
		

}



void AccountRepository::Insert(Account account)
{

	ConnectDB();
	string comma = "','";
	string s = "INSERT INTO Account(email,phone_number,password,first_name,last_name,date_of_birth,sex,avatar,status)VALUES('"
		+ account.getEmail() + comma
		+ account.getPhoneNumber() + comma
		+ account.getPassoword() + comma
		+ account.getFirstName() + comma
		+ account.getLastName() + comma
		+ account.getDate_of_birth() + comma
		+ account.getSex() + comma
		+ account.getAvatar() + comma
		+ account.getStatus() + "');";


	const char *query = s.c_str();
	rc = sqlite3_exec(filename, query, NULL, NULL, &error);

}

string AccountRepository::selectEmail(int _id)
{
	ConnectDB();

	string _query = "SELECT * FROM Account WHERE id_account = \'" + to_string(_id) + "'\;";
	const char *query = _query.c_str();

	char **results = NULL;
	int rows, columns;
	sqlite3_get_table(filename, query, &results, &rows, &columns, &error);
	int col = columns - 1;
	Account account;
	account.setEmail(results[col + 2]);
	return account.getEmail();
}





AccountRepository::AccountRepository()
{
}


AccountRepository::~AccountRepository()
{
}
