#include<iostream>
using namespace std;
#include<string>
//thisָ��ָ�����޸ģ�ָ���ֵ���Ը�
class person
{
public:
	person(int age)
	{
		this->age = age;//��������ͬ������
	}
	person& personadd(person& p)
	{
		this->age += p.age;
		return *this;//���ض�������*this
	 }
	int age;
};
void test1()
{
	person p1(18);
	cout << "p1������Ϊ��" << p1.age << endl;
}
void test2()
{
	person p1(10);
	person p2(10);
	p2.personadd(p1).personadd(p1);
	cout << "p2������Ϊ" << p2.age << endl;
}
//��ָ����ó�Ա����
class per
{
public:
	void showclassname()
	{
		cout << "this is per class" << endl;
	}
	void showperage()
	{
		if (this == NULL)//��ֹ���б���
		{
			return;
		}
		cout << "age=" <<m_age << endl;
	}
	int m_age;
};
void test3()
{
	per* p = NULL;
	p->showperage();
}
//const���γ�Ա������ֹ���޸�
class Person
{
public:
	void showPerson()const//�����const��Ϊ������
	{
		this->m_b = 100;
	}
	int m_a;
	mutable int m_b;//mutable��������������Ҳ�����޸�
};
void test4()
{
	Person p;
	p.showPerson();
}
void test5()
{
	const Person p;//����ǰ����const����Ϊ������
	//p.m_a = 100;
	p.m_b = 100;
	//������ֻ�ܵ��ó�����
	p.showPerson();

}
//��Ԫ
class building
{
	friend void good(building* building);//+firend����������Է���
public:
	building()
	{
		m_sit = "����";
		m_bed = "����";
	}
public:	string m_sit;
private:	string m_bed;

};
//ȫ�ֺ�������Ԫ
void good(building* building)
{
	cout << "���������ڷ���:" << building->m_sit << endl;
	cout << "���������ڷ���:" << building->m_bed << endl;//�ʼ��friend
}
void test6()
{
	building building;
	good(&building);
}
//������Ԫ
class Building;
class Good
{
public:
	Good();
	void visit();
	Building* building;
};
class Building
{
	friend class Good;//�ô�����Է���˽�еĳ�Ա
public:Building();
public:	string m_sit;
private:	string m_bed;
};
Building::Building()
{
	m_sit = "����";
	m_bed = "����";
}
Good::Good()
{
	//�������������
	building = new Building;
}
void Good::visit()
{
	cout << "���������ڷ��ʣ�" << building->m_sit << endl;
	cout << "���������ڷ��ʣ�" << building->m_bed << endl;
}
void test7()
{
	Good gg;
	gg.visit();
}
//��Ա��������Ԫ
class B;
class goodgay
{
public:
	goodgay();
	void visit();//���������
	void visit2();//�����Է���˽��
	B* b;

};
class B
{
	friend void goodgay::visit();//�ô�����Է���˽�еĳ�Ա
public:B();
public:	string m_sit;
private:	string m_bed;
};
B::B()
{
	m_sit = "����";
	m_bed = "����";
}
goodgay::goodgay()
{
	//�������������
	b = new B;
}
void goodgay::visit()
{
	cout << "visit�������ڷ��ʣ�" << b->m_sit << endl;
	cout << "visit�������ڷ��ʣ�" << b->m_bed << endl;
}//���������
void goodgay::visit2()
{
	cout << "visit2�������ڷ��ʣ�" << b->m_sit << endl;
}//�����Է���˽��
void test8()
{
	goodgay g;
	g.visit();
	g.visit2();
}
//���������
class son
{
public:
	//��Ա��������
	son operator+(son &s)
	{
		son temp;
		temp.m_c = this->m_c + m_c;
		temp.m_d = this->m_d + m_d;
		return temp;
	}
	/*son operator+(son& s1, int num)
	{
		son temp;
		temp.m_c = s1.m_c + num;
		temp.m_d = s1.m_d + num;
		return temp;
	}*/
	int m_c;
	int m_d;
};
void test9()
{
	son s1;
	s1.m_c = 10;
	s1.m_d = 10;
	son s2;
	s2.m_c=10;
	s2.m_d = 10;
	son s3 = s1+s2;
	cout << "s3.m_c=" << s3.m_c << endl;
	cout << "s3.m_d=" << s3.m_d<<endl;

}
//ȫ�ֺ�������
//son operator+(son& s1, son& s2)
//{
//	son temp;
//	temp.m_c = s1.m_c +s2. m_c;
//	temp.m_d = s1.m_d + s2.m_d;
//	return temp;
//}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	cout << endl;
	test7();
	test8();
	test9();
	system("pause");
	return 0;
}