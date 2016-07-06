#include <iostream>
#include <fstream>
#include "head.h"
using namespace std;

/************************************************************************/
/*���ļ��ж�ȡ���ݣ��γ����������������Ѿ���ɣ�         */
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
	cout << "\n_________���������_______________\n";
	return pHeader;
}

/************************************************************************/
/*����������ݣ��Ա����������Ƿ���ȷ     �����Ѿ����                                                                 */
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
/*����ָ�������֣���������ɾ��Ԫ��
/*pName ѧ������  pHeader ����ͷָ��-------------�Ѿ����
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
	/*�ַ��ȽϺ���
	int n = strcmp(pName,"***");
	��� n == 0 ��ʾ���ַ����
	n> 0 ��ʾpName > "***"
	n < 0 ��ʾpName > "***"

	ע�⣺ ���������Ƚ�
	if(pName > "***")//�����Ƚ����ַ������׵�ַ�Ƚϣ������ַ����Ƚ�
	*/

}

/************************************************************************/
/*    ��������
pHeader ����ͷָ��
nFlag 0 ��ʾ�����֣�����1 2 3 ��ʾ���ɼ�����
bDec Ϊ false ��ʾ����true ��ʾ����
����������������Ҫ��ȥ��ɵĺ��� */
/************************************************************************/
void Sort(Student1 * pHeader, int nFlag, bool bDec)
{
	//����Ҫʵ�ִ˺���
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
				i = i;//����
			}
			else{ i = !i; }//����
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
/*׷��ĳ��ѧ����������
pName ѧ������
nScore1, nScore2, nScore3 ���ſγ̵ĳɼ�
Ҫ��׷�ӵ��ȸ�ѧ����pName���ɼ��õ�ѧ���ĺ���
����������������Ҫ��ȥ��ɵĺ��� */
/************************************************************************/

void AddElement(Student1 * pHeader, const char *pName, int nScore1, int nScore2, int nScore3)
{
	//����Ҫʵ�ִ˺���
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
/*�������л��ĳ��ѧ���Ŀ���                                            */
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

void inversion(Student1 *pHeader)//ʵ�ַ�ת
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
/*������� DELETE,�Ա�����˳���ʱ�򲻳�������й©
����������������Ҫ��ȥ��ɵĺ��� */
/************************************************************************/
void Clear(Student1 * pHeader)
{
	//����Ҫʵ�ִ˺���
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
/* ���ݸ���������������һ��������ȫһ����������                       */
/************************************************************************/
Student1 * CopyLink(Student1 * pHeader)
{
	//����Ҫʵ�ִ˺���
	Student1 *newst = new Student1;
	newst->next = pHeader->next;
	return newst;
}
