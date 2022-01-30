#include<iostream>
using namespace std;
class person
{
public:	int age = 0;
public:
	//1.构造函数
	//2.没有返回值，不用写void
	//3.函数名与类名相同
	//4.构造函数可以有参数，可以发生重载
	//5.创造对象的时候，构造函数会自动调用，而且只调用一次
	person()//无参构造函数
	{
		cout << "person无参构造函数的调用" << endl;
	}
person(int a)//有参构造函数
	{
		age = a;
		cout << "person有参构造函数的调用" << endl;
	}
	person(const person &p)//拷贝构造函数
	{
		int age = p.age;
		cout << "person拷贝构造函数的调用" << endl;
	}
	//1.析构函数
	//2.没有返回值，不用写void
	//3.函数名与类名相同
	//4.构造函数不可以有参数，不可以发生重载
	//5.创造对象销毁前会自动调用析构函数，而且只调用一次
	~person()
	{
		cout << "person析构函数的调用" << endl;
	}
};
void dowork(person p)
{

}
void test1()
{
	person p1;//默认构造函数的调用，别加小括号，
	dowork(p1);//拷贝函数的调用
	person p2(10);//有参构造函数的调用
	person p3;//拷贝构造函数的调用
	cout << "p2的年纪" << p2.age << endl;
	cout << "p3的年纪" << p3.age << endl;
	person p4 = person(10);//有参函数调用
	person p5 = person(p4);//拷贝函数调用
	person p6 = 10;//相当于person p6=person(10)
}
person dowork1()
{
	person p;
	cout << (int*)&p<< endl;
	return p;
}
void test2()
{
	person p = dowork1();
	cout << (int*)&p << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}