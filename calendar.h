#pragma once
class calendar
{
public:
	int day;
	int mouth;
	int year;
	int i, j, m, n;
	int weekday;
	long wantyear;
	int sum = 0;
	calendar();
	void show();
	~calendar();
};

