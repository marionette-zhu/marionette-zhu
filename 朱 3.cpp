#include<iostream>
using namespace std;
int main()
{
	for (int i = 0; i <= 10; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		cout << i << "  ";
	}
	cout << endl;
	cout <<"* ****"<< endl;
	cout << "* ****" << endl;
	goto en;
	cout << "* ****" << endl;
	cout << "* ****" << endl;
en:cout << "&&&&&&" << endl;
	//һά����
	int arr[] = { 1,2,3,4,5 };
	cout << arr << endl;
	cout << (int)arr[0] << endl;
	cout << (int)sizeof(arr[1]) << endl;
	int brr[5] = { 100,200,20,40,500 };
	int max = 0;
	for (int i = 0; i < 5; i++)
		if (max < brr[i ])
		{
			max = brr[i];
		}
	cout << max << endl;
	//����
	int c[5] = { 7,8,5,2,3 };
	cout << "ԭ����˳��Ϊ��" ;
	for(int i=0;i<5;i++)
	{
		cout << c[i] ;
	}
	cout << endl;
	for(int i = 0;i<2;i++)
	{
		int t=c[i]; c[i] = c[4 - i]; c[4 - i]=t;
	}
	cout << "���ڵ�˳��Ϊ��" ;
		for (int i = 0; i < 5; i++)
		{
			cout << c[i];
		}
//ð�ݷ�����
		int d[] = { 4,2,8,0,5,7,1,3,9 };
		cout << "����ǰ��";
		for (int i = 0; i < 9; i++)
		{
			cout << d[i];
		}
		cout << endl;
		cout << "�����:";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8 - i; j++)
			{
				if (d[j] > d[j + 1])
				{
					int p = d[j]; d[j] = d[j + 1]; d[j + 1] = p;
				}

			}
		}
		for (int i = 0; i < 9; i++)
		{
			cout << d[i];
		}
		cout << endl;
		//��ά����
		int a[2][3] = { {1,2,3},{4,5,6} };
		for (int i = 0; i < 2; i++) 
		{ 
			for (int j=0; j < 3; j++)
			{
				cout << a[i][j] <<"  ";
		}
			cout << endl;
		}
		cout << sizeof(a) << endl;
		cout << &a[2][3] << endl;

	system("pause");
	return 0;
}