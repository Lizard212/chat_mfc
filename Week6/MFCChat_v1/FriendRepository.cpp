#include "stdafx.h"
#include "FriendRepository.h"
#include<string>

Account account = Context::getAccount();
bool FriendRepository::Check(int _id_friend)
{

	ConnectDB();
	string _query = "SELECT id_account,id_friend FROM Friend WHERE id_account = \'"
		+ to_string(account.getIdAccount()) + "\' AND id_friend = \'" + to_string(_id_friend) + "\'";
	const char *query = _query.c_str();

	char **results = NULL;
	int rows, columns;
	sqlite3_get_table(filename, query, &results, &rows, &columns, &error);

	if (rows == 0) { DisconnectDB(); return false; }

	else { DisconnectDB(); return true; }

	return false;
}

bool FriendRepository::checkStatus(int _id_friend)
{
	ConnectDB();

	string _query = "SELECT id_account,id_friend,status FROM Friend WHERE id_account = '"
		+ to_string(_id_friend) + "' AND id_friend = '" + to_string(account.getIdAccount()) + "'" +
		" AND status  = 1" + ";";
	const char *query = _query.c_str();

	char **results = NULL;
	int rows, columns;
	sqlite3_get_table(filename, query, &results, &rows, &columns, &error);

	if (rows == 0) { DisconnectDB(); return false; }

	else { DisconnectDB(); return true; }
	return false;
}


void FriendRepository::Insert(Friend _friend)
{
	ConnectDB();
	string comma = "','";

	string s = "INSERT INTO Friend(id_account, id_friend, friend_name)VALUES('"
		+ to_string(_friend.getIdAccount()) + comma
		+ to_string(_friend.getIdFriend()) + comma
		+ _friend.getFriendName() + "');";



	const char *query = s.c_str();
	rc = sqlite3_exec(filename, query, NULL, NULL, &error);

}

void FriendRepository::updateStatus(Friend _friend)
{
	ConnectDB();
	string comma = "','";

	string s = "UPDATE  Friend SET status=  0 where id_account = '"
		+ to_string(account.getIdAccount()) + "'" + "AND id_friend = '" + to_string(_friend.getIdFriend()) + "';";



	const char *query = s.c_str();
	rc = sqlite3_exec(filename, query, NULL, NULL, &error);

}

void FriendRepository::updateName(Friend _friend, string new_name)
{
	//account = Context::getAccount();
	ConnectDB();
	string comma = "','";

	string s = "UPDATE  Friend SET friend_name = '"
		+ new_name + "' where email = '"
		+ account.getEmail() + "';";



	const char *query = s.c_str();
	rc = sqlite3_exec(filename, query, NULL, NULL, &error);

}

list<Friend> FriendRepository::Search(string keywords)
{
	list<Friend> list_friend;
	Friend _friend;

	ConnectDB();
	Account account = Context::getAccount();
	string _query = "SELECT *FROM Friend WHERE id_account = '" + to_string(account.getIdAccount())
		                                       +"'AND friend_name LIKE '" + keywords + "%'"  ;
	const char *query = _query.c_str();

	char **results = NULL;
	int rows, columns;
	sqlite3_get_table(filename, query, &results, &rows, &columns, &error);
	for (int rowCtr = 1; rowCtr <= rows; ++rowCtr)
	{
		int position = (rowCtr * columns);

		int id = stoi(string(results[position]));
		int id_account = stoi(string(results[position + 1]));
		int id_friend = stoi(string(results[position + 2]));

		_friend.setFriendId(id);

		_friend.setIdAccount(id_account);
		_friend.setIdFriend(id_friend);
		_friend.setFriendName(results[position + 3]);
		_friend.setDateModified((results[position + 4]));
		_friend.setStatus(bool(results[position + 6]));


		list_friend.push_back(_friend);
	}

	return list_friend;
}

list<Friend> FriendRepository::selectAll()
{
	list<Friend> list_friend;
	Friend  _friend;
	

	ConnectDB();
	account = Context::getAccount();
	string _query = "SELECT * FROM Friend WHERE id_account = '" + to_string(account.getIdAccount())
		+ "' ORDER BY friend_name ASC " + ";";
	const char *query = _query.c_str();

	char **results = NULL;
	int rows, columns;
	sqlite3_get_table(filename, query, &results, &rows, &columns, &error);

	for (int rowCtr = 1; rowCtr <= rows; ++rowCtr)
	{
		int position = (rowCtr * columns);

		int id = stoi(string(results[position]));
		int id_account = stoi(string(results[position + 1]));
		int id_friend = stoi(string(results[position + 2]));

		_friend.setFriendId(id);

		_friend.setIdAccount(id_account);
		_friend.setIdFriend(id_friend);
		_friend.setFriendName(results[position + 3]);
		_friend.setDateModified((results[position + 4]));
		_friend.setStatus(bool(results[position + 6]));


		list_friend.push_back(_friend);
	}

	return list_friend;
}



FriendRepository::FriendRepository() {}


FriendRepository::~FriendRepository() {}

