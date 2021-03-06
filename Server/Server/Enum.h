#pragma once

namespace COMMAND_TYPE
{
	constexpr static char LOGIN =		'l';
	constexpr static char HELP =		'h';
	constexpr static char SHOWROOM =	's';
	constexpr static char SHOWROOMALL = 'o';
	constexpr static char SHOWUSER =	'u';
	constexpr static char SHOWUSERALL = 'p';
	constexpr static char SENDMSG =		't';
	constexpr static char CREATEROOM =	'c';
	constexpr static char JOINROOM =	'j';
	constexpr static char DESTROYROOM = 'd';
	constexpr static char CLOSE =		'x';
};

namespace _MSG
{
	enum class TYPE
	{
		NORMAL,

		LOGIN_MSG,
		HELP_MSG,
		SHOWROOM_MSG,
		SHOWROOMALL_MSG,
		SHOWUSER_MSG,
		SHOWUSERALL_MSG,
		SENDMSG_MSG,
		CREATEROOM_MSG,
		JOINROOM_MSG,
		DESTROYROOM_MSG,
		CLOSE_MSG,

		// ���� Ÿ��
		ERROR_MSG,
		CANT_LOGIN_MSG,
		MUST_LOGIN_MSG,
		DO_NOT_LOGIN_MSG,
		CANT_USE_ID_MSG,
		CANT_SEARCH_USER_MSG,
		CANT_CREATE_ROOM_MSG,
		CANT_SEARCH_ROOM_MSG,
		CANT_JOIN_ROOM_MSG,
		NO_MSG,
		ERROR_END,

		END,
	};
};

namespace _ROOM
{
	enum class TYPE
	{
		LOGIN_ROOM,
		MAIN_ROOM,

		NORMAL_ROOM,

		END,
	};
}

using MSG_TYPE = _MSG::TYPE;
using ROOM_TYPE = _ROOM::TYPE;
using uint = unsigned int;