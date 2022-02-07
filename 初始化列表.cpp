#include<iostream>
using namespace std;
#include<string>
//初始化列表
//构造函数（）：属性1（值1），属性2（值2）……{}
class person
{
public:
	//person(int a, int b, int c)一般方法
	//{
		//m_a = a;
		//m_b = b;
		//m_c = c;
	//}
	//列表法
	person(int A,int B,int C):m_a(A), m_b(B), m_c(C)
	{

	}
		int m_a;
	int m_b;
	int m_c;
};
void test1()
{
	//一般方法person p(10, 20, 30);
	person p(30,50,50);
	cout << "m_a=" << p.m_a << endl;
	cout << "m_b=" << p.m_b << endl;
	cout << "m_c=" << p.m_c << endl;
}
class phone
{
public:
	phone(string pname)
	{
		m_pname = pname;
		cout << "phone的构造函数调用" << endl;
	}
	~phone()
	{
		cout << "phone的构造函数调用" << endl;
	}
	string m_pname;
};
class per
{
public:
	per(string name, string pname) :m_name(name),m_pname(pname)
	{
		cout << "per的构造函数调用" << endl;
	}
	~per()
	{
		cout << "per的构造函数调用" << endl;
	}
	string m_name;
	phone m_pname;
};
void test2()
{
	per p("张三丰","苹果");
	cout << p.m_name << "使用的是"<<p.m_pname.m_pname << endl;
}
// 静态成员函数
//所有对象共享一个函数
//静态成员函数只能访问静态成员变量
class pe
{
public:
	static void func()
	{
		m_A = 100;
		cout << "static void func的调用" << endl;
	}
	static int m_A;//静态成员变量
	int m_B;
};
int pe::m_A = 0;//静态要初始化 
void test3()
{
	//通过对象访问
	pe p;
	p.func();
	//通过类名访问
	pe::func();
}
//成员变量和成员函数是分开存储的
class Person
{
	int m_d;//非静态成员变量 属于类的对象上
	static int m_f;//静态成员变量 不属于类对象上
	void func(){}//非静态成员函数 不属于类对象上
	 static void func2(){}//静态成员函数 不属于类的对象上
};
int Person::m_f = 0;
void test4()
{
	Person p;
	//空对象占用的内存空间为：1
	//C++编译器会给每个空对象分配一个字节空间，是为了区分空对象占用内存空间
	//每个空对象都有一个独一无二的内存地址
	cout << "size of p=" << sizeof(p) << endl;
}
void test5()
{
	Person p;
	cout << "size of p=" << sizeof(p) << endl;
}
//this指针

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	system("pause");
	return 0;
}