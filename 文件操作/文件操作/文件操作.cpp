//ofstreamд������ifstream��������fstream��д����
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
//д�ļ�������ͷ�ļ�#include<fstream>************
void test1()
{
	ofstream ofs;//����������
	ofs.open("test.txt", ios::out);//ָ���򿪷�ʽopen("�ļ�·��",�򿪷�ʽ);ios::outΪд�ļ�
	//д����
	ofs << "������������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺19" << endl;
	//�ر��ļ�
	ofs.close();
}
//���ļ�
void test2()
{
	ifstream ifs;//����������
	//���ļ��ж��Ƿ�򿪳ɹ���ios::inΪ���ļ�
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//�����ݵ�һ��************
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
	/*�ڶ���******************
	char buf[1024] = { 0 };
	while (ifs.geline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}
	*/
	/*������***********************
	string buf;
	while(geline(ifs,buf))
	{
		cout << buf << endl;
	}
	
	*/
	/*
	char c;
	while((c=ifs.get())!=EOF)EOFΪ�ļ�β����־
	{
		cout <<c;
	}
	*/
	//�ر��ļ�
	ifs.close();
}
//������д�ļ� ostream& write(const char * buffer,int len);
class person
{
public:
	char m_name[64];
	int m_age;
};
void test3()
{
	//����������
	ofstream ofs("person.txt", ios::out | ios::binary);//ios::binaryΪ�Զ����Ʒ�ʽд  |�������ַ�ʽ����
	//д�ļ�
	person p = { "������",18 };
	ofs.write((const char*)&p, sizeof(person));
	ofs.close();
}
//�����Ʒ�ʽ���ļ� istream& read(char *buffer,int len);
class Person
{
public:
	char m_name[64];
	int m_age;
};
void test4()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "������" << p.m_name << "����:" << p.m_age;
	ifs.close();
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	system("pasuse");
	return 0;
}