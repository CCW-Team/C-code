
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SeqList.h"

//在结构体套1级指针
typedef struct _tag_List
{
	int length;
	int capactiy;
	unsigned int** node;
}TList;


//创建并且返回一个空的线性表
List* LinkList_Create(int capactiy)
{
	TList * tmp = NULL;
	int ret = 0;
	tmp = (TList*)malloc(sizeof(TList));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func LinkList_Create err:%d \n", ret);
		return NULL;
	}
	memset(tmp, 0, sizeof(TList));
	//根据capacity的大小分配节点的大小
	tmp->node = (unsigned int **)malloc(sizeof(unsigned int*)* capactiy);
	if (tmp->node == NULL)
	{
		ret = -2;
		printf("func LinkList_Create err: malloc err%d \n", ret);
		return NULL;
	}
	tmp->capactiy = capactiy;
	tmp->length = 0;
	return tmp;
}

//销毁一个线性表list
void List_Destroy(List* list)
{
	TList * tlist = NULL;
	if (list == NULL)
	{
		return ;
	}
	tlist = (TList*)list;
	if (tlist->node != NULL)
	{
		free(tlist->node);
	}
	free(tlist);
	return;
}


//将一个线性表list中的所有元素清空, 线性表回到创建时的初始状态
void List_Clear(List* list)
{

	TList * tlist = NULL;
	if (list == NULL)
	{
		return;
	}
	tlist = (TList*)list;
	tlist->length = 0;
	return;
}


//返回一个线性表list中的所有元素个数
int List_Length(List* list)
{
	TList * tlist = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tlist = (TList*)list;
	return tlist->length;
}


//向一个线性表list的pos位置处插入新元素node
int List_Insert(List* list, ListNode* node, int pos)
{
	int ret = 0;
	TList * tlist = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func List_Insert err:%d \n ", ret);
		return ret;
	}
	tlist = (TList *)list;

	//判断是不是满了
	if (tlist->length >= tlist->capactiy)
	{
		ret = -2;
		printf("func List_Insert err:(tlist->length >=tlist->capactiy)%d \n ", ret);
		return ret;
	}

	//容错修正,比如容量是20个元素,长度是5,但是插入的位置大于5小于20
	if (pos >= tlist->length)
	{
		pos = tlist->length;
	}
	//元素后移
	for (int i = tlist->length; i >pos; i--)
	{
		tlist->node[i] = tlist->node[i-1];//a[7]=a[6]
	}//应该从最后一一个元素移动开始,如果是从a[pos]开始移动,那么后面的每个元素都是a[pos]
	//插入元素
	tlist->node[pos] = node;
	tlist->length++;
	return 0;
}


//获取一个线性表list的pos位置处的元素
ListNode* List_Get(List* list, int pos)
{
	ListNode* ret = 0;
	TList * tlist = NULL;
	if (list == NULL || pos < 0)
	{
		printf("func List_Get err:\n ");
		return NULL;
	}
	tlist = (TList*)list;
	ret = (void*)tlist->node[pos];
	return ret;
}


//删除一个线性表list的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
ListNode* List_Delete(List* list, int pos)
{

	ListNode* ret = 0;
	TList * tlist = NULL;
	if (list == NULL || pos < 0)
	{
		printf("func List_Delete err:\n ");
		return NULL;
	}
	tlist = (TList*)list;
	ret = (ListNode*)tlist->node[pos];
	int i = 0;
	for (i = pos+1; i < tlist->length;i++) //从pos位置后面的元素前移
	{
		tlist->node[i - 1] = tlist->node[i];
	}
	tlist->length--;
	return ret;
}

int List_Capactiy(List* list)
{
	TList * tlist = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tlist = (TList*)list;
	return tlist->capactiy;
}