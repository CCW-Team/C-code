#include<stdio.h>
#include "CircleList.h"

typedef struct tag_Teachr
{
	CircleListNode header;
	int age;
	char name[64];
}Teacher; 

int main()
{

	CircleList* list = NULL;
	Teacher t1, t2, t3, t4, t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	list = CircleList_Create();
	if (list == NULL)
	{
		return;
	}

	int len =CircleList_Length(list);
	int ret = 0;
	//������㷨�;����ҵ��ʵ�ַ���
	ret = (list, (CircleListNode*)&t1, 0);
	ret = CircleList_Insert(list, (CircleListNode*)&t2, 0);
	ret = CircleList_Insert(list, (CircleListNode*)&t3, 0);
	ret = CircleList_Insert(list, (CircleListNode*)&t4, 0);
	ret = CircleList_Insert(list, (CircleListNode*)&t5, 0);

	//����
	for (int i = 0; i < CircleList_Length(list); i++)
	{
		Teacher* tmp = (Teacher*)CircleList_Get(list, i);
		if (tmp == NULL)
		{
			return;
		}
		printf("��������tmp->age:%d\n", tmp->age);
	}

	//ɾ������
	while (CircleList_Length(list) > 0)
	{
		Teacher* tmp = (Teacher*)CircleList_Delete(list, 0);
		if (tmp == NULL)
		{
			return;
		}
		printf("ɾ������tmp%d\n", tmp->age);
	}

	CircleList_Destroy(list);
	return 0;
}