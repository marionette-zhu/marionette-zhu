#include<iostream>
using namespace std;
#include<ctime>
int main()
{
	int a = 10, b = 20, c = 0;
	cout << (a && b) << endl;
	cout << (a && c) << endl;
	cout << (a ||b) << endl;
	cout << (a ||c) << endl;
	if (a<b)
	{
		if (a < c)
			cout << a << endl;
		else cout << c << endl;
	}
	int t = 0;
	t = ((a < b) ? a : b);
		cout <<"t=" << t << endl;
		int num = 5;
		while (num < 10)
		{
			cout << num;
			num++;
		}
		cout << num << endl;
		//ˮ����
		do {
			cout << num << endl;
			num++;
		} while (num < 13);

		int n = 100;
		do {
			int a = 0, b = 0, c = 0;
			a = num % 10; b = num / 10 % 10; c = num / 100;
			if (num = a * a * a + b * b * b + c * c * c)
			{
				cout << num << endl;
			}
			num++;
		} while (num < 1000);
		for (int i = 1; i <= 20; i++)
		{
			if (i % 7 == 0 || i % 10 == 7)
			{
				cout << "������" << endl;
			}
			else cout << i << endl;
		}
		for (int t = 0; t < 7; t++)
		{
			for (int p = 0; p <= 7; p++)
			{
				cout << "*";
			}
			cout << endl;
		}
		//�˷��ھ���
		for (int i = 1; i < 9; i++)
		{
			for(int j=1;j<=i;j++)
			{
				cout << j << "*" << i << "=" << j * i <<"  ";
			}
			cout << endl;
		}
		//������
		srand((unsigned int)time(NULL));
		int k=rand( ) % 100+1;
		int val = 0;
		while (1)
		{
			cin >> val;
			if (val > k)
			{
				cout << "�²����" << endl;
			}
			else if (val < k)
			{
				cout << "�²��С" << endl;
			}
			else { cout << "�²���ȷ" << endl; break; }
		}
		int score = 0;
		cin >> score;
		cout << "��������Ϊ��" << score << endl;
		switch (score)
		{
		case 10:
			cout << "����" << endl; break;
		case 9:
			cout << "����" << endl; break;
		case 8:
			cout << "����" << endl; break;
		default:cout << "һ��" << endl; break;
		}

	system("pause");
	return 0;
}