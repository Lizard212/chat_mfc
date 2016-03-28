#pragma once
#include "Repository.h"
#include "Context.h"
#include"AccountRepository.h"
#include"Message.h"
#include<list> ;

class MessageRepository :
	public Repository
{
protected:
	char *error;
	int rc;
public:
	void Insert(Message );
	list<Message> Select(string email,int number_of_message);
	list<Message> SelectNotRead(string email);

	int CountMessages();
	MessageRepository();
	~MessageRepository();
};

