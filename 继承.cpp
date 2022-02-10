#include<iostream>
using namespace std;
#include<string>
//继承的语法class 子类：继承方式 父类1，继承方式 父类2
//继承方式有public,private,protected
// 无论子类用什么方式继承
// 父类公共去子类也是公共，
// 父类保护去子类也是保护
// 父类私密子类不可以访问
//实现普通页面***************
class prime
{
public:
	void haeder()
	{
		cout << "首页，公开课，登录，注册……（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心，交流合作，站内地图……（公共底部）" << endl;
	}
	void left()
	{
		cout << "jave,python,c++,……（公共分类表）" << endl;
	}
};
class jave :public prime
{
public:
	void content()
	{
		cout << "jave教学视频" << endl;
	}
};
class py :public prime
{
public:
	void content()
	{
		cout << "python教学视频" << endl;
	}
};
class cp :public prime
{
public:
	void content()
	{
		cout << "c++教学视频" << endl;
	}
};
void test1()
{
	cout << "jave下载视频页面如下" << endl;
	jave ja;
	ja.haeder();
	ja.footer();
	ja.left();
	ja.content();
	cout << "------------------------" << endl;
	cout << "python下载视频页面如下" << endl;
	py p;
	p.haeder();
	p.footer();
	p.left();
	p.content();
	cout << "------------------------" << endl;
	cout << "c++下载视频页面如下" << endl;
	cp c;
	c.haeder();
	c.footer();
	c.left();
	c.content();
}
//继承中的对象模型************
class bace
{
public:int m_age;
private:int A;
protected:int B;
};
class son :public bace//子类会把父类所以的继承过来，只是有些不显示
{
public:int C;
};
//利用开发人员命令提示工具查看对象模型
//挑战盘符 F:
//跳转文件路径 cd 具体路径下
//查看名称
//c1 /d1 reportSingleClassLayout类名 文件名
void test2()
{
	son s;
	cout << (int)sizeof(s) << endl;
}
//继承构造与析构的顺续
class ba
{
public:ba()
{
	cout << "ba构造函数" << endl;
}
	  ~ba()
	  {
		  cout << "ba析构函数" << endl;
	  }
};
class er:public ba
{
public:er()
{
	cout << "er构造函数" << endl;
}
	  ~er()
	  {
		  cout << "er析构函数" << endl;
	  }
};
void test3()
{
	//继承中的构造与析构顺序如下
	// 先构造后析构
	//构造先父后子，析构反之
	er e;
}
//同名成员处理************
class baba
{
public:baba()
{
	m_c = 100;
}
	  void func()
	  {
		  cout << "baba-func()调用" << endl;
	  }
	  void func(int a)
	  {
		  cout << "baba-func(int a)调用" << endl;
	  }
	  int m_c;
};
class erer :public baba
{
public:erer()
{
	m_c = 200;
}
	  void func()
	  {
		  cout << "erer-func()调用" << endl;
	  }
	  int m_c;
};
void test4()
{
	//同名成员属性的处理
	erer son;
	cout << "erer下m_c=" << son.m_c << endl;
	//若通过子类访问父类同名成员，加上父类作用域
	cout << "baba下m_c=" << son.baba::m_c << endl;
}
//同名成员函数处理
void test5()
{
	erer son;
	son.func();//直接调用函数为子类中的
	son.baba::func();//加父类作用域为父类的
	//若子类出现与父类同名的成员函数，子类中的会隐藏父类中的函数
	//想访问父类中的函数需要加作用域
	son.baba::func(1000);
}
//同名静态函数处理***************
class bas
{
public:
	  static void func()
	  {
		  cout << "bas-func()调用" << endl;
	  }
	  static void func(int a)
	  {
		  cout << "bas-func(int a)调用" << endl;
	  }
	  static int m_d; //静态函数类内声明
};
int bas::m_d = 100;//静态函数类外初始化
class Son:public bas
{
public:
	static void func()
	{
		cout << "son-static func()调用" << endl;
	}
	static void func(int a)
	{
		cout << "son-static func(int a)调用" << endl;
	}
	static int m_d;
};
int Son::m_d = 200;
void test6()
{
	cout << "通过对象访问" << endl;
	Son ss;
	cout << "son 下 m_d" << ss.m_d << endl;
	cout << "bas 下 m_d" << ss.bas::m_d << endl;
	cout << "通过类名访问" << endl;
	cout << "son 下 m_d" << Son::m_d << endl;
	cout << "son 下 m_d" << Son::bas::m_d << endl;
}
void test7()
{
	cout << "通过对象访问" << endl;
	Son s;
	s.func();
	s.bas::func();
	cout << "通过类名访问" << endl;
	Son::func();
	Son::bas::func();
	Son::func(10);
	Son::bas::func(20);
}
//多继承***********
class base1
{
public:
	base1()
	{
		m_a = 100;

	}
	int m_a;
};
class base2
{
public:
	base2()
	{
		m_b = 100;
		m_a = 10;
	}
	int m_b;
	int m_a;
};
class son1 :public base1, public base2
{
public:
	son1()
	{
		m_c = 300;
		m_d = 400;
	}
	int m_c;
	int m_d;
};
void test8()
{
	son1 s;
	cout << "sizeof son1=" << (int)sizeof(s) << endl;
	cout << "m_a=" << s.base1::m_a << endl;
	cout << "m_a=" << s.base2::m_a << endl;
}
//菱形继承问题************
class animal
{
public:
	int m_age;
};
//虚继承解决菱形继承问题，virtual关键字
class sheep:virtual public animal{};
class tuo:virtual public animal{};
class sheeptuo:public sheep,public tuo{};
void test9()
{
	sheeptuo st;
	st.sheep::m_age = 18;
	st.tuo::m_age = 28;
	//菱形继承会有两个年龄
	cout << "st.sheep::m_age = " << st.sheep::m_age << endl;
	cout << "st.tuo::m_age = " << st.tuo::m_age  << endl;
	cout << "st.m_age" << st.m_age << endl;//一个年龄被虚继承处理掉了
}
int main()
{
	test1();
	test2();
	cout << "-------------" << endl;
	test3();
	test4();
	cout << "-------------" << endl;
	test5();
	cout << "-------------" << endl;
	cout << "-------------" << endl;
	test6();
	test7();
	cout << "-------------" << endl;
	cout << "-------------" << endl;
	test8();
	cout << "-------------" << endl;
	cout << "-------------" << endl;
	test9();
	system("pause");
	return 0;
}