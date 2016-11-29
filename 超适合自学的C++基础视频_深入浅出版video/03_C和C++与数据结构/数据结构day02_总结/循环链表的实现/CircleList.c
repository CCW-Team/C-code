#include "CircleList.h"




typedef struct _tag_Circle_List
{
	CircleListNode header;
	CircleListNode* slider;
	int length;
}TCircleList;

//创建并且返回一个空的链表
CircleList* CircleList_Create() //O(1)
{
	TCircleList* ret = (TCircleList*)malloc(sizeof(TCircleList));
	if (ret == NULL)
	{
		return NULL;
	}
	ret->length = 0;
	ret->header.next = NULL;
	ret->slider = NULL;
	return ret;
}

//销毁一个链表list
void CircleList_Destroy(CircleList* list)  //O(1)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

//将一个链表list中的所有元素清空, 链表回到创建时的初始状态
void CircleList_Clear(CircleList* list)  //O(1)
{
	TCircleList* tlist = (TCircleList*)list;
	if (list == NULL)
	{
		return;
	}
	tlist->length = 0;
	tlist->header.next = NULL;
	tlist->slider = NULL;
	return;
}

//返回一个链表list中的所有元素个数
int CircleList_Length(CircleList* list) //O(1)
{
	TCircleList* tlist = (TCircleList*)list;
	if (list == NULL)
	{
		return 0;
	}
	return tlist->length;
}

//向一个链表list的pos位置处插入新元素node
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos) //O(n)
{
	int ret = 0;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func CircleList_Insert() err:%d", ret);
		return ret;
	}
	TCircleList* tlist = (TCircleList*)list;

	CircleListNode* current = (CircleList*)tlist;


	//将辅助指针后移到pos位置的前一个位置
	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	//1结束循环后current表示的是pos-1这个节点,所以让插入节点的next等于current的next,让node连接后续节点
	node->next = current->next;
	//2 然后再让current的next节点等于node;让前面的链表链接node节点
	current->next = node;

	//如果是第一次插入节点
	if (tlist->length == 0)
	{
		tlist->slider = node;
	}
	tlist->length++;

	//如果current此时指向头部节点,那么表面是头插法
	if (current == (CircleListNode*)tlist)
	{
		//获取最后一个元素
		CircleListNode* last = CircleList_Get(tlist, tlist->length - 1);
		//将最后一个节点的next域指向新插入的节点
		last->next = current->next;
	}
	return 0;
}

//获取一个链表list的pos位置处的元素
CircleListNode* CircleList_Get(CircleList* list, int pos)  //O(n)
{
	int ret = 0;
	if (list == NULL || pos < 0)
	{
		ret = 0;
		printf("func CircleList_Get() err:%d", ret);
		return NULL;
	}
	TCircleList* tlist = (TCircleList*)list;

	CircleListNode* current = (CircleListNode*)tlist;


	current = &(tlist->header);//先让辅助指针指向头结点

	 //将辅助指针后移到pos位置的前一个位置
	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	return current->next;
}

//删除一个链表list的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
CircleListNode* CircleList_Delete(CircleList* list, int pos)  //O(n)
{
	TCircleList* tlist = (TCircleList*)list;

	if ((tlist != NULL) && (pos >= 0) && (tlist->length > 0))
	{
		//CircleListNode* current = (CircleListNode*)&(tlist->header);//先让辅助指针指向头结点
		CircleListNode* current = (CircleListNode*)tlist;//先让辅助指针指向头结点
		CircleListNode* last = NULL;

		for (int i = 0; i < pos; i++)
		{
			current = current->next;
		}

		//若删除的是头节点,需要先保存最后一个节点(头插法)
		if (current == (CircleListNode*)tlist)
		{
			last = (CircleListNode*)CircleList_Get(tlist, tlist->length - 1);
		}
		//循环执行完后此时current指向要删除节点的前一个节点

		//求要删除的节点
		CircleListNode* tmp = NULL;//声明一个临时节点
		tmp = current->next;//让临时节点等于要删除的pos节点
		current->next = tmp->next;//再让要删除的pos节点的前一个节点的next和后面的节点连接
		tlist->length--;

		//先判断链表是否为空,让尾部节点连接原来的滴二个节点
		if (last != NULL)
		{
			tlist->header.next = tmp->next;
			last->next = tmp->next;
		}

		//若删除的元素为游标所指的元素
		if (tlist->slider == tmp)
		{
			tlist->slider = tmp->next;
		}

		//若删除元素后,链表的长度为0
		if (tlist->length == 0)
		{
			tlist->header.next = NULL;
			tlist->slider = NULL;
		}
		return tmp;//返回被删除的节点,好让上层应用去析构
	}
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node) //O(n)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;	

	if (tlist != NULL)
	{
		CircleListNode* current = (CircleListNode*)tlist;
		//查找node节点在循环链表中的位置i
		int i = 0;
		for (i = 0; i < tlist->length; i++)	
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;	
		}

		//如果找到,根据i去删除
		if (ret != NULL)
		{
			CircleList_Delete(tlist, i);
		}
	}
	return ret;
}

//让游标指向第0个业务节点
CircleListNode* CircleList_Reset(CircleList* list)  //O(1)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if (tlist != NULL)
	{
		tlist->slider = tlist->header.next;
		ret = tlist->slider;
	}
	return ret;
}
//获取游标指向的位置
CircleListNode* CircleList_Current(CircleList* list) //O(1)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if (tlist != NULL)
	{
		ret = tlist->slider;
	}

	return ret;
}
//把当前位置返回,并且游标下移
CircleListNode* CircleList_Next(CircleList* list) //O(1)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if ((tlist != NULL) && (tlist->slider != NULL))
	{
		ret = tlist->slider;
		tlist->slider = ret->next;
	}
	return ret;
}