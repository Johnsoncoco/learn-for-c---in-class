#include "Strfun.h"
#include <iostream>
using namespace std;

Strfun::Strfun()
{
}
//字符的复制
void Strfun::mystrcopy(char *obj, const char *org)
{
	while ('\0' != *org)
		*obj++ = *org++;
	*obj++ = '\0';
}
//字符串的长度
void Strfun::mystrlen(const char *obj)
{
	const char * ps = obj;
	while ('\0' != *ps)
		ps++;
	cout << obj << "的长度为" << ps - obj;
}
//字符的连接
void Strfun::mystrconnect(char *obj, const char *org)
{
	const char *ps = obj;
	while ('\0' != *obj)
		obj++;
	while ('\0' != *org)
		*obj++ = *org++;
	*obj++ = '\0';
}
//字符的翻转
void Strfun::mystrturn(char *obj)
{
	const char * ps = obj;
	while ('\0' != *ps)
		ps++;
	int n = ps - obj;
	for (int i = 0; i < n; i++)
	for (int j = n - 1; j>i; j--)
	{
		int temp = obj[j - 1];
		obj[j - 1] = obj[j];
		obj[j] = temp;
	}
}
//字符串的比较
int Strfun::mystrcompare(char obj1[], char obj2[])
{
	int i;
	for (i = 0;; i++)
	{
		if (obj1[i]>obj2[i])
		{
			cout << obj1 << ">" << obj2;
			return 1;
		}
		else if (obj1[i]<obj2[i])
		{
			cout << obj1 << "<" << obj2;
			return -1;
		}
		else if (obj1[i] == '\0')
		{
			cout << obj1 << "=" << obj2;
			return 0;
		}
	}
}

Strfun::~Strfun()
{
}
