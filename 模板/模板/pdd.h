#pragma once
#include<iostream>
using namespace std;
#include<string>
template<class t1, class t2>
class pdd
{
public:
	pdd(t1 name, t2 age);
	void show();
	t1 m_name;
	t2 m_age;
};