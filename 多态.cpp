#include<iostream>
using namespace std;
#include<string>
//��̬��̬��������
// 1.�м̳й�ϵ
// 2.������д�����麯��
//

//��̬��̬ʹ��****************
//�����ָ�������ִ���������
class animal
{
public:
	virtual void speak()//virtual�麯����ʹ��ַ���
	{
		cout << "������˵��" << endl;
	}
};
//������д����������ֵ ������ �����б���ͬ
class cat:public animal
{
public:
	 virtual void speak()//virtul��д�ɲ�д����д�󽫸�����麯������
	{
		cout << "è��˵��" << endl;
	}
};
class dog :public animal
{
public:
	void speak()
	{
		cout << "����˵��" << endl;
	}
};
//��ַ��󶨣��ڱ���׶ξ�ȷ���˵�ַ
//����è˵������Ҫ��ַ�����н׶ΰ�,��̬��̬
void dospeak(animal& animal)//ִ��˵���ĺ���
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
	cout << "animal��СΪ��" << (int)sizeof(animal) << endl;
}
//���������****************
//��ͨд��
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
//����ԭ�򣺶���չ���ţ����޸Ĺر�
//���ö�̬ʵ��
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
	acalculater* abc = new addcalculator;//����ָ��ָ�����ö���
	abc-> m_num1 = 10;
	abc->m_num2 = 10;
	cout << abc->m_num1 << "+" << abc->m_num2 << "=" <<abc->getresult() << endl;
	delete abc;//�ֶ��ͷŶ���
	abc = new subcalculator;
	abc->m_num1 = 100;
	abc->m_num2 = 10;
	cout << abc->m_num1 << "-" << abc->m_num2 << "=" << abc->getresult() << endl;
	delete abc;
}
//���麯���ͳ����� �﷨��  virtual ����ֵ���� ������ �������б�=0��
class base
{
public: virtual void func() = 0;//�������޷�ʵ�л�����
};
class son :public base//���������д���ി�캯�� �����޷�ʵ�л�����
{
public:
	void func()
	{
		cout << "func��������" << endl;
	 };
};
void test5()
{
	base* base = new son;
	base->func();
	delete base;
}
//�������ϰ���***************
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
		cout << "��Ȫˮ" << endl;
	}
	virtual void brew()
	{
		cout << "�忧��" << endl;
	};
	virtual void pour() 
	{
		cout << "���Ǻ�ţ��" << endl;
	}
	virtual void put() 
	{
		cout << "���뱭��" << endl;
	}
};
class tea :public dringk
{
	virtual void boil()
	{
		cout << "��Ȫˮ" << endl;
	}
	virtual void brew()
	{
		cout << "�ݲ�Ҷ" << endl;
	};
	virtual void pour()
	{
		cout << "������� " << endl;
	}
	virtual void put()
	{
		cout << "���뱭��" << endl;
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
//�������ʹ�������*****************
class Animal
{
public:
	Animal()
	{
		cout << "animal���캯������" << endl;
	}
	virtual~Animal()//�������������ָ���ڴ�й¶
	{
		cout << "animal������������" << endl;
	}
	//virtual ~animal����=0;�����������������滹��Ҫʵ��
	virtual void speak() = 0;
};
//������д����������ֵ ������ �����б���ͬ
class sheap :public animal
{
public:
	sheap(string name)
	{
		cout << "���캯������" << endl;
		m_name = new string(name);
	}
	virtual void speak()//virtul��д�ɲ�д����д�󽫸�����麯������
	{
		cout << *m_name<<"������˵��" << endl;
	}
	~sheap()
	{
		if (m_name != NULL)
		{
			cout << "������������" << endl;
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