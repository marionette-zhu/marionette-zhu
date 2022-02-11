#include<iostream>
using namespace std;
#include<string>
//动态多态满足条件
// 1.有继承关系
// 2.子类重写父类虚函数
//

//动态多态使用****************
//父类的指针或引用执行子类对象
class animal
{
public:
	virtual void speak()//virtual虚函数，使地址晚绑定
	{
		cout << "动物在说话" << endl;
	}
};
//函数重写，函数返回值 函数名 参数列表相同
class cat:public animal
{
public:
	 virtual void speak()//virtul可写可不写，重写后将父类的虚函数覆盖
	{
		cout << "猫在说话" << endl;
	}
};
class dog :public animal
{
public:
	void speak()
	{
		cout << "狗在说话" << endl;
	}
};
//地址早绑定，在编译阶段就确定了地址
//若想猫说话，需要地址在运行阶段绑定,动态多态
void dospeak(animal& animal)//执行说话的函数
{
	animal.speak();
}
void test1()
{
	cat m;
	dospeak(m);
	dog d;
	dospeak(d);
}
void test2()
{
	cout << "animal大小为：" << (int)sizeof(animal) << endl;
}
//计算机案例****************
//普通写法
class calculater
{
public:
	int geresult(string oper)
	{
		if (oper == "+")
		{
			return m_num1 + m_num2;
		}
		else if (oper == "-")
		{
			return m_num1 - m_num2;
		}
	}
	int m_num1;
	int m_num2;
};
void test3()
{
	calculater c;
	c.m_num1 = 10;
	c.m_num2 = 5;
	cout << c.m_num1 << "+" << c.m_num2 << "=" << c.geresult("+") << endl;
	cout << c.m_num1 << "-" << c.m_num2 << "=" << c.geresult("-") << endl;
}
//开闭原则：对扩展开放，对修改关闭
//利用多态实现
class acalculater
{
public:
	virtual int getresult()
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};
class addcalculator :public acalculater
{
public:
	int getresult()
	{
		return m_num1 + m_num2;
	}
};
class subcalculator :public acalculater
{
public:
	int getresult()
	{
		return m_num1 - m_num2;
	}
};
class mulcalculator :public acalculater
{
public:
	int getresult()
	{
		return m_num1 * m_num2;
	}
};
void test4()
{
	acalculater* abc = new addcalculator;//父类指针指向引用对象
	abc-> m_num1 = 10;
	abc->m_num2 = 10;
	cout << abc->m_num1 << "+" << abc->m_num2 << "=" <<abc->getresult() << endl;
	delete abc;//手动释放堆区
	abc = new subcalculator;
	abc->m_num1 = 100;
	abc->m_num2 = 10;
	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getresult() << endl;
	delete abc;
}
//纯虚函数和抽象类 语法：  virtual 返回值类型 函数名 （参数列表）=0；
class base
{
public: virtual void func() = 0;//抽象类无法实列化对象
};
class son :public base//子类必须重写父类纯徐函数 否则无法实列化对象
{
public:
	void func()
	{
		cout << "func函数调用" << endl;
	 };
};
void test5()
{
	base* base = new son;
	base->func();
	delete base;
}
//制作饮料案例***************
class dringk
{
public:
	virtual void boil() = 0;
	virtual void brew() = 0;
	virtual void pour() = 0;
	virtual void put() = 0;
	void makedrink()
	{
		boil();
		brew();
		pour();
		put();
	}

};
class coffee :public dringk
{
	virtual void boil()
	{
		cout << "矿泉水" << endl;
	}
	virtual void brew()
	{
		cout << "冲咖啡" << endl;
	};
	virtual void pour() 
	{
		cout << "加糖和牛奶" << endl;
	}
	virtual void put() 
	{
		cout << "倒入杯子" << endl;
	}
};
class tea :public dringk
{
	virtual void boil()
	{
		cout << "矿泉水" << endl;
	}
	virtual void brew()
	{
		cout << "泡茶叶" << endl;
	};
	virtual void pour()
	{
		cout << "加入枸杞 " << endl;
	}
	virtual void put()
	{
		cout << "倒入杯子" << endl;
	}
};
void dowork(dringk* abs)
{
	abs->makedrink();
	delete abs;
}
void test6()
{
	dowork(new coffee);
	cout << "-----------" << endl;
	dowork(new tea);
}
//虚析构和纯虚析构*****************
class Animal
{
public:
	Animal()
	{
		cout << "animal构造函数调用" << endl;
	}
	virtual~Animal()//虚析构解决父类指针内存泄露
	{
		cout << "animal析构函数调用" << endl;
	}
	//virtual ~animal（）=0;纯虚析构函数，后面还需要实现
	virtual void speak() = 0;
};
//函数重写，函数返回值 函数名 参数列表相同
class sheap :public animal
{
public:
	sheap(string name)
	{
		cout << "构造函数调用" << endl;
		m_name = new string(name);
	}
	virtual void speak()//virtul可写可不写，重写后将父类的虚函数覆盖
	{
		cout << *m_name<<"动物在说话" << endl;
	}
	~sheap()
	{
		if (m_name != NULL)
		{
			cout << "析构函数调用" << endl;
			delete m_name;
			m_name = NULL;
		}
	}
	string* m_name;
};
void test7()
{
	Animal* nmial =new sheap("se");
	nmial->speak();
	delete nmial;
}
int mian()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	system("pause");
	return 0;
}