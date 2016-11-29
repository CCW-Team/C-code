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

//�������ҷ���һ���յ�����
CircleList* CircleList_Create();

//����һ������list
void CircleList_Destroy(CircleList* list);

//��һ������list�е�����Ԫ�����, ����ص�����ʱ�ĳ�ʼ״̬
void CircleList_Clear(CircleList* list);

//����һ������list�е�����Ԫ�ظ���
int CircleList_Length(CircleList* list);

//��һ������list��posλ�ô�������Ԫ��node
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

//��ȡһ������list��posλ�ô���Ԫ��
CircleListNode* CircleList_Get(CircleList* list, int pos);

//ɾ��һ������list��posλ�ô���Ԫ��  ����ֵΪ��ɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
CircleListNode* CircleList_Delete(CircleList* list, int pos);

//��������Ԫ��ɾ���ڵ�
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

//���α�ָ���0��ҵ��ڵ�
CircleListNode* CircleList_Reset(CircleList* list);

//��ȡ�α�ָ���λ��
CircleListNode* CircleList_Current(CircleList* list);

//�ѵ�ǰλ�÷���,�����α�����
CircleListNode* CircleList_Next(CircleList* list);
