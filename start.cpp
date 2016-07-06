#include <iostream>
#include "head.h"
#include "byteturn.h"
#include "MatrixMulti.h"
#include "calendar.h"
#include "Strfun.h"
#include "structlink.h"
#include "P1.h"
#include "P2.h"
#include "P3.h"
#include "P5.h"
#include "P6.h"
#include "P7.h"
#include "homework.h"
using namespace std;
void TestStructFunction();
void main()
{
	TestStructFunction();//利用函数实现链表


	//字节翻转（整型移位运算、用地址翻转、模板翻转）
	byteturn mybyte(123125);
	mybyte.fun1();

	//矩阵的乘法类
	int A2[2][3] = { 1, 2, 3, 4, 5, 6 };
	int A3[3][2] = { 6, 5, 4, 3, 2, 1 };
	int A4[2][2] = { 0, 0 };
	MatrixMulti((int *)A2, 2, 3, (int *)A3, 2, (int *)A4);

	//实现日历类
	calendar mcalendar;
	mcalendar.show();

	//字符串函数（字符串拷贝、字符串连接、字符串比较、字符串翻转、字符串长度）
	char A[20];
	char C[] = "adadfdfa";
	char B[30] = "1255845";
	Strfun mystrfun;
	mystrfun.mystrcopy(A, "abcdef");
	cout << "字符的复制" << A;	cout << endl;
	mystrfun.mystrlen(B);		cout << endl;
	cout << "将" << B << "和" << C << "连接后的结果为";
	mystrfun.mystrconnect(B, C);
	cout << B;	cout << endl;
	cout << C << "翻转后为";
	mystrfun.mystrturn(C);
	cout << C;	cout << endl;
	mystrfun.mystrcompare(A, C);

	//链表的封装
	//从文件中建立链表
	structlink mstructlink("C:\\temp\\score.txt");
	Student *pHeader = mstructlink.GetLinkTableFromFile("C:\\temp\\score.txt");
	//删除链表中名字为 张三 的元素
	mstructlink.DeleteElement(pHeader, "张三");
	mstructlink.OutPutLink(pHeader);//输出链表，检查是否已经删除
	//实现翻转
	mstructlink.inversion(pHeader);
	mstructlink.OutPutLink(pHeader);
	//删除链表中名字为 周星星 的元素
	mstructlink.DeleteElement(pHeader, "周星星");
	mstructlink.OutPutLink(pHeader);//输出链表，检查是否已经删除
	//追加一名新同学
	mstructlink.AddElement(pHeader, "新同学1", 90, 87, 55);
	mstructlink.OutPutLink(pHeader);//输出链表，检查是否已经追加
	//追加一名新同学
	mstructlink.AddElement(pHeader, "新同学2", 89, 87, 55);
	mstructlink.OutPutLink(pHeader);//输出链表，检查是否已经追加
	//排序，根据 名字 进行 降序 排序
	mstructlink.Sort(pHeader, 0, true);
	mstructlink.OutPutLink(pHeader);//输出链表，检查排序是否正确
	//排序，根据 名字 进行 升序 排序
	mstructlink.Sort(pHeader, 0, false);
	mstructlink.OutPutLink(pHeader);//输出链表，检查排序是否正确*/
	//排序，根据 某项成绩 进行 降序 排序
	mstructlink.Sort(pHeader, 2, true);
	mstructlink.OutPutLink(pHeader);//输出链表，检查排序是否正确
	//获得某个元素（李四）的拷贝
	Student aStudent = mstructlink.GetElementByName(pHeader, "李四");
	mstructlink.OutPutLink(pHeader);
	//复制链表
	mstructlink.CopyLink(pHeader);
	mstructlink.OutPutLink(pHeader);
	//清空整个链表
	mstructlink.Clear(pHeader);
	mstructlink.OutPutLink(pHeader);

	//各章例题的类封装
	P1 mP1;mP1.P1_1();mP1.P1_2();mP1.P1_3();

	P2 mP2;mP2.P2_1(); mP2.P2_2(); mP2.P2_3(); mP2.P2_4(); mP2.P2_5(); mP2.P2_6(); mP2.P2_7(); mP2.P2_8(); mP2.P2_9(); mP2.P2_10(); mP2.P2_11(); mP2.P2_12();mP2.P2_13(); mP2.P2_14(); mP2.P2_15(); mP2.P2_16(); mP2.P2_17(); mP2.P2_18(); mP2.P2_19();

	P3 mP3;mP3.P3_1(); mP3.P3_2(); mP3.P3_3(); mP3.P3_4(); mP3.P3_5();mP3.P3_7(); mP3.P3_8(); mP3.P3_9(); mP3.P3_10();mP3.P3_11(); mP3.P3_12();  mP3.P3_13();  mP3.P3_14();  mP3.P3_15();

	P5 mP5;mP5.P5_1_a(); mP5.P5_1_b(); mP5.P5_2();mP5.P5_3(); mP5.P5_4(); mP5.P5_6(); mP5.P5_7(); mP5.P5_8();mP5.P5_9(); mP5.P5_10(); mP5.P5_11(); mP5.P5_12();

	P6 mP6;	mP6.P6_1();	mP6.P6_2();mP6.P6_3();mP6.P6_4();mP6.P6_5();mP6.P6_6();mP6.P6_7();

	P7 mP7;mP7.P7_1();mP7.P7_2();	mP7.P7_3();	mP7.P7_4();	mP7.P7_5();	mP7.P7_6();	mP7.P7_7();	mP7.P7_8();	mP7.P7_9();mP7.P7_10();
	
	//平时作业
	homework mhomework;
	mhomework.NYear(); mhomework.Pyramid(); mhomework.PAIXU(); 

}
void TestStructFunction(){


	//请根据你机器的实际情况，修改以下文件的路径名

	/****************************************************************************
	请将老师给定的文本文件： socre.txt 拷贝到 C盘的temp目录下。否则文件打开失败
	******************************************************************************/

	const char * pFilefullPathName = "C:\\temp\\score.txt";//存储成绩的文件名

	//从文件中建立链表
	Student1 *
		pHeader = GetLinkTableFromFile(pFilefullPathName);

	//输出链表
	OutPutLink(pHeader);

	//删除链表中名字为 张三 的元素
	DeleteElement(pHeader, "张三");
	OutPutLink(pHeader);//输出链表，检查是否已经删除

	//删除链表中名字为 周星星 的元素
	DeleteElement(pHeader, "周星星");
	OutPutLink(pHeader);//输出链表，检查是否已经删除

	//追加一名新同学
	AddElement(pHeader, "新同学1", 90, 87, 55);
	OutPutLink(pHeader);//输出链表，检查是否已经追加

	//追加一名新同学
	AddElement(pHeader, "新同学2", 89, 87, 55);
	OutPutLink(pHeader);//输出链表，检查是否已经追加

	//排序，根据 名字 进行 降序 排序
	Sort(pHeader, 0, true);
	OutPutLink(pHeader);//输出链表，检查排序是否正确

	//排序，根据 名字 进行 升序 排序
	Sort(pHeader, 0, false);
	OutPutLink(pHeader);//输出链表，检查排序是否正确

	//排序，根据 某项成绩 进行 降序 排序
	Sort(pHeader, 2, true);
	OutPutLink(pHeader);//输出链表，检查排序是否正确



	inversion(pHeader);
	OutPutLink(pHeader);
	//获得某个元素（李四）的拷贝
	Student1 aStudent = GetElementByName(pHeader, "李四");
	OutPutLink(pHeader);

	CopyLink(pHeader);
	OutPutLink(pHeader);

	//清空整个链表
	Clear(pHeader);
	OutPutLink(pHeader);

}