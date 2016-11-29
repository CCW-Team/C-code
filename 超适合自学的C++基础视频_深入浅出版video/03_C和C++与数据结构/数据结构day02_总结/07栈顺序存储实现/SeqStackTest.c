#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SeqStack.h"

int main()
{
	SeqStack* stack = NULL;
	stack = SeqStack_Create(10);
	if (NULL == stack)
	{
		return;
	}
	int i = 0;
	int a[10];

	//Ñ¹Õ»
	for (i = 0; i < 5;i++)
	{
		a[i] = i + 1;
		SeqStack_Push(stack, &a[i]);
	}

	//ÇóÕ»µÄÈÝÁ¿
	printf("Capacity:%d \n", SeqStack_Capacity(stack));
	printf("Length:%d \n", SeqStack_Size(stack));
	printf("top: %d \n", *(int*)SeqStack_Top(stack));
	while (SeqStack_Size(stack) > 0)	
	{
		int tmp = 	*(int*)SeqStack_Pop(stack);
		printf("tmp:%d \n", tmp);
	}
	printf("\n");
	return 0;
}