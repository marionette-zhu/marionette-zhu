#include<iostream>
using namespace std;
class person
{
public:person(int age)
{
	m_age = new int(age);//new����
}
	  ~person()//�����ͷŶ������ڴ�
	  {
		  if (m_age != NULL)
		  {
			  delete m_age;
			  m_age = NULL;
		  }
	  }
	  //���ظ�ֵ�����
	  person& operator=(person& p)
	  {
		  if (m_age != NULL)
		  {
			  delete m_age;
			  m_age = NULL;
		  }
		  //���
		  m_age =new int(*p.m_age);
		  return *this;
	  }
	  int* m_age;
};
void test()
{
	person p1(10);
	person p2(20);
	person p3(30);
	p3=p2=p1;
	cout <<"p1������Ϊ��" <<*p1.m_age << endl;
	cout << "p2������Ϊ��" <<*p2.m_age << endl;
	cout << "p3������Ϊ��" << *p3.m_age << endl;
}
int main()
{
	system("pause");
	return 0;
}