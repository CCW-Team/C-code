#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SeqStack.h"
#include "SeqList.h"



//创建栈相当于创建线性表
SeqStack* SeqStack_Create(int capacity)
{
	return LinkList_Create(capacity);
}

//销毁栈相当于销毁线性表
void SeqStack_Destroy(SeqStack* stack)
{
	List_Destroy(stack);
}

//清空栈 相当于 清空线性表
void SeqStack_Clear(SeqStack* stack)
{
	List_Clear(stack);
}

//向栈中压入元素(入栈,压栈) 相当于 向链表的尾部插入元素
int SeqStack_Push(SeqStack* stack, void* item)
{
	return	List_Insert(stack, item, List_Length(stack));//尾部插入
}

//从栈中弹出元素,相当于从链表的尾部删除元素,并且返回被删除的元素
void* SeqStack_Pop(SeqStack* stack)
{
	return List_Delete(stack, List_Length(stack) - 1);
}

//获取栈顶元素,相当于获取链表的尾部元素
void* SeqStack_Top(SeqStack* stack)
{
	return List_Get(stack, List_Length(stack) - 1);
}

//获取栈的大小,想当于 获取链表的实际长度
int SeqStack_Size(SeqStack* stack)
{
	return List_Length(stack);
}

//获取栈的容量,相当于获取线性表的容量
int SeqStack_Capacity(SeqStack* stack)
{
	return List_Capactiy(stack);
}