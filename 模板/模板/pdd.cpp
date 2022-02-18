#include<iostream>
using namespace std;
#include"pdd.h"
#include<string>
template<class t1, class t2>
pdd<t1, t2>::pdd(t1 name, t2 age)
{
	this->m_name = name;
	this->m_age = age;
}
template<class t1, class t2>
void pdd<t1, t2>::show()
{
	cout << "name:" << this->m_name << "  age=" << this->m_age << endl;
}