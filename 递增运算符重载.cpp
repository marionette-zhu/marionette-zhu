#include<iostream>
using namespace std;
class person
{
	friend ostream& operator<<(ostream& cout, person p);
public:person()
{
	m_num = 0;
}
	  //ǰ����++
	  person &operator++()
	  {
		  m_num++;
		  return *this;
	  }
	  //������++
	  person operator++(int)//int����ǰ��++
	  {
		  person temp = *this;
		  m_num++;
		  return temp;
	  }
private:int m_num;
};
ostream& operator<<(ostream& cout, person p)
{
	cout << p.m_num;
	return cout;
}
void test()
{
	person p;
	cout <<++ p << endl;
	cout << p;
}
void test1()
{
	person p;
	cout << p++ << endl;
	cout << p;
}
int main()
{
	test();
	test1();
	system("pause");
	return 0;
}