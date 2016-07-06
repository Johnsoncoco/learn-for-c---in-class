#include "P1.h"
#include <iostream>
#include <iomanip>
using namespace std;

P1::P1()
{
}
int P1::P1_1()/*例题1 陈强志2015302580198 */
{
	cout << "Hello C++!" << endl;
	return 0;
}
int P1::P1_2()
/*例题2 陈强志2015302580198 */
{
	float num1, num2, num3;//定义三个数
	cout << "Please input three numbers:";
	cin >> num1 >> num2 >> num3;//莫名其妙的中断
	cout << endl << "There average of " << num1 << "," << num2 << "and" << num3 << "is:" << (num1 + num2 + num3) / 3 << endl;
	return 0;
}
int P1::P1_3()
/*例题3 陈强志2015302580198 */
{
	float num1, num2, num3;//定义三个数
	cout << "Please input three numbers:";
	cin >> num1 >> num2 >> num3;
	cout << setw(8) << setprecision(12);
	cout << endl << "There average of " << num1 << "," << num2 << "and" << num3 << "is:" << setw(20) << (num1 + num2 + num3) / 3 << endl;
	return 0;
}

P1::~P1()
{
}
