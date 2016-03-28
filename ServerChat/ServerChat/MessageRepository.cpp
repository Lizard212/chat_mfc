#include "stdafx.h"
#include "MessageRepository.h"


void MessageRepository::Insert(Message message)
{

	string comma = "','";
	string s = "INSERT INTO Message(sender_id,receiver_id,content)VALUES('"
		+ to_string(message.getSender()) + comma
		+ to_string(message.getReceiver()) + comma
		+ message.getContent() + "');";
	ConnectDB();
	ExecuteNonQuery(s);

   
}

void MessageRepository::Delete(int _id_sender)
{
}



list<Message> MessageRepository::Select(int _user_id, int _friend_id,int number_of_message)
{
	Message _messages;
	list<Message>  list_messages;

	string _query = "SELECT  * FROM Message WHERE sender_id = '"
		+ to_string(_user_id)
		+ "'AND receiver_id = '" + to_string(_friend_id)
		+ "' OR sender_id = '" + to_string(_friend_id)
		+ "'AND receiver_id = '" + to_string(_user_id) +
		"' ORDER BY id_message DESC limit '" + to_string(number_of_message) + "';";


	char **results = NULL;
	int rows = 0, columns = 0;
	ConnectDB();
	results = ExecuteTable(_query, rows, columns);

	for (int rowCtr = 1; rowCtr <= rows; ++rowCtr)
	{
		int position = (rowCtr * columns);
		int id = stoi(string(results[position]));
		int id_sender = stoi(string(results[position + 1]));
		int id_recevier = stoi(string(results[position + 2]));

		_messages.setIdMessage(id);

		_messages.setIdSender(id_sender);
		_messages.setIdReceiver(id_recevier);
		_messages.setContent(results[position + 3]);
		_messages.setRead(bool(results[position + 4]));
		_messages.setTimeSend((results[position + 5]));


		list_messages.push_back(_messages);
	}
	return list_messages;
}

MessageRepository::MessageRepository()
{
}


MessageRepository::~MessageRepository()
{
}
