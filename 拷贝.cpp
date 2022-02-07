#include<iostream>
using namespace std;
class person
{
public:
	person()
	{
		cout << "person默认构造函数调用" << endl;
	}
	person(int age,int h)
	{
		m_age = age;
		m_h=new int(h);//堆区的开辟
		cout << "person有参构造函数调用" << endl;
	}
	//自己实现拷贝构造函数解决浅拷贝
	person(const person& p)
	{
		cout << "person拷贝构造函数调用" << endl;
		m_age = p.m_age;
		//深拷贝操作
		m_h = new int(*p.m_h);
	}
	~person()
	{//析构代码将堆区释放
		if (m_h != NULL)
		{
			delete m_h;
			m_h = NULL;
		}
		cout << "person析构函数调用" << endl;
	}
	int m_age;
	int *m_h;
};
void test1()
{
	person p1(18,170);
	cout << "P1的年龄为：" << p1.m_age <<"身高为："<<*p1.m_h << endl;
	person p2(p1);
	cout << "P2的年龄为：" << p2.m_age << "身高为：" << *p2.m_h << endl;
}
int main()
{
	test1();
}