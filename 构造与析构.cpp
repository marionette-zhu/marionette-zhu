#include<iostream>
using namespace std;
class person
{
public:	int age = 0;
public:
	//1.���캯��
	//2.û�з���ֵ������дvoid
	//3.��������������ͬ
	//4.���캯�������в��������Է�������
	//5.��������ʱ�򣬹��캯�����Զ����ã�����ֻ����һ��
	person()//�޲ι��캯��
	{
		cout << "person�޲ι��캯���ĵ���" << endl;
	}
person(int a)//�вι��캯��
	{
		age = a;
		cout << "person�вι��캯���ĵ���" << endl;
	}
	person(const person &p)//�������캯��
	{
		int age = p.age;
		cout << "person�������캯���ĵ���" << endl;
	}
	//1.��������
	//2.û�з���ֵ������дvoid
	//3.��������������ͬ
	//4.���캯���������в����������Է�������
	//5.�����������ǰ���Զ�������������������ֻ����һ��
	~person()
	{
		cout << "person���������ĵ���" << endl;
	}
};
void dowork(person p)
{

}
void test1()
{
	person p1;//Ĭ�Ϲ��캯���ĵ��ã����С���ţ�
	dowork(p1);//���������ĵ���
	person p2(10);//�вι��캯���ĵ���
	person p3;//�������캯���ĵ���
	cout << "p2�����" << p2.age << endl;
	cout << "p3�����" << p3.age << endl;
	person p4 = person(10);//�вκ�������
	person p5 = person(p4);//������������
	person p6 = 10;//�൱��person p6=person(10)
}
person dowork1()
{
	person p;
	cout << (int*)&p<< endl;
	return p;
}
void test2()
{
	person p = dowork1();
	cout << (int*)&p << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}