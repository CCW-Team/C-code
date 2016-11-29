#pragma once

#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void List;
typedef void ListNode;

//�������ҷ���һ���յ����Ա�
List* LinkList_Create(int capactiy);

//����һ�����Ա�list
void List_Destroy(List* list);

//��һ�����Ա�list�е�����Ԫ�����, ���Ա�ص�����ʱ�ĳ�ʼ״̬
void List_Clear(List* list);

//����һ�����Ա�list�е�����Ԫ�ظ���
int List_Length(List* list);

//�������Ա������
int List_Capactiy(List* list);

//��һ�����Ա�list��posλ�ô�������Ԫ��node
int List_Insert(List* list, ListNode* node, int pos);

//��ȡһ�����Ա�list��posλ�ô���Ԫ��
ListNode* List_Get(List* list, int pos);

//ɾ��һ�����Ա�list��posλ�ô���Ԫ��  ����ֵΪ��ɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
ListNode* List_Delete(List* list, int pos);



#endif
