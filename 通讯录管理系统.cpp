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
void reveal(book* abc)
{
	if (abc->size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
		system("pauce");
		system("cls");
	}
	else
	{
		for (int i = 0; i < abc->size; i++)
		{
			cout << "/t������" << abc->m[i].name << "/t�Ա�" << (abc->m[i].sex==1?"��":"Ů")<< "�绰��" << abc->m[i].phone << endl;
			system("pauce");
			system("cls");
		}

	}
}
int isexist(book* abc, string name)
{
	for (int i = 0; i < abc->size; i++)
	{
		if (abc->m[i].name == name)
		{
			return i;
		}
	}
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
		{
		case 3:cout << "������Ҫɾ������ϵ�ˣ�" << endl;
			   string name;
			   cin >> name;
			   if (isexist(&abc, name) == -1)
			   {
				   cout << "���޴���" << endl;
				}
			   else
			   {
				   cout << "�ҵ�����" << endl;
			   }
			   break;
		}
		case 4: break;
		case 5: break;
		case 6: break;
		case 0:cout << "��ӭ�´�ʹ��" << endl; break;
		}
	}
	system("pause");
	return 0;
}