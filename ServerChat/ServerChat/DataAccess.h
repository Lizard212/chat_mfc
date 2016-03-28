#pragma once
#include <iostream>
#include "sqlite3.h"
#include <string>
#include <list>
using namespace std;

class DataAccess
{
private:
	 sqlite3 *filename;
	 char *error;
	 int rc;
public:
	 bool ConnectDB();
     void DisconnectDB();

   	void ExecuteNonQuery(string query);
	 char** ExecuteTable(string query, int &rows, int &columns);

	 DataAccess();
	~DataAccess();

};