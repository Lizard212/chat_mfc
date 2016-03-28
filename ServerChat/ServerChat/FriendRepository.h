#pragma once
#include "Friend.h"
#include "DataAccess.h"

class FriendRepository:public DataAccess
{

public:

	bool  Check(int id_user1, int _id_friend);
	bool  CheckStatus(int _id_friend);

	void Insert(Friend);
	void Delete(int _id);
	void Update(Friend);

	list<Friend> Search(string keyword,int _id_user);
	list<Friend> Select(int );
public:
	FriendRepository();
	~FriendRepository();
};

