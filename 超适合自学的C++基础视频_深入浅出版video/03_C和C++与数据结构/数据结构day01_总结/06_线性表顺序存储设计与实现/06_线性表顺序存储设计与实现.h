#pragma once

#ifndef _WBM_LIST_H_
#define _WBM_LIST_H_

typedef void List;
typedef void ListNode;

//创建并且返回一个空的线性表
List* LinkList_Create(int capactiy);

//销毁一个线性表list
void List_Destroy(List* list);

//将一个线性表list中的所有元素清空, 线性表回到创建时的初始状态
void List_Clear(List* list);

//返回一个线性表list中的所有元素个数
int List_Length(List* list);

//向一个线性表list的pos位置处插入新元素node
int List_Insert(List* list, ListNode* node, int pos);

//获取一个线性表list的pos位置处的元素
ListNode* List_Get(List* list, int pos);

//删除一个线性表list的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
ListNode* List_Delete(List* list, int pos);



#endif
