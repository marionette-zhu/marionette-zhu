#include<iostream>
using namespace std;
#include<string>
//�̳е��﷨class ���ࣺ�̳з�ʽ ����1���̳з�ʽ ����2
//�̳з�ʽ��public,private,protected
// ����������ʲô��ʽ�̳�
// ���๫��ȥ����Ҳ�ǹ�����
// ���ౣ��ȥ����Ҳ�Ǳ���
// ����˽�����಻���Է���
//ʵ����ͨҳ��***************
class prime
{
public:
	void haeder()
	{
		cout << "��ҳ�������Σ���¼��ע�ᡭ��������ͷ����" << endl;
	}
	void footer()
	{
		cout << "�������ģ�����������վ�ڵ�ͼ�����������ײ���" << endl;
	}
	void left()
	{
		cout << "jave,python,c++,���������������" << endl;
	}
};
class jave :public prime
{
public:
	void content()
	{
		cout << "jave��ѧ��Ƶ" << endl;
	}
};
class py :public prime
{
public:
	void content()
	{
		cout << "python��ѧ��Ƶ" << endl;
	}
};
class cp :public prime
{
public:
	void content()
	{
		cout << "c++��ѧ��Ƶ" << endl;
	}
};
void test1()
{
	cout << "jave������Ƶҳ������" << endl;
	jave ja;
	ja.haeder();
	ja.footer();
	ja.left();
	ja.content();
	cout << "------------------------" << endl;
	cout << "python������Ƶҳ������" << endl;
	py p;
	p.haeder();
	p.footer();
	p.left();
	p.content();
	cout << "------------------------" << endl;
	cout << "c++������Ƶҳ������" << endl;
	cp c;
	c.haeder();
	c.footer();
	c.left();
	c.content();
}
//�̳��еĶ���ģ��************
class bace
{
public:int m_age;
private:int A;
protected:int B;
};
class son :public bace//�����Ѹ������Եļ̳й�����ֻ����Щ����ʾ
{
public:int C;
};
//���ÿ�����Ա������ʾ���߲鿴����ģ��
//��ս�̷� F:
//��ת�ļ�·�� cd ����·����
//�鿴����
//c1 /d1 reportSingleClassLayout���� �ļ���
void test2()
{
	son s;
	cout << (int)sizeof(s) << endl;
}
//�̳й�����������˳��
class ba
{
public:ba()
{
	cout << "ba���캯��" << endl;
}
	  ~ba()
	  {
		  cout << "ba��������" << endl;
	  }
};
class er:public ba
{
public:er()
{
	cout << "er���캯��" << endl;
}
	  ~er()
	  {
		  cout << "er��������" << endl;
	  }
};
void test3()
{
	//�̳��еĹ���������˳������
	// �ȹ��������
	//�����ȸ����ӣ�������֮
	er e;
}
//ͬ����Ա����************
class baba
{
public:baba()
{
	m_c = 100;
}
	  void func()
	  {
		  cout << "baba-func()����" << endl;
	  }
	  void func(int a)
	  {
		  cout << "baba-func(int a)����" << endl;
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
		  cout << "erer-func()����" << endl;
	  }
	  int m_c;
};
void test4()
{
	//ͬ����Ա���ԵĴ���
	erer son;
	cout << "erer��m_c=" << son.m_c << endl;
	//��ͨ��������ʸ���ͬ����Ա�����ϸ���������
	cout << "baba��m_c=" << son.baba::m_c << endl;
}
//ͬ����Ա��������
void test5()
{
	erer son;
	son.func();//ֱ�ӵ��ú���Ϊ�����е�
	son.baba::func();//�Ӹ���������Ϊ�����
	//����������븸��ͬ���ĳ�Ա�����������еĻ����ظ����еĺ���
	//����ʸ����еĺ�����Ҫ��������
	son.baba::func(1000);
}
//ͬ����̬��������***************
class bas
{
public:
	  static void func()
	  {
		  cout << "bas-func()����" << endl;
	  }
	  static void func(int a)
	  {
		  cout << "bas-func(int a)����" << endl;
	  }
	  static int m_d; //��̬������������
};
int bas::m_d = 100;//��̬���������ʼ��
class Son:public bas
{
public:
	static void func()
	{
		cout << "son-static func()����" << endl;
	}
	static void func(int a)
	{
		cout << "son-static func(int a)����" << endl;
	}
	static int m_d;
};
int Son::m_d = 200;
void test6()
{
	cout << "ͨ���������" << endl;
	Son ss;
	cout << "son �� m_d" << ss.m_d << endl;
	cout << "bas �� m_d" << ss.bas::m_d << endl;
	cout << "ͨ����������" << endl;
	cout << "son �� m_d" << Son::m_d << endl;
	cout << "son �� m_d" << Son::bas::m_d << endl;
}
void test7()
{
	cout << "ͨ���������" << endl;
	Son s;
	s.func();
	s.bas::func();
	cout << "ͨ����������" << endl;
	Son::func();
	Son::bas::func();
	Son::func(10);
	Son::bas::func(20);
}
//��̳�***********
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
//���μ̳�����************
class animal
{
public:
	int m_age;
};
//��̳н�����μ̳����⣬virtual�ؼ���
class sheep:virtual public animal{};
class tuo:virtual public animal{};
class sheeptuo:public sheep,public tuo{};
void test9()
{
	sheeptuo st;
	st.sheep::m_age = 18;
	st.tuo::m_age = 28;
	//���μ̳л�����������
	cout << "st.sheep::m_age = " << st.sheep::m_age << endl;
	cout << "st.tuo::m_age = " << st.tuo::m_age  << endl;
	cout << "st.m_age" << st.m_age << endl;//һ�����䱻��̳д������
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