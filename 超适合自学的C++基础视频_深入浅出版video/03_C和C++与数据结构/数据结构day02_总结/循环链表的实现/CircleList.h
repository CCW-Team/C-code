#pragma once



#include<stdlib.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

typedef void CircleList;

typedef struct _tag_CircleListNode
{
	struct CircleListNode* next;
}CircleListNode;

//创建并且返回一个空的链表
CircleList* CircleList_Create();

//销毁一个链表list
void CircleList_Destroy(CircleList* list);

//将一个链表list中的所有元素清空, 链表回到创建时的初始状态
void CircleList_Clear(CircleList* list);

//返回一个链表list中的所有元素个数
int CircleList_Length(CircleList* list);

//向一个链表list的pos位置处插入新元素node
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

//获取一个链表list的pos位置处的元素
CircleListNode* CircleList_Get(CircleList* list, int pos);

//删除一个链表list的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
CircleListNode* CircleList_Delete(CircleList* list, int pos);

//根据链表元素删除节点
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

//让游标指向第0个业务节点
CircleListNode* CircleList_Reset(CircleList* list);

//获取游标指向的位置
CircleListNode* CircleList_Current(CircleList* list);

//把当前位置返回,并且游标下移
CircleListNode* CircleList_Next(CircleList* list);
