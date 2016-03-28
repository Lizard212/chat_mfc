#pragma once
#include "Enitty.h"
class Message
{
private:
	int id_message;
	int sender_id;
	int receiver_id;
	string content;
	bool read;
	string time_send;
public:
	Message();
	~Message();
public:
	int getIdMessage()
	{
		return id_message;
	}
	int getSender()
	{
		return sender_id;
	}

	int getReceiver()
	{
		return receiver_id;
	}

	string getContent()
	{
		return content;
	}
	string getTimeSend()
	{
		return time_send;
	}
	bool getRead()
	{
		return read;
	}

	void setIdMessage(int _message_id)
	{
		id_message = _message_id;
	}
	void setIdSender(int _id_sender)
	{
		sender_id = _id_sender;
	}
	void setIdReceiver(int _id_recevier)
	{
		receiver_id = _id_recevier;
	}
	void setContent(string _content)
	{
		content = _content;
	}
	void setRead(bool _read)
	{
		read = _read;
	}
	void setTimeSend(string _time_send)
	{
		time_send = _time_send;
	}
};

