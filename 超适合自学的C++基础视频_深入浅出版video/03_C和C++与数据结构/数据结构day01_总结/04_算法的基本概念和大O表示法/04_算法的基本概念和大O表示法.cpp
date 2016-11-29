#include<iostream>
#include<stdio.h>

using namespace std;
//�㷨������Ҫ����ɾ���ļ����ָ��
//ûһ��ָ���ھ���ļ������cpu�����е�ʱ����̶���
//ͨ�������n�Ĳ�����پͿ����Ƶ����㷨�ĸ��Ӷ�
												
long sum1(int n)			//2n+3 ʱ�临�Ӷ�ΪO(n)		�ռ临�Ӷ�  4n+8 O(n)
{												
	long ret = 0;					//1��	�ڴ�4
	int* array = (int*)malloc(n * sizeof(int));	 //1�� �ڴ�4n
	int i = 0;									//1��  �ڴ�4
												
	for (i = 0; i < n; i++)						  //n�� ��cpu�����в���Ҫ�ڴ�
	{											
		array[i] = i + 1;						
	}											
												
	for (i = 0; i < n; i++)						 //n�� 
	{											
		ret += array[i];						  
	}											
												
	free(array);								 //1��
												
	return ret;									
}

long sum2(int n)   //n+2 ʱ�临�Ӷ� O(n)  �ռ临�Ӷ� 8 O(1)
{
	long ret = 0;//1��  �ڴ�4
	int i = 0;//1��		�ڴ�4

	for (i = 1; i <= n; i++)  //n�� 
	{
		ret += i;
	}

	return ret;
}

long sum3(int n) //ʱ�临�Ӷ�Ϊ O(1) �ռ临�Ӷ� 4 O(1)
{
	long ret = 0; //1�� �ڴ�4

	if (n > 0)
	{
		ret = (1 + n) * n / 2;  //1��
	}

	return ret;
}

int main()
{
	printf("%d\n", sum1(100));
	printf("%d\n", sum2(100));
	printf("%d\n", sum3(100));

	return 0;
}

