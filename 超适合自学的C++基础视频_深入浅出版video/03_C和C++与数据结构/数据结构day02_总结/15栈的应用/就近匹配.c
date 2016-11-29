///*
//算法思路
//从第一个字符开始扫描
//当遇见普通字符时忽略，当遇见左符号时压入栈中
//当遇见右符号时从栈中弹出栈顶符号，并进行匹配
//匹配成功：继续读入下一个字符
//匹配失败：立即停止，并报错
//结束：
//成功: 所有字符扫描完毕，且栈为空
//失败：匹配失败或所有字符扫描完毕但栈非空
//*/
//
//#include "LinkStack.h"
//#include <stdlib.h>
//#include <stdio.h>
//
//int  isLeft(char ch)
//{
//	int ret = 0;
//	switch (ch)
//	{
//	case '<':
//	case '(':
//	case '[':
//	case '{':
//	case '\'':
//	case '\"':
//		ret = 1;
//		break;
//	default:
//		ret = 0;
//		break;
//	}
//	return ret;
//}
//
//int isRight(char ch)
//{
//	int ret = 0;
//	switch (ch)
//	{
//	case '>':
//	case ')':
//	case ']':
//	case '}':
//	case '\'':
//	case '\"':
//		ret = 1;
//		break;
//	default:
//		ret = 0;
//		break;
//	}
//	return ret;
//}
//
//int match(char left ,char  right)
//{
//	int ret = 0;
//	switch (left)
//	{
//	case '<':
//		ret = (right == '>' );
//		break;
//	case '(':
//		ret = (right == ')');
//		break;
//	case '[':
//		ret = (right == ']');
//		break;
//	case '{':
//		ret = (right == '}');
//		break;
//	case '\'':
//		ret = (right == '\'');
//		break;
//	case '\"':
//		ret = (right == "\"");
//		break;
//	default:
//		ret = 0;
//		break;
//	}
//	return ret;
//}
//int scanner(const char* ch)
//{
//	LinkStack* stack = LinkStack_Create();
//	printf("ch:%s\n", ch);
//	int ret = 0, i = 0;
//	while (ch[i] != '\0')
//	{
//		if (isLeft(ch[i]))
//		{
//			//printf("%c\n",ch[i]);
//			LinkStack_Push(stack, ch[i]);
//		}
//		if (isRight(ch[i]))
//		{
//			char* tmp = (char*)LinkStack_Pop(stack);
//			//printf("%c", tmp);
//			if (!match(tmp, ch[i]) || tmp == NULL)
//			{
//				printf("%c does not match !\n", ch[i]);
//				ret = 0;
//				break;
//			}
//		}
//		i++;
//	}
//
//	if (LinkStack_Size(stack) == 0 && ch[i] == '\0')
//	{
//		printf("successed! \n");
//		ret = 1;
//	}
//	else
//	{
//		printf("Invalid failed! \n");
//		ret = 0;
//	}
//	LinkStack_Destroy(stack);
//	return ret;
//}
//
//void main1()
//{
//	const char* code = "#include <stdio.h> int main() { int a[4][4]; int (*p)[4]; p = a[0]; return 0;}";
//	scanner(code);
//	return;
//}