#include<iostream>
using namespace std;
#include<vector>//����ͷ�ļ�
#include<algorithm>//��׼�㷨ͷ�ļ�
#include<string>
void myprint(int val)
{
	cout << val << endl;
}
void test1()
{
	//����һ��vector����������
	vector<int>v;
	//�������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//ͨ�����������������е�����
	vector<int>::iterator itBegin = v.begin();//��ʼ��������ָ��������һ������
	vector<int>::iterator itEnd = v.end();//������������ָ���������һ������һ��λ��
	//��һ�ֱ�����ʽ
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	cout << endl;
	//�ڶ���
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
	//������,����STL�ṩ�����㷨����Ҫ����#include<algorithm>��׼�㷨ͷ�ļ�

	for_each(v.begin(), v.end(), myprint);
	cout << endl;
}
//vector�����д���Զ�����������
class person
{
public:
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
void test2()
{
	vector<person>v;
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);
	person p4("ddd", 40);
	person p5("eee", 50);
	//���������������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	//��������������
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������"<<it->m_name<<"   ���䣺"<<it->m_age << endl;
		//����cout << "������"<<(*it).m_name<<"   ���䣺"<<(*it).m_age << endl;
	}
}
//����Զ������͵�ָ��
void test3()
{
	vector<person*>v;
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);
	person p4("ddd", 40);
	person p5("eee", 50);
	//���������������   ָ��������&
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	//��������
	for (vector<person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "---������" << (*it)->m_name << "   ���䣺" << (*it)->m_age << endl;
	}
}
//����Ƕ������
void test4()
{
	vector<vector<int>>v;
	//����С����
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	//��С�������������
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	//��С�������������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	//ͨ�������������������ݱ���һ��
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//(*it)---����vector<int>
		for (vector<int>::iterator ve = (*it).begin(); ve != (*it).end(); ve++)
		{
			cout << *ve << "   ";
		}
		cout << endl;
	}
}
//string�������캯��
void test5()
{
	string s1;//Ĭ�Ϲ���
	const char* str = "hello world";
	string s2(str);
	cout << "s2=" << s2 << endl;
	string s3(s2);
	cout << "s3=" << s3 << endl;// ��������
	string s4(10, 'a');
	cout << "s4=" << s4 << endl;
}
//string������ֵ
void test6()
{
	string str1;
	str1 = "hello world";
	cout << "str1=" << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2=" << str2<< endl;

	string s3;
	s3 = 'a';
	cout << "s3=" << s3 << endl;

	string s4;
	s4.assign("hello C++");
	cout << "s4=" << s4 << endl;

	string s5;
	s5.assign("hello C++", 5);//����Ϊ���ǰ������ĸ
	cout << "s5=" << s5 << endl;

	string s6;
	s6.assign(s5);
	cout << "s6=" << s6 << endl;

	string s7;
	s7.assign(7,'d');
	cout << "s7=" << s7 << endl;
}
//string����--�ַ���ƴ��
void test7()
{
	string s1 = "��";
	s1 += "������Ϸ";// ƴ��һ���ַ���
	cout << "s1=" << s1 << endl;
	s1 += ":";//ƴ��һ���ַ�
	cout << "s1=" << s1 << endl;
	string s2 = "LOL CF";
	s1 += s2;
	cout << "s1=" << s1 << endl;
	string s3 = "I";
	s3.assign(" love ");
	cout << "s3=" << s3 << endl;
	s3.assign("game abcd", 4);//��ǰ4��ƴ�ӽ�ȥ
	cout << "s3=" << s3 << endl;
	s3.assign(s2);
	cout << "s3=" << s3 << endl;
	s3.assign(s2, 3, 2);//�����飬�ڼ�����ʼ��ȡ��0 1 ����������ȡ������
	cout << "s3=" << s3 << endl;
}
//string����--���Һ��滻
//����
void test8()
{
	string s1 = "abcdef";
	int p1 = s1.find("de");
	if (p1 == -1)
	{
		cout << "δ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "�ҵ��ַ�����p1=" << p1 << endl;
	}
	//rfind ���������� find ����������
	int p2 = s1.rfind("de");
	cout << "p2=" << p2 << endl;
}
//�滻
void test9()
{
	string s1 = "abcdefg";
	s1.replace(1, 3, "1111");//(���Ǹ�λ�����滻���ٸ����滻Ϊ��
	cout << "s1=" << s1 << endl;
}
//string����--�ַ����Ƚ�
void test10()
{
	string s1 = "hello";
	string s2 = "hello";
	if (s1.compare(s2) == 0)
	{
		cout << "s1=s2" << endl;
	}
	else if (s1.compare(s2) > 0)
	{
		cout << "s1>s2" << endl;
	}
	else cout << "s1<s2" << endl;
}
//string ����--�ַ���ȡ
void test11()
{
	string s1 = "hello";
	//ͨ��[]���ʵ����ַ�
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << "  ";
	}
	cout << endl;
	//ͨ��at��ʽ���ʵ����ַ�
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1.at(i)<< "  ";
	}
	cout << endl;
	//�޸ĵ����ַ�
	s1[0] = 'x';
	cout << "s1=" << s1 << endl;
	s1.at(1) = 'x';
	cout << "s1=" << s1 << endl;
}
//string����--�����ɾ��
void test12()
{
	string s = "world";
	//����
	s.insert(1, "111");//���Ӷ���λ�𣬼���ʲô��
	cout << "s=" << s << endl;
	//ɾ��
	s.erase(1, 4);//���Ӷ���λ��,ɾ��������
	cout << "s=" << s << endl;
}
//strign����--�Ӵ���ȡ
void test13()
{
	string s = "abcdefg";
	string ss = s.substr(3);
	cout << "ss=" << ss << endl;
	//ʵ�� ȡ�û���
	string email = "zhangsanfeng@sina.com";
	int p=email.find("@");
	cout << p << endl;
	string uername = email.substr(0, p);
	cout << uername << endl;
}
int main()
{
	test1();
	test2();
	test3();
	cout << endl;
	test4();
	cout << endl;
	test5();
	cout << endl;
	test6();
	cout << endl;
	test7();
	cout << endl;
	test8();
	cout << endl;
	test9();
	cout << endl;
	test10();
	cout << endl;
	test11();
	cout << endl;
	test12();
	cout << endl;
	test13();
	system("pause");
	return 0;
}