#include<iostream>
using namespace std;
#include<iostream>
//�������������**********
class person
{
	friend ostream& operator<<(ostream& cout, person& p);//��Ԫ
public:person (int a,int b)
{
	 m_a=a;
	 m_b=b;
}
private:int m_a;//˽�����ⲻ�ܷ���
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
//�������������**********
class add
{
	friend ostream& operator<<(ostream& cout, add& A);
public:add()
{
	m_a = 0;
}
	  //ǰ��++
	  add& operator++()
	  {
		  m_a++;
		  return *this;//��������
	  }
	  //����++
	  add& operator++(int)//int��������ǰ�ú��õ���
	  {
		  add temp = *this;//��¼����
		  m_a++;
		  return temp;//��������
	  }
private:int m_a;
};
//����һ�����������
ostream& operator<<(ostream& cout, add& A)//��&���ⶼ���Ըı�
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
//��ֵ���������**********
class ev
{

public:  ev(int age)
	  {
	m_age = new int(age);//���ٶ�����ָ��ά����������
	  }
	  ~ev()
	  {
		  if (m_age != NULL)
		  {
			  delete m_age;//�ֶ��ͷŶ���
			  m_age = NULL;
		  }
	  }
	  //���ظ�ֵ�����
	  ev& operator=(ev& e)
	  {
		  if (m_age != NULL)//�ж��Ƿ��������ڶ����������ͷţ������
		  {
			  delete m_age;
			  m_age = NULL;
		  }
		  m_age = new int(*e.m_age);//���
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
	cout << "e3=" << *e3.m_age;//��ָ�����������+*��
}
//��ϵ���������**********
class relative
{
public:
	relative(string name, int age)
	{
		this->m_name= name;
		this->m_age = age;
	}
	bool operator==(relative& r)//bool�ж��������
	{
		if (this->m_name == r.m_name && this->m_age == r.m_age)
		{
			return true;
		}
		return false;
	}
	bool operator!=(relative& r)//bool�ж��������
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
	relative r1("������",18);
	relative r2("������", 18);
	if (r1 == r2)
	{
		cout << "r1��r2���" << endl;
	}
	else cout << "r1��r2�����" << endl;
	if (r1 != r2)
	{
		cout << "r1��r2�����" << endl;
	}
	else cout << "r1��r2���" << endl;
}
//�����������������************
//��ӡ�����
class myprint
{
public:void operator()(string text)
{
	cout << text << endl;
}
};
void myprint2(string test)//��������
{
	cout << test << endl;
}
void test6()
{
	myprint myfunc;
	myfunc("hello world");
}
//�ӷ���
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
	cout << "���Ϊ��" << ret << endl;
	//������������ʹ�ú������ͷ�
	cout << myadd()(10, 20) << endl;//()����my
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
	myprint2("hhhhhh");//��������
	system("pause");
	return 0;
	}