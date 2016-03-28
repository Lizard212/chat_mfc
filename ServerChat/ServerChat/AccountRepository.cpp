#include "stdafx.h"
#include "AccountRepository.h"


bool AccountRepository::Check(string _email, string _password)
{

	string _query = "SELECT * FROM User WHERE email = \'"
		+ _email + "\' AND password = \'" + _password + "\';";

	char **results = NULL;
	int rows = 0, columns = 0;
	ConnectDB();
	results = ExecuteTable(_query, rows, columns);

	if (rows == 0) {  return false; }
	else {  return true; }

	return false;
}

bool AccountRepository::CheckEmail(string _email , string _username)
{
	

	string _query = "SELECT email,password FROM User WHERE email = \'"
		+ _email + "\' AND \'" + _username + "\'"  ;

	char **results = NULL;
	int rows =0, columns = 0;
	ConnectDB();
	results = ExecuteTable(_query, rows, columns);

	if (rows == 0) {  return false; }

	else { return true; }

	return false;
}

User AccountRepository::Select(string _email)
{
	

	string _query = "SELECT * FROM User WHERE email = \'" + _email + "'\;";

	char **results = NULL;
	int rows = 0, columns = 0;
	ConnectDB();
	results = ExecuteTable(_query, rows, columns);

	int col = columns - 1;
	int id = stoi(string(results[col + 1]));

	User user;
	user.setIdUser(id);
	user.setUsername(string(results[col + 2]));
	user.setEmail(string(results[col + 3]));
	user.setPassword(string(results[col + 4]));
	user.setDateOfBirth(string(results[col + 5]));

	user.setSex(string(results[col + 6]));
	user.setAddress(string(results[col + 7]));
	user.setAvatar(string(results[col + 8]));
	user.setStatus(string(results[col + 9]));
	user.setTimerRegister(string(results[col + 10]));

	
	return user;
}

bool AccountRepository::CheckUsername(string _username)
{

	string _query = "SELECT * FROM User WHERE username = \'" + _username + "\'";

	char **results = NULL;
	int rows = 0, columns = 0;
	ConnectDB();
	results = ExecuteTable(_query, rows, columns);

	if (rows == 0) { return false; }

	else { return true; }

	return false;
}

void AccountRepository::Insert(User user)
{

	string comma = "','";
	string s = "INSERT INTO User(username,email,password,date_of_birth,sex,address)VALUES('"
		+ user.getUsername() +   comma
		+ user.getEmail() +      comma
		+ user.getPassoword() +  comma
		+ user.getDate_of_birth() + comma
		+ user.getSex() + comma
		+ user.getAddress() + "');";
	ConnectDB();
	ExecuteNonQuery(s);
	
	
}

void AccountRepository::Delete(int _id)
{
	string query = "Delete from User where id_user = '" + to_string(_id) + "');";
	ConnectDB();
	ExecuteNonQuery(query);
}

string AccountRepository::SelectEmail(int _id)
{

	string _query = "SELECT * FROM User WHERE id_user = \'" + to_string(_id) + "'\;";

	char **results = NULL;
	int rows = 0, columns = 0;
	ConnectDB();
	results = ExecuteTable(_query, rows, columns);


	int col = columns - 1;
	User user;
	user.setUsername(results[col + 2]);
	return user.getUsername();
}

int AccountRepository::SelectId(string _username)
{
	string _query = "SELECT * FROM User WHERE username = \'" + _username + "'\;";

	char **results = NULL;
	int rows = 0, columns = 0;
	ConnectDB();
	results = ExecuteTable(_query, rows, columns);


	int col = columns - 1;
	User user;

	user.setIdUser(stoi(string(results[col +1] )));
	return user.getIdUser();
	
}

AccountRepository::AccountRepository()
{
}


AccountRepository::~AccountRepository()
{
}
