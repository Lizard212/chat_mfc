#include "stdafx.h"
#include "Message.h"



Message::Message(int _message_id, int _id_sender, int _id_receiver, string _content, bool _visible, string _date_creation)
{
	message_id = _message_id;
	id_sender = _id_sender;
	id_receiver = _id_receiver;
	content = _content;
	visible = _visible;
	date_creation = _date_creation;

}

Message::Message()
{

	visible = false;
}


Message::~Message()
{
}
