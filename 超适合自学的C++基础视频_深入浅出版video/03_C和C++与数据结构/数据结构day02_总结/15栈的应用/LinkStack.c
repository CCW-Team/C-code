#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"


typedef struct tag_LinkStackNode  //ջ��ҵ��ڵ�
{
	LinkListNode node;//��һ����(Ԫ��)
	void* item; //ջ��ҵ��ڵ�,����ҵ��ڵ������һ��ջ��ҵ��ڵ�
}TLinkStackNode;

//����һ��ջ		�൱�ڴ���һ������
LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

//����һ��ջ		�൱������һ������
void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
}

//���һ��ջ		�൱�����һ������
//���ջ��ʱ���漰��ջ���������ڵĹ���:������ջ�Ľڵ㶼��malloc,���ջ��ʱ��Ҫ��ջ��Ԫ�ص���,�����ͷŽڵ�
void LinkStack_Clear(LinkStack* stack)
{
	if (NULL == stack)
	{
		return;
	}
	while (LinkStack_Size(stack) > 0)
	{
		LinkStack_Pop(stack);//��pop�������ͷŽڵ��ڴ�
	}
	return;
}

// ��ջ�����Ԫ��	�൱���������ͷ������Ԫ��
//void* item ջ��ҵ��ڵ�  ,��Ҫת���������ҵ��ڵ�
int LinkStack_Push(LinkStack* stack, void* item)
{
	TLinkStackNode* tmp = NULL;
	//���Ԫ�غ�ϣ���ڴ汻����,��Ҫ�����ڴ�
	tmp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (NULL == tmp)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	
	tmp->item = item;//�Ѵ����ҵ��ڵ��ַ����tmp��ҵ��ڵ�

	int ret = LinkList_Insert(stack, (TLinkStackNode*)tmp, 0);
	if (ret != 0)
	{
		printf("func LinkList_Insert err:%d ", ret);
		if (tmp != NULL)
		{
			free(tmp);
		}
		return ret;
	}
	return ret;
}

//��ջ�е���Ԫ��		�൱�ڴ�����ͷ��ɾ��Ԫ��
//�������ҵ��ڵ� ת��Ϊ ջ��ҵ��ڵ�
void* LinkStack_Pop(LinkStack* stack)
{
	void* item = NULL;//ջ��ҵ��ڵ�
	TLinkStackNode* tmp = NULL;
	tmp = (TLinkStackNode*)LinkList_Delete(stack, 0);
	if (NULL == tmp)
	{
		return NULL;
	}
	item = tmp->item;
	//��ΪlinList_Insert��ʱ��,�������ڴ�,����LinkList_Delete�ͷ��ڴ�
	free(tmp);
	return item;
}

//��ȡջ��Ԫ��	�൱�ڻ�ȡ�����0��λ��
void* LinkStack_Top(LinkStack* stack)
{
	TLinkStackNode* tmp = NULL;
	tmp = (TLinkStackNode*)LinkList_Get(stack, 0);
	if (NULL == tmp)
	{
		return NULL;
	}
	return tmp->item;
}

//��ջ�Ĵ�С		�൱���������len
int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}