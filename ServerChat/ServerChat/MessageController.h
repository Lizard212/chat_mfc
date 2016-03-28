#pragma once
#include "Controller.h"
class MessageController : public Controller
{
private:
	Bus bus;

public:
	string Respond(string _request);
private:	
	string SelectMessages(string _request);
	string InsertMessage(string _request);
	string DeleteMessage(string _request);
public:
	MessageController();
	~MessageController();
};

