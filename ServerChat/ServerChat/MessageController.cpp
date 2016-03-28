#include "stdafx.h"
#include "MessageController.h"


string MessageController::Respond(string _request)
{
	Document d;
	d.Parse(_request.c_str());
	int temp_type;
	temp_type = d["type"].GetInt();

	switch (temp_type)
	{
	case SELECT_MESSAGES:
		return "{\"type\":10,\"result\":[" + SelectMessages(_request) + "\]}";
	case INSERT_MESSAGES:
		return "{\"type\":11,\"result\":\"" + InsertMessage(_request) + "\"}";

	case DELETE_MESSAGE:
		break;
	default:
		break;
	}
	return "false";
}

string MessageController::SelectMessages(string _request)
{
	Document d;
	d.Parse(_request.c_str());
	string temp_user1 = d["username1"].GetString();
	string temp_user2 = d["username2"].GetString();
	int temp_id_user1 = bus.SelectIdUser(temp_user1);
	int temp_id_user2 = bus.SelectIdUser(temp_user2);

	string temp_user;
	string list_string;

	list<Message> list_message;
	list_message  = bus.GetListMessages(temp_id_user1, temp_id_user2, 20);

	if (list_message.size() == 0)
	{
		return "{\"username1\":\"false\",\"username2\":\"false\",\"content\":\"null\",\"time_send\":\"null\"}";
	}
	list<Message>::iterator i;
	for (i = list_message.begin(); i != list_message.end(); ++i)
	{

		list_string += ("{\"username1\":\""+ bus.SelectEmailUser(i->getSender()) +"\",\"username2\":\"" + bus.SelectEmailUser(i->getReceiver()) + "\",\"content\":\"" + i->getContent() + "\",\"time_send\":\"" + i->getTimeSend() + "\" },");
	}

	list_string.resize(list_string.size() - 1);
	return list_string;
}

string MessageController::InsertMessage(string _request)
{
	Document d;
	d.Parse(_request.c_str());
	string temp_user1 = d["username1"].GetString();
	string temp_user2 = d["username2"].GetString();
	string temp_content = d["content"].GetString();

	int temp_id_user1 = bus.SelectIdUser(temp_user1);
	int temp_id_user2 = bus.SelectIdUser(temp_user2);

	Message message;
	message.setIdSender(temp_id_user1);
	message.setIdReceiver(temp_id_user2);
	message.setContent(temp_content);
	bus.InsertMessage(message);
	return "true";
}

string MessageController::DeleteMessage(string _request)
{
	return string();
}

MessageController::MessageController()
{
}


MessageController::~MessageController()
{
}
