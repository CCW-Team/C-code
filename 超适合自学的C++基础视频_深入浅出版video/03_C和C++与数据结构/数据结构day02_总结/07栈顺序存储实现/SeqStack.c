#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SeqStack.h"
#include "SeqList.h"



//����ջ�൱�ڴ������Ա�
SeqStack* SeqStack_Create(int capacity)
{
	return LinkList_Create(capacity);
}

//����ջ�൱���������Ա�
void SeqStack_Destroy(SeqStack* stack)
{
	List_Destroy(stack);
}

//���ջ �൱�� ������Ա�
void SeqStack_Clear(SeqStack* stack)
{
	List_Clear(stack);
}

//��ջ��ѹ��Ԫ��(��ջ,ѹջ) �൱�� �������β������Ԫ��
int SeqStack_Push(SeqStack* stack, void* item)
{
	return	List_Insert(stack, item, List_Length(stack));//β������
}

//��ջ�е���Ԫ��,�൱�ڴ������β��ɾ��Ԫ��,���ҷ��ر�ɾ����Ԫ��
void* SeqStack_Pop(SeqStack* stack)
{
	return List_Delete(stack, List_Length(stack) - 1);
}

//��ȡջ��Ԫ��,�൱�ڻ�ȡ�����β��Ԫ��
void* SeqStack_Top(SeqStack* stack)
{
	return List_Get(stack, List_Length(stack) - 1);
}

//��ȡջ�Ĵ�С,�뵱�� ��ȡ�����ʵ�ʳ���
int SeqStack_Size(SeqStack* stack)
{
	return List_Length(stack);
}

//��ȡջ������,�൱�ڻ�ȡ���Ա������
int SeqStack_Capacity(SeqStack* stack)
{
	return List_Capactiy(stack);
}