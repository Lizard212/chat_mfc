#pragma once
#include<string>
#include"../ServerChat/rapidjson/document.h"
#include"../ServerChat/rapidjson/writer.h"
#include"rapidjson\stringbuffer.h"
#include"API.h"
#include"Bus.h"
#include<list>
using namespace std;
using namespace rapidjson;
class Controller
{
public:
	virtual string Respond(string _request) = 0;
	Controller();
	~Controller();
};

