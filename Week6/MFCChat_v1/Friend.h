#pragma once
#include "Entity.h"
#include<iostream>

using namespace std;
class Friend :public Entity
{
private:
	int friend_id;
	int id_account;
	int id_friend;
	string friend_name;
	string date_modified;
	bool status;

public:
	Friend();
	Friend(int, int, int, string, string, bool);
	int getFriendId() const
	{
		return friend_id;
	}
	int getIdAccount() const
	{
		return id_account;
	}
	int getIdFriend() const
	{
		return id_friend;
	}
	bool getStatus()
	{
		return status;
	}
	string getFriendName() const
	{
		return friend_name;
	}
	string getDateModified() const
	{
		return date_modified;
	}

	void setFriendId(int _friend_id)
	{
		friend_id = _friend_id;
	}
	void setIdAccount(int _id_account)
	{
		id_account = _id_account;
	}
	void setIdFriend(int _id_friend)
	{
		id_friend = _id_friend;
	}
	void setFriendName(string _friend_name)
	{
		friend_name = _friend_name;
	}
	void setStatus(bool _status)
	{
		status = _status;
	}
	void setDateModified(string _date_modified)
	{
		date_modified = _date_modified;
	}



	~Friend();
};

