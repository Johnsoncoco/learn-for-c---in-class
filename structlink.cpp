#include "structlink.h"
#include <iostream>
#include <fstream>
using namespace std;

structlink::structlink(const char * pFilefullPathName)
{
	//������������ʵ��������޸������ļ���·����
	/****************************************************************************
	�뽫��ʦ�������ı��ļ��� socre.txt ������ C�̵�tempĿ¼�¡������ļ���ʧ��
	******************************************************************************/
	//���ļ��н�������
		Student *pHeader = GetLinkTableFromFile(pFilefullPathName);
	OutPutLink(pHeader);
}

/************************************************************************/
/*���ļ��ж�ȡ���ݣ��γ����������������Ѿ���ɣ�         */
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
	cout << "\n_________���������_______________\n";
	return pHeader;
}
/************************************************************************/
/*����������ݣ��Ա����������Ƿ���ȷ     �����Ѿ����                                                                 */
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
/*����ָ�������֣���������ɾ��Ԫ��
/*pName ѧ������  pHeader ����ͷָ��-------------�Ѿ����
/************************************************************************/
void structlink::DeleteElement(Student * pHeader, const char * pName)
{
	cout << "ɾ��Ԫ��"<<endl;
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
	/*�ַ��ȽϺ���
	int n = strcmp(pName,"***");
	��� n == 0 ��ʾ���ַ����
	n> 0 ��ʾpName > "***"
	n < 0 ��ʾpName > "***"

	ע�⣺ ���������Ƚ�
	if(pName > "***")//�����Ƚ����ַ������׵�ַ�Ƚϣ������ַ����Ƚ�
	*/

}
/*    ��������
pHeader ����ͷָ��
nFlag 0 ��ʾ�����֣�����1 2 3 ��ʾ���ɼ�����
bDec Ϊ false ��ʾ����true ��ʾ����
����������������Ҫ��ȥ��ɵĺ��� */
/************************************************************************/
void structlink::Sort(Student * pHeader, int nFlag, bool bDec)
{
	cout << "��������" << endl;
	//����Ҫʵ�ִ˺���
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
/*׷��ĳ��ѧ����������
pName ѧ������
nScore1, nScore2, nScore3 ���ſγ̵ĳɼ�
Ҫ��׷�ӵ��ȸ�ѧ����pName���ɼ��õ�ѧ���ĺ���
����������������Ҫ��ȥ��ɵĺ��� */
/************************************************************************/
void structlink::AddElement(Student * pHeader, const char *pName, int nScore1, int nScore2, int nScore3)
{
	cout << "׷��Ԫ��" << endl;
	//����Ҫʵ�ִ˺���
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
/*�������л��ĳ��ѧ���Ŀ���                                            */
/************************************************************************/
Student structlink::GetElementByName(Student * pHeader, const char *pName)
{
	cout << "Ԫ�ؿ���" << endl;
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
/*������� DELETE,�Ա�����˳���ʱ�򲻳�������й©
����������������Ҫ��ȥ��ɵĺ��� */
/************************************************************************/
void structlink::Clear(Student * pHeader)
{
	cout << "�������" << endl;
	//����Ҫʵ�ִ˺���
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
/* ���ݸ���������������һ��������ȫһ����������                       */
/************************************************************************/
Student * structlink::CopyLink(Student * pHeader)
{
	cout << "��������" << endl;
	//����Ҫʵ�ִ˺���
	Student *newst = new Student;
	newst->next = pHeader->next;
	return newst;
}
//ʵ�ַ�ת
void structlink::inversion(Student *pHeader)
{
	cout << "��ת����" << endl;
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
