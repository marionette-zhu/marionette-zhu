#pragma once
#include<iostream>
using namespace std;
template<class T>
class myarray
{
public:
	//�вι���
	myarray(int capacity)
	{
		cout << "myarray�вι������" << endl;
		this->m_capacity = capacity;
		this->m_size = 0;
		this_ > paddress = new T[this->m_capacity];
	}
	//��������
	myarray(const myarray& arr)
	{
		cout << "myarray�п��������" << endl;
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		//this->paddress = arr.paddress;
		this->paddress = new T[arr.m_capacity];//���
		//��arr�е����ݿ�������
		for (int i = 0; i < this->m_size; i++)
		{
			this->paddress[i] = arr.paddress[i];
		}
	}
	//operator=��ֹǳ��������
	myarray& operator=(const myarrat& arr)
	{
		cout << "myarray operator=����" << endl;
		if (this->paddress != NULL)
		{
			delete[]this->paddress;
			this->paddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		//β�巨
		void push_back(const T & val)
		{
			//�ж������Ƿ�����
			if (this->m_capacity == this->m_size)
			{
				return;
			}
			this->paddress[this->m_size] = val;//������β��������
			this->m_size++;
		}
		//βɾ��
		void pop()
		{
			//���û��޷��������һ��Ԫ��
			if (this->m_size == 0)
			{
				return;
			}
			this->m_size--;
		}
		//ͨ���±���������е�Ԫ��
		T &operator[](int index)
		{
			retunr this->paddress[index];
		}
		//������������
		int getcapacity()
		{
			return this->m_capacity;
		}
		// ���������С
		int getsize()
		{
			return this->m_size;
		}
		//���
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
		cout << "myarray����������" << endl;
		if (this->paddress != NULL)
		{
			delete[]this->paddress;//ӦΪ���������Լ�������
			this->paddress=NULL;
		}
	}
private:
	T* paddress;//ָ�뿪�ٵ���ʵ����
	int m_capacity;//��������
	int m_size;//�����С
};