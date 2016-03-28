#pragma once
#include"Repository.h"
#include"Friend.h"
#include"Context.h"
#include<list>
#include<string.h>
class FriendRepository :public Repository
{
protected:
	char * error;
	int rc;
	// Account account;
public:

	bool Check(int _id_friend);
	bool  checkStatus(int _id_friend);

	void Insert(Friend);
	void updateStatus(Friend);
	void updateName(Friend, string _new_name);
	list<Friend> Search(string keywords);
	list<Friend> selectAll();

	
	FriendRepository();
	~FriendRepository();
};

