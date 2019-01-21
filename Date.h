#ifndef DATE_H
#define DATE_H
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
	int totalDays;//�������ھ���1/1/1������
public:
	Date(int year,int month,int day);
	~Date();
	int getYear() const;
	int getMonth()const;
	int getDay()const;
	int getMaxDay()const;//��ȡ�����ж�����
	bool isLeapYear()const;//�ж��Ƿ�������
	void show()const;//��ʾ����
	int distance(const Date&date) const;//������������֮ǰ������졣

};

#endif