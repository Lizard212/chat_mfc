#pragma once
#include "Entity.h"
#include<iostream>
using namespace std;

class Message:public Entity
{
private:
	int message_id;
	int id_sender;
	int id_receiver;
	string content;
	bool visible;
	string date_creation;
public:
	Message(int, int, int, string, bool, string);

	int getMessageId()
	{
		return message_id;
	}
	int getSender()
	{
		return id_sender;
	}

	int getReceiver()
	{
		return id_receiver;
	}

	string getContent()
	{
		return content;
	}
	string getDateCreation()
	{
		return date_creation;
	}
	bool getVisible()
	{
		return visible;
	}

	void setMessageId(int _message_id)
	{
		message_id = _message_id;
	}
	void setIdSender(int _id_sender)
	{
		id_sender = _id_sender;
	}
	void setIdReceiver(int _id_recevier)
	{
		id_receiver = _id_recevier;
	}
	void setContent(string _content)
	{
		content = _content;
	}
	void setVisible(bool _visible)
	{
		visible = _visible;
	}
	void setDateCreation(string _date_creation)
	{
		date_creation = _date_creation;
	}
	Message();
	~Message();
};


