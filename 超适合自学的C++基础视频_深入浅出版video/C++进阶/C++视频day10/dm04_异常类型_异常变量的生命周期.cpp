
#include <iostream>
using namespace std;


//传统的错误处理机制
//throw int类型异常
void my_strcpy1(char *to, char *from)
{
	if (from == NULL)
	{
		throw 1;
	}
	if (to == NULL)
	{
		throw 2;
	}

	//copy是的 场景检查
	if (*from == 'a')
	{
		throw 3; //copy时出错
	}
	while (*from != '\0')
	{
		*to = *from;
		to ++;
		from ++;
	}
	*to = '\0';
}

//传统的错误处理机制
//throw char*类型异常
void my_strcpy2(char *to, char *from)
{
	if (from == NULL)
	{
		throw "源buf出错";
	}
	if (to == NULL)
	{
		throw "目的buf出错";
	}

	//copy是的 场景检查
	if (*from == 'a')
	{
		throw "copy过程出错"; //copy时出错
	}
	while (*from != '\0')
	{
		*to = *from;
		to ++;
		from ++;
	}
	*to = '\0';
}


class BadSrcType {};
class BadDestType {};
class BadProcessType
{
public:
	BadProcessType()
	{
		cout << "BadProcessType构造函数do \n";
	}


	BadProcessType(const BadProcessType &obj)
	{
		cout << "BadProcessType copy构造函数do \n";
	}

	~BadProcessType()
	{
		cout << "BadProcessType析构函数do \n";
	}

};


//传统的错误处理机制
//throw 类对象 类型异常
void my_strcpy3(char *to, char *from)
{
	if (from == NULL)
	{
		throw BadSrcType();
	}
	if (to == NULL)
	{
		throw BadDestType();
	}

	//copy是的 场景检查
	if (*from == 'a')
	{
		printf("开始 BadProcessType类型异常 \n");
		throw BadProcessType(); //会不会产生一个匿名对象?
	}

	if (*from == 'b')
	{
		throw &(BadProcessType()); //会不会产生一个匿名对象?
	}

	if (*from == 'c')
	{
		throw new BadProcessType; //会不会产生一个匿名对象?
	}
	while (*from != '\0')
	{
		*to = *from;
		to ++;
		from ++;
	}
	*to = '\0';
}

void main()
{
	int ret = 0;
	char buf1[] = "cbbcdefg";
	char buf2[1024] = {0};

	try
	{
		//my_strcpy1(buf2, buf1);
		//my_strcpy2(buf2, buf1);
		my_strcpy3(buf2, buf1);
	}
	catch (int e) //e可以写 也可以不写
	{
		cout << e << " int类型异常" << endl;
	}
	catch(char *e)
	{
		cout << e << " char* 类型异常" << endl;
	}

	//---
	catch(BadSrcType e)
	{
		cout << " BadSrcType 类型异常" << endl;
	}
	catch(BadDestType e)
	{
		cout << " BadDestType 类型异常" << endl;
	}
	//结论1: 如果 接受异常的时候 使用一个异常变量,则copy构造异常变量.  
	/*
	catch( BadProcessType e) //是把匿名对象copy给e 还是e还是那个匿名对象
	{
		cout << " BadProcessType 类型异常" << endl;
	}
	*/
	//结论2: 使用引用的话 会使用throw时候的那个对象
	//catch( BadProcessType &e) //是把匿名对象copy给e 还是e还是那个匿名对象
	//{
	//	cout << " BadProcessType 类型异常" << endl;
	//}

	//结论3: 指针可以和引用/元素写在一块 但是引用/元素不能写在一块
	catch( BadProcessType *e) //是把匿名对象copy给e 还是e还是那个匿名对象
	{
		cout << " BadProcessType 类型异常" << endl;
		delete e;
	}
	
	//结论4: 类对象时, 使用引用比较合适 

	// --
	catch (...)
	{
		cout << "未知 类型异常" << endl;
	}

	cout<<"hello..."<<endl;
	system("pause");
	return ;
}


//传统的错误处理机制
int my_strcpy(char *to, char *from)
{
	if (from == NULL)
	{
		return 1;
	}
	if (to == NULL)
	{
		return 2;
	}
		
	//copy是的 场景检查
	if (*from == 'a')
	{
		return 3; //copy时出错
	}
	while (*from != '\0')
	{
		*to = *from;
		to ++;
		from ++;
	}
	*to = '\0';

	return 0;
}


void main41()
{
	int ret = 0;
	char buf1[] = "zbcdefg";
	char buf2[1024] = {0};

 	ret = my_strcpy(buf2, buf1);
	if (ret != 0)
	{
		switch(ret)
		{
		case 1:
			printf("源buf出错!\n");
			break;
		case 2:
			printf("目的buf出错!\n");
			break;
		case 3:
			printf("copy过程出错!\n");
			break;
		default:
			printf("未知错误!\n");
			break;
		}
	}
	printf("buf2:%s \n", buf2);
	
	cout<<"hello..."<<endl;
	system("pause");
	return ;
}