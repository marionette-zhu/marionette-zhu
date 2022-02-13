#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
class boss :public work
{
public:
	boss(int id, string name, int did);
	virtual void showinfo();//显示个人信息
	virtual string getdeptname();//显示岗位#pragma once
}; 
