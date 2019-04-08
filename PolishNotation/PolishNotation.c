#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include "UserData.h"



int main()
{
	while (1)
	{
		pLinkStackMan link_stack_instance;
		link_stack_instance = Init_LinkStack();

		char str[128] = { 0 };
		char polish_notation[128] = { 0 };
		printf("Please input a expression:\n");

		scanf("%s", str);
		char ch;
		ch = getchar();

		char *p = str;
		char *p_polish_notation = polish_notation;
		while (*p != 0)
		{
			if (*p > '0' && *p < '9')
			{
				*p_polish_notation = *p;
				p_polish_notation++;
			}
			if (*p == '(')
			{
				Push_LinkStack(link_stack_instance, &left_brace);
			}
			while (*p == '+' || *p == '-' || *p == '*' || *p == '/')
			{
				pUserData temp_string = (pUserData)malloc(sizeof(UserData));
				*temp_string = GetStruct(*p);
				if (IsEmpty_LinkStack(link_stack_instance))
				{
					Push_LinkStack(link_stack_instance, (DataType)temp_string);
					break;
				}
				else
				{
					pUserData temp_stack = (pUserData)malloc(sizeof(UserData));
					temp_stack =(pUserData)GetTopElement_LinkStack(link_stack_instance);
					if (temp_stack->element == '(' || temp_stack->priority_level < temp_string->priority_level)
					{
						Push_LinkStack(link_stack_instance,(DataType)temp_string);
						break;

					}
					else
					{
						*p_polish_notation = temp_stack->element;
						Pop_LinkStack(link_stack_instance);
						Push_LinkStack(link_stack_instance, temp_string);
						p_polish_notation++;
						break;
					}
					free(temp_stack);
				}
				free(temp_string);
			}
			if (*p == ')')
			{
				UserData temp_stack =*(pUserData)GetTopElement_LinkStack(link_stack_instance);
				UserData temp_string = GetStruct(*p);
				while (temp_stack.element != '(')
				{
					(*p_polish_notation++) = temp_stack.element;
					Pop_LinkStack(link_stack_instance);
					temp_stack = *(pUserData)GetTopElement_LinkStack(link_stack_instance);
				}
				//p++;
				Pop_LinkStack(link_stack_instance);
			}
			p++;
		}
		while (!IsEmpty_LinkStack(link_stack_instance))
		{
			pUserData temp = (pUserData)malloc(sizeof(UserData));
			*temp = *(pUserData)GetTopElement_LinkStack(link_stack_instance);
			*p_polish_notation = temp->element;
			Pop_LinkStack(link_stack_instance);
			p_polish_notation++;
			free(temp);
		}

		printf("%s\n", polish_notation);
		printf("--------------------------------------------------------------------\n");

	}
	return 0;
}


