#pragma once



#include<stdlib.h>
#include <string.h>
#include <stdio.h>

typedef void LinkList;

typedef struct _tag_LinkListNode
{
	struct LinkListNode* next;
}LinkListNode;

//创建并且返回一个空的链表
LinkList* LinkList_Create();

//销毁一个链表list
void LinkList_Destroy(LinkList* list);

//将一个链表list中的所有元素清空, 链表回到创建时的初始状态
void LinkList_Clear(LinkList* list);

//返回一个链表list中的所有元素个数
int LinkList_Length(LinkList* list);

//向一个链表list的pos位置处插入新元素node
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

//获取一个链表list的pos位置处的元素
LinkListNode* LinkList_Get(LinkList* list, int pos);

//删除一个链表list的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
LinkListNode* LinkList_Delete(LinkList* list, int pos);
