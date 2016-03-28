#pragma once
#include "DataAccess.h"
#include "Message.h"
class MessageRepository:public DataAccess
{
public:
	void Insert(Message);
	void Delete(int _id_sender);
	list<Message> Select(int _user_id,int _friend_id,int number_of_message);

public:
	MessageRepository();
	~MessageRepository();
};

