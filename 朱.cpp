#include<iostream>
using namespace std;
#define hour 24
int main()
{
	cout << "helloword" << endl;
	cout << "aaa\thelloword" << endl;
	cout << "һ���ж���Сʱ��" << hour << "Сʱ" << endl;
	int a = 10, b = 20;
	int sum;
	cout << "sum=" << a + b << endl;
	cout << "sumռ�õ��ڴ�ռ�Ϊ:" << sizeof(sum) << endl;
	//��ASCII
	char ch = 'a';
	cout << (int)ch << endl;
	char str[] = "hello";
	cout << str << endl;
	bool flag = true;
	cout << flag << endl;
	cout << "bool��ռ�ڴ�:" << sizeof(flag) << endl;
	int c = 10, d = 20;
	int k;
	cout << "k=" << c++ * d << endl;
	float f = 1.3f;
	cin >> f;
	cout << "�����ͱ���f=" << f << endl;
	system("pause");
	return 0;
}