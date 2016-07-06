#include "P3.h"
#include <iostream>
using namespace std;
P3::P3()
{
	
}
int P3::P3_1()//枚举功能的使用，输出城市代号，输出城市名称
{
	enum city{ Beijing, Shanghai, Tianjin = 6, Chongqing };
	int n;
	cout << "Inut a city number(" << Beijing - 1 << "to exit(退出)):" << endl;
	cin >> n;
	while (n >= Beijing)
	{
		switch (n)
		{
		case Beijing:cout << "Beijing" << endl; break;
		case Shanghai:cout << "Shanghai" << endl; break;
		case Tianjin:cout << "Tianjin" << endl; break;
		case Chongqing:cout << "Chongqing" << endl; break;
		default:cout << "Invaild city number" << endl; break;
		}
		cin >> n;
	}
	return 0;
}
int P3::P3_2()//数组应用——选择排序
{
	const int MaxN = 5;
	int n, a[MaxN], i, j;
	cout << "请输入五个数：" << endl;
	for (n = 0; n < MaxN; n++)
	{
		cin >> a[n];//输入数组元素
		if (a[n] < 0)
			break;
	}
	//对数组元素逐趟进行选择排序
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
	return 0;
}
int P3::P3_3()
//求学生多门功课的总分，并求所有学生各门功课的平均分
{
	const int MaxN = 100, CourseN = 5;
	int n, score[MaxN][CourseN + 1] = { 0 };
	float aver[CourseN + 1] = { 0 };
	cout << "请输入学生成绩（输入-1结束输入）（3*5）：";
	for (n = 0; n < MaxN; n++)
	{
		for (int j = 0; j < CourseN; j++)
		{
			cin >> score[n][j];
		}
		if (score[n][0] < 0)
			break;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < CourseN; j++)
		{
			score[i][CourseN] = score[i][CourseN] + score[i][j];
		}
	}
	for (int j = 0; j < CourseN + 1; j++)
	{
		for (int i = 0; i < n; i++)
		{
			aver[j] = aver[j] + score[i][j];
		}
		aver[j] = aver[j] / n;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < CourseN + 1; j++)
		{
			cout << score[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "---------------------------------------------------" << endl;
	for (int i = 0; i < CourseN + 1; i++)
	{
		cout << aver[i] << "\t";
	}
	cout << endl;
	return 0;
}
const int col = 5;
enum dir{ Asc, Des };
void sort(int a[][col], int n, int Cn, dir D)
{
	int t[col];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][Cn]<a[j][Cn] && D == Des || a[i][Cn]>a[j][Cn] && D == Asc)
			{
				memcpy(t, a[i], sizeof(t));
				memcpy(a[i], a[j], sizeof(t));
				memcpy(a[j], t, sizeof(t));
			}
		}
	}
}
int P3::P3_4()
//利用对一个多维数组的某列排序的函数
{
	const int CourseN = 5;
	int n, score[][CourseN] = { { 20060101, 1, 82, 86, 0 }, { 20060203, 2, 80, 80, 0 },
	{ 20060204, 2, 86, 90, 0 }, { 20060205, 2, 90, 83, 0 }, { 20060102, 1, 75, 86, 0 } };
	n = sizeof(score) / sizeof(score[0]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 2; j < CourseN - 1; j++)
		{
			score[i][CourseN - 1] = score[i][CourseN - 1] + score[i][j];
		}
	}
	sort(score, n, 4, Des);
	sort(score, n, 1, Asc);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < CourseN; j++)
		{
			cout << score[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
const int NameLen = 20;
void order(char name[][NameLen], int n)
{
	char temp[NameLen];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(name[i], name[j])>0)
			{
				strcpy_s(temp, name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j], temp);
			}
		}
	}
}
int find(char name[][NameLen], int n, char searchname[NameLen])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(name[i], searchname) == 0)
		{
			return i + 1;
		}
		else if (strcmp(name[i], searchname)>0)
		{
			return 0;
		}
	}
	return 0;
}
int P3::P3_5()
//字符串的排序与查找
{
	char NameTap[][NameLen] = { "GongJing", "LiuNa", "HuangPin", "ZhouZijun", "LianXiaolei", "ChenHailing", "GuiPeng", "LiuPing" };
	char searchname[NameLen];
	int n = sizeof(NameTap) / NameLen;
	order(NameTap, n);
	for (int i = 0; i < n; i++)
		cout << i + 1 << '\t' << NameTap[i] << endl;
	cout << "Input the searching name:";
	cin >> searchname;
	if (n = find(NameTap, n, searchname))
		cout << "Position:" << n << endl;
	else
		cout << "Not found!" << endl;
	return 0;
}
int P3::P3_6()
//动态二维矩阵
{
	int m, n;
	int **dm;
	cout << "input matrix size m,n:";
	cin >> m >> n;
	dm = new int *[m];
	for (int i = 0; i < m; i++)
	if ((dm[i] = new int[n]) == NULL)
	{
		exit(0);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> dm[i][j];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << dm[i][j] << "\t";
		cout << endl;
	}
	for (int i = 0; i < m; i++)
	{
		delete[]dm[i];
	}
	delete[]dm;
	return 0;
}
int P3::P3_7()
//动态创建多维数组
{
	float(*p)[3][4];
	int i, j, k;
	p = new float[2][3][4];
	for (i = 0; i < 2; i++)
	for (j = 0; j < 3; j++)
	for (k = 0; k < 4; k++)
		*(*(*(p + i) + j) + k) = i * 100 + j * 10 + k;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
				cout << p[i][j][k] << " ";
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
//实现两个数据交换的通用程序
void swap_i(int *num1, int *num2)
{
	int t; t = *num1;
	*num1 = *num2;
	*num2 = t;
}
void swap(void *num1, void *num2, int size)
{
	char * first = (char *)num1, *second = (char *)num2;
	for (int k = 0; k < size; k++)
	{
		char temp;
		temp = first[k];
		first[k] = second[k];
		second[k] = temp;
	}
}
int P3::P3_8()
{
	int a = 3, b = 6;
	double x = 2.3, y = 4.5;
	char c1[8] = "John", c2[8] = "Antony";
	cout << "before swap:a=" << a << "b=" << b << endl;
	swap_i(&a, &b);
	cout << "after swap:a=" << a << "b=" << b << endl;
	cout << "before swap:x=" << x << "y=" << y << endl;
	swap(&x, &y, sizeof(x));
	cout << "after swap:x=" << x << "y=" << y << endl;
	cout << "before swap:c1=" << c1 << "c2=" << c2 << endl;
	swap(&c1, &c2, sizeof(c1));
	cout << "after swap:c1=" << c1 << "c2=" << c2 << endl;
	return 0;
}
//超长整数加法
char * ladd(char * s1, char * s2)
{
	int n1, n2, n;
	char *res, c = 0;
	n1 = strlen(s1);
	n2 = strlen(s2);
	n = n1 > n2 ? n1 : n2;
	res = new char[n + 2];
	for (int i = n + 1; i >= 0; i--)
		res[i] = i > n - n1 ? s1[i - n - 1 + n1] : '0';
	for (int i = n; i >= 0; i--)
	{
		char tchar;
		tchar = i > n - n2 ? s2[i - n + n2 - 1] - '0' + c : res[i] - '0' + c;
		c = tchar > 9 ? 1 : 0;
		res[i] = c > 0 ? tchar - 10 + '0' : tchar + '0';
	}
	return res;
}
int P3::P3_9()
{
	cout << "请输入两个数：";
	char num1[100], num2[100], *num;
	cin >> num1 >> num2;
	num = ladd(num1, num2);
	cout << num1 << "+" << num2 << "=" << num << endl;
	delete[] num;
	return 0;
}
//模拟简单菜单程序
int add1(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a*b;
}
int divi(int a, int b)
{
	if (b == 0)return 0x7fffffff;
	return a / b;
}
int(*menu[])(int a, int b) = { add1, sub, mul, divi };
int P3::P3_10()
{
	int num1, num2, choice;
	cout << "Select operator:" << endl;
	cout << "	1:add" << endl;
	cout << "	2:sub" << endl;
	cout << "	3:multiply" << endl;
	cout << "	4:divide" << endl;
	cin >> choice;
	cout << "Input number(a,b):";
	cin >> num1 >> num2;
	cout << "Result:" << menu[choice - 1](num1, num2) << endl;
	return 0;
}
//使用引用参数实现两个数的交换
void swap2(int &refx, int &refy)
{
	int temp;
	temp = refx; refx = refy; refy = temp;
}
int P3::P3_11()
{
	int x = 3, y = 5;
	cout << "before swap:x=" << x << "y=" << y << endl;
	swap2(x, y);
	cout << "after swap:x=" << x << "y=" << y << endl;
	return 0;
}
//使用引用作为函数的返回值
int max1(int a[], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	if (a[i]>a[t])t = i;
	return a[t] + 0;
}
int& max2(int a[], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	if (a[i]>a[t])t = i;
	return a[t];
}
int& sum(int a[], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		s += a[i];
	return s;
}
int P3::P3_12()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int m1 = max1(a, 10);
	int m2 = max2(a, 10);
	int &m3 = max2(a, 10);
	int &m4 = sum(a, 10);
	cout << "m1=" << m1 << endl;
	cout << "m2=" << m2 << endl;
	cout << "m3=" << m3 << endl;
	cout << "m4=" << m4 << endl;
	m3 += 10;
	max2(a, 10) -= 100;
	cout << sum(a, 10) << endl;
	return 0;
}
//学生成绩的排序，结构数组的应用
struct student
{
	char name[20];
	float score;
};
int input(student s[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> s[i].name >> s[i].score;
		if (s[i].score < 0)break;
	}
	return i;
}
void output(student s[], int n)
{
	for (int i = 0; i < n; i++)
		cout << s[i].name << "\t" << s[i].score << endl;
}
void sort(student a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (a[i].score < a[j].score)
	{
		student t; t = a[i];
		a[i] = a[j]; a[j] = t;
	}
}
int P3::P3_13()
{
	cout << "请输入学生姓名和分数，输入-1结束输入";
	const int MaxNum = 100;
	int num;
	student s[MaxNum];
	num = input(s, MaxNum);
	sort(s, num);
	output(s, num);
	return 0;
}
//单向链表的排序查找插入删除
struct student2
{
	char name[20];
	float score;
	struct student2 *next;
};
typedef student2 NODE;
NODE *Search(NODE *head, int key)
{
	NODE *p;
	p = head;
	while (p->next != NULL)
	{
		if (p->next->score < key)
			return p;
		p = p->next;
	}
	return p;
}
void InsertNode(NODE *p, NODE *newp)
{
	newp->next = p->next;
	p->next = newp;
}
void DelNode(NODE *p)
{
	NODE *q;
	if (p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		delete q;
	}
}
void DelList(NODE *head)
{
	NODE *p;
	p = head;
	while (head->next != NULL)
	{
		head = head->next;
		delete p;
		p = head;
	}
	delete head;
}
void DispList(NODE *head)
{
	NODE *p;
	p = head;
	while (p->next != NULL)
	{
		cout << p->next->name << "\t" << p->next->score << endl;
		p = p->next;
	}
}
int P3::P3_14()
{
	NODE *newp, *head, *p;
	char name[20];
	float score, low = 60;
	if ((newp = new NODE) == NULL)
	{
		cout << "new NODE fail!" << endl;
		exit(0);
	}
	head = newp;
	head->next = NULL;
	cout << "Input name and score(-1 to exit):" << endl;
	cin >> name >> score;
	while (score > 0)
	{
		if ((newp = new NODE) == NULL)
		{
			cout << "new NODE fail!" << endl;
			exit(0);
		}
		strcpy_s(newp->name, name);
		newp->score = score;
		newp->next = NULL;
		p = Search(head, score);
		InsertNode(p, newp);
		cin >> name >> score;
	}
	cout << "Before delete:" << endl;
	DispList(head);
	for (p = Search(head, low); p->next != NULL; p = Search(head, low))
		DelNode(p);
	cout << "After delete:" << endl;
	DispList(head);
	DelList(head);
	return 0;
}
//显示联合体中各类型成员的内存排列
int P3::P3_15()
{
	union UData
	{
		char Ch;
		short Sint;
		long Lint;
		unsigned Uint;
		float f;
		double d;
		char str[10];
	};
	UData u;
	strcpy_s(u.str, "123456789");
	cout << "char:" << '\t' << u.Ch << endl;
	cout << "short:" << '\t' << hex << u.Sint << endl;
	cout << "long:" << '\t' << u.Lint << endl;
	cout << "unsigned:" << '\t' << u.Uint << endl;
	cout << "float:" << '\t' << u.f << endl;
	cout << "double:" << '\t' << u.d << endl;
	cout << "string:" << "\t" << u.str << endl;
	return 0;
}
P3::~P3()
{
}
