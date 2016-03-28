#include "stdafx.h"
#include "FriendRepository.h"


bool FriendRepository::Check(int id_user1, int id_user2)
{

	string _query = "SELECT user_id,friend_id FROM Friend WHERE user_id = \'"
		+ to_string(id_user1) + "\' AND friend_id = \'" + to_string(id_user2) + "\'";

	char **results = NULL;
	int rows = 0, columns = 0;
	ConnectDB();
	results = ExecuteTable(_query, rows, columns);

	if (rows == 0) { return false; }

	else { return true; }

	return false;
	
}

bool FriendRepository::CheckStatus(int _id_friend)
{
	return false;
}

void FriendRepository::Insert(Friend _friend)
{
	string comma = "','";

	string s = "INSERT INTO Friend(user_id, friend_id, friend_name)VALUES('"
		+ to_string(_friend.getUserId()) + comma
		+ to_string(_friend.getFriend_id()) + comma
		+ _friend.getFriendName() + "');";
	ConnectDB();
	ExecuteNonQuery(s);
    

}

void FriendRepository::Delete(int _id)
{
	string query = "DELETE FROM FRIEND where user_id = '" + to_string(_id) + "')";
	ConnectDB();
	ExecuteNonQuery(query);
}

void FriendRepository::Update(Friend _friend)
{
	string comma = "',";

	string s = "Update Friend set user_id = '" +        to_string(_friend.getUserId()) + comma
	                            +"friend_id = '" +      to_string(_friend.getFriend_id()) + comma
		                        +"friend_name = '" +    _friend.getFriendName()     + comma
		                        + "where user_id = '" + to_string(_friend.getUserId())
		                         
		                        + "');";
	ConnectDB();

	ExecuteNonQuery(s);
}

list<Friend> FriendRepository::Search(string keywords,int _id_user)
{

	list<Friend> list_friend;
	Friend _friend;

	string _query = "SELECT *FROM Friend WHERE user_id = '" + to_string(_id_user)
		+ "'AND friend_name LIKE '" + keywords + "%'";

	char **results = NULL;
	int rows = 0, columns = 0;
	ConnectDB();
	results = ExecuteTable(_query, rows, columns);

	for (int rowCtr = 1; rowCtr <= rows; ++rowCtr)
	{
		int position = (rowCtr * columns);
	
		int id = stoi(string(results[position]));
		int id_user = stoi(string(results[position + 1]));
		int id_friend = stoi(string(results[position + 2]));

		//_friend.setFriendId(id);
		_friend.setUserId(id_user);
		_friend.setFriendId(id_friend);
		_friend.setFriend_name(results[position + 3]);
		_friend.setTimeAdd((results[position + 4]));

		_friend.setRelationship(bool(results[position + 5]));


		list_friend.push_back(_friend);
	}

	return list_friend;
}

list<Friend> FriendRepository::Select(int _user_id)
{
	list<Friend> list_friend;
	Friend  _friend;

	string _query = "SELECT * FROM Friend WHERE user_id = '" + to_string(_user_id)
		+ "' ORDER BY friend_name ASC " + ";";

	char **results = NULL;
	int rows = 0, columns = 0;
	ConnectDB();
	results = ExecuteTable(_query, rows, columns);

	for (int rowCtr = 1; rowCtr <= rows; ++rowCtr)
	{
		int position = (rowCtr * columns);

		int id = stoi(string(results[position]));
		int id_account = stoi(string(results[position + 1]));
		int id_friend = stoi(string(results[position + 2]));

		_friend.setIdFriend(id);

		_friend.setUserId(id_account);
		_friend.setFriendId(id_friend);
		_friend.setFriend_name(results[position + 3]);
		_friend.setTimeAdd((results[position + 4]));
		_friend.setRelationship(bool(results[position + 5]));


		list_friend.push_back(_friend);
	}

	return list_friend;
}

FriendRepository::FriendRepository()
{
}


FriendRepository::~FriendRepository()
{
}
