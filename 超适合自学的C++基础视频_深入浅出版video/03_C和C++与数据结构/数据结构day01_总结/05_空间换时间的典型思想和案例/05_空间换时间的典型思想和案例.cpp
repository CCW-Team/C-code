#include<iostream>
#include<stdio.h>

using namespace std;

/*
问题：
在一个由自然数1-1000中某些数字所组成的数组中，每个数字可能出现零次或者多次。
设计一个算法，找出出现次数最多的数字。
方法1：
排序，然后找出出现次数最多的数字

方法2：
*/

void search(int a[], int len)
{
	int sp[1000] = { 0 };
	int i = 0;
	int max = 0;

	for (i = 0; i<len; i++)//遍历数组,数组sp[a[i]-1]的值表示的是每个数字a[i]出现次数
	{
		int index = a[i] - 1;

		sp[index]++;
	}

	int num = 0;
	for (i = 0; i<1000; i++)//扫描数组sp[1000],求出sp[i]的最大值,那么在数组a[]中出现做多的就是i+1,出现的次数就是a[i]
	{
		if (max < sp[i])
		{
			max = sp[i];
			num = i+1;
		}
	}
	cout << "数组中" << num << "出现次数最多" << "出现了" << max << "次" << endl;
}

int main()
{
	int array[] = { 1, 1, 1,1,1,1,13, 4, 5, 6, 6, 6, 2, 3 };

	search(array, sizeof(array) / sizeof(*array));

	return 0;
}
