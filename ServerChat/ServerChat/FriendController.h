#pragma once
#include "Controller.h"
class FriendController :
	public Controller
{
private:
	Bus bus;
public:
	string Respond(string _request);
private:
	string SelectFriend(string _request);
	string SelectFriends(string _request);
	string InsetFriend(string _request);
	string UpdateFriend(string _request);
	string DeleteFriend(string _request);
public:
	FriendController();
	~FriendController();
};

