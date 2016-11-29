
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
	//������㷨�;����ҵ��ʵ�ַ���
	ret = LinkList_Insert(list, (LinkListNode*)&t1, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t2, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t3, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t4, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t5, 0);

	//����
	for (int i = 0; i < LinkList_Length(list);i++)
	{
		Teacher* tmp = (Teacher*)LinkList_Get(list, i);
		if (tmp==NULL)
		{
			return;
		}
		printf("��������tmp->age:%d\n", tmp->age);
	}

	//ɾ������
	while(LinkList_Length(list)>0)
	{
		Teacher* tmp = (Teacher*)LinkList_Delete(list, 0);
		if (tmp==NULL)
		{
			return;
		}
		printf("ɾ������tmp%d\n", tmp->age);
	}

	LinkList_Destroy(list);
	return;
}


////�������ҷ���һ���յ�����
//LinkList* LinkList_Create();
//
////����һ������list
//void LinkList_Destroy(LinkList* list);
//
////��һ������list�е�����Ԫ�����, ����ص�����ʱ�ĳ�ʼ״̬
//void LinkList_Clear(LinkList* list);
//
////����һ������list�е�����Ԫ�ظ���
//int LinkList_Length(LinkList* list);
//
////��һ������list��posλ�ô�������Ԫ��node
//int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);
//
////��ȡһ������list��posλ�ô���Ԫ��
//LinkListNode* LinkList_Get(LinkList* list, int pos);
//
////ɾ��һ������list��posλ�ô���Ԫ��  ����ֵΪ��ɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
//LinkListNode* LinkList_Delete(LinkList* list, int pos);