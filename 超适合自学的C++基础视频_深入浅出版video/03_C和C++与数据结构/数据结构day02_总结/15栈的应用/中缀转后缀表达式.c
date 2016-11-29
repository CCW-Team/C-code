/*
中缀转后缀算法：
   遍历中缀表达式中的数字和符号
   对于数字：直接输出
   对于符号：
   左括号：进栈
   运算符号：与栈顶符号进行优先级比较
   若栈顶符号优先级低：此符合进栈  （默认栈顶若是左括号，左括号优先级最低）
   若栈顶符号优先级不低：将栈顶符号弹出并输出，之后进栈
   右括号：将栈顶符号弹出并输出，直到匹配左括号
   遍历结束：将栈中的所有符号弹出并输出
   中缀转后缀
*/


// http://blog.csdn.net/qwq1503/article/details/52677673
//网上代码
/*
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 512

int top = -1;
int stack[512];

void Push(int e) {
	if (top >= MAXSIZE) {
		puts("栈已满");
		exit(1);
	}
	stack[++top] = e;

}
int isEmpty() {
	return top == -1 ? 1 : 0;
}
int Pop() {
	if (top == -1) {
		puts("这是一个空栈。");
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
	// 1 先出栈， 再进栈
	// 0 直接进栈
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
		// 数字
		if (p[i] >= '0' && p[i] <= '9')
			str[j++] = p[i];
		// 字符
		else {
			op1 = getTop();
			op2 = p[i];
			if (isEmpty())
				Push(op2);
			// 非空
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
	puts("输入运算表达式：");
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
		//对于数字：直接输出
		if (isNumber(exp[i]))
		{
			output(exp[i]);
		}
		//对于左括号：进栈 
		else if(isLeft(exp[i]))
		{
			LinkStack_Push(stack, (void*)exp[i]);
		}
		//对于运算符号：与栈顶符号进行优先级比较
		else if (isOperator(exp[i]))
		{
			//若栈顶符号优先级高：将栈顶符号弹出并输出，之后进栈,
			//若栈顶符号优先级低：符合直接进栈  （默认栈顶若是左括号，左括号优先级最低）
			if (priority(exp[i]) <= priority((char)LinkStack_Top(stack)))
			{
				output((char)LinkStack_Pop(stack));
			}
			LinkStack_Push(stack, (void*)exp[i]);
		}
		//对于右括号：将栈顶符号弹出并输出，直到匹配左括号
		else if (isRight(exp[i]))
		{
			while (!isLeft((char)LinkStack_Top(stack)))
			{
				output((char)LinkStack_Pop(stack));
			}
			//注意需要再弹出栈顶一次,因为左括号自己也需要弹出
			LinkStack_Pop(stack);
		}
		else
		{
			printf("Invalid expression!\n");
			break;
		}
		i++;
	}
	//遍历结束：将栈中的所有符号弹出并输出
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
	transform("6＋3*(9-7)-8/2");
	printf("\n");
	transform("(8-2)/(3-1)*(9-6)");
	return 0;
}