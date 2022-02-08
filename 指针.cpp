#include<iostream>
using namespace std;
#include<string>
//this指针指向不能修改，指向的值可以改
class person
{
public:
	person(int age)
	{
		this->age = age;//用来区分同样名称
	}
	person& personadd(person& p)
	{
		this->age += p.age;
		return *this;//反回对象本身用*this
	 }
	int age;
};
void test1()
{
	person p1(18);
	cout << "p1的年龄为：" << p1.age << endl;
}
void test2()
{
	person p1(10);
	person p2(10);
	p2.personadd(p1).personadd(p1);
	cout << "p2的年龄为" << p2.age << endl;
}
//空指针调用成员函数
class per
{
public:
	void showclassname()
	{
		cout << "this is per class" << endl;
	}
	void showperage()
	{
		if (this == NULL)//防止运行报错
		{
			return;
		}
		cout << "age=" <<m_age << endl;
	}
	int m_age;
};
void test3()
{
	per* p = NULL;
	p->showperage();
}
//const修饰成员函数防止误修改
class Person
{
public:
	void showPerson()const//后面加const变为常函数
	{
		this->m_b = 100;
	}
	int m_a;
	mutable int m_b;//mutable特殊声明常函数也可以修改
};
void test4()
{
	Person p;
	p.showPerson();
}
void test5()
{
	const Person p;//对象前方加const，变为常对象
	//p.m_a = 100;
	p.m_b = 100;
	//常对象只能调用常函数
	p.showPerson();

}
//友元
class building
{
	friend void good(building* building);//+firend着内外均可以访问
public:
	building()
	{
		m_sit = "客厅";
		m_bed = "卧室";
	}
public:	string m_sit;
private:	string m_bed;

};
//全局函数做友元
void good(building* building)
{
	cout << "好朋友正在访问:" << building->m_sit << endl;
	cout << "好朋友正在访问:" << building->m_bed << endl;//最开始加friend
}
void test6()
{
	building building;
	good(&building);
}
//类做友元
class Building;
class Good
{
public:
	Good();
	void visit();
	Building* building;
};
class Building
{
	friend class Good;//让此类可以访问私有的成员
public:Building();
public:	string m_sit;
private:	string m_bed;
};
Building::Building()
{
	m_sit = "客厅";
	m_bed = "卧室";
}
Good::Good()
{
	//创建建筑物对象
	building = new Building;
}
void Good::visit()
{
	cout << "好朋友正在访问：" << building->m_sit << endl;
	cout << "好朋友正在访问：" << building->m_bed << endl;
}
void test7()
{
	Good gg;
	gg.visit();
}
//成员函数做友元
class B;
class goodgay
{
public:
	goodgay();
	void visit();//可任意访问
	void visit2();//不可以访问私有
	B* b;

};
class B
{
	friend void goodgay::visit();//让此类可以访问私有的成员
public:B();
public:	string m_sit;
private:	string m_bed;
};
B::B()
{
	m_sit = "客厅";
	m_bed = "卧室";
}
goodgay::goodgay()
{
	//创建建筑物对象
	b = new B;
}
void goodgay::visit()
{
	cout << "visit函数正在访问：" << b->m_sit << endl;
	cout << "visit函数正在访问：" << b->m_bed << endl;
}//可任意访问
void goodgay::visit2()
{
	cout << "visit2函数正在访问：" << b->m_sit << endl;
}//不可以访问私有
void test8()
{
	goodgay g;
	g.visit();
	g.visit2();
}
//运算符重载
class son
{
public:
	//成员函数重载
	son operator+(son &s)
	{
		son temp;
		temp.m_c = this->m_c + m_c;
		temp.m_d = this->m_d + m_d;
		return temp;
	}
	/*son operator+(son& s1, int num)
	{
		son temp;
		temp.m_c = s1.m_c + num;
		temp.m_d = s1.m_d + num;
		return temp;
	}*/
	int m_c;
	int m_d;
};
void test9()
{
	son s1;
	s1.m_c = 10;
	s1.m_d = 10;
	son s2;
	s2.m_c=10;
	s2.m_d = 10;
	son s3 = s1+s2;
	cout << "s3.m_c=" << s3.m_c << endl;
	cout << "s3.m_d=" << s3.m_d<<endl;

}
//全局函数重载
//son operator+(son& s1, son& s2)
//{
//	son temp;
//	temp.m_c = s1.m_c +s2. m_c;
//	temp.m_d = s1.m_d + s2.m_d;
//	return temp;
//}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	cout << endl;
	test7();
	test8();
	test9();
	system("pause");
	return 0;
}