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
		cout << "���ڵ�˳��" << "  ������" << a[i].name << "  ����:" << a[i].age << endl;
	}
}

int main()
{
	//�ṹ��ָ��
	student s = { "zz",20,100 };
	student * p = &s;
	cout << "������" << p->name << "���䣺" << p->age << "������" << p->score << endl;
	//
	hero a[] = { {"����",34},{"����",50},{"�ŷ�",29},{"����",24},{"��",26} };
	int len = sizeof(a) / sizeof(a[0]);
	for (int b = 0; b < 5; b++)
	{
		cout << "ԭ����˳��" <<"  ������" <<a[b].name<< "  ����:"<<a[b].age<<endl;

	}
	cout << endl;
	change(a, 5);
	P(a, 5);




	system("pause");
	return 0;

}