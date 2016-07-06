#include "homework.h"
#include <iostream>
using namespace std;

homework::homework()
{
}
int homework::NYear()
{
	int nyear;
	cout << "请输入一个年份：";
	cin >> nyear;
	cout << '\n';
	cout << "从公元0年开始到" << nyear << "年，所有的闰年年份有：";
	for (int i = 0; i <= nyear; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
		{
			cout << i << "年" << " ";
		}
	}
	cout << endl;
	return 0;
}
/*构建一个函数来输出金字塔*/
int homework::Pyramid()
{
	{
		int n;
		cout << "请输入你希望的金字塔高度：";
		cin >> n;
		/*输出第一种金字塔*/
		cout << '\n' << "第一种金字塔：" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2 * i + 1; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		/*输出第二种金字塔*/
		cout << '\n' << "第二种金字塔：" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2 * (n - (i + 1)) + 1; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		/*输出第三种金字塔*/
		cout << '\n' << "第三种金字塔：" << endl;
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
		/*输出第四种金字塔*/
		cout << '\n' << "第四种金字塔：" << endl;
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
	cout << "请输入10个数";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	//冒泡排序法
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
	cout << "十个数按从大到小排列";
	for (int j = 0; j < N; j++)
	{
		cout << A[j] << " ";
	}
	cout << endl;
	//另一种交换方法
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
