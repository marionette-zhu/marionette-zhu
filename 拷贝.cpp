#include<iostream>
using namespace std;
class person
{
public:
	person()
	{
		cout << "personĬ�Ϲ��캯������" << endl;
	}
	person(int age,int h)
	{
		m_age = age;
		m_h=new int(h);//�����Ŀ���
		cout << "person�вι��캯������" << endl;
	}
	//�Լ�ʵ�ֿ������캯�����ǳ����
	person(const person& p)
	{
		cout << "person�������캯������" << endl;
		m_age = p.m_age;
		//�������
		m_h = new int(*p.m_h);
	}
	~person()
	{//�������뽫�����ͷ�
		if (m_h != NULL)
		{
			delete m_h;
			m_h = NULL;
		}
		cout << "person������������" << endl;
	}
	int m_age;
	int *m_h;
};
void test1()
{
	person p1(18,170);
	cout << "P1������Ϊ��" << p1.m_age <<"���Ϊ��"<<*p1.m_h << endl;
	person p2(p1);
	cout << "P2������Ϊ��" << p2.m_age << "���Ϊ��" << *p2.m_h << endl;
}
int main()
{
	test1();
}