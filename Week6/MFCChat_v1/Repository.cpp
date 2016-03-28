#include "stdafx.h"
#include "Repository.h"

sqlite3 *Repository::filename;
bool Repository::ConnectDB()
{

	int rc;
	char *error;


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

void Repository::DisconnectDB()
{
	if (ConnectDB() == true)
	{
		sqlite3_close(filename);
	}
}

Repository::Repository()
{
}


Repository::~Repository()
{
}
