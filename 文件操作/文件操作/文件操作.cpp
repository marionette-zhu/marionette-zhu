//ofstream写操作，ifstream读操作，fstream读写操作
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
//写文件，包含头文件#include<fstream>************
void test1()
{
	ofstream ofs;//创建流对象
	ofs.open("test.txt", ios::out);//指定打开方式open("文件路径",打开方式);ios::out为写文件
	//写内容
	ofs << "姓名：张三丰" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：19" << endl;
	//关闭文件
	ofs.close();
}
//读文件
void test2()
{
	ifstream ifs;//创建流对象
	//打开文件判断是否打开成功，ios::in为读文件
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//读数据第一种************
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
	/*第二种******************
	char buf[1024] = { 0 };
	while (ifs.geline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}
	*/
	/*第三种***********************
	string buf;
	while(geline(ifs,buf))
	{
		cout << buf << endl;
	}
	
	*/
	/*
	char c;
	while((c=ifs.get())!=EOF)EOF为文件尾部标志
	{
		cout <<c;
	}
	*/
	//关闭文件
	ifs.close();
}
//二进制写文件 ostream& write(const char * buffer,int len);
class person
{
public:
	char m_name[64];
	int m_age;
};
void test3()
{
	//创建流对象
	ofstream ofs("person.txt", ios::out | ios::binary);//ios::binary为以二进制方式写  |用于两种方式链接
	//写文件
	person p = { "张三丰",18 };
	ofs.write((const char*)&p, sizeof(person));
	ofs.close();
}
//二进制方式读文件 istream& read(char *buffer,int len);
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
		cout << "文件打开失败" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名：" << p.m_name << "年龄:" << p.m_age;
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