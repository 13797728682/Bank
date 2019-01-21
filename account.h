#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#include"Date.h"
#include<iostream>
#include<cmath>
#include<string>

class SavingsAccount//储蓄账户类
{
private:
	string id;//账户ID；
	double balance;//账户余额
	double rate;//利息利率
	Date lastDate;//记录上一次余额变动的日期
	double accumulation;//余额按日累加之和
	static double total;//所有账户的总金额
	void record(const Date &date, double amount, const string &desc);//获得到指定日期为止的存款金额按日累积值	desc为说明	
	double accumulate(const Date &date) const;//计算截至指定日期的账户余额按日累积值

public:
	SavingsAccount(const Date &date, const string &id, double rate);
	~SavingsAccount();
	string getID()const;
	double getBalance()const;
	double getRate()const;
	void deposit(const Date&date, double amount,const string &desc);//存款
	void withdraw(const Date&date, double amount, const string &desc);//取款
	void settle(const Date&date);//结算利息，每年1月1日调用一次该函数
	void show() const;//显示账户信息
	void error(const string &msg);
	static double getTotal() 
	{ 
		return total;
	}
};

#endif