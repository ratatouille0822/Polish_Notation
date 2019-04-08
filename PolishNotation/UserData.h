#pragma once
#include<stdio.h>

typedef struct UserData
{
	void* ptr;
	char element;
	int priority_level;
}UserData, *pUserData;


UserData operator_plus;// = { NULL, '+',1 };
UserData operator_minus;// = { NULL, '-',1 };
UserData operator_multiply;// = { NULL, '*',2 };
UserData operator_devide;// = { NULL, '/',2 };
UserData left_brace;// = { NULL, '(',3 };
UserData right_brace;// = { NULL, ')',3 };
UserData default_data;// = { NULL,'0',0 };

UserData GetStruct(char ch);
