#include "stdafx.h"
#include "Friend.h"



Friend::Friend()
{
	friend_id = 0;
	id_account = 0;
	id_friend = 0;
	friend_name = "";
	date_modified = "";
	status = 1;
}

Friend::Friend(int _friend_id, int _id_account, int _id_friend, string _friend_name, string _date_modified, bool _status)

{
	friend_id = _friend_id;
	id_account = _id_account;
	id_friend = _id_friend;
	friend_name = _friend_name;
	date_modified = _date_modified;
	status = _status;
}


Friend::~Friend()
{
}
