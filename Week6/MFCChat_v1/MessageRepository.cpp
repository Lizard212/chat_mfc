#include "stdafx.h"
#include "MessageRepository.h"


void MessageRepository::Insert(Message message)
{
	ConnectDB();
	string comma = "','";
	string s = "INSERT INTO Message(id_sender,id_receiver,content)VALUES('"
		+ to_string(message.getSender()) + comma
		+ to_string(message.getReceiver()) + comma
		+ message.getContent() + "');";


	const char *query = s.c_str();
	rc = sqlite3_exec(filename, query, NULL, NULL, &error);
	DisconnectDB();
}

list<Message> MessageRepository::Select(string email,int number_of_message)
{
	ConnectDB();
	Message _messages;
	list<Message>  list_messages;
	Account account = Context::getAccount();
	int temp = Context::getIdAccount();
	//string _query = "SELECT * FROM Message WHERE id_sender = '" + to_string(account.getIdAccount())
	//	+ "' ORDER BY date_creation DESC " + ";";
	string _query = "SELECT  * FROM Message WHERE id_sender = '"
		+ to_string(account.getIdAccount())
	    + "'AND id_receiver = '"+  to_string(Context::getIdAccount())
		+"' OR id_sender = '" + to_string(Context::getIdAccount())
		+ "'AND id_receiver = '" + to_string(account.getIdAccount()) +
		"' ORDER BY date_creation DESC limit '"+ to_string(number_of_message)+ "';";
	const char *query = _query.c_str();

	char **results = NULL;
	int rows, columns;
	sqlite3_get_table(filename, query, &results, &rows, &columns, &error);

	for (int rowCtr = 1; rowCtr <= rows; ++rowCtr)
	{
		int position = (rowCtr * columns);
		int id = stoi(string(results[position]));
		int id_sender = stoi(string(results[position + 1]));
		int id_recevier = stoi(string(results[position + 2]));

		_messages.setMessageId(id);

		_messages.setIdSender(id_sender);
		_messages.setIdReceiver(id_recevier);
		_messages.setContent(results[position + 3]);
		_messages.setVisible(bool(results[position + 4]));
		_messages.setDateCreation((results[position + 5]));


		list_messages.push_back(_messages);
	}
	DisconnectDB();
	return list_messages;
}

list<Message> MessageRepository::SelectNotRead(string email)
{
	ConnectDB();
	Message _messages;
	list<Message>  list_messages;
	Account account = Context::getAccount();
	int temp = Context::getIdAccount();

	string _query = "SELECT  * FROM Message WHERE id_sender = '" + to_string(Context::getIdAccount())
		+ "'AND id_receiver = '" + to_string(account.getIdAccount()) 
		+"' AND visible = 0  ORDER BY date_creation DESC limit  ";
	const char *query = _query.c_str();

	char **results = NULL;
	int rows, columns;
	sqlite3_get_table(filename, query, &results, &rows, &columns, &error);

	for (int rowCtr = 1; rowCtr <= rows; ++rowCtr)
	{
		int position = (rowCtr * columns);
		int id = stoi(string(results[position]));
		int id_sender = stoi(string(results[position + 1]));
		int id_recevier = stoi(string(results[position + 2]));

		_messages.setMessageId(id);

		_messages.setIdSender(id_sender);
		_messages.setIdReceiver(id_recevier);
		_messages.setContent(results[position + 3]);
		_messages.setVisible(bool(results[position + 4]));
		_messages.setDateCreation((results[position + 5]));


		list_messages.push_back(_messages);
	}
	DisconnectDB();
	return list_messages;
}

int MessageRepository::CountMessages()
{
	ConnectDB();
	Account account = Context::getAccount();
	string comma = "','";
	string _query = "SELECT count(*) from Message WHERE id_recevier = '" + to_string(account.getIdAccount())
		             + "' ORDER BY date_creation ASC " + "';";
	const char *query = _query.c_str();

	char **results = NULL;
	int rows, columns;
	sqlite3_get_table(filename, query, &results, &rows, &columns, &error);



	return rows;
}

MessageRepository::MessageRepository()
{
}


MessageRepository::~MessageRepository()
{
}
