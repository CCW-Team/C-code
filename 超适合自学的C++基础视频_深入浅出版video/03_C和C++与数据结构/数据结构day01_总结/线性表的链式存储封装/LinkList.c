#include "LinkList.h"

typedef struct _tag_Link_List
{
	LinkListNode header;
	int length;
}TlinkList;
//�������ҷ���һ���յ�����
LinkList* LinkList_Create()
{
	TlinkList* ret = NULL;
	ret = (TlinkList*)malloc(sizeof(TlinkList));
	memset(ret, 0, sizeof(TlinkList));

	ret->length = 0;//�Ǳ���
	ret->header.next = NULL;//�Ǳ���	
	return ret;
}

//����һ������list
void LinkList_Destroy(LinkList* list)
{
	if (list!=NULL)
	{
		free(list);
		list = NULL;
	}
	return ;
}

//��һ������list�е�����Ԫ�����, ����ص�����ʱ�ĳ�ʼ״̬
void LinkList_Clear(LinkList* list)
{
	TlinkList* tlist = NULL;
	if (list==NULL)
	{
		return;
	}
	tlist = (TlinkList*)list;
	tlist->length = 0;
	tlist->header.next = NULL;
	return ;
}

//����һ������list�е�����Ԫ�ظ���
int LinkList_Length(LinkList* list)
{
	TlinkList* tlist = NULL;
	if (list == NULL)
	{
		return 0;
	}
	tlist = (TlinkList*)list;
	return tlist->length;
}

//��һ������list��posλ�ô�������Ԫ��node
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	int ret = 0;
	if (list==NULL||node==NULL||pos <0)
	{
		ret = 0;
		printf("func LinkList_Insert() err:%d", ret);
		return ret;
	}
	TlinkList* tlist = NULL;
	tlist = (TlinkList*)list;

	//LinkListNode* current = &(tlist->header);//���ø���ָ��ָ��ͷ���

	LinkListNode* current = (LinkListNode*)tlist;//��Ϊ��TlinkList��header�ĵ�ַ�����׵�ַ

	//������ָ����Ƶ�posλ�õ�ǰһ��λ��
	for (int i = 0; i < pos&&(current->next!=NULL);i++)
	{
		current = current->next;
	}

	//1����ѭ����current��ʾ����pos-1����ڵ�,�����ò���ڵ��next����current��next,��node���Ӻ����ڵ�
	node->next = current->next;
	//2 Ȼ������current��next�ڵ����node;��ǰ�����������node�ڵ�
	current->next = node;
	tlist->length++;
	return 0;
}

//��ȡһ������list��posλ�ô���Ԫ��
LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	int ret = 0;
	if (list == NULL || pos < 0)	
	{
		ret = 0;
		printf("func LinkList_Get() err:%d", ret);
		return NULL;
	}
	TlinkList* tlist = NULL;
	tlist = (TlinkList*)list;

	LinkListNode* current = NULL;

	current = &(tlist->header);//���ø���ָ��ָ��ͷ���
	
	//������ָ����Ƶ�posλ�õ�ǰһ��λ��
	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	return current->next;
}

//ɾ��һ������list��posλ�ô���Ԫ��  ����ֵΪ��ɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
	int ret = 0;
	if (list == NULL || pos < 0)
	{
		ret = 0;
		printf("func LinkList_Delete() err:%d", ret);
		return ret;
	}
	TlinkList* tlist = NULL;
	tlist = (TlinkList*)list;

	LinkListNode* current = NULL;//����һ�������ڵ�

	current = &(tlist->header);//���ø���ָ��ָ��ͷ���

	//������ָ����Ƶ�posλ�õ�ǰһ��λ��
	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	//ѭ��ִ������ʱcurrentָ��Ҫɾ���ڵ��ǰһ���ڵ�

	LinkListNode* tmp = NULL;//����һ����ʱ�ڵ�

	tmp = current->next;//����ʱ�ڵ����Ҫɾ����pos�ڵ�

	current->next = tmp->next;//����Ҫɾ����pos�ڵ��ǰһ���ڵ��next�ͺ���Ľڵ�����

	tlist->length--;

	
	return tmp;//���ر�ɾ���Ľڵ�,�����ϲ�Ӧ��ȥ����
}