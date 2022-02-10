#include<iostream>
using namespace std;
#include<iostream>
//左移运算符重载**********
class person
{
	friend ostream& operator<<(ostream& cout, person& p);//友元
public:person (int a,int b)
{
	 m_a=a;
	 m_b=b;
}
private:int m_a;//私有域外不能访问
	  int m_b;
};
ostream& operator<<(ostream& cout, person& p)
{
	cout << "m_a=" << p.m_a << "m_b=" << p.m_b << endl;
	return cout;
}
void test1()
{
	person p1(10,20);
	cout << p1 ;

}
//递增运算符重载**********
class add
{
	friend ostream& operator<<(ostream& cout, add& A);
public:add()
{
	m_a = 0;
}
	  //前置++
	  add& operator++()
	  {
		  m_a++;
		  return *this;//返回自身
	  }
	  //后置++
	  add& operator++(int)//int用于区分前置后置递增
	  {
		  add temp = *this;//记录自身
		  m_a++;
		  return temp;//返回自身
	  }
private:int m_a;
};
//重载一下左移运算符
ostream& operator<<(ostream& cout, add& A)//用&内外都可以改变
{
	cout <<A.m_a;
	return cout;
}
void test2()
{
	add A;
	cout << ++(++A) << endl;
	cout << A << endl;
}
void test3()
{
	add A;
	cout << A++ << endl;
	cout << A << endl;
}
//赋值运算符重载**********
class ev
{

public:  ev(int age)
	  {
	m_age = new int(age);//开辟堆区，指针维护堆区数据
	  }
	  ~ev()
	  {
		  if (m_age != NULL)
		  {
			  delete m_age;//手动释放堆区
			  m_age = NULL;
		  }
	  }
	  //重载赋值运算符
	  ev& operator=(ev& e)
	  {
		  if (m_age != NULL)//判断是否有属性在堆区，有则释放，再深拷贝
		  {
			  delete m_age;
			  m_age = NULL;
		  }
		  m_age = new int(*e.m_age);//深拷贝
		  return *this;
	  }
	  int* m_age;
};

void tets4()
{
	ev e1(18);
	ev e2(20);
	ev e3(30);
	e3 = e2 = e1;
	cout << "e1=" << *e1.m_age << "    " << "e2=" << *e2.m_age <<endl;
	cout << "e3=" << *e3.m_age;//看指针里面的数据+*号
}
//关系运算符重载**********
class relative
{
public:
	relative(string name, int age)
	{
		this->m_name= name;
		this->m_age = age;
	}
	bool operator==(relative& r)//bool判断真假类型
	{
		if (this->m_name == r.m_name && this->m_age == r.m_age)
		{
			return true;
		}
		return false;
	}
	bool operator!=(relative& r)//bool判断真假类型
	{
		if (this->m_name == r.m_name && this->m_age == r.m_age)
		{
			return false;
		}
		return true;
	}
	string m_name;
	int m_age;
};
void test5()
{
	relative r1("张三丰",18);
	relative r2("张三丰", 18);
	if (r1 == r2)
	{
		cout << "r1与r2相等" << endl;
	}
	else cout << "r1与r2不相等" << endl;
	if (r1 != r2)
	{
		cout << "r1与r2不相等" << endl;
	}
	else cout << "r1与r2相等" << endl;
}
//函数调用运算符重载************
//打印输出类
class myprint
{
public:void operator()(string text)
{
	cout << text << endl;
}
};
void myprint2(string test)//函数调用
{
	cout << test << endl;
}
void test6()
{
	myprint myfunc;
	myfunc("hello world");
}
//加法类
class myadd
{
public:int operator()(int num1, int num2)
{
	return num1 + num2;
}
};
void test7()
{
	myadd my;
	int ret=my(10, 20);
	cout << "结果为：" << ret << endl;
	//匿名函数对象，使用后立即释放
	cout << myadd()(10, 20) << endl;//()代替my
}
int main()
{
	test1();
	test2();
	cout << endl;
	test3();
	cout << "*******" << endl;
	tets4();
	cout << "*******" << endl;
	test5();
	test6();
	test7();
	myprint2("hhhhhh");//函数调用
	system("pause");
	return 0;
	}