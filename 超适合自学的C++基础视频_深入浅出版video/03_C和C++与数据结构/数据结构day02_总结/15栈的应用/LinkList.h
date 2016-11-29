#pragma once



#include<stdlib.h>
#include <string.h>
#include <stdio.h>

typedef void LinkList;

typedef struct _tag_LinkListNode
{
	struct LinkListNode* next;
}LinkListNode;

//�������ҷ���һ���յ�����
LinkList* LinkList_Create();

//����һ������list
void LinkList_Destroy(LinkList* list);

//��һ������list�е�����Ԫ�����, ����ص�����ʱ�ĳ�ʼ״̬
void LinkList_Clear(LinkList* list);

//����һ������list�е�����Ԫ�ظ���
int LinkList_Length(LinkList* list);

//��һ������list��posλ�ô�������Ԫ��node
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

//��ȡһ������list��posλ�ô���Ԫ��
LinkListNode* LinkList_Get(LinkList* list, int pos);

//ɾ��һ������list��posλ�ô���Ԫ��  ����ֵΪ��ɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
LinkListNode* LinkList_Delete(LinkList* list, int pos);
