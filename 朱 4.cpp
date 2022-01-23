#include<iostream>
using namespace std;
#include<string>
#include<ctime>
#include"swap.h"
void swap(int a, int b)
{
	int t = a; a = b; b = t;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}
int max(int c, int d)
{
	return c > d ? c: d;
}
struct student
{
	string s; int score;
};
struct teacher 
{
	string t; student s[5];
};
void prinInfo(teacher t[], int len)
{
	for (int i1 = 0; i1 < len; i1++)
	{
		cout << "老师姓名：" << t[i1].t << endl;
		for (int j1 = 0; j1 < 5; j1++)
		{
			cout << "\t学生姓名：" << t[i1].s[j1].s << "  考试分数：" << t[i1].s[j1].score << endl;
		}
	}
}
void A(teacher t[], int len)
{
	string nameseed = "ABCDE";
	for (int i2 = 0; i2 < len; i2++)
	{
		t[i2].t = "teacher_"; t[i2].t += nameseed[i2];
	
		for (int j2 = 0; j2 < 5; j2++)
		{
			
			t[i2].s[j2].s = "student_"; t[i2].s[j2].s = nameseed[j2];
			int random = rand() % 61 + 40;
			t[i2].s[j2].score = random;
		}
	}
}
void B(int* arr, int lon)
{
	for (int I = 0; I < lon - 1; I++)
	{
		if (arr[I] > arr[I + 1])
		{
			int te = arr[I]; arr[I] = arr[I + 1]; arr[I + 1] = te;
		}
	}
}
void P(int* arr, int lon)
{
	for (int i; i< lon; i++)
	{
		cout << arr[i] << "  ";
	}
}
int main()
{
	int c = 10; int d = 20;
	swap(c,d);
	cout << "最大为：" << max(c, d) << endl;
	//指针
	int* p;
	int a = 10;
	p = &a;
	cout << "指针P为：" << p << endl;
	*p = 100;
	cout << "a=" << a << endl;
	cout << "*p=" << *p << endl;
	cout << "指针的内存为：" << sizeof(int*) << endl;
	//指针和数组
	int arr[5] = { 1,2,3,4,5};
	int * f = arr;
	cout << "第一个元素为：" <<arr[0] << endl;
	cout << "指针第一个：" << *f << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << *f << endl; f++;
	}
	//老师与学生
	srand((unsigned int)time(NULL));
	teacher t[3];
	int len = sizeof(t) / sizeof(t[0]);
	A(t, len);
	prinInfo(t, len);
	//冒泡法
	int brr[5] = { 4,5,2,3,1 };
	int lon = sizeof(arr) / sizeof(arr[0]);
	P(arr, lon);
	B(arr, lon);
	system("pause");
	
	return 0;
}