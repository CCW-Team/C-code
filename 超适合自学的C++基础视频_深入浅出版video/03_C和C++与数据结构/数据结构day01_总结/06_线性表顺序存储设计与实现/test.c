#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "06_线性表顺序存储设计与实现.h"


typedef struct _Teacher
{
	int age;
	char name[64];
}Teachr;

void main()
{

	List* list = NULL;

	
	Teachr t1 = { 21,"a" };
	Teachr t2 = { 22,"b" };
	Teachr t3 = { 23,"c" };
	Teachr t4 = { 24,"d" };
	Teachr t5 = { 25,"e" };

	list = LinkList_Create(5);
	int ret = 0;
	if (list == NULL)
	{
		printf("func LinkList_Create() ret: %d \n", ret);
		return;
	}

	ret = List_Insert(list, (ListNode*)&t1, 0);//头插法	
	ret = List_Insert(list, (ListNode*)&t2, 0);//头插法	
	ret = List_Insert(list, (ListNode*)&t3, 0);//头插法
	ret = List_Insert(list, (ListNode*)&t4, 0);//头插法
	ret = List_Insert(list, (ListNode*)&t5, 0);//头插法

	int i;
	//遍历
	for (i = 0; i < List_Length(list); i++)
	{
		Teachr* tmp = (Teachr*)List_Get(list, i);
		if (tmp == NULL)
		{
			return;
		}
		printf("tmp->age:%d ", tmp->age);
	}

	//删除链表中的节点
	while (List_Length(list) > 0)
	{
		List_Delete(list, 0);
	}
	system("pause");
	/*
	//创建并且返回一个空的线性表
	List* LinkList_Create();

	//销毁一个线性表list
	void List_Destroy(List* list);

	//将一个线性表list中的所有元素清空, 线性表回到创建时的初始状态
	void List_Clear(List* list);

	//返回一个线性表list中的所有元素个数
	int List_Length(List* list);

	//向一个线性表list的pos位置处插入新元素node
	int List_Insert(List* list, ListNode* node, int pos);

	//获取一个线性表list的pos位置处的元素
	ListNode* List_Get(List* list, int pos);

	//删除一个线性表list的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
	ListNode* List_Delete(List* list, int pos);

	*/
}