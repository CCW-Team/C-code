#include "CircleList.h"




typedef struct _tag_Circle_List
{
	CircleListNode header;
	CircleListNode* slider;
	int length;
}TCircleList;

//�������ҷ���һ���յ�����
CircleList* CircleList_Create() //O(1)
{
	TCircleList* ret = (TCircleList*)malloc(sizeof(TCircleList));
	if (ret == NULL)
	{
		return NULL;
	}
	ret->length = 0;
	ret->header.next = NULL;
	ret->slider = NULL;
	return ret;
}

//����һ������list
void CircleList_Destroy(CircleList* list)  //O(1)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}

//��һ������list�е�����Ԫ�����, ����ص�����ʱ�ĳ�ʼ״̬
void CircleList_Clear(CircleList* list)  //O(1)
{
	TCircleList* tlist = (TCircleList*)list;
	if (list == NULL)
	{
		return;
	}
	tlist->length = 0;
	tlist->header.next = NULL;
	tlist->slider = NULL;
	return;
}

//����һ������list�е�����Ԫ�ظ���
int CircleList_Length(CircleList* list) //O(1)
{
	TCircleList* tlist = (TCircleList*)list;
	if (list == NULL)
	{
		return 0;
	}
	return tlist->length;
}

//��һ������list��posλ�ô�������Ԫ��node
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos) //O(n)
{
	int ret = 0;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func CircleList_Insert() err:%d", ret);
		return ret;
	}
	TCircleList* tlist = (TCircleList*)list;

	CircleListNode* current = (CircleList*)tlist;


	//������ָ����Ƶ�posλ�õ�ǰһ��λ��
	for (int i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}

	//1����ѭ����current��ʾ����pos-1����ڵ�,�����ò���ڵ��next����current��next,��node���Ӻ����ڵ�
	node->next = current->next;
	//2 Ȼ������current��next�ڵ����node;��ǰ�����������node�ڵ�
	current->next = node;

	//����ǵ�һ�β���ڵ�
	if (tlist->length == 0)
	{
		tlist->slider = node;
	}
	tlist->length++;

	//���current��ʱָ��ͷ���ڵ�,��ô������ͷ�巨
	if (current == (CircleListNode*)tlist)
	{
		//��ȡ���һ��Ԫ��
		CircleListNode* last = CircleList_Get(tlist, tlist->length - 1);
		//�����һ���ڵ��next��ָ���²���Ľڵ�
		last->next = current->next;
	}
	return 0;
}

//��ȡһ������list��posλ�ô���Ԫ��
CircleListNode* CircleList_Get(CircleList* list, int pos)  //O(n)
{
	int ret = 0;
	if (list == NULL || pos < 0)
	{
		ret = 0;
		printf("func CircleList_Get() err:%d", ret);
		return NULL;
	}
	TCircleList* tlist = (TCircleList*)list;

	CircleListNode* current = (CircleListNode*)tlist;


	current = &(tlist->header);//���ø���ָ��ָ��ͷ���

	 //������ָ����Ƶ�posλ�õ�ǰһ��λ��
	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	return current->next;
}

//ɾ��һ������list��posλ�ô���Ԫ��  ����ֵΪ��ɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
CircleListNode* CircleList_Delete(CircleList* list, int pos)  //O(n)
{
	TCircleList* tlist = (TCircleList*)list;

	if ((tlist != NULL) && (pos >= 0) && (tlist->length > 0))
	{
		//CircleListNode* current = (CircleListNode*)&(tlist->header);//���ø���ָ��ָ��ͷ���
		CircleListNode* current = (CircleListNode*)tlist;//���ø���ָ��ָ��ͷ���
		CircleListNode* last = NULL;

		for (int i = 0; i < pos; i++)
		{
			current = current->next;
		}

		//��ɾ������ͷ�ڵ�,��Ҫ�ȱ������һ���ڵ�(ͷ�巨)
		if (current == (CircleListNode*)tlist)
		{
			last = (CircleListNode*)CircleList_Get(tlist, tlist->length - 1);
		}
		//ѭ��ִ������ʱcurrentָ��Ҫɾ���ڵ��ǰһ���ڵ�

		//��Ҫɾ���Ľڵ�
		CircleListNode* tmp = NULL;//����һ����ʱ�ڵ�
		tmp = current->next;//����ʱ�ڵ����Ҫɾ����pos�ڵ�
		current->next = tmp->next;//����Ҫɾ����pos�ڵ��ǰһ���ڵ��next�ͺ���Ľڵ�����
		tlist->length--;

		//���ж������Ƿ�Ϊ��,��β���ڵ�����ԭ���ĵζ����ڵ�
		if (last != NULL)
		{
			tlist->header.next = tmp->next;
			last->next = tmp->next;
		}

		//��ɾ����Ԫ��Ϊ�α���ָ��Ԫ��
		if (tlist->slider == tmp)
		{
			tlist->slider = tmp->next;
		}

		//��ɾ��Ԫ�غ�,����ĳ���Ϊ0
		if (tlist->length == 0)
		{
			tlist->header.next = NULL;
			tlist->slider = NULL;
		}
		return tmp;//���ر�ɾ���Ľڵ�,�����ϲ�Ӧ��ȥ����
	}
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node) //O(n)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;	

	if (tlist != NULL)
	{
		CircleListNode* current = (CircleListNode*)tlist;
		//����node�ڵ���ѭ�������е�λ��i
		int i = 0;
		for (i = 0; i < tlist->length; i++)	
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;	
		}

		//����ҵ�,����iȥɾ��
		if (ret != NULL)
		{
			CircleList_Delete(tlist, i);
		}
	}
	return ret;
}

//���α�ָ���0��ҵ��ڵ�
CircleListNode* CircleList_Reset(CircleList* list)  //O(1)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if (tlist != NULL)
	{
		tlist->slider = tlist->header.next;
		ret = tlist->slider;
	}
	return ret;
}
//��ȡ�α�ָ���λ��
CircleListNode* CircleList_Current(CircleList* list) //O(1)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if (tlist != NULL)
	{
		ret = tlist->slider;
	}

	return ret;
}
//�ѵ�ǰλ�÷���,�����α�����
CircleListNode* CircleList_Next(CircleList* list) //O(1)
{
	TCircleList* tlist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if ((tlist != NULL) && (tlist->slider != NULL))
	{
		ret = tlist->slider;
		tlist->slider = ret->next;
	}
	return ret;
}