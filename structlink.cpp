#include "structlink.h"
#include <iostream>
#include <fstream>
using namespace std;

structlink::structlink(const char * pFilefullPathName)
{
	//请根据你机器的实际情况，修改以下文件的路径名
	/****************************************************************************
	请将老师给定的文本文件： socre.txt 拷贝到 C盘的temp目录下。否则文件打开失败
	******************************************************************************/
	//从文件中建立链表
		Student *pHeader = GetLinkTableFromFile(pFilefullPathName);
	OutPutLink(pHeader);
}

/************************************************************************/
/*从文件中读取数据，形成链表——————已经完成，         */
/************************************************************************/
Student  * structlink::GetLinkTableFromFile(const char * pFileFullPathName)
{
	Student * pHeader = new Student;
	pHeader->next = NULL;
	//OpenFile
	ifstream in;
	in.open(pFileFullPathName);
	if (!in.is_open()) return pHeader;
	Student *pTemp = pHeader;
	while (in.good())
	{
		pTemp->next = new Student;
		pTemp = pTemp->next;
		pTemp->next = NULL;
		in >> pTemp->sName >> pTemp->nScores[0] >> pTemp->nScores[1]
			>> pTemp->nScores[2];

		cout << pTemp->sName << "   " << pTemp->nScores[0] << "   " << pTemp->nScores[1] << "   " << pTemp->nScores[2] << endl;
	}
	cout << "\n_________链表构建完毕_______________\n";
	return pHeader;
}
/************************************************************************/
/*输出链表内容，以便检查链表结果是否正确     ——已经完成                                                                 */
/************************************************************************/
void structlink:: OutPutLink(Student * pHeader)
{
	pHeader = pHeader->next;
	while (pHeader != NULL)
	{

		cout << pHeader->sName << "   " << pHeader->nScores[0] << "   " << pHeader->nScores[1] << "   " << pHeader->nScores[2] << endl;
		pHeader = pHeader->next;
	}
	cout << "\n________________________\n";
}
/*根据指定的名字，从链表中删除元素
/*pName 学生名字  pHeader 链表头指针-------------已经完成
/************************************************************************/
void structlink::DeleteElement(Student * pHeader, const char * pName)
{
	cout << "删除元素"<<endl;
	if (pHeader->next == NULL)return;
	while (pHeader->next != NULL)
	{
		//if(pHeader->next->sName == pName)
		//if(pHeader->next->sName == pName)
		int nC = strcmp(pHeader->next->sName, pName);
		if (0 == nC)
		{
			Student *pTT = pHeader->next;
			pHeader->next = pTT->next;
			delete pTT;

		}
		else
		{
			pHeader = pHeader->next;

		}

	}
	/*字符比较函数
	int n = strcmp(pName,"***");
	如果 n == 0 表示两字符相等
	n> 0 表示pName > "***"
	n < 0 表示pName > "***"

	注意： 不能这样比较
	if(pName > "***")//这样比较是字符串的首地址比较，不是字符串比较
	*/

}
/*    链表排序
pHeader 链表头指针
nFlag 0 表示按名字，排序，1 2 3 表示按成绩排序
bDec 为 false 表示升序，true 表示降序
———————需要您去完成的函数 */
/************************************************************************/
void structlink::Sort(Student * pHeader, int nFlag, bool bDec)
{
	cout << "链表排序" << endl;
	//您需要实现此函数
	Student *ptemp1 = pHeader, *ptemp = pHeader;
	Student *ptemp2 = pHeader->next;
	Student *ptemp3 = pHeader->next->next;
	while (NULL != ptemp3)
	{
		while (NULL != ptemp3)
		{
			int i;
			switch (nFlag)
			{
			case 0:i = (ptemp2->sName[nFlag] < ptemp3->sName[nFlag]) ? 1 : 0; break;
			default:i = (ptemp2->nScores[nFlag - 1] < ptemp3->nScores[nFlag - 1]) ? 1 : 0;
			}
			if (bDec)
			{
				i = i;//降序
			}
			else{ i = !i; }//升序
			if (i)
			{
				ptemp2->next = ptemp2->next->next;
				ptemp3->next = ptemp2;
				ptemp1->next = ptemp3;
				ptemp1 = ptemp1->next;
			}
			else
			{
				ptemp1 = ptemp1->next;
			}
			ptemp2 = ptemp1->next;
			ptemp3 = ptemp2->next;
		}
		ptemp = ptemp->next;
		ptemp1 = ptemp;
		ptemp2 = ptemp1->next;
		ptemp3 = ptemp2->next;
	}
}
/*追加某个学生到链表中
pName 学生名字
nScore1, nScore2, nScore3 三门课程的成绩
要求：追加到比该学生（pName）成绩好的学生的后面
———————需要您去完成的函数 */
/************************************************************************/
void structlink::AddElement(Student * pHeader, const char *pName, int nScore1, int nScore2, int nScore3)
{
	cout << "追加元素" << endl;
	//您需要实现此函数
	Student *ptemp = pHeader;
	Student * add = new Student;
	strcpy_s(add->sName, pName);
	add->nScores[0] = nScore1;
	add->nScores[1] = nScore2;
	add->nScores[2] = nScore3;
	while (NULL != ptemp->next)
	{
		if (ptemp->next->nScores[0] > add->nScores[0])
		{
			ptemp = ptemp->next; continue;
		}
		else
		{
			add->next = ptemp->next;
			ptemp->next = add;
			break;
		}
	}
}
/************************************************************************/
/*从链表中获得某个学生的拷贝                                            */
/************************************************************************/
Student structlink::GetElementByName(Student * pHeader, const char *pName)
{
	cout << "元素拷贝" << endl;
	if (pHeader->next == NULL)return *pHeader;
	while (pHeader->next != NULL)
	{
		int nC = strcmp(pHeader->next->sName, pName);
		if (0 != nC)
		{
			Student *pTT = pHeader->next;
			pHeader->next = pTT->next;
			delete pTT;
		}
		else break;
	}
	pHeader->next->next = NULL;
	return *pHeader;
}
/*清空链表 DELETE,以便程序退出的时候不出现内容泄漏
———————需要您去完成的函数 */
/************************************************************************/
void structlink::Clear(Student * pHeader)
{
	cout << "清空链表" << endl;
	//您需要实现此函数
	Student *ptemp = pHeader;
	Student *p = pHeader;
	while (pHeader->next != NULL)
	{
		pHeader = pHeader->next;
		delete p;
		p = pHeader;
	}
	delete p;
	pHeader = ptemp;
	pHeader->next = NULL;
}
/************************************************************************/
/* 根据给定的链表，拷贝出一个内容完全一样的新链表                       */
/************************************************************************/
Student * structlink::CopyLink(Student * pHeader)
{
	cout << "拷贝链表" << endl;
	//您需要实现此函数
	Student *newst = new Student;
	newst->next = pHeader->next;
	return newst;
}
//实现翻转
void structlink::inversion(Student *pHeader)
{
	cout << "翻转链表" << endl;
	Student *ptemp = pHeader->next;
	Student *ptemp1 = pHeader->next;
	while (ptemp1->next != NULL)
	{
		Student *ptemp2 = ptemp1->next;
		Student *ptemp3 = ptemp2->next;
		ptemp2->next = ptemp; pHeader->next = ptemp2; ptemp1->next = ptemp3;
		ptemp = ptemp2;
	}
}
structlink::~structlink()
{
}
