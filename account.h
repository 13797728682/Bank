#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include"Date.h"
#include<iostream>
#include<cmath>
#include<string>

class SavingsAccount//�����˻���
{
private:
	string id;//�˻�ID��
	double balance;//�˻����
	double rate;//��Ϣ����
	Date lastDate;//��¼��һ�����䶯������
	double accumulation;//�����ۼ�֮��
	static double total;//�����˻����ܽ��
	void record(const Date &date, double amount, const string &desc);//��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ	descΪ˵��	
	double accumulate(const Date &date) const;//�������ָ�����ڵ��˻������ۻ�ֵ

public:
	SavingsAccount(const Date &date, const string &id, double rate);
	~SavingsAccount();
	string getID()const;
	double getBalance()const;
	double getRate()const;
	void deposit(const Date&date, double amount,const string &desc);//���
	void withdraw(const Date&date, double amount, const string &desc);//ȡ��
	void settle(const Date&date);//������Ϣ��ÿ��1��1�յ���һ�θú���
	void show() const;//��ʾ�˻���Ϣ
	void error(const string &msg);
	static double getTotal() 
	{ 
		return total;
	}
};

#endif