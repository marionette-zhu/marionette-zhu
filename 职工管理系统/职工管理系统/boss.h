#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
class boss :public work
{
public:
	boss(int id, string name, int did);
	virtual void showinfo();//��ʾ������Ϣ
	virtual string getdeptname();//��ʾ��λ#pragma once
}; 
