#include "byteturn.h"
#include <iostream>
using namespace std;

byteturn::byteturn(int n)
{
	this->n = n;
}
int byteturn::fun1()
{
	n = ((n >> 24) & 0xff) | ((n >> 8) & 0xff00) | ((n << 8) & 0xff0000) | ((n << 24) & 0xff000000);
	cout << n << endl;
	return 0;
}

byteturn::~byteturn()
{
}
