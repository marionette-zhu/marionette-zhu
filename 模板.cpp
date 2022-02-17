#include<iostream>
using namespace std;
#include<string>
template<typename T>//声明模板，告诉编译器不要报错，T为通用数据类型
void myswap(T& a, T & b)
{
	T t = a;
	a = b;
	b = t;
}
void test()
{
	int a = 10;
	int b = 20;
	float c = 3.3;
	float d = 4.4;
	//自动类型推导
	myswap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	//显示指定类型
	myswap<float>(c, d);
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
}
//函数模板注意事项
// 1.自动类型推导，必须推导出一致的数据类型T才可以使用
// 2.模板必须确定T的数据类型，才能使用
template<class T>
void func()
{
	cout << "func调用" << endl;
}
void test1()
{
	func<int>();//电脑无法识别数据类型，手动加一种数据类型
}

//实现通用的数组排序函数-----------------
template<class t>
void mysort(t arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//认定最大值的下标
		for (int j = i + 1; j < len; j++)
		{
			//认定的最大值 比 普遍的数值
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			myswap(arr[max], arr[i]);//交换max和i的元素
		}
	}
}
//打印数组模板
template<class T>
void print(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "    ";
	}
}
void test2()
{
	//测试数组char
	char chararr[] = "dadcfe";
	int num = sizeof(chararr) / sizeof(char);
	mysort(chararr, num);
	print(chararr,num);
}
void test3()
{
	int intarr[] = { 3,4,2,6,8,9 };
	int num = sizeof(intarr) / sizeof(int);
	mysort(intarr, num);
	print(intarr, num);
}
//普通函数与模板函数的区别--------------
//1.普通函数调用可以发生隐式类型转换
// 2.函数模板 用自动类型推导，不可以发生隐式转换
// 3.函数模板 用显示指定类型，可以发生隐式类型转换
int add1(int g, int h)
{
	return g + h;
}
template<class T>
T add2(T a, T b)
{
	return a + b;
}
void test4()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << add1(a, b) << endl;
	cout << add1(a, c) << endl;//自动将c转换为97
	cout << add2(a, b) << endl;
	cout << add2<int>(a, c) << endl;//int确定类型后自动转换
}
//普通函数与函数模板调用规则
//1.如果函数模板与普通模板都可以调用，优先调用普通函数
// 2.可以通过空模板参数列表 强制调用 函数模板
// 3.函数模板可以发生函数重载
// 4.如果函数模板可以产生更好的匹配，优先调用函数模板
void myprint(int a, int b)
{
	cout << "调用的普通函数" << endl;
}
template<class T>
void myprint(T a, T b)
{
	cout << "调用的模板" << endl;
}
template<class T>
void myprint(T a, T b,T c)
{
	cout << "调用的重载模板" << endl;
}
void test7()
{
	int a = 100;
	int b = 200;
	char c1 = 'a';
	char c2 = 'b';
	myprint(a, b);
	myprint<>(a, b);//空模板强制调用函数模板
	//重载myprint(a, b, 100);
	myprint(c1, c2);
}
//模板的局限性----------------
class Per
{
public:
	Per (string name,int age)
           {
	this->m_name = name;
	this->m_age = age;
           }
	string m_name;
	int m_age;
};
template<class T>
bool compare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//利用具体化person版本实现
template<> bool compare(Per& p1, Per& p2)
{
if(p1.m_name==p2.m_name&&p1.m_age==p2.m_age)
{
	return true;
}
else
{
	return false;
}
}
void test8()
{
	int a = 100;
	int b = 100;
	bool ret = compare(a, b);
	if (ret)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}
void test9()
{
	Per p1("Tom", 19);
	Per p2("Tom", 19);
	bool ret = compare(p1, p2);
	if (ret)
	{
		cout << "两人信息相同" << endl;
	}
	else
	{
		cout << "两人信息不相同" << endl;
	}
}
//提前让编译器知道-------------------------
template<class t1, class t2>
class person;
//类外实现
template<class t1, class t2>
void printperson2(person<t1, t2>p)
{
	cout << "类外实现----姓名：" << p.m_name << "   年龄：" << p.m_age << endl;
}
//通过全局函数打印person信息
template<class t1,class t2>
class person

{
	//全局函数，类内实现
	friend void printperson(person<t1, t2>p)
	{
		cout << "姓名：" << p.m_name << "   年龄：" << p.m_age << endl;
	}
	//全局函数，类外实现  加空模板的参数列表
	friend void printperson2<>(person<t1, t2>p);
public:person(t1 name, t2 age)
{
	this->m_name = name;
	this->m_age = age;
}
private:
	  t1 m_name;
	  t2 m_age;
};
void test5()
{
	person<string, int>p("Tom", 20);
	printperson(p);
}
void test6()
{
	person<string, int>p("Jerry", 20);
	printperson2(p);
}
//类模板----------------------
template<class nt,class at>
class pe
{
public:
	pe(nt name, at age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	void show()
	{
		cout << "name:" << this->m_name << "  age=" << this->m_age << endl;
	}
	nt m_name;
	at m_age;
};
void test10()
{
	pe<string, int>p1("孙悟空", 9999);
	p1.show();
}
//类模板与函数模板的区别----------------------
template<class nt,class at=int>
class pet
{
public:
	pet(nt name, at age)
	{
		this->m__name = name;
		this->m__age = age;
	}
	void show()
	{
		cout << "name:" << this->m__name << "  age=" << this->m__age << endl;
	}
	nt m__name;
	at m__age;
};
//1.类模板没有自动类型推导使用方式
void test11()
{
	//pet p("孙悟空"，9999)  无法自动推导
	pet<string, int>P("齐天大圣", 9999);
	P.show();
}
//2.类模板在模板参数列表中可以有默认参数
void test12()
{
	pet<string>p("天蓬元帅", 8888);
	p.show();
}
int main()
{
	test();
	test1();
	test2();
	test3();
	test4();
	test5();
	cout << endl;
	test6();
	test7();
	cout << endl;
	test8();
    test9();
	cout << endl;
	test10();
	test11();
	test12();
	system("pause");
	return 0;
}