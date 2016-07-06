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
	TestStructFunction();//���ú���ʵ������


	//�ֽڷ�ת��������λ���㡢�õ�ַ��ת��ģ�巭ת��
	byteturn mybyte(123125);
	mybyte.fun1();

	//����ĳ˷���
	int A2[2][3] = { 1, 2, 3, 4, 5, 6 };
	int A3[3][2] = { 6, 5, 4, 3, 2, 1 };
	int A4[2][2] = { 0, 0 };
	MatrixMulti((int *)A2, 2, 3, (int *)A3, 2, (int *)A4);

	//ʵ��������
	calendar mcalendar;
	mcalendar.show();

	//�ַ����������ַ����������ַ������ӡ��ַ����Ƚϡ��ַ�����ת���ַ������ȣ�
	char A[20];
	char C[] = "adadfdfa";
	char B[30] = "1255845";
	Strfun mystrfun;
	mystrfun.mystrcopy(A, "abcdef");
	cout << "�ַ��ĸ���" << A;	cout << endl;
	mystrfun.mystrlen(B);		cout << endl;
	cout << "��" << B << "��" << C << "���Ӻ�Ľ��Ϊ";
	mystrfun.mystrconnect(B, C);
	cout << B;	cout << endl;
	cout << C << "��ת��Ϊ";
	mystrfun.mystrturn(C);
	cout << C;	cout << endl;
	mystrfun.mystrcompare(A, C);

	//����ķ�װ
	//���ļ��н�������
	structlink mstructlink("C:\\temp\\score.txt");
	Student *pHeader = mstructlink.GetLinkTableFromFile("C:\\temp\\score.txt");
	//ɾ������������Ϊ ���� ��Ԫ��
	mstructlink.DeleteElement(pHeader, "����");
	mstructlink.OutPutLink(pHeader);//�����������Ƿ��Ѿ�ɾ��
	//ʵ�ַ�ת
	mstructlink.inversion(pHeader);
	mstructlink.OutPutLink(pHeader);
	//ɾ������������Ϊ ������ ��Ԫ��
	mstructlink.DeleteElement(pHeader, "������");
	mstructlink.OutPutLink(pHeader);//�����������Ƿ��Ѿ�ɾ��
	//׷��һ����ͬѧ
	mstructlink.AddElement(pHeader, "��ͬѧ1", 90, 87, 55);
	mstructlink.OutPutLink(pHeader);//�����������Ƿ��Ѿ�׷��
	//׷��һ����ͬѧ
	mstructlink.AddElement(pHeader, "��ͬѧ2", 89, 87, 55);
	mstructlink.OutPutLink(pHeader);//�����������Ƿ��Ѿ�׷��
	//���򣬸��� ���� ���� ���� ����
	mstructlink.Sort(pHeader, 0, true);
	mstructlink.OutPutLink(pHeader);//���������������Ƿ���ȷ
	//���򣬸��� ���� ���� ���� ����
	mstructlink.Sort(pHeader, 0, false);
	mstructlink.OutPutLink(pHeader);//���������������Ƿ���ȷ*/
	//���򣬸��� ĳ��ɼ� ���� ���� ����
	mstructlink.Sort(pHeader, 2, true);
	mstructlink.OutPutLink(pHeader);//���������������Ƿ���ȷ
	//���ĳ��Ԫ�أ����ģ��Ŀ���
	Student aStudent = mstructlink.GetElementByName(pHeader, "����");
	mstructlink.OutPutLink(pHeader);
	//��������
	mstructlink.CopyLink(pHeader);
	mstructlink.OutPutLink(pHeader);
	//�����������
	mstructlink.Clear(pHeader);
	mstructlink.OutPutLink(pHeader);

	//������������װ
	P1 mP1;mP1.P1_1();mP1.P1_2();mP1.P1_3();

	P2 mP2;mP2.P2_1(); mP2.P2_2(); mP2.P2_3(); mP2.P2_4(); mP2.P2_5(); mP2.P2_6(); mP2.P2_7(); mP2.P2_8(); mP2.P2_9(); mP2.P2_10(); mP2.P2_11(); mP2.P2_12();mP2.P2_13(); mP2.P2_14(); mP2.P2_15(); mP2.P2_16(); mP2.P2_17(); mP2.P2_18(); mP2.P2_19();

	P3 mP3;mP3.P3_1(); mP3.P3_2(); mP3.P3_3(); mP3.P3_4(); mP3.P3_5();mP3.P3_7(); mP3.P3_8(); mP3.P3_9(); mP3.P3_10();mP3.P3_11(); mP3.P3_12();  mP3.P3_13();  mP3.P3_14();  mP3.P3_15();

	P5 mP5;mP5.P5_1_a(); mP5.P5_1_b(); mP5.P5_2();mP5.P5_3(); mP5.P5_4(); mP5.P5_6(); mP5.P5_7(); mP5.P5_8();mP5.P5_9(); mP5.P5_10(); mP5.P5_11(); mP5.P5_12();

	P6 mP6;	mP6.P6_1();	mP6.P6_2();mP6.P6_3();mP6.P6_4();mP6.P6_5();mP6.P6_6();mP6.P6_7();

	P7 mP7;mP7.P7_1();mP7.P7_2();	mP7.P7_3();	mP7.P7_4();	mP7.P7_5();	mP7.P7_6();	mP7.P7_7();	mP7.P7_8();	mP7.P7_9();mP7.P7_10();
	
	//ƽʱ��ҵ
	homework mhomework;
	mhomework.NYear(); mhomework.Pyramid(); mhomework.PAIXU(); 

}
void TestStructFunction(){


	//������������ʵ��������޸������ļ���·����

	/****************************************************************************
	�뽫��ʦ�������ı��ļ��� socre.txt ������ C�̵�tempĿ¼�¡������ļ���ʧ��
	******************************************************************************/

	const char * pFilefullPathName = "C:\\temp\\score.txt";//�洢�ɼ����ļ���

	//���ļ��н�������
	Student1 *
		pHeader = GetLinkTableFromFile(pFilefullPathName);

	//�������
	OutPutLink(pHeader);

	//ɾ������������Ϊ ���� ��Ԫ��
	DeleteElement(pHeader, "����");
	OutPutLink(pHeader);//�����������Ƿ��Ѿ�ɾ��

	//ɾ������������Ϊ ������ ��Ԫ��
	DeleteElement(pHeader, "������");
	OutPutLink(pHeader);//�����������Ƿ��Ѿ�ɾ��

	//׷��һ����ͬѧ
	AddElement(pHeader, "��ͬѧ1", 90, 87, 55);
	OutPutLink(pHeader);//�����������Ƿ��Ѿ�׷��

	//׷��һ����ͬѧ
	AddElement(pHeader, "��ͬѧ2", 89, 87, 55);
	OutPutLink(pHeader);//�����������Ƿ��Ѿ�׷��

	//���򣬸��� ���� ���� ���� ����
	Sort(pHeader, 0, true);
	OutPutLink(pHeader);//���������������Ƿ���ȷ

	//���򣬸��� ���� ���� ���� ����
	Sort(pHeader, 0, false);
	OutPutLink(pHeader);//���������������Ƿ���ȷ

	//���򣬸��� ĳ��ɼ� ���� ���� ����
	Sort(pHeader, 2, true);
	OutPutLink(pHeader);//���������������Ƿ���ȷ



	inversion(pHeader);
	OutPutLink(pHeader);
	//���ĳ��Ԫ�أ����ģ��Ŀ���
	Student1 aStudent = GetElementByName(pHeader, "����");
	OutPutLink(pHeader);

	CopyLink(pHeader);
	OutPutLink(pHeader);

	//�����������
	Clear(pHeader);
	OutPutLink(pHeader);

}