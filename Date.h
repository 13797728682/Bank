#ifndef DATE_H
#define DATE_H
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
	int totalDays;//读入日期距离1/1/1的日期
public:
	Date(int year,int month,int day);
	~Date();
	int getYear() const;
	int getMonth()const;
	int getDay()const;
	int getMaxDay()const;//获取当月有多少天
	bool isLeapYear()const;//判断是否是闰年
	void show()const;//显示日期
	int distance(const Date&date) const;//计算两个日期之前差多少天。

};

#endif