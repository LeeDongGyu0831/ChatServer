#pragma once

enum COMMAND_TYPE
{
	LOGIN = 'l',
	HELP = 'h',
	SHOWROOM = 's',
	SHOWROOMALL = 'o',
	SHOWUSER = 'u',
	SHOWUSERALL = 'p',
	SENDMSG = 't',
	CREATEROOM = 'c',
	JOINROOM = 'j',
	DESTROYROOM = 'd',
	CLOSE = 'x',
};

enum MSG_TYPE
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

enum ROOM_TYPE 
{
	LOGIN_ROOM,
	MAIN_ROOM,
};

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