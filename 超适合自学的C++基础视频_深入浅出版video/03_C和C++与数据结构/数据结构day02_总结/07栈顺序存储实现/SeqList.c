
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SeqList.h"

//�ڽṹ����1��ָ��
typedef struct _tag_List
{
	int length;
	int capactiy;
	unsigned int** node;
}TList;


//�������ҷ���һ���յ����Ա�
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
	//����capacity�Ĵ�С����ڵ�Ĵ�С
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

//����һ�����Ա�list
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


//��һ�����Ա�list�е�����Ԫ�����, ���Ա�ص�����ʱ�ĳ�ʼ״̬
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


//����һ�����Ա�list�е�����Ԫ�ظ���
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


//��һ�����Ա�list��posλ�ô�������Ԫ��node
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

	//�ж��ǲ�������
	if (tlist->length >= tlist->capactiy)
	{
		ret = -2;
		printf("func List_Insert err:(tlist->length >=tlist->capactiy)%d \n ", ret);
		return ret;
	}

	//�ݴ�����,����������20��Ԫ��,������5,���ǲ����λ�ô���5С��20
	if (pos >= tlist->length)
	{
		pos = tlist->length;
	}
	//Ԫ�غ���
	for (int i = tlist->length; i >pos; i--)
	{
		tlist->node[i] = tlist->node[i-1];//a[7]=a[6]
	}//Ӧ�ô����һһ��Ԫ���ƶ���ʼ,����Ǵ�a[pos]��ʼ�ƶ�,��ô�����ÿ��Ԫ�ض���a[pos]
	//����Ԫ��
	tlist->node[pos] = node;
	tlist->length++;
	return 0;
}


//��ȡһ�����Ա�list��posλ�ô���Ԫ��
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


//ɾ��һ�����Ա�list��posλ�ô���Ԫ��  ����ֵΪ��ɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
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
	for (i = pos+1; i < tlist->length;i++) //��posλ�ú����Ԫ��ǰ��
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