#include<iostream>
#include<stdio.h>

using namespace std;

/*
���⣺
��һ������Ȼ��1-1000��ĳЩ��������ɵ������У�ÿ�����ֿ��ܳ�����λ��߶�Ρ�
���һ���㷨���ҳ����ִ����������֡�
����1��
����Ȼ���ҳ����ִ�����������

����2��
*/

void search(int a[], int len)
{
	int sp[1000] = { 0 };
	int i = 0;
	int max = 0;

	for (i = 0; i<len; i++)//��������,����sp[a[i]-1]��ֵ��ʾ����ÿ������a[i]���ִ���
	{
		int index = a[i] - 1;

		sp[index]++;
	}

	int num = 0;
	for (i = 0; i<1000; i++)//ɨ������sp[1000],���sp[i]�����ֵ,��ô������a[]�г�������ľ���i+1,���ֵĴ�������a[i]
	{
		if (max < sp[i])
		{
			max = sp[i];
			num = i+1;
		}
	}
	cout << "������" << num << "���ִ������" << "������" << max << "��" << endl;
}

int main()
{
	int array[] = { 1, 1, 1,1,1,1,13, 4, 5, 6, 6, 6, 2, 3 };

	search(array, sizeof(array) / sizeof(*array));

	return 0;
}
