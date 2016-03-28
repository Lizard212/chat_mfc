#include "stdafx.h"
#include "FriendController.h"


string FriendController::Respond(string _request)
{
	Document d;
	d.Parse(_request.c_str());

	int temp_type = d["type"].GetInt();
	switch (temp_type)
	{
	case SELECT_FRIEND:
	case	SELECT_FRIENDS:

		return "{\"type\":6,\"result\":[" + SelectFriends(_request) + "\]}";
	case	INSERT_FRIEND:
		return "{\"type\":7,\"result\":\"" + InsetFriend(_request) + "\"}";

	case	UPDATE_FRIEND:
		break;
	case	DELETE_FRIEND:
		break;
	default:
		break;
	}
	return string();
}

string FriendController::SelectFriend(string _request)
{
	return string();
}

string FriendController::SelectFriends(string _request)
{
	Document d;
	d.Parse(_request.c_str());
	string temp_username =  d["username"].GetString();
	int temp_id = bus.SelectIdUser(temp_username);

	string list_friendname;
	list<Friend> list_friend = bus.GetListFriend(temp_id);
	list<Friend>::iterator i;
	for (i = list_friend.begin(); i != list_friend.end(); ++i)
	{
		list_friendname += "{\"friend_name\":\"" + i->getFriendName() + "\"},";
	}
    list_friendname.resize(list_friendname.size() - 1);
	
	return list_friendname;
}

string FriendController::InsetFriend(string _request)
{
	Document d;
	d.Parse(_request.c_str());
	
	string temp_user1 = d["username1"].GetString();

	string temp_user2  = d["username2"].GetString();
	
	if (bus.CheckUsername(temp_user2) == false )
	{
		return "false";
	}
	else
	{

		Friend _friend;
		int temp_id_user1 = bus.SelectIdUser(temp_user1);
		int temp_id_user2 = bus.SelectIdUser(temp_user2);
		if (bus.CheckFriendExits(temp_id_user1, temp_id_user2) == true)
		{
			return "false";
		}
		_friend.setUserId(temp_id_user1);
		_friend.setFriendId(temp_id_user2);
		_friend.setFriend_name(temp_user2);
		bus.InsertFriend(_friend);
		
		_friend.setUserId(temp_id_user2);
		_friend.setFriendId(temp_id_user1);
		bus.InsertFriend(_friend);
		return "true";
	}
	return "false";
}

string FriendController::UpdateFriend(string _request)
{
	return string();
}

string FriendController::DeleteFriend(string _request)
{
	return string();
}

FriendController::FriendController()
{
}


FriendController::~FriendController()
{
}
