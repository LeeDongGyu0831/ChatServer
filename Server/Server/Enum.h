#pragma once

enum COMMAND
{
	LOGIN = 'l',
	HELP = 'h',
};

enum MSGTYPE
{
	NORMAL,
	LOGIN_MSG,
	HELP_MSG,
	NOTHING,
	END,
};