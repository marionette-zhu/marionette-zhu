#include<iostream>
using namespace std;
#include<string>
#define max 100
void show()
{
	cout << "******1.�����ϵ��******" << endl;
	cout << "******2.��ʾ��ϵ��******" << endl;
	cout << "******3.ɾ����ϵ��******" << endl;
	cout << "******4.������ϵ��******" << endl;
	cout << "******5.�޸���ϵ��******" << endl;
	cout << "******6.�����ϵ��******" << endl;
	cout << "******0.�˳�ͨѶ¼******" << endl;

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
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abc->m[abc->size].name = name;
		cout << "�������Ա�" << endl;
		cout << "1--�У�2--Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abc->m[abc->size].sex = sex; break;
			}
			cout << "������������������" << endl;
		}
		cout << "������绰����" << endl;
		string phone;
		cin >> phone;
		abc->m[abc->size].phone = phone;
		abc->size++;
		cout << "��ӳɹ�" << endl;
		system("pauce");
		system("cls");
	}
  }
//
void reveal(book* abc)
{
	if (abc->size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < abc->size; i++)
		{
			cout << "\t������" << abc->m[i].name << "\t�Ա�" << (abc->m[i].sex==1?"��":"Ů")<< "\t�绰��" << abc->m[i].phone << endl;
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
	cout << "������Ҫɾ������ϵ�ˣ�" << endl;
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
				   cout << "ɾ���ɹ�" << endl;
				   system("pause");
				} 
			   else
			   {
				   cout << "���޴���" << endl;
			   }
			   system("pause");
			   system("cls");
}
//
void find(book* abc)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isexist(abc, name);
	if (ret != -1)
	{
		cout << "\t������" << abc->m[ret].name << "\t�Ա�" << (abc->m[ret].sex == 1 ? "��" : "Ů") << "\t�绰��" << abc->m[ret].phone << endl;
		system("pause");
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//
void M(book* abc)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int i = isexist(abc, name);
	if (i != -1)
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abc->m[i].name = name;
		cout << "�������Ա�" << "1--��" << "2--Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abc->m[i].sex = sex; break;
			}
			cout << "���������������룺" << endl;
		}
		string phone;
		cout << "������绰���룺" << endl;
		cin >> phone;
		abc->m[i].phone = phone;
		cout << "�޸ĳɹ�" << endl;
	}
	else cout << "���޴���" << endl;

	system("pause");
		system("cls");
}
//
void clean(book* abc)
{
	cout << "\t�Ƿ�Ҫ�����ϵ��" << "\tȷ���밴1" << "\tȡ���밴2"<<endl;
	int i = 0;
	cin >> i;
	if (i==1)
	{
		abc->size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	else
	{
		cout << "������ȡ��" << endl;
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
		   cout << "��ӭ�´�ʹ��" << endl;
		   system("pause");
		   return 0;
		   break;
		}
		}
	}
	system("pause");
	return 0;
}