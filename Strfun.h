#pragma once
class Strfun
{
public:
	Strfun();
	~Strfun();
	void mystrcopy(char *obj, const char *org);
	void mystrlen(const char *obj);
	void mystrconnect(char *obj, const char *org);
	void mystrturn(char *obj);
	int mystrcompare(char obj1[], char obj2[]);
};

