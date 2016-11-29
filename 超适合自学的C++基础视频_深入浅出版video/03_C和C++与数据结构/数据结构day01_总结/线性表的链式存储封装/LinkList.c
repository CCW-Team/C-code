#include "LinkList.h"

typedef struct _tag_Link_List
{
	LinkListNode header;
	int length;
}TlinkList;
//创建并且返回一个空的链表
LinkList* LinkList_Create()
{
	TlinkList* ret = NULL;
	ret = (TlinkList*)malloc(sizeof(TlinkList));
	memset(ret, 0, sizeof(TlinkList));

	ret->length = 0;//非必须
	ret->header.next = NULL;//非必须	
	return ret;
}

//销毁一个链表list
void LinkList_Destroy(LinkList* list)
{
	if (list!=NULL)
	{
		free(list);
		list = NULL;
	}
	return ;
}

//将一个链表list中的所有元素清空, 链表回到创建时的初始状态
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

//返回一个链表list中的所有元素个数
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

//向一个链表list的pos位置处插入新元素node
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

	//LinkListNode* current = &(tlist->header);//先让辅助指针指向头结点

	LinkListNode* current = (LinkListNode*)tlist;//因为在TlinkList中header的地址就是首地址

	//将辅助指针后移到pos位置的前一个位置
	for (int i = 0; i < pos&&(current->next!=NULL);i++)
	{
		current = current->next;
	}

	//1结束循环后current表示的是pos-1这个节点,所以让插入节点的next等于current的next,让node连接后续节点
	node->next = current->next;
	//2 然后再让current的next节点等于node;让前面的链表链接node节点
	current->next = node;
	tlist->length++;
	return 0;
}

//获取一个链表list的pos位置处的元素
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

	current = &(tlist->header);//先让辅助指针指向头结点
	
	//将辅助指针后移到pos位置的前一个位置
	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}

	return current->next;
}

//删除一个链表list的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
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

	LinkListNode* current = NULL;//声明一个辅助节点

	current = &(tlist->header);//先让辅助指针指向头结点

	//将辅助指针后移到pos位置的前一个位置
	for (int i = 0; i < pos && (current->next != NULL); i++)
	{
		current = current->next;
	}
	//循环执行完后此时current指向要删除节点的前一个节点

	LinkListNode* tmp = NULL;//声明一个临时节点

	tmp = current->next;//让临时节点等于要删除的pos节点

	current->next = tmp->next;//再让要删除的pos节点的前一个节点的next和后面的节点连接

	tlist->length--;

	
	return tmp;//返回被删除的节点,好让上层应用去析构
}