#pragma once

namespace COMMAND_TYPE
{
	constexpr static char LOGIN = 'l';
	constexpr static char HELP = 'h';
	constexpr static char SHOWROOM = 's';
	constexpr static char SHOWROOMALL = 'o';
	constexpr static char SHOWUSER = 'u';
	constexpr static char SHOWUSERALL = 'p';
	constexpr static char SENDMSG = 't';
	constexpr static char CREATEROOM = 'c';
	constexpr static char JOINROOM = 'j';
	constexpr static char DESTROYROOM = 'd';
	constexpr static char CLOSE = 'x';
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
		NOTHING,

		END,
	};
};
using MSG_TYPE = _MSG::TYPE;

//enum ROOM_TYPE 
//{
//	LOGIN_ROOM,
//	MAIN_ROOM,
//};

enum class EVENT_TYPE
{
	CREATE_OBJECT,	// wParam : GameObject, lParam : Layer Idx
	DELETE_OBJECT,	// wParam : GameObject,
	ADD_CHILD,		// wParam : Parent Object, lParam : Child Object
	CLEAR_PARENT,	// wParam : Target Object
	TRANSFER_LAYER,	// wParam : Target Object, lParam : (HIWORD)Layer Index (LOWORD)bMoveAll
	TRANSFER_SCENE,
	ACTIVATE_GAMEOBJECT,	// wParam : GameObject Adress
	DEACTIVATE_GAMEOBJECT,	// wParam : GameObject Adress

	ACTIVATE_COMPONENT,		// wParam : Component Adress
	DEACTIVATE_COMPONENT,	// wParam : Component Adress

	END,
};