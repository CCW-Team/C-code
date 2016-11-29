#include<iostream>
#include<stdio.h>

using namespace std;
//算法的最终要编译成具体的计算机指令
//没一个指令在具体的计算机中cpu上运行的时间输固定的
//通过具体的n的步骤多少就可以推导出算法的复杂度
												
long sum1(int n)			//2n+3 时间复杂度为O(n)		空间复杂度  4n+8 O(n)
{												
	long ret = 0;					//1步	内存4
	int* array = (int*)malloc(n * sizeof(int));	 //1步 内存4n
	int i = 0;									//1步  内存4
												
	for (i = 0; i < n; i++)						  //n步 在cpu中运行不需要内存
	{											
		array[i] = i + 1;						
	}											
												
	for (i = 0; i < n; i++)						 //n步 
	{											
		ret += array[i];						  
	}											
												
	free(array);								 //1步
												
	return ret;									
}

long sum2(int n)   //n+2 时间复杂度 O(n)  空间复杂度 8 O(1)
{
	long ret = 0;//1步  内存4
	int i = 0;//1步		内存4

	for (i = 1; i <= n; i++)  //n步 
	{
		ret += i;
	}

	return ret;
}

long sum3(int n) //时间复杂度为 O(1) 空间复杂度 4 O(1)
{
	long ret = 0; //1步 内存4

	if (n > 0)
	{
		ret = (1 + n) * n / 2;  //1步
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

