#define _CRT_SECURE_NO_WARNINGS
#include "P5.h"
#include <iostream>
using namespace std;
#include <cstring>
P5::P5()
{
}
//面向过程的时钟程序
struct Clock{
	int H, M, S;
};
Clock MyClock;
void SetTime(int H, int M, int S)
{
	MyClock.H = (H >= 0 && H < 24) ? H : 0;
	MyClock.M = (M >= 0 && M < 60) ? M : 0;
	MyClock.S = (S >= 0 && S < 60) ? S : 0;
}
void ShowTime()
{
	cout << MyClock.H << ":";
	cout << MyClock.M << ":";
	cout << MyClock.S << endl;
}
int P5::P5_1_a()
{
	ShowTime();
	SetTime(8, 30, 30);
	ShowTime();
	return 0;
}
class CClock{
private:
	int H, M, S;
public:
	void SetTime(int h, int m, int s)
	{
		H = (h >= 0 && h < 24) ? h : 0;
		M = (m >= 0 && m < 60) ? m : 0;
		S = (s >= 0 && s < 60) ? s : 0;
	}
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
};
int P5::P5_1_b()
{
	CClock MyClock;
	MyClock.ShowTime();
	MyClock.SetTime(8, 30, 30);
	MyClock.ShowTime();
	return 0;
}
//构造函数和析构函数
class CClock2
{
private:
	int H, M, S;
public:
	CClock2(int h = 0, int m = 0, int s = 0)
	{
		H = h, M = m, S = s;
		cout << "constructor:" << H << ":" << M << ":" << S << endl;
	}
	~CClock2()
	{
		cout << "constructor:" << H << ":" << M << ":" << S << endl;
	}
};
int P5::P5_2()
{
	CClock2 C3(10, 0, 0);
	CClock2 C4(11, 0, 0);
	return 0;
}
//基本的字符串类 
class CString
{
private:
	char *Str;
	int len;
public:
	void ShowStr()
	{
		cout << "string:" << Str << ",length:" << len << endl;
	}
	CString()
	{
		len = 0; Str = NULL;
	}
	CString(char *p)
	{
		len = strlen(p);
		Str = new char[len + 1];
		strcpy(Str, p);
	}
	~CString()
	{
		if (Str != NULL)
		{
			delete[]Str;
			Str = NULL;
		}
	}
};
int P5::P5_3()
{
	char s[] = "ABCDE";
	CString s1(s);
	CString s2("123456");
	s1.ShowStr();
	s2.ShowStr();
	return 0;
}
//构造拷贝构造函数
class CClock4
{
private:
	int H, M, S;
public:
	CClock4(int h = 0, int m = 0, int s = 0)
	{
		H = h, M = m, S = s;
		cout << "constructor:" << H << ":" << M << ":" << S << endl;
	}
	~CClock4()
	{
		cout << "destructor:" << H << ":" << M << ":" << S << endl;
	}
	CClock4(CClock4 &p)
	{
		cout << "copy constructor,before call:" << H << ":" << M << ":" << S << endl;
	}
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
};
CClock4 fun(CClock4 C)
{
	return C;
}
int P5::P5_4()
{
	CClock4 C1(8, 0, 0);
	CClock4 C2(9, 0, 0);
	CClock4 C3(C2);
	fun(C2);
	CClock4 C4;
	C4 = C2;
	return 0;
}
//带时间加法的时钟类
class CClock6{
private:
	int H, M, S;
public:
	void SetTime(int h, int m, int s)
	{
		H = h, M = m, S = s;
	}
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
	CClock6(int h = 0, int m = 0, int s = 0)
	{
		H = h, M = m, S = s;
	}
	CClock6(CClock6 &p)
	{
		H = p.H, M = p.M, S = p.S;
	}
	void TimeAdd(CClock6 *Cp);
	void TimeAdd(int h, int m, int s);
	void TimeAdd(int s);
};
void CClock6::TimeAdd(CClock6 *Cp)
{
	H = (Cp->H + H + (Cp->M + M + (Cp->S + S) / 60) / 60) % 24;
	M = (Cp->M + M + (Cp->S + S) / 60) % 60;
	S = (Cp->S + S) % 60;
}
void CClock6::TimeAdd(int h, int m, int s)
{
	H = (h + H + (m + M + (s + S) / 60) / 60) % 24;
	M = (m + M + (s + S) / 60) % 60;
	S = (s + S) % 60;
}
void CClock6::TimeAdd(int s)
{
	H = (H + (M + (s + S) / 60) / 60) % 24;
	M = (M + (s + S) / 60) % 60;
	S = (s + S) % 60;
}
int P5::P5_6()
{
	CClock6 C1;
	CClock6 C2(8, 20, 20);
	C1.TimeAdd(4000);
	C1.ShowTime();
	C2.TimeAdd(&C1);
	C2.ShowTime();
	return 0;
}
//求一个班学生某门课的总评成绩
const int MaxN = 100;
const double Rate = 0.6;
class CScore
{
private:
	long No;
	char *Name;
	int Peace;
	int Final;
	int Total;
public:
	CScore(long = 0, char * = NULL, int = 0, int = 0, int = 0);
	void Count();
	void ShowScore();
};
CScore::CScore(long no, char *name, int peace, int final, int total)
{
	No = no;
	Name = name;
	Peace = peace;
	Final = final;
	Total = total;
}
void CScore::Count()
{
	Total = Peace*Rate + Final*(1 - Rate) + 0.5;
}
void CScore::ShowScore()
{
	cout << No << "\t" << Name << "\t" << Peace << "\t" << Final << "\t" << Total << endl;
}
int P5::P5_7()
{
	CScore ClassScore1[3];
	CScore ClassScore2[3] = { CScore(200607001, "LiuNa", 80, 79), CScore(200607002, "CuiPeng", 90, 85),
		CScore(200607003, "ZhouJun", 70, 55) };
	for (int i = 0; i < 3; i++)
		ClassScore2[i].Count();
	for (int i = 0; i < 3; i++)
		ClassScore2[i].ShowScore();
	return 0;
}
//计算火车旅途时间的组合类
class CClock8{
private:
	int H, M, S;
public:
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
	void SetTime(int H = 0, int M = 0, int S = 0)
	{
		this->H = H; this->M = M; this->S = S;
	}
	CClock8(int H = 0, int M = 0, int S = 0)
	{
		this->H = H; this->M = M; this->S = S;
	}
	int GetH()
	{
		return H;
	}
	int GetM()
	{
		return M;
	}
	int GetS()
	{
		return S;
	}
};
class TrainTrip
{
private:
	char*TrainNo;//车次
	CClock8 StartTime;//出发时间
	CClock8 EndTime;//到达时间
public:
	TrainTrip(char*TrainNo, CClock8 S, CClock8 E)
	{
		this->TrainNo = TrainNo;
		this->StartTime = S;
		this->EndTime = E;
	}
	CClock8 TripTime()
	{
		int tH, tM, tS;
		int carry = 0;
		CClock8 tTime;
		(tS = EndTime.GetS() - StartTime.GetS()) > 0 ? carry = 0 : tS += 60, carry = 1;
		(tM = EndTime.GetM() - StartTime.GetM()) > 0 ? carry = 0 : tM += 60, carry = 1;
		(tH = EndTime.GetH() - StartTime.GetH() - carry) > 0 ? carry = 0 : tH += 24;
		tTime.SetTime(tH, tM, tS);
		return tTime;
	}
};
int P5::P5_8()
{
	CClock8 C1(8, 10, 10), C2(6, 1, 2);
	CClock8 C3;
	TrainTrip T1("K16", C1, C2);
	C3 = T1.TripTime();
	C3.ShowTime();
	return 0;
}
//含有对象计数器的学生类
class CStudent
{
private:
	char *Name;
	int No;
	static int counts;
public:
	static int GetCount()
	{
		return counts;
	}
	CStudent(char* = "", int = 0);
	CStudent(CStudent &);
	~CStudent();
};
CStudent::CStudent(char * Name, int No)
{
	this->Name = new char[strlen(Name) + 1];
	strcpy(this->Name, Name);
	this->No = No;
	++counts;
	cout << "constructing:" << Name << endl;
}
CStudent::CStudent(CStudent &r)
{
	Name = new char[strlen(r.Name) + 1];
	strcpy(Name, r.Name);
	No = r.No;
	++counts;
	cout << "copy constructing:" << r.Name << endl;
}
CStudent::~CStudent()
{
	cout << "destructing :" << Name << endl;
	delete[]Name;
	--counts;
}
int CStudent::counts = 0;
int P5::P5_9()
{
	cout << CStudent::GetCount() << endl;
	CStudent s1("Antony");
	cout << s1.GetCount() << endl;
	CStudent s2(s1);
	//cout << s1.GetCount() << endl;
	CStudent S3[2];
	cout << CStudent::GetCount() << endl;
	CStudent *s4 = new CStudent[3];
	cout << CStudent::GetCount() << endl;
	delete[]s4;
	cout << CStudent::GetCount() << endl;
	return 0;
}
//计算火车旅途时间的有元函数
class CClock9
{
private:
	int H, M, S;
public:
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
	void SetTime(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M, this->S = S;
	}
	CClock9(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M, this->S = S;
	}
	friend CClock9 TripTime(CClock9 &StartTime, CClock9 & EndTime);
};
CClock9 TripTime(CClock9 &StartTime, CClock9 & EndTime)
{
	int tH, tM, tS;
	int carry = 0; CClock9 tTime;
	(tS = EndTime.S - StartTime.S) > 0 ? carry = 0 : tS += 60, carry = 1;
	(tM = EndTime.M - StartTime.M - carry) > 0 ? carry = 0 : tM += 60, carry = 1;
	(tH = EndTime.H - StartTime.H - carry) > 0 ? carry = 0 : tH += 24;
	tTime.SetTime(tH, tM, tS);
	return tTime;
}
int P5::P5_10()
{
	CClock9 C1(8, 10, 10), C2(6, 1, 2);
	CClock9 C3;
	C3 = TripTime(C1, C2);
	C3.ShowTime();
	return 0;
}
//计算火车旅途时间的有元类
class CClock11
{
private:
	int H, M, S;
public:
	void ShowTime()
	{
		cout << H << ":" << M << ":" << S << endl;
	}
	void SetTime(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M, this->S = S;
	}
	CClock11(int H = 0, int M = 0, int S = 0)
	{
		this->H = H, this->M = M, this->S = S;
	}
	friend class TrainTrip11;
};
class TrainTrip11
{
private:
	char*TrainNo;//车次
	CClock11 StartTime;//出发时间
	CClock11 EndTime;//到达时间
public:
	TrainTrip11(char *TrainNo, CClock11 S, CClock11 E)
	{
		this->TrainNo = TrainNo;
		this->StartTime = S;
		this->EndTime = E;
	}
	CClock11 TripTime11()
	{
		int tH, tM, tS;
		int carry = 0;
		CClock11 tTime;
		(tS = EndTime.S - StartTime.S) > 0 ? carry = 0 : tS += 60, carry = 1;
		(tM = EndTime.M - StartTime.M - carry) > 0 ? carry = 0 : tM += 60, carry = 1;
		(tH = EndTime.H - StartTime.H - carry) > 0 ? carry = 0 : tH += 24;
		tTime.SetTime(tH, tM, tS);
		return tTime;
	}
};
int P5::P5_11()
{
	CClock11 C1(8, 10, 10), C2(6, 1, 2);
	CClock11 C3;
	TrainTrip11 T1("K16", C1, C2);
	C3 = T1.TripTime11();
	C3.ShowTime();
	return 0;
}
//演示常数据成员的使用
class CA{
private:
	const int &r;//常引用数据成员
	const int a; //常数据成员
	static const int b;//静态常数据成员
public:
	CA(int i) :a(i), r(a)//常数据成员只能通过初始化列表获得初值
	{
		cout << "constructor!" << endl;
	}
	void display()
	{
		cout << a << "," << b << "," << r << endl;
	}
};
const int CA::b = 3;//静态常数据成员在类外说明和初始化
int P5::P5_12()
{
	CA a1(1);
	a1.display();
	CA a2(2);
	a2.display();
	return 0;
}
P5::~P5()
{
}
