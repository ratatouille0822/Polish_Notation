#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"


LinkStackType Init_LinkStack()
{
	pLinkStackMan temp = (pLinkStackMan)malloc(sizeof(LinkStackMan));
	temp->head.next = NULL;
	temp->size = 0;

	return temp;

}

int Push_LinkStack(LinkStackType link_stack_manager, DataType data)
{
	if (NULL == link_stack_manager || NULL == data)
	{
		perror("EMPTY !\n");
		return -1;
	}

	pLinkStackMan temp = (pLinkStackMan)link_stack_manager;
	pNode new_node = (pNode)data;

	new_node->next = temp->head.next;
	temp->head.next = new_node;

	temp->size += 1;
	return 0;
}

int Pop_LinkStack(LinkStackType link_stack_manager)
{
	if (NULL == link_stack_manager )
	{
		perror("EMPTY !\n");
		return -1;
	}

	pLinkStackMan temp = (pLinkStackMan)link_stack_manager;

	temp->head.next = temp->head.next->next;
	temp->size -= 1;
	return 0;

}
DataType GetTopElement_LinkStack(LinkStackType link_stack_manager)
{
	if (NULL == link_stack_manager )
	{
		perror("EMPTY !\n");
		return NULL;
	}

	pLinkStackMan temp = (pLinkStackMan)link_stack_manager;

	return temp->head.next;

}
int GetSize_LinkStack(LinkStackType link_stack_manager)
{
	if (NULL == link_stack_manager )
	{
		perror("EMPTY !\n");
		return -1;
	}

	pLinkStackMan temp = (pLinkStackMan)link_stack_manager;

	return temp->size;
}
int IsEmpty_LinkStack(LinkStackType link_stack_manager)
{
	if (NULL == link_stack_manager )
	{
		perror("EMPTY !\n");
		return -1;
	}

	pLinkStackMan temp = (pLinkStackMan)link_stack_manager;
	 
	return temp->size == 0 ? 1 : 0;


}
int Free_LinkStack(LinkStackType link_stack_manager)
{
	if (NULL == link_stack_manager )
	{
		perror("EMPTY !\n");
		return -1;
	}

	pLinkStackMan temp = (pLinkStackMan)link_stack_manager;

	free(temp);
	return 0;

}
