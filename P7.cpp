#define _CRT_SECURE_NO_WARNINGS
#include "P7.h"
#include <iostream>
//using namespace std;
using std::cout;
using std::endl;

P7::P7()
{
}

class Complex
{
private:
	double real;
	double image;
public:
	Complex(double real = 0.0,double image = 0.0)
	{
		this->real = real; this->image = image;
	}
	void display()
	{
		cout << "(" << real << "," << image << ")" << endl;
	}
	friend Complex operator +(Complex A, Complex B)
	{
		return Complex(A.real + B.real, A.image + B.image);
	}
	friend Complex operator -(Complex A, Complex B);
	friend Complex operator -(Complex A);
	friend Complex operator ++(Complex &A);//前置
	friend Complex operator ++(Complex &A, int);//后置
};
Complex operator -(Complex A, Complex B)
{
	return Complex(A.real - B.real, A.image -B.image);
}
Complex operator -(Complex A)
{
	return Complex(-A.real ,-A.image);
}
Complex operator ++(Complex &A)
{
	return Complex(++A.real , A.image);
}
Complex operator ++(Complex &A,int )
{
	return Complex(A.real ++, A.image);
}
int P7::P7_1()
{
	Complex A(100.0, 200.0), B(-10.0, 20.0), C;
	cout << "A=", A.display();
	cout << "B=", B.display();
	C = A + B;
	cout << "C=A+B=", C.display();
	C = A - B;
	cout << "C=A-B=", C.display();
	C = -A + B;
	cout << "C=-A+B=", C.display();
	C = A++;
	cout << "C=A++,C=", C.display();
	C = ++A;
	cout << "C=++A,C=", C.display();
	C = A+5;
	C.display();
	return 0;
}

class Complex2
{
private:
	double real;
	double image;
public:
	Complex2(double real = 0.0, double image = 0.0)
	{
		this->real = real; this->image = image;
	}
	void display()
	{
		cout << "(" << real << "," << image << ")" << endl;
	}
	Complex2 operator +(Complex2 B);
	Complex2 operator -(Complex2 B);
	Complex2 operator -();//取负
	Complex2 operator ++();//前置
	Complex2 operator ++( int);//后置
};
Complex2 Complex2::operator +(Complex2 B)
{
	return Complex2(real + B.real, image + B.image);
}
Complex2 Complex2::operator -(Complex2 B)
{
	return Complex2(real - B.real, image - B.image);
}
Complex2 Complex2::operator -()
{
	return Complex2(-real,-image);
}
Complex2 Complex2::operator ++()
{
	return Complex2(++real, image);
}
Complex2 Complex2::operator ++(int)
{
	return Complex2(real++, image);
}
int P7::P7_2()
{
	Complex2 A(100.0, 200.0), B(-10.0, 20.0), C;
	cout << "A=", A.display();
	cout << "B=", B.display();
	C = A + B;
	cout << "C=A+B=", C.display();
	C = A - B;
	cout << "C=A-B=", C.display();
	C = -A + B;
	cout << "C=-A+B=", C.display();
	C = A++;
	cout << "C=A++,C=", C.display();
	C = ++A;
	cout << "C=++A,C=", C.display();
	C = A + 5;
	C.display();
	return 0;
}

class Complex3
{
private:
	double real;
	double image;
public:
	Complex3(double real = 0.0, double image = 0.0)
	{
		this->real = real; this->image = image;
	}
	void display()
	{
		cout << "(" << real << "," << image << ")" << endl;
	}
	Complex3 operator +(Complex3 B);
	Complex3 operator =(Complex3 B);
};
Complex3 Complex3::operator +(Complex3 B)
{
	return Complex3(real + B.real, image + B.image);
}
Complex3 Complex3::operator =(Complex3 B)
{
	real = B.real, image = B.image;
	cout << "opreator =callong ..." << endl;
	return *this;
}
int P7::P7_3()
{
	Complex3 A(100.0, 200.0), B(-10.0, 20.0), C;
	cout << "A=", A.display();
	cout << "B=", B.display();
	C = A + B;
	cout << "C=A+B=", C.display();
	C = A ;
	cout << "C=A=", C.display();
	return 0;
}

class Complex4
{
private:
	double real;
	double image;
public:
	Complex4(double real = 0.0, double image = 0.0)
	{
		this->real = real; this->image = image;
	}
	void display()
	{
		cout << "(" << real << "," << image << ")" << endl;
	}
};
class PComplex
{
private:
	Complex4 *PC;
public:
	PComplex(Complex4 *PC = NULL)
	{
		this -> PC = PC;
	}
	Complex4 *operator ->()
	{
		static Complex4 NULLComplex(0, 0);
		if (PC == NULL)
		{
			return &NULLComplex;
		}
		return PC;
	}
};
int P7::P7_4()
{
	PComplex P1;
	P1->display();
	Complex4 C1(100, 200);
	P1 = &C1;
	P1->display();
	return 0;
}

class String
{
private:
	char * Str;
	int len;
public:
	void ShowStr()
	{
		cout << "string :" << Str << ",length:" << len << endl;
	}
	String(const char *p = NULL)
	{
		if (p)
		{
			len = strlen(p);
			Str = new char[len + 1];
			strcpy(Str, p);
		}
		else
		{
			len = 0; Str = NULL;
		}
	}
	~String()
	{
		if (Str != NULL)
			delete[]Str;
	}
	char &operator [](int n)
	{
		return *(Str + n);
	}
	const char &operator[](int n)const
	{
		return *(Str + n);
	}
};
int P7::P7_5()
{
	String S1("0123456789abcdef");
	S1.ShowStr();
	S1[10] = 'A';
	cout << "S1[10]=A" << endl;
	S1.ShowStr();
	const String S2("ABCDEFGHIJKLMN");
	cout << "S2[10]=" << S2[10] << endl;
	return 0;
}

class Point
{
private:
	int X, Y;
public:
	Point(int X = 0, int Y = 0)
	{
		this->X = X, this->Y = Y;
	}
	double area()
	{
		return 0.0;
	}
};
const double PI = 3.14159;
class Circle :public Point
{
private:double radius;
public:
	Circle(int X, int Y, double R) :Point(X,Y)
	{
		radius = R;
	}
	double area()
	{
		return PI*radius*radius;
	}
};
int P7::P7_6()
{
	Point P1(10, 10);
	cout << "P1.area()=" << P1.area() << endl;
	Circle C1(10, 10, 20);
	cout << "C1.area()=" << C1.area() << endl;
	Point *Pp;
	Pp = &C1;
	cout << "Pp->area()=" << Pp->area() << endl;
	Point &Rp = C1;
	cout << "Rp.area()=" << Rp.area() << endl;
	return 0;
}

class Point7
{
private:
	int X, Y;
public:
	Point7(int X = 0, int Y = 0)
	{
		this->X = X, this->Y = Y;
	}
	virtual double area()
	{
		return 0.0;
	}
};
class Circle7 :public Point7
{
private:double radius;
public:
	Circle7(int X, int Y, double R) :Point7(X, Y)
	{
		radius = R;
	}
	double area()
	{
		return PI*radius*radius;
	}
};
int P7::P7_7()
{
	Point7 P1(10, 10);
	cout << "P1.area()=" << P1.area() << endl;
	Circle7 C1(10, 10, 20);
	cout << "C1.area()=" << C1.area() << endl;
	Point7 *Pp;
	Pp = &C1;
	cout << "Pp->area()=" << Pp->area() << endl;
	Point7 &Rp = C1;
	cout << "Rp.area()=" << Rp.area() << endl;
	return 0;
}

class A
{
public:
	virtual ~A()
	{
		cout << "A::~A() is called." << endl;
	}
	A()
	{
		cout << "A::A() is called." << endl;
	}
};
class B:public A
{
private:
	int *ip;
public:
	B(int size = 0)
	{
		ip = new int[size];
		cout << "B::B() is called." << endl;
	}
	~B()
	{
		cout << "B::~B is called." << endl;
		delete[] ip;
	}
};
int P7::P7_8()
{
	A *b = new B(10);
	delete b; return 0;
}
class Shape
{
public:
	virtual double area()const = 0;
	virtual void show() = 0;
};
class Point9 :public Shape
{
protected:
	int X,Y;
public:
	Point9(int X = 0, int  Y = 0)
	{
		this->X = X, this->Y = Y;
	}
	void show()
	{
		cout << "(" << X << "," << Y << ")" << endl;
	}
	double area() const
	{
		return 0.0;
	}
};
class Circle9 :public Point9
{
protected:double radius;
public:
	Circle9(int X, int Y, double R) :Point9(X, Y)
	{
		radius = R;
	}
	double area()const
	{
		return PI*radius*radius;
	}
	void show()
	{
		cout <<"Centre"<< "(" << X << "," << Y << ")" << endl;
		cout << "radius" << radius<< endl;
	}
};
class Cylinder :public Circle9
{
private:
	double height;
public:
	Cylinder(int X, int Y, double R, double H) :Circle9(X, Y, R)
	{
		height = H;
	}
	double area()const
	{
		return 2 * Circle9::area() + 2 * PI*radius*height;
	}
	void show()
	{
		Circle9::show();
		cout << "height of cylinder:" << height << endl;
	}
};
int P7::P7_9()
{
	Cylinder CY(100, 200, 10, 50);
	Shape *p;
	p = &CY;
	p->show();
	cout << "total area :" << p->area() << endl;
	Circle9 Cir(5, 10, 100);
	Shape &R = Cir;
	R.show();
	return 0;
}
#include <cstring>
class Person
{
protected:
	char name[20];
public:
	Person(char *iname){ strcpy(name,iname); }
	virtual void who_am_I() = 0;
	virtual ~Person(){ cout << "~Person() called." << endl; }
};
class Student :public Person
{
private:
	char major[20];
public:
	Student(char *iname, char *imajor) :Person(iname)
	{
		strcpy(major, imajor);
	}
	void who_am_I()
	{
		cout << "My name is" << name << ", I major in" << major << endl;
	}
	~Student(){ cout << "~Student() called!" << endl; }
};
class Teacher :public Person
{
private:
	char teach[20];
public:
	Teacher(char * iname, char * iteach) :Person(iname)
	{
		strcpy(teach,iteach);
	}
	void who_am_I()
	{
		cout << "My name is " << name << ", I teach " << teach << endl;
	}
	~Teacher()
	{
		cout << "~Teacher() called!" << endl;
	}
};
int P7::P7_10()
{
	Person *PersonArr[5];
	PersonArr[0] = new Student("Joe", "computer");
	PersonArr[1] = new Student("Mary", "mathmatics");
	PersonArr[2] = new Teacher("Jasmine", "physics");
	PersonArr[3] = new Teacher("Antony", "chemical");
	PersonArr[4] = new Teacher("Jayden", "biology");
	for (int i = 0; i < 5; i++)
	{
		PersonArr[i]->who_am_I();
		delete PersonArr[i];
	}
	return 0;
}
P7::~P7()
{
}
