#include<iostream>
using namespace std;
int* fun()
{
	int* p = new int(10);
	return p;
}
void test1()
{
	int* p = fun();
	cout << *p << endl;
	delete p;//将p所占的内存释放
}
void test2()//用new创建数组
{
	int* a = new int[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << endl;
	}
	delete[]a;//释放数组
		 
}
int c = 10;
int d = 20;
const int  g = 30;
//值传递,不会改变main函数里的数据
void t1(int a, int b)
{
	int t = a; a = b; b = t;
	cout << "a=" << a<< endl;
	cout << "b=" <<b << endl;
}
//地址传递；会改变main函数里面的数据
void t2(int* a, int* b)
{
	int t = *a; *a = *b;
	*b = t;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}
//引用传递，会改变main函数里面的数据
void t3(int& a, int& b)
{
	int t = a; a = b; b = t;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}
//
int& t4()
{
	static int a = 10;
	return a;
}
//const防止误修改,加上后修改会报错
void show(const int& a)
{
	cout << "a=" << a << endl;
}
//函数的默认参数，从第一个赋值后的都要复制赋值
int func(int a, int b = 30, int c = 20)
{
	return a + b + c;
}
int func1(int a = 10,int b = 20);//函数声明有默认后，实现就不能有
int func1(int a, int b)
{
	return a + b;
}

//函数的占位参数,不写数据名只写数据类型就是占位，它也可以有默认参数
//int=10,这为占位值
void func2(int a, int)
{
	cout << "this" << endl;
}
//函数重载 
//1.同一个作用域下
//2.函数名称相同
//3.函数参数类型不同，或者个数不同，或者顺序不同
void hun()
{
	cout << "hun" << endl;
}
void hun(int a)
{
	cout << "hun(int a)" << endl;
}
void hun(double a)
{
	cout << "hun(double)" << endl;
}
void hun(int a, double b)
{
	cout << "hun(int a, double b)" << endl;
}
void hun( double b, int a)
{
	cout << "hun( double b, int a)" << endl;
}
//注意
void tun( int& a)
{
	cout << "tun( int& a)" << endl;
}
void tun(const int & a)
{
	cout << "tun(const int &a)" << endl;
}
void tun2(int a,int b = 10)//默认参数,仅输入一个数两个函数都满足，编译器无法识别
{
	cout << "tun2(int a，int b=10)" << endl;
}
void tun2(int a)
{
	cout << "tun2(int a)" << endl;
} 
//设计一个圆类，求圆的周长
const double PI = 3.14;
class ci
{
public:
	int r;
	double ca()
	{
		return 2 * PI * r;
	}
};
int main()
{    
	test1();
	test2();
	int* p = fun();
	cout << *p << endl;
	cout << *p << endl;
		int a = 10;
		int b = 20;
		static int f = 50;
		const int h = 40;
		cout << "字符串长量的地址：" << (int)&"hello" << endl;
		cout << "局部变量a地址：" << (int)&a << endl;
		cout << "局部变量b地址：" << (int)&b << endl;
		cout << "全局变量c地址：" << (int)&c << endl;
		cout << "全局变量d地址：" << (int)&d << endl;
		cout << "静态变量f地址：" << (int)&f << endl;
		cout << "局部常量h地址：" << (int)&h<< endl;
		cout << "全局常量g地址：" << (int)&g << endl;
		cout << endl;
		//引用语法,引用必须初始化，int &w;错误；引用一个后不能在引用其他的
		int q= 10;
		int& w= q;//
		cout << "q=" << q<< endl;
		cout << "w=" << w << endl;
		 w= 20;
		cout << "q=" << q << endl;
		cout << "w=" << w<< endl;
		//
		int c = 5;
		int d = 3;
		t1(c, d);
		cout << "c=" << c << endl;
		cout << "d=" << d<< endl;
		t2(&c,& d);
		cout << "c=" << c << endl;
		cout << "d=" << d << endl;
		t3(c, d);
		cout << "c=" << c << endl;
		cout << "d=" << d << endl;
		//引用函数的返回值
		int& r = t4();
		cout << "r=" << r << endl;
		cout << "r=" << r << endl;
		cout << "r=" << r << endl;
		t4() = 100;//T4里面的树枝改变
		cout << "r=" << r << endl;
		cout << "r=" << r << endl;
		//引用的本质就是指针被电脑自动转化（指针常量）
		show(a);
		//若传了值就用传的，没传1用默认的
		cout << func(10) << endl;
		cout << func(10,20) << endl;
		cout << func1(10) << endl;
		//函数重载
		hun();
		hun(10);
		hun(3.11);
		hun(10, 3.11);
		hun(3.11, 10);
		int qq = 22;
		tun(qq);
		tun(10);
		cout << endl;
		//求圆的周长
		ci c1;
		c1.r = 10;
		cout << "圆的周长：" << c1.ca() << endl;
		system("pause");
	return 0;
}