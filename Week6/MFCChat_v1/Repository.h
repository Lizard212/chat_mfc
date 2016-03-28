#pragma once
#include"sqlite3.h"
#include<iostream>

using namespace std;

class Repository
{
protected:
	static sqlite3 *filename;
public:
	static bool ConnectDB();
	static void DisconnectDB();
	Repository();
	~Repository();
};

