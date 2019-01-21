#include "account.h"
#include<iostream>
#include<cmath>
using namespace std;

double SavingsAccount::total = 0;

void SavingsAccount::record(const Date & date, double amount, const string & desc)
{
	accumulation = accumulate(date);
	lastDate = date;
	amount = floor(amount * 100 + 0.5) / 100;  //保留小数点后两位
	balance += amount;
	total += amount;
	date.show();
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

double SavingsAccount::accumulate(const Date&date)const
{
	return accumulation + balance * date.distance(lastDate);
}




SavingsAccount::SavingsAccount(const Date & date, const string & id, double rate):id(id),balance(0),rate(rate),lastDate(date), accumulation(0)
{
	date.show();
	cout << "\t#" << id << " created" << endl;

}

SavingsAccount::~SavingsAccount()
{
}

string SavingsAccount::getID()const
{
	return id;
}

double SavingsAccount::getBalance()const
{

	return balance;
}

double SavingsAccount::getRate()const

{
	return rate;
}

void SavingsAccount::deposit(const Date & date, double amount, const string & desc)
{
	record(date, amount, desc);
}

void SavingsAccount::show()const
{
	cout << '#' << id << "\tBalance:" << balance;
}

void SavingsAccount::error(const string & msg)
{
	cout << "Error(#" << id << "): " << msg << endl;
}







void SavingsAccount::withdraw(const Date&date, double amount, const string &desc)
{
	if (amount > getBalance())
		cout << "Error:not enough money" << endl;
	else
		record(date, -amount,desc);
}

void SavingsAccount::settle(const Date &date)
{
	double interest = accumulate(date) * rate	//计算年息
		/ date.distance(Date(date.getYear() - 1, 1, 1));
	if (interest != 0)
		record(date, interest, "interest");
	accumulation = 0;
	
}

