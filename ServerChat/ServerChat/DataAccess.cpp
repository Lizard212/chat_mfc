#include "stdafx.h"
#include "DataAccess.h"

//sqlite3 *Repository::filename;
bool DataAccess::ConnectDB()
{


	rc = sqlite3_open("MyChatDb.db", &filename);

	if (rc)
	{
		cerr << "Error opening SQLite3 database: " << sqlite3_errmsg(filename) << endl << endl;
		sqlite3_close(filename);
		return false;
	}
	else
	{
		return true;
	}
	return false;
}

void DataAccess::DisconnectDB()
{
	if (ConnectDB() == true)
	{
		sqlite3_close(filename);
	}
}

void DataAccess::ExecuteNonQuery(string query)
{
	ConnectDB();
	const char *_query = query.c_str();

	rc = sqlite3_exec(filename, _query, NULL, NULL, &error);
	if (rc)
	{
		DisconnectDB(); return;
	}
	DisconnectDB();
}

char ** DataAccess::ExecuteTable(string query, int &rows, int &columns)
{
	char **results = NULL;
	const char* _query = query.c_str();
	rc = sqlite3_get_table(filename, _query, &results, &rows, &columns, &error);
	if (rc)
	{
		DisconnectDB();
		return nullptr;
	}
	DisconnectDB();
	return results;
}

DataAccess::DataAccess()
{
}


DataAccess::~DataAccess()
{
}
