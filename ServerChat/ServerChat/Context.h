#pragma once

#include"rapidjson\stringbuffer.h"
#include"list"
#include<string>
#include"Controller.h"
#include"AccountController.h"
#include"MessageController.h"
#include"FriendController.h"


using namespace std;
using namespace rapidjson;

class Context
{
private:
	AccountController ac;
	MessageController mc;
	FriendController fc;

public:
	string ExecuteRespond(string _request);

public:
   
	Context();
	~Context();
};

