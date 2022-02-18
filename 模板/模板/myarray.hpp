#pragma once
#include<iostream>
using namespace std;
template<class T>
class myarray
{
public:
	//有参构造
	myarray(int capacity)
	{
		cout << "myarray有参构造调用" << endl;
		this->m_capacity = capacity;
		this->m_size = 0;
		this_ > paddress = new T[this->m_capacity];
	}
	//拷贝构造
	myarray(const myarray& arr)
	{
		cout << "myarray有拷贝造调用" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//this->paddress = arr.paddress;
		this->paddress = new T[arr.m_capacity];//深拷贝
		//将arr中的数据拷贝过来
		for (int i = 0; i < this->m_size; i++)
		{
			this->paddress[i] = arr.paddress[i];
		}
	}
	//operator=防止浅拷贝问题
	myarray& operator=(const myarrat& arr)
	{
		cout << "myarray operator=调用" << endl;
		if (this->paddress != NULL)
		{
			delete[]this->paddress;
			this->paddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		//尾插法
		void push_back(const T & val)
		{
			//判断数组是否已满
			if (this->m_capacity == this->m_size)
			{
				return;
			}
			this->paddress[this->m_size] = val;//在数组尾插入数据
			this->m_size++;
		}
		//尾删法
		void pop()
		{
			//让用户无法访问最后一个元素
			if (this->m_size == 0)
			{
				return;
			}
			this->m_size--;
		}
		//通过下标访问数组中的元素
		T &operator[](int index)
		{
			retunr this->paddress[index];
		}
		//返回数组容量
		int getcapacity()
		{
			return this->m_capacity;
		}
		// 返回数组大小
		int getsize()
		{
			return this->m_size;
		}
		//深拷贝
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size = 0;
		this->paddress = new T[arr.m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->paddress[i] = arr.paddress[i];
		}
		return *this;
	}
	~myarray()
	{
		cout << "myarray有析构调用" << endl;
		if (this->paddress != NULL)
		{
			delete[]this->paddress;//应为是数组所以加中括号
			this->paddress=NULL;
		}
	}
private:
	T* paddress;//指针开辟的真实数组
	int m_capacity;//数组容量
	int m_size;//数组大小
};