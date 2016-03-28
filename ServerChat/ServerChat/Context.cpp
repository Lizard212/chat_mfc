#include "stdafx.h"
#include "Context.h"





string Context::ExecuteRespond(string _request)
{
	Document d;
	d.Parse(_request.c_str());

	int temp_type;
	temp_type = d["type"].GetInt();

	switch (temp_type)
	{
	case SELECT_USER:
	case INSERT_USER:
	case UPDATE_USER:
	case DELETE_USER:
	case SELECT_USERS:
	case LOGOUT:
          return	 ac.Respond(_request);
	case  SELECT_FRIEND:
	case  SELECT_FRIENDS:
	case  INSERT_FRIEND:
	case  UPDATE_FRIEND:
	case  DELETE_FRIEND:
		return fc.Respond(_request);
	case    SELECT_MESSAGES:
	case	INSERT_MESSAGES:
	case	DELETE_MESSAGE:
		return mc.Respond(_request);

	default:
		break;
	}
	return "false";
}



Context::Context()
{

}


Context::~Context()
{
}
