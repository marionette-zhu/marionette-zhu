#include<iostream>
using namespace std;
int* fun()
{
	int* p = new int(10);
	return p;
}
void test1()
{
	int* p = fun();
	cout << *p << endl;
	delete p;//��p��ռ���ڴ��ͷ�
}
void test2()//��new��������
{
	int* a = new int[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << endl;
	}
	delete[]a;//�ͷ�����
		 
}
int c = 10;
int d = 20;
const int  g = 30;
//ֵ����,����ı�main�����������
void t1(int a, int b)
{
	int t = a; a = b; b = t;
	cout << "a=" << a<< endl;
	cout << "b=" <<b << endl;
}
//��ַ���ݣ���ı�main�������������
void t2(int* a, int* b)
{
	int t = *a; *a = *b;
	*b = t;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}
//���ô��ݣ���ı�main�������������
void t3(int& a, int& b)
{
	int t = a; a = b; b = t;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}
//
int& t4()
{
	static int a = 10;
	return a;
}
//const��ֹ���޸�,���Ϻ��޸Ļᱨ��
void show(const int& a)
{
	cout << "a=" << a << endl;
}
//������Ĭ�ϲ������ӵ�һ����ֵ��Ķ�Ҫ���Ƹ�ֵ
int func(int a, int b = 30, int c = 20)
{
	return a + b + c;
}
int func1(int a = 10,int b = 20);//����������Ĭ�Ϻ�ʵ�־Ͳ�����
int func1(int a, int b)
{
	return a + b;
}

//������ռλ����,��д������ֻд�������;���ռλ����Ҳ������Ĭ�ϲ���
//int=10,��Ϊռλֵ
void func2(int a, int)
{
	cout << "this" << endl;
}
//�������� 
//1.ͬһ����������
//2.����������ͬ
//3.�����������Ͳ�ͬ�����߸�����ͬ������˳��ͬ
void hun()
{
	cout << "hun" << endl;
}
void hun(int a)
{
	cout << "hun(int a)" << endl;
}
void hun(double a)
{
	cout << "hun(double)" << endl;
}
void hun(int a, double b)
{
	cout << "hun(int a, double b)" << endl;
}
void hun( double b, int a)
{
	cout << "hun( double b, int a)" << endl;
}
//ע��
void tun( int& a)
{
	cout << "tun( int& a)" << endl;
}
void tun(const int & a)
{
	cout << "tun(const int &a)" << endl;
}
void tun2(int a,int b = 10)//Ĭ�ϲ���,������һ�����������������㣬�������޷�ʶ��
{
	cout << "tun2(int a��int b=10)" << endl;
}
void tun2(int a)
{
	cout << "tun2(int a)" << endl;
} 
//���һ��Բ�࣬��Բ���ܳ�
const double PI = 3.14;
class ci
{
public:
	int r;
	double ca()
	{
		return 2 * PI * r;
	}
};
int main()
{    
	test1();
	test2();
	int* p = fun();
	cout << *p << endl;
	cout << *p << endl;
		int a = 10;
		int b = 20;
		static int f = 50;
		const int h = 40;
		cout << "�ַ��������ĵ�ַ��" << (int)&"hello" << endl;
		cout << "�ֲ�����a��ַ��" << (int)&a << endl;
		cout << "�ֲ�����b��ַ��" << (int)&b << endl;
		cout << "ȫ�ֱ���c��ַ��" << (int)&c << endl;
		cout << "ȫ�ֱ���d��ַ��" << (int)&d << endl;
		cout << "��̬����f��ַ��" << (int)&f << endl;
		cout << "�ֲ�����h��ַ��" << (int)&h<< endl;
		cout << "ȫ�ֳ���g��ַ��" << (int)&g << endl;
		cout << endl;
		//�����﷨,���ñ����ʼ����int &w;��������һ������������������
		int q= 10;
		int& w= q;//
		cout << "q=" << q<< endl;
		cout << "w=" << w << endl;
		 w= 20;
		cout << "q=" << q << endl;
		cout << "w=" << w<< endl;
		//
		int c = 5;
		int d = 3;
		t1(c, d);
		cout << "c=" << c << endl;
		cout << "d=" << d<< endl;
		t2(&c,& d);
		cout << "c=" << c << endl;
		cout << "d=" << d << endl;
		t3(c, d);
		cout << "c=" << c << endl;
		cout << "d=" << d << endl;
		//���ú����ķ���ֵ
		int& r = t4();
		cout << "r=" << r << endl;
		cout << "r=" << r << endl;
		cout << "r=" << r << endl;
		t4() = 100;//T4�������֦�ı�
		cout << "r=" << r << endl;
		cout << "r=" << r << endl;
		//���õı��ʾ���ָ�뱻�����Զ�ת����ָ�볣����
		show(a);
		//������ֵ���ô��ģ�û��1��Ĭ�ϵ�
		cout << func(10) << endl;
		cout << func(10,20) << endl;
		cout << func1(10) << endl;
		//��������
		hun();
		hun(10);
		hun(3.11);
		hun(10, 3.11);
		hun(3.11, 10);
		int qq = 22;
		tun(qq);
		tun(10);
		cout << endl;
		//��Բ���ܳ�
		ci c1;
		c1.r = 10;
		cout << "Բ���ܳ���" << c1.ca() << endl;
		system("pause");
	return 0;
}