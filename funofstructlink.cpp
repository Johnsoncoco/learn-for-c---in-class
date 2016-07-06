#include <iostream>
#include <fstream>
#include "head.h"
using namespace std;

/************************************************************************/
/*从文件中读取数据，形成链表——————已经完成，         */
/************************************************************************/
Student1 * GetLinkTableFromFile(const char * pFileFullPathName)
{
	Student1 * pHeader = new Student1;
	pHeader->next = NULL;
	//OpenFile
	ifstream in;
	in.open(pFileFullPathName);
	if (!in.is_open()) return pHeader;
	Student1 *pTemp = pHeader;
	while (in.good())
	{
		pTemp->next = new Student1;
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
void OutPutLink(Student1 * pHeader)
{
	pHeader = pHeader->next;
	while (pHeader != NULL)
	{

		cout << pHeader->sName << "   " << pHeader->nScores[0] << "   " << pHeader->nScores[1] << "   " << pHeader->nScores[2] << endl;
		pHeader = pHeader->next;
	}
	cout << "\n________________________\n";
}

/************************************************************************/
/*根据指定的名字，从链表中删除元素
/*pName 学生名字  pHeader 链表头指针-------------已经完成
/************************************************************************/
void DeleteElement(Student1 * pHeader, const char * pName)
{
	if (pHeader->next == NULL)return;
	while (pHeader->next != NULL)
	{
		//if(pHeader->next->sName == pName)
		//if(pHeader->next->sName == pName)
		int nC = strcmp(pHeader->next->sName, pName);
		if (0 == nC)
		{
			Student1 *pTT = pHeader->next;
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

/************************************************************************/
/*    链表排序
pHeader 链表头指针
nFlag 0 表示按名字，排序，1 2 3 表示按成绩排序
bDec 为 false 表示升序，true 表示降序
———————需要您去完成的函数 */
/************************************************************************/
void Sort(Student1 * pHeader, int nFlag, bool bDec)
{
	//您需要实现此函数
	Student1 *ptemp1 = pHeader, *ptemp = pHeader;
	Student1 *ptemp2 = pHeader->next;
	Student1 *ptemp3 = pHeader->next->next;
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


/************************************************************************/
/*追加某个学生到链表中
pName 学生名字
nScore1, nScore2, nScore3 三门课程的成绩
要求：追加到比该学生（pName）成绩好的学生的后面
———————需要您去完成的函数 */
/************************************************************************/

void AddElement(Student1 * pHeader, const char *pName, int nScore1, int nScore2, int nScore3)
{
	//您需要实现此函数
	Student1 *ptemp = pHeader;
	Student1 * add = new Student1;
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
Student1 GetElementByName(Student1 * pHeader, const char *pName)
{
	if (pHeader->next == NULL)return *pHeader;
	while (pHeader->next != NULL)
	{
		int nC = strcmp(pHeader->next->sName, pName);
		if (0 != nC)
		{
			Student1 *pTT = pHeader->next;
			pHeader->next = pTT->next;
			delete pTT;
		}
		else break;
	}
	pHeader->next->next = NULL;
	return *pHeader;
}

void inversion(Student1 *pHeader)//实现翻转
{
	Student1 *ptemp = pHeader->next;
	Student1 *ptemp1 = pHeader->next;
	while (ptemp1->next != NULL)
	{
		Student1 *ptemp2 = ptemp1->next;
		Student1 *ptemp3 = ptemp2->next;
		ptemp2->next = ptemp; pHeader->next = ptemp2; ptemp1->next = ptemp3;
		ptemp = ptemp2;
	}
}

/************************************************************************/
/*清空链表 DELETE,以便程序退出的时候不出现内容泄漏
———————需要您去完成的函数 */
/************************************************************************/
void Clear(Student1 * pHeader)
{
	//您需要实现此函数
	Student1 *ptemp = pHeader;
	Student1 *p = pHeader;
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
Student1 * CopyLink(Student1 * pHeader)
{
	//您需要实现此函数
	Student1 *newst = new Student1;
	newst->next = pHeader->next;
	return newst;
}
