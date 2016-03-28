#pragma once
#include"AccountRepository.h"
#include"FriendRepository.h"
#include"MessageRepository.h"
class BUS
{
protected:
	AccountRepository account_repository;
	FriendRepository friend_repository;
	MessageRepository message_repository;
public:
	bool Check(string _email, string _password)
	{
		return account_repository.Check(_email, _password);

	}
	bool checkEmail(string _email)
	{
		return account_repository.checkEmail(_email);
	}

	Account Select(string _email)
	{
		return account_repository.Select(_email);
	}

	void Insert(Account _account)
	{
		account_repository.Insert(_account);
	}

	string selectEmail(int _id)
	{
		return account_repository.selectEmail(_id);
	}
	// FRIEND

	// Check friend exists
	bool friend_Check(int _id_friend)
	{
		return friend_repository.Check(_id_friend);
	}

	bool friend_Check_Status(int _id_friend)
	{
		return friend_repository.checkStatus(_id_friend);
	}

	void friend_Insert(Friend _friend)
	{
		friend_repository.Insert(_friend);
	}

	void friend_Update_Status(Friend _friend)
	{
		friend_repository.updateStatus(_friend);
	}
	void friend_Update_Name(Friend _friend, string _new_name)
	{
		friend_repository.updateName(_friend, _new_name);
	}
	list<Friend> friend_Select_All()
	{
		return friend_repository.selectAll();
	}
	list<Friend> friend_Search(string keywords)
	{
		return friend_repository.Search(keywords);
	}

	// Message
	void message_Insert(Message message)
	{
		message_repository.Insert(message);
	}
	list<Message> message_Select(string email, int number_of_message)
	{
		return message_repository.Select(email, number_of_message);
	}
	int CountMessages()
	{
		return message_repository.CountMessages();
	}
	list<Message> message_SelectNotRead(string email)
	{
		return message_repository.SelectNotRead(email);
	}


	BUS() {}
	~BUS() {}
};

