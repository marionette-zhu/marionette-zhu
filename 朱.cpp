#include<iostream>
using namespace std;
#define hour 24
int main()
{
	cout << "helloword" << endl;
	cout << "aaa\thelloword" << endl;
	cout << "一天有多少小时：" << hour << "小时" << endl;
	int a = 10, b = 20;
	int sum;
	cout << "sum=" << a + b << endl;
	cout << "sum占用的内存空间为:" << sizeof(sum) << endl;
	//求ASCII
	char ch = 'a';
	cout << (int)ch << endl;
	char str[] = "hello";
	cout << str << endl;
	bool flag = true;
	cout << flag << endl;
	cout << "bool所占内存:" << sizeof(flag) << endl;
	int c = 10, d = 20;
	int k;
	cout << "k=" << c++ * d << endl;
	float f = 1.3f;
	cin >> f;
	cout << "浮点型变量f=" << f << endl;
	system("pause");
	return 0;
}