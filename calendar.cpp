#include "calendar.h"
#include <iostream>
#include <iomanip>
using namespace std;

calendar::calendar()
{
	
}
void calendar::show()
{
	cout << "请输入你想查询的年份:";
	cin >> wantyear;
	cout << endl;
	cout << "*******************************************" << endl;
	cout << " " << setw(25) << wantyear << "年" << " " << endl;
	cout << "___________________________________________" << endl;
	for (year = 1; year <= wantyear; year++)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			sum = sum + 366;
		}
		else sum = sum + 365;
	}
	weekday = sum % 7;
	do{
		for (mouth = 1; mouth <= 12; mouth++)
		{
			cout << setw(25) << mouth << "月" << endl;
			cout << setw(7) << "日" << setw(6) << "一" << setw(6) << "二" << setw(6) << "三" << setw(6) << "四" << setw(6) << "五" << setw(6) << "六" << endl;
			cout << " ";
			// for(i=0;i<=weekday;i++)
			// cout<<" ");
			switch (mouth)
			{
			case 1:case 3:case 5:case 7:case 8:case 10:case 12:day = 31; break;
			case 4:case 6:case 9:case 11:day = 30; break;
			case 2:if ((wantyear % 4 == 0 && wantyear % 100 != 0) || wantyear % 400 == 0) day = 29;
				   else day = 28;
				   break;
			}
			//cout<<" ");
			if (weekday < 6)
			{
				for (i = 0; i <= weekday; i++)
					cout << setw(6) << " ";
			}
			else cout << setw(6) << " ";

			for (j = 1, m = weekday; j <= day; j++)
			{
				m = m++ % 7;
				if ((weekday + j) % 7 == 0){
					cout << endl;
					cout << " ";
				}
				cout << setw(6) << j;
			}
			weekday = m;
			cout << endl << endl << endl << endl;
		}
	} while (mouth<12);
}
calendar::~calendar()
{
}
