#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"


typedef struct tag_LinkStackNode  //栈的业务节点
{
	LinkListNode node;//第一个域(元素)
	void* item; //栈的业务节点,链表业务节点包含了一个栈的业务节点
}TLinkStackNode;

//创建一个栈		相当于创建一个链表
LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

//销毁一个栈		相当于销毁一个链表
void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
}

//清空一个栈		相当于清空一个链表
//清空栈的时候涉及到栈的生命周期的管理:所有入栈的节点都是malloc,清空栈的时候要把栈的元素弹出,并且释放节点
void LinkStack_Clear(LinkStack* stack)
{
	if (NULL == stack)
	{
		return;
	}
	while (LinkStack_Size(stack) > 0)
	{
		LinkStack_Pop(stack);//在pop函数中释放节点内存
	}
	return;
}

// 向栈中添加元素	相当于向链表的头部插入元素
//void* item 栈的业务节点  ,需要转化成链表的业务节点
int LinkStack_Push(LinkStack* stack, void* item)
{
	TLinkStackNode* tmp = NULL;
	//添加元素后不希望内存被析构,就要分配内存
	tmp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (NULL == tmp)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	
	tmp->item = item;//把传入的业务节点地址赋给tmp的业务节点

	int ret = LinkList_Insert(stack, (TLinkStackNode*)tmp, 0);
	if (ret != 0)
	{
		printf("func LinkList_Insert err:%d ", ret);
		if (tmp != NULL)
		{
			free(tmp);
		}
		return ret;
	}
	return ret;
}

//从栈中弹出元素		相当于从链表头部删除元素
//把链表的业务节点 转化为 栈的业务节点
void* LinkStack_Pop(LinkStack* stack)
{
	void* item = NULL;//栈的业务节点
	TLinkStackNode* tmp = NULL;
	tmp = (TLinkStackNode*)LinkList_Delete(stack, 0);
	if (NULL == tmp)
	{
		return NULL;
	}
	item = tmp->item;
	//因为linList_Insert的时候,分配了内存,所以LinkList_Delete释放内存
	free(tmp);
	return item;
}

//获取栈顶元素	相当于获取链表的0号位置
void* LinkStack_Top(LinkStack* stack)
{
	TLinkStackNode* tmp = NULL;
	tmp = (TLinkStackNode*)LinkList_Get(stack, 0);
	if (NULL == tmp)
	{
		return NULL;
	}
	return tmp->item;
}

//求栈的大小		相当于求链表的len
int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}