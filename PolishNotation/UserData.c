#include "UserData.h"

UserData operator_plus = { NULL, '+',1 };
UserData operator_minus = { NULL, '-',1 };
UserData operator_multiply = { NULL, '*',2 };
UserData operator_devide = { NULL, '/',2 };
UserData left_brace = { NULL, '(',3 };
UserData right_brace = { NULL, ')',3 };
UserData default_data = { NULL,'0',0 };

UserData GetStruct(char ch)
{
	switch (ch)
	{
	case '+':
		return operator_plus;
	case '-':
		return operator_minus;
	case '*':
		return operator_multiply;
	case '/':
		return operator_devide;
	case '(':
		return left_brace;
	case ')':
		return right_brace;
	default:
		return default_data;
	}
}
