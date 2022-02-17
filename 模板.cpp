#include<iostream>
using namespace std;
#include<string>
template<typename T>//����ģ�壬���߱�������Ҫ����TΪͨ����������
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
	//�Զ������Ƶ�
	myswap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	//��ʾָ������
	myswap<float>(c, d);
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;
}
//����ģ��ע������
// 1.�Զ������Ƶ��������Ƶ���һ�µ���������T�ſ���ʹ��
// 2.ģ�����ȷ��T���������ͣ�����ʹ��
template<class T>
void func()
{
	cout << "func����" << endl;
}
void test1()
{
	func<int>();//�����޷�ʶ���������ͣ��ֶ���һ����������
}

//ʵ��ͨ�õ�����������-----------------
template<class t>
void mysort(t arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//�϶����ֵ���±�
		for (int j = i + 1; j < len; j++)
		{
			//�϶������ֵ �� �ձ����ֵ
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			myswap(arr[max], arr[i]);//����max��i��Ԫ��
		}
	}
}
//��ӡ����ģ��
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
	//��������char
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
//��ͨ������ģ�庯��������--------------
//1.��ͨ�������ÿ��Է�����ʽ����ת��
// 2.����ģ�� ���Զ������Ƶ��������Է�����ʽת��
// 3.����ģ�� ����ʾָ�����ͣ����Է�����ʽ����ת��
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
	cout << add1(a, c) << endl;//�Զ���cת��Ϊ97
	cout << add2(a, b) << endl;
	cout << add2<int>(a, c) << endl;//intȷ�����ͺ��Զ�ת��
}
//��ͨ�����뺯��ģ����ù���
//1.�������ģ������ͨģ�嶼���Ե��ã����ȵ�����ͨ����
// 2.����ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
// 3.����ģ����Է�����������
// 4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
void myprint(int a, int b)
{
	cout << "���õ���ͨ����" << endl;
}
template<class T>
void myprint(T a, T b)
{
	cout << "���õ�ģ��" << endl;
}
template<class T>
void myprint(T a, T b,T c)
{
	cout << "���õ�����ģ��" << endl;
}
void test7()
{
	int a = 100;
	int b = 200;
	char c1 = 'a';
	char c2 = 'b';
	myprint(a, b);
	myprint<>(a, b);//��ģ��ǿ�Ƶ��ú���ģ��
	//����myprint(a, b, 100);
	myprint(c1, c2);
}
//ģ��ľ�����----------------
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
//���þ��廯person�汾ʵ��
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
		cout << "������Ϣ��ͬ" << endl;
	}
	else
	{
		cout << "������Ϣ����ͬ" << endl;
	}
}
//��ǰ�ñ�����֪��-------------------------
template<class t1, class t2>
class person;
//����ʵ��
template<class t1, class t2>
void printperson2(person<t1, t2>p)
{
	cout << "����ʵ��----������" << p.m_name << "   ���䣺" << p.m_age << endl;
}
//ͨ��ȫ�ֺ�����ӡperson��Ϣ
template<class t1,class t2>
class person

{
	//ȫ�ֺ���������ʵ��
	friend void printperson(person<t1, t2>p)
	{
		cout << "������" << p.m_name << "   ���䣺" << p.m_age << endl;
	}
	//ȫ�ֺ���������ʵ��  �ӿ�ģ��Ĳ����б�
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
//��ģ��----------------------
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
	pe<string, int>p1("�����", 9999);
	p1.show();
}
//��ģ���뺯��ģ�������----------------------
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
//1.��ģ��û���Զ������Ƶ�ʹ�÷�ʽ
void test11()
{
	//pet p("�����"��9999)  �޷��Զ��Ƶ�
	pet<string, int>P("�����ʥ", 9999);
	P.show();
}
//2.��ģ����ģ������б��п�����Ĭ�ϲ���
void test12()
{
	pet<string>p("����Ԫ˧", 8888);
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