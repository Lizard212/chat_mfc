#pragma once
#include "Enitty.h"

class Friend
{
private:
	int id_friend;
	int user_id;
	int friend_id;
	string friend_name;
	string time_add;
	int relationship;

public:
	Friend();
	~Friend();
public:
	void setIdFriend(int _id_friend)
	{
		id_friend = _id_friend;
	}
	void setUserId(int _user_id)
	{
		user_id = _user_id;
	}
	void setFriendId(int _friend_id)
	{
		friend_id = _friend_id;
	}
	void setFriend_name(string _friend_name)
	{
		friend_name = _friend_name;
	}
	void setTimeAdd(string _time_add)
	{
		time_add = _time_add;
	}
	void setRelationship(int _relationship)
	{
		relationship = _relationship;
	}

	int getIdFriend()
	{
		return id_friend;
	}
	int getUserId()
	{
		return user_id;
	}
	int getFriend_id()
	{
		return friend_id;
	}
	string getFriendName()
	{
		return friend_name;
	}
	string getTimeAdd()
	{
		return time_add;
	}
	int getRelationship()
	{
		return relationship;
	}
};

