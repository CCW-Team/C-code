/*
��׺ת��׺�㷨��
   ������׺���ʽ�е����ֺͷ���
   �������֣�ֱ�����
   ���ڷ��ţ�
   �����ţ���ջ
   ������ţ���ջ�����Ž������ȼ��Ƚ�
   ��ջ���������ȼ��ͣ��˷��Ͻ�ջ  ��Ĭ��ջ�����������ţ����������ȼ���ͣ�
   ��ջ���������ȼ����ͣ���ջ�����ŵ����������֮���ջ
   �����ţ���ջ�����ŵ����������ֱ��ƥ��������
   ������������ջ�е����з��ŵ��������
   ��׺ת��׺
*/


// http://blog.csdn.net/qwq1503/article/details/52677673
//���ϴ���
/*
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 512

int top = -1;
int stack[512];

void Push(int e) {
	if (top >= MAXSIZE) {
		puts("ջ����");
		exit(1);
	}
	stack[++top] = e;

}
int isEmpty() {
	return top == -1 ? 1 : 0;
}
int Pop() {
	if (top == -1) {
		puts("����һ����ջ��");
		exit(1);
	}
	return stack[top--];
}

int getTop() {
	if (top < MAXSIZE)
		return stack[top];
	exit(1);
}

int judgePriority(char op1, char op2) {
	// 1 �ȳ�ջ�� �ٽ�ջ
	// 0 ֱ�ӽ�ջ
	if (op1 == '(' || op2 == '(')
		return 0;
	if ((op1 == '-' || op1 == '+') && (op2 == '*' || op2 == '/'))
		return 0;
	return 1;
}
void infix2postfix(char *tmp, char *str) {
	char *p = tmp;
	int i, j, k;
	char op1, op2;
	j = 0;
	for (i = 0; p[i]; i++) {
		// ����
		if (p[i] >= '0' && p[i] <= '9')
			str[j++] = p[i];
		// �ַ�
		else {
			op1 = getTop();
			op2 = p[i];
			if (isEmpty())
				Push(op2);
			// �ǿ�
			else {
				if (op2 == ')') {
					while (getTop() != '(')
						str[j++] = Pop();
					Pop();
					continue;
				}
				switch (judgePriority(op1, op2)) {
				case  1: str[j++] = Pop();
					for (k = 0; k <= top; k++) {
						if (!judgePriority(op1, op2)) break;
						str[j++] = Pop();
					}
					Push(op2);
					break;
				case  0:  Push(op2); break;
				}
			}
		}
	}

	while (!isEmpty())
		str[j++] = Pop();
	str[j] = 0;
}

int calc(char *buf) {
	int i, k, j;
	for (i = 0; buf[i]; i++) {
		switch (buf[i]) {
		case '+':
			k = Pop() + Pop();
			Push(k);
			break;
		case '-':
			j = Pop();
			k = Pop() - j;
			Push(k);
			break;
		case '*':
			k = Pop() * Pop();
			Push(k);
			break;
		case '/':
			j = Pop();
			k = Pop() / j;
			Push(k);
			break;
		default:
			Push(buf[i] - 48);
		}
	}
	return Pop();

}
int main() {
	char tmp[512] = "9-2*2+(9-8)", str[512];
	puts("����������ʽ��");
	gets(tmp);
	infix2postfix(tmp, str);
	puts(str);
	printf("%s = %d\n", tmp, calc(str));
}
*/

#include <stdio.h>
#include <stdlib.h>
#include"LinkStack.h"
#include<ctype.h>

int isNumber(char ch)
{
	/*if ( isdigit(ch))
	{
		return 1;
	}
	return 0;*/
	return('0' <= ch) && (ch <= '9');
}

int isOperator(char ch)
{
	/*
		int i = 0;
	switch (ch)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		i = 1;
		break;
	default:
		break;
	}
	return i;
	*/
	return(ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');
}

int isLeft(char ch)
{/*
	if ('(' == ch)
	{
		return 1;
	}
	return 0;*/
	return (ch == '(');
}

int isRight(char ch)
{
	if (')' == ch)
	{
		return 1;
	}
	return 0;
}

void output(char ch)
{
	if (ch != '\0')
	{
		printf("%c", ch);
	}
}

int priority(char ch)
{
	if (('+' == ch) || ('-' == ch))
	{
		return 1;
	}
	if (('*' == ch) || ('/') == ch)
	{
		return 2;
	}
	return 0;
}
transform(const char* exp)
{
	int i = 0;
	LinkStack* stack = LinkStack_Create();
	while (exp[i] != '\0')
	{
		//�������֣�ֱ�����
		if (isNumber(exp[i]))
		{
			output(exp[i]);
		}
		//���������ţ���ջ 
		else if(isLeft(exp[i]))
		{
			LinkStack_Push(stack, (void*)exp[i]);
		}
		//����������ţ���ջ�����Ž������ȼ��Ƚ�
		else if (isOperator(exp[i]))
		{
			//��ջ���������ȼ��ߣ���ջ�����ŵ����������֮���ջ,
			//��ջ���������ȼ��ͣ�����ֱ�ӽ�ջ  ��Ĭ��ջ�����������ţ����������ȼ���ͣ�
			if (priority(exp[i]) <= priority((char)LinkStack_Top(stack)))
			{
				output((char)LinkStack_Pop(stack));
			}
			LinkStack_Push(stack, (void*)exp[i]);
		}
		//���������ţ���ջ�����ŵ����������ֱ��ƥ��������
		else if (isRight(exp[i]))
		{
			while (!isLeft((char)LinkStack_Top(stack)))
			{
				output((char)LinkStack_Pop(stack));
			}
			//ע����Ҫ�ٵ���ջ��һ��,��Ϊ�������Լ�Ҳ��Ҫ����
			LinkStack_Pop(stack);
		}
		else
		{
			printf("Invalid expression!\n");
			break;
		}
		i++;
	}
	//������������ջ�е����з��ŵ��������
	while ((LinkStack_Size(stack) > 0) && (exp[i]=='\0'))
	{
		output((char)LinkStack_Pop(stack));
	}
	LinkStack_Destroy(stack);
}

int main()
{
	transform("8+(3-1)*5");
	printf("\n");
	transform("6��3*(9-7)-8/2");
	printf("\n");
	transform("(8-2)/(3-1)*(9-6)");
	return 0;
}