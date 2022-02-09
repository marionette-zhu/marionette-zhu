#include<iostream>
using namespace std;
class person
{
public:person(int age)
{
	m_age = new int(age);//new堆区
}
	  ~person()//用来释放堆区的内存
	  {
		  if (m_age != NULL)
		  {
			  delete m_age;
			  m_age = NULL;
		  }
	  }
	  //重载赋值运算符
	  person& operator=(person& p)
	  {
		  if (m_age != NULL)
		  {
			  delete m_age;
			  m_age = NULL;
		  }
		  //深拷贝
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
	cout <<"p1的年龄为：" <<*p1.m_age << endl;
	cout << "p2的年龄为：" <<*p2.m_age << endl;
	cout << "p3的年龄为：" << *p3.m_age << endl;
}
int main()
{
	system("pause");
	return 0;
}