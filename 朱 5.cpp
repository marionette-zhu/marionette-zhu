#include<iostream>
using namespace std;
#include<string>

struct student
{
	string name; int age; int score;
};
struct hero
{
	string name;
	int age;
};
void change(hero a[],int len)
{
	for (int i = 0; i < 5; i++)
	{
		for(int j=0;j<4;j++)
			if (a[j].age > a[j + 1].age)
			{
				hero t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
			}
	}
}
void P(hero a[], int len)
{
	for(int i=0;i<5;i++)
	{
		cout << "现在的顺序：" << "  姓名：" << a[i].name << "  年龄:" << a[i].age << endl;
	}
}

int main()
{
	//结构体指针
	student s = { "zz",20,100 };
	student * p = &s;
	cout << "姓名：" << p->name << "年龄：" << p->age << "分数：" << p->score << endl;
	//
	hero a[] = { {"关羽",34},{"黄忠",50},{"张飞",29},{"赵云",24},{"马超",26} };
	int len = sizeof(a) / sizeof(a[0]);
	for (int b = 0; b < 5; b++)
	{
		cout << "原来的顺序：" <<"  姓名：" <<a[b].name<< "  年龄:"<<a[b].age<<endl;

	}
	cout << endl;
	change(a, 5);
	P(a, 5);




	system("pause");
	return 0;

}