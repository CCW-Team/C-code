
#include "LinkList.h"

typedef struct _Teacher
{
	LinkListNode node;
	int age;
	char name[64];
}Teacher;

void main()
{
	LinkList* list = NULL;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	list = LinkList_Create();
	if (list == NULL)
	{
		return;
	}

	int len = LinkList_Length(list);
	int ret = 0;
	//链表的算法和具体的业务实现分离
	ret = LinkList_Insert(list, (LinkListNode*)&t1, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t2, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t3, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t4, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t5, 0);

	//遍历
	for (int i = 0; i < LinkList_Length(list);i++)
	{
		Teacher* tmp = (Teacher*)LinkList_Get(list, i);
		if (tmp==NULL)
		{
			return;
		}
		printf("遍历链表tmp->age:%d\n", tmp->age);
	}

	//删除链表
	while(LinkList_Length(list)>0)
	{
		Teacher* tmp = (Teacher*)LinkList_Delete(list, 0);
		if (tmp==NULL)
		{
			return;
		}
		printf("删除链表tmp%d\n", tmp->age);
	}

	LinkList_Destroy(list);
	return;
}


////创建并且返回一个空的链表
//LinkList* LinkList_Create();
//
////销毁一个链表list
//void LinkList_Destroy(LinkList* list);
//
////将一个链表list中的所有元素清空, 链表回到创建时的初始状态
//void LinkList_Clear(LinkList* list);
//
////返回一个链表list中的所有元素个数
//int LinkList_Length(LinkList* list);
//
////向一个链表list的pos位置处插入新元素node
//int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);
//
////获取一个链表list的pos位置处的元素
//LinkListNode* LinkList_Get(LinkList* list, int pos);
//
////删除一个链表list的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
//LinkListNode* LinkList_Delete(LinkList* list, int pos);