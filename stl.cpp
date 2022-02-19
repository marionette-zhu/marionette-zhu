#include<iostream>
using namespace std;
#include<vector>//包含头文件
#include<algorithm>//标准算法头文件
#include<string>
void myprint(int val)
{
	cout << val << endl;
}
void test1()
{
	//创建一个vector容器，数组
	vector<int>v;
	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器第一个数据
	vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器最后一个的下一个位置
	//第一种遍历方式
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	cout << endl;
	//第二种
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;
	//第三种,利用STL提供遍历算法，需要保含#include<algorithm>标准算法头文件

	for_each(v.begin(), v.end(), myprint);
	cout << endl;
}
//vector容器中存放自定义数据类型
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
	//向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	//遍历容器中数据
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名："<<it->m_name<<"   年龄："<<it->m_age << endl;
		//或者cout << "姓名："<<(*it).m_name<<"   年龄："<<(*it).m_age << endl;
	}
}
//存放自定义类型的指针
void test3()
{
	vector<person*>v;
	person p1("aaa", 10);
	person p2("bbb", 20);
	person p3("ccc", 30);
	person p4("ddd", 40);
	person p5("eee", 50);
	//向容器中添加数据   指针用引用&
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	//遍历容器
	for (vector<person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "---姓名：" << (*it)->m_name << "   年龄：" << (*it)->m_age << endl;
	}
}
//容器嵌套容器
void test4()
{
	vector<vector<int>>v;
	//创建小容器
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	//向小容器中添加数据
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	//将小容器插入大容器
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	//通过大容器，把所以数据遍历一遍
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//(*it)---容器vector<int>
		for (vector<int>::iterator ve = (*it).begin(); ve != (*it).end(); ve++)
		{
			cout << *ve << "   ";
		}
		cout << endl;
	}
}
//string容器构造函数
void test5()
{
	string s1;//默认构造
	const char* str = "hello world";
	string s2(str);
	cout << "s2=" << s2 << endl;
	string s3(s2);
	cout << "s3=" << s3 << endl;// 拷贝构造
	string s4(10, 'a');
	cout << "s4=" << s4 << endl;
}
//string容器赋值
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
	s5.assign("hello C++", 5);//数组为输出前几个字母
	cout << "s5=" << s5 << endl;

	string s6;
	s6.assign(s5);
	cout << "s6=" << s6 << endl;

	string s7;
	s7.assign(7,'d');
	cout << "s7=" << s7 << endl;
}
//string容器--字符串拼接
void test7()
{
	string s1 = "我";
	s1 += "爱玩游戏";// 拼接一个字符串
	cout << "s1=" << s1 << endl;
	s1 += ":";//拼接一个字符
	cout << "s1=" << s1 << endl;
	string s2 = "LOL CF";
	s1 += s2;
	cout << "s1=" << s1 << endl;
	string s3 = "I";
	s3.assign(" love ");
	cout << "s3=" << s3 << endl;
	s3.assign("game abcd", 4);//将前4个拼接进去
	cout << "s3=" << s3 << endl;
	s3.assign(s2);
	cout << "s3=" << s3 << endl;
	s3.assign(s2, 3, 2);//（数组，第几个开始截取（0 1 ……），截取几个）
	cout << "s3=" << s3 << endl;
}
//string容器--查找和替换
//查找
void test8()
{
	string s1 = "abcdef";
	int p1 = s1.find("de");
	if (p1 == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "找到字符串：p1=" << p1 << endl;
	}
	//rfind 从右往左找 find 从左往右找
	int p2 = s1.rfind("de");
	cout << "p2=" << p2 << endl;
}
//替换
void test9()
{
	string s1 = "abcdefg";
	s1.replace(1, 3, "1111");//(重那个位置起，替换多少个，替换为）
	cout << "s1=" << s1 << endl;
}
//string容器--字符串比较
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
//string 容器--字符存取
void test11()
{
	string s1 = "hello";
	//通过[]访问单个字符
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << "  ";
	}
	cout << endl;
	//通过at方式访问单个字符
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1.at(i)<< "  ";
	}
	cout << endl;
	//修改单个字符
	s1[0] = 'x';
	cout << "s1=" << s1 << endl;
	s1.at(1) = 'x';
	cout << "s1=" << s1 << endl;
}
//string容器--插入和删除
void test12()
{
	string s = "world";
	//插入
	s.insert(1, "111");//（从多少位起，加入什么）
	cout << "s=" << s << endl;
	//删除
	s.erase(1, 4);//（从多少位起,删除几个）
	cout << "s=" << s << endl;
}
//strign容器--子串获取
void test13()
{
	string s = "abcdefg";
	string ss = s.substr(3);
	cout << "ss=" << ss << endl;
	//实用 取用户名
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