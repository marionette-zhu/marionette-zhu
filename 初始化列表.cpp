#include<iostream>
using namespace std;
#include<string>
//��ʼ���б�
//���캯������������1��ֵ1��������2��ֵ2������{}
class person
{
public:
	//person(int a, int b, int c)һ�㷽��
	//{
		//m_a = a;
		//m_b = b;
		//m_c = c;
	//}
	//�б�
	person(int A,int B,int C):m_a(A), m_b(B), m_c(C)
	{

	}
		int m_a;
	int m_b;
	int m_c;
};
void test1()
{
	//һ�㷽��person p(10, 20, 30);
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
		cout << "phone�Ĺ��캯������" << endl;
	}
	~phone()
	{
		cout << "phone�Ĺ��캯������" << endl;
	}
	string m_pname;
};
class per
{
public:
	per(string name, string pname) :m_name(name),m_pname(pname)
	{
		cout << "per�Ĺ��캯������" << endl;
	}
	~per()
	{
		cout << "per�Ĺ��캯������" << endl;
	}
	string m_name;
	phone m_pname;
};
void test2()
{
	per p("������","ƻ��");
	cout << p.m_name << "ʹ�õ���"<<p.m_pname.m_pname << endl;
}
// ��̬��Ա����
//���ж�����һ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class pe
{
public:
	static void func()
	{
		m_A = 100;
		cout << "static void func�ĵ���" << endl;
	}
	static int m_A;//��̬��Ա����
	int m_B;
};
int pe::m_A = 0;//��̬Ҫ��ʼ�� 
void test3()
{
	//ͨ���������
	pe p;
	p.func();
	//ͨ����������
	pe::func();
}
//��Ա�����ͳ�Ա�����Ƿֿ��洢��
class Person
{
	int m_d;//�Ǿ�̬��Ա���� ������Ķ�����
	static int m_f;//��̬��Ա���� �������������
	void func(){}//�Ǿ�̬��Ա���� �������������
	 static void func2(){}//��̬��Ա���� ��������Ķ�����
};
int Person::m_f = 0;
void test4()
{
	Person p;
	//�ն���ռ�õ��ڴ�ռ�Ϊ��1
	//C++���������ÿ���ն������һ���ֽڿռ䣬��Ϊ�����ֿն���ռ���ڴ�ռ�
	//ÿ���ն�����һ����һ�޶����ڴ��ַ
	cout << "size of p=" << sizeof(p) << endl;
}
void test5()
{
	Person p;
	cout << "size of p=" << sizeof(p) << endl;
}
//thisָ��

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