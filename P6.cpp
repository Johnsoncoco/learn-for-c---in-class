#include "P6.h"
#include <iostream>
using namespace std;

P6::P6()
{
}

class CPoint
{
private:int X, Y;
public:
	CPoint(int X = 0, int Y = 0)
	{
		this->X = X; this->Y = Y;
	}
	void move(int offx, int offy)
	{
		X += offx; Y += offy;
	}
	void ShowXY()
	{
		cout << "(" << X << "," << Y << ")" << endl;
	}
};
const double PI = 3.14159;
class CCircle :public CPoint
{
private:double radius;
public :
	CCircle(double R, int X, int Y)
	{
		radius = R;
	}
	double area()
	{
		return PI*radius*radius;
	}
	void ShowCCircle()
	{
		cout << "Centre of circle:";
		ShowXY();
		cout << "radius:" << radius << endl;
	}
};
int P6::P6_1()
{
	CCircle cirl(10, 100, 200);
	cirl.ShowCCircle();
	cout << "area is:" << cirl.area() << endl;
	cirl.move(10, 20);
	cirl.ShowXY();
	return 0;
}
class CPoint2
{
protected:int X, Y;
public:
	CPoint2(int X = 0, int Y = 0)
	{
		this->X = X; this->Y = Y;
	}
	void move(int offx, int offy)
	{
		X += offx; Y += offy;
	}
	void ShowXY()
	{
		cout << "(" << X << "," << Y << ")" << endl;
	}
};
class CCircle2 :protected CPoint2
{
protected:
	double radius;
public:
	CCircle2(double R, int X, int Y) :CPoint2(X,Y)
	{
		radius = R;
	}
	double area()
	{
		return PI*radius*radius;
	}
	void ShowCCircle2()
	{
		cout << "Centre of circle:";
		ShowXY();
		cout << "radius:" << radius << endl;
	}
};
class CCylinder :protected CCircle2
{
private:
	double height;
public:
	CCylinder(int X, int Y, double R, double H) :CCircle2(R,X,Y)
	{
		height = H;
	}
	double area()
	{
		return 2 * CCircle2::area() + 2 * PI*radius*height;
	}
	double volume()
	{
		return CCircle2::area()*height;
	}
	void ShowCylinder()
	{
		ShowCCircle2();
		cout << "height of cylinder:" << height << endl;
	}
};
int P6::P6_2()
{
	CCylinder CY(100, 20, 10, 50);
	CY.ShowCylinder();
	cout << "total area:" << CY.area() << endl;
	cout << "volume:" << CY.volume() << endl;
	return 0;
}
//单继承的构造函数和析构函数
class CPoint3
{
private:int x,y;
public:
	CPoint3(int x = 0, int y = 0)
	{
		this->x = x; this->y = y;
		cout << "point(" << x << "," << y << ")constructing..." << endl;
	}
	~CPoint3()
	{
		cout << "point(" << x << "," << y << ")destructing..." << endl;
	}
};
class CCircle3 :protected CPoint3
{
protected:
	double radius;
public:
	CCircle3(double R, int x = 0, int y = 0) :CPoint3(x, y)
	{
		radius = R;
		cout << "Circle constructing,radius:" << R << endl;
	}
	~CCircle3()
	{
		cout << "Circle destructing,radius:" << radius << endl;
	}
};
class Ctube :protected CCircle3
{
private:
	double height;
	CCircle3 InCircle;
public:
	Ctube(double h, double r1, double r2 = 0, int x = 0, int y = 0) :InCircle(r2, x, y), CCircle3(r1, x, y)
	{
		height = h;
		cout << "tube constructing,height:" << h << endl;
	}
	~Ctube()
	{
		cout << "tube destructing,hright:" << height << endl;
	}
};
int P6::P6_3()
{
	Ctube TU(100, 20, 5);
	return 0;
}
//演示类的兼容性
class CCylinder4 :public CCircle
{
private:
	double height;
public:
	CCylinder4(int x, int y, double r, double h) :CCircle(x, y, r)
	{
		height = h;
	}
	void ShowCylinder4()
	{
		ShowCCircle();
		cout << "height of cylinder:" << height << endl;
	}
};
int P6::P6_4()
{
	CPoint Cp(1, 1);
	CCircle Cir(20, 20, 15.5);
	CCylinder4 CY(300, 300, 15.5, 50);
	CPoint *Pp;
	Pp = &Cp;
	Pp->ShowXY();
	Pp = &Cir;
	Pp->ShowXY();
	Pp = &CY;
	Pp->ShowXY();
	CCircle &RC = CY;
	RC.ShowXY();
	Cp = Cir;
	Cp.ShowXY();
	return 0;
}
//多继承的二义性
class Car
{
private :
	int power; int seat;
public:
	Car(int power, int seat)
	{
		this->power = power, this->seat = seat;
	}
	void Show()
	{
		cout << "car power:" << power << "	seat:" << seat << endl;
	}
};
class Wagon
{
private:
	int power; int load;
public:
	Wagon(int power, int load)
	{
		this->power = power, this->load = load;
	}
	void Show()
	{
		cout << "wagon power:" << power << "	load:" << load << endl;
	}
};
class StationWagon :public Car, public Wagon
{
public:
	StationWagon(int power, int seat, int load) :Wagon(power, load), Car(power, seat)
	{
	}
	void ShowSW()
	{
		cout << "StationWagon:" << endl;
		Car::Show();
		Wagon::Show();
	}
};
int P6::P6_5()
{
	StationWagon Sw(105, 3, 8);
	//Sw.Show();
	Sw.ShowSW();
	return 0;
}
//多重继承的二义性
class Automonbile
{
private:
	int power;
public:
	Automonbile(int power)
	{
		this->power = power;
	}
	void Show()
	{
		cout << "		power:" << power;
	}
};
class Car6 :public Automonbile
{
private:
	int seat;
public:
	Car6(int power, int seat) :Automonbile(power)
	{
		this->seat = seat;
	}
	void Show()
	{
		cout << "car:";
		Automonbile::Show();
		cout << "		seat:" << seat << endl;
	}
};
class Wagon6 :public Automonbile
{
private:
	int load;
public:
	Wagon6(int power, int load) :Automonbile(power)
	{
		this->load = load;
	}
	void Show()
	{
		cout << "wagon:";
		Automonbile::Show();
		cout << "		load:" << load << endl;
	}
};
class StationWagon6 :public Car6, public Wagon6
{
public:
	StationWagon6(int Cpower, int Wpower, int seat, int load) :Wagon6(Wpower, load), Car6(Cpower, seat)
	{
	}
	void Show()
	{
		cout << "StationWagon:" << endl;
		Car6::Show();
		Wagon6::Show();
	}
};
int P6::P6_6()
{
	StationWagon6 Sw(105, 108, 3, 8);
	Sw.Show();
	return 0;
}
//虚基类的构造函数
class Automonbile7
{
private:
	int power;
public:
	Automonbile7(int power)
	{
		this->power = power;
		cout << "Automobile constructing..." << endl;
	}
	void Show()
	{
		cout << "		power:" << power;
	}
};
class Car7 :virtual public Automonbile7
{
private:
	int seat;
public:
	Car7(int power, int seat) :Automonbile7(power)
	{
		this->seat = seat;
		cout << "Car constructing..." << endl;
	}
	void Show()
	{
		cout << "car:";
		Automonbile7::Show();
		cout << "		seat:" << seat << endl;
	}
};
class Wagon7 :virtual public Automonbile7
{
private:
	int load;
public:
	Wagon7(int power, int load) :Automonbile7(power)
	{
		this->load = load;
		cout << "Wagon constructing..." << endl;
	}
	void Show()
	{
		cout << "wagon:";
		Automonbile7::Show();
		cout << "		load:" << load << endl;
	}
};
class StationWagon7 :public Car7, public Wagon7
{
public:
	StationWagon7(int Cpower, int Wpower, int seat, int load) :Automonbile7(Cpower),Wagon7(Wpower, load), Car7(Cpower, seat)
	{
		cout << "StationWagon constructing..." << endl;
	}
	void Show()
	{
		cout << "StationWagon:" << endl;
		Car7::Show();
		Wagon7::Show();
	}
};
int P6::P6_7()
{
	StationWagon7 Sw(105, 108, 3, 8);
	Sw.Show();
	return 0;
}
P6::~P6()
{
}
