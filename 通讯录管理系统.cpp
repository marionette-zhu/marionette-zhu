#include<iostream>
using namespace std;
#include<string>
#define max 100
void show()
{
	cout << "******1.添加联系人******" << endl;
	cout << "******2.显示联系人******" << endl;
	cout << "******3.删除联系人******" << endl;
	cout << "******4.查找联系人******" << endl;
	cout << "******5.修改联系人******" << endl;
	cout << "******6.清空联系人******" << endl;
	cout << "******0.退出通讯录******" << endl;

};
struct person
{
	string name;
	int sex;
	string phone;
};
struct book
{
	person m[max];
	int size;
};
void add(book* abc)
{
	if (abc->size == max)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abc->m[abc->size].name = name;
		cout << "请输入性别" << endl;
		cout << "1--男，2--女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abc->m[abc->size].sex = sex; break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		cout << "请输入电话号码" << endl;
		string phone;
		cin >> phone;
		abc->m[abc->size].phone = phone;
		abc->size++;
		cout << "添加成功" << endl;
		system("pauce");
		system("cls");
	}
  }
//
void reveal(book* abc)
{
	if (abc->size == 0)
	{
		cout << "当前记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < abc->size; i++)
		{
			cout << "\t姓名；" << abc->m[i].name << "\t性别：" << (abc->m[i].sex==1?"男":"女")<< "\t电话：" << abc->m[i].phone << endl;
			system("pause");
			system("cls");
		}

	}
}
//
int isexist(book* abc, string name)
{
	for (int i = 0; i < abc->size; i++)
	{
		if (abc->m[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
void D(book* abc)
{
	cout << "请输入要删除的联系人：" << endl;
			   string name;
			   cin >> name;
			   int ret = isexist(abc, name);
			   if(ret!=-1)
			   {
				   for (int i = ret; i < abc->size; i++)
				   {
					  abc->m[i] =abc->m[i + 1];
				   }
				  abc->size--;
				   cout << "删除成功" << endl;
				   system("pause");
				} 
			   else
			   {
				   cout << "查无此人" << endl;
			   }
			   system("pause");
			   system("cls");
}
//
void find(book* abc)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abc, name);
	if (ret != -1)
	{
		cout << "\t姓名；" << abc->m[ret].name << "\t性别：" << (abc->m[ret].sex == 1 ? "男" : "女") << "\t电话：" << abc->m[ret].phone << endl;
		system("pause");
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//
void M(book* abc)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int i = isexist(abc, name);
	if (i != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abc->m[i].name = name;
		cout << "请输入性别：" << "1--男" << "2--女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abc->m[i].sex = sex; break;
			}
			cout << "输入误请重新输入：" << endl;
		}
		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abc->m[i].phone = phone;
		cout << "修改成功" << endl;
	}
	else cout << "查无此人" << endl;

	system("pause");
		system("cls");
}
//
void clean(book* abc)
{
	cout << "\t是否要清空联系人" << "\t确认请按1" << "\t取消请按2"<<endl;
	int i = 0;
	cin >> i;
	if (i==1)
	{
		abc->size = 0;
		cout << "通讯录已清空" << endl;
	}
	else
	{
		cout << "操作已取消" << endl;
	}
	system("pause");
	system("cls");
}
int main()
{
	book abc;  
	int a = 0;
	abc.size = 0;
	while (true)
	{
		show();
		cin >> a;

		switch (a)
		{
		case 1: add(&abc); break;
		case 2:reveal(&abc); break;
		case 3: D(&abc); break;
		case 4:find(&abc); break;
		case 5:M(&abc); break;
		case 6:clean(&abc); break;
		case 0:
		{
		   cout << "欢迎下次使用" << endl;
		   system("pause");
		   return 0;
		   break;
		}
		}
	}
	system("pause");
	return 0;
}