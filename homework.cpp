#include "homework.h"
#include <iostream>
using namespace std;

homework::homework()
{
}
int homework::NYear()
{
	int nyear;
	cout << "������һ����ݣ�";
	cin >> nyear;
	cout << '\n';
	cout << "�ӹ�Ԫ0�꿪ʼ��" << nyear << "�꣬���е���������У�";
	for (int i = 0; i <= nyear; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
		{
			cout << i << "��" << " ";
		}
	}
	cout << endl;
	return 0;
}
/*����һ�����������������*/
int homework::Pyramid()
{
	{
		int n;
		cout << "��������ϣ���Ľ������߶ȣ�";
		cin >> n;
		/*�����һ�ֽ�����*/
		cout << '\n' << "��һ�ֽ�������" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2 * i + 1; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		/*����ڶ��ֽ�����*/
		cout << '\n' << "�ڶ��ֽ�������" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2 * (n - (i + 1)) + 1; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		/*��������ֽ�����*/
		cout << '\n' << "�����ֽ�������" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int z = 0; z < 2 * (n - (i + 1)); z++)
			{
				cout << " ";
			}
			for (int j = 0; j < 2 * i + 1; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		/*��������ֽ�����*/
		cout << '\n' << "�����ֽ�������" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int z = 0; z < i; z++)
			{
				cout << " ";
			}
			for (int j = 0; j < 2 * (n - (i + 1)) + 1; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		return 0;
	}
}
int homework::PAIXU()
{
	const int N = 10;
	int A[N];
	cout << "������10����";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	//ð������
	for (int k = 0; k < N - 1; k++)
	{
		for (int i = N - 1; i > k; i--)
		{
			if (A[i] > A[i - 1])
			{
				int temp = A[i - 1];
				A[i - 1] = A[i];
				A[i] = temp;
			}
		}
	}
	cout << "ʮ�������Ӵ�С����";
	for (int j = 0; j < N; j++)
	{
		cout << A[j] << " ";
	}
	cout << endl;
	//��һ�ֽ�������
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (A[i] < A[j])
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	for (int j = 0; j < N; j++)
	{
		cout << A[j] << " ";
	}
	cout << endl;
	return 0;
}

homework::~homework()
{
}
