#include<iostream>
using namespace std;
#include<string>
const double PI = 3.14;
//��װ
class ci
{
public:
	int r;
	double ca()
	{
		return 2 * PI * r;
	}
};
class student
{
public:
	string name;
	int Id=0;
	void show()
	{
		cout << "������" << name << "\tѧ�ţ�" << Id << endl;
	}
public:
	void setname(string name1)
	{
		name = name1;
     }
};
//����Ȩ��
//����Ȩ�� public ���ڣ����ⶼ�ɷ���
//����Ȩ�� protected ���ڿ��ã����ⲻ����
//˽��Ȩ�� private ���ڿ��ã����ⲻ����
//structĬ��Ȩ��Ϊ���� classĬ��Ȩ��Ϊ˽��
class person
{
public:string m_name;
protected:string m_car;
public:int getpass()
{
	m_pass = 16782;
	return m_pass;

};
private:int m_pass;
public:void fun()
	
	{
	m_name = "����";
	m_car = "������";
	m_pass = 16782;
	}
};
//��װ�����尸��
class cube
{
public:
	void setl(int l)
   {
	m_l = l;
   }
	int getl()
	{
		return m_l;
	}
	  void setw(int w)
	  {
		  m_w = w;
	  }
	  int getw()
	  {
		  return m_w;
	  }
	  void seth(int h)
	  {
		  m_h = h;
	  }
	  int geth()
	  {
		  return m_h;
	  }
	  int cas()
	  {
		  return 2 * m_l * m_w + 2 * m_l * m_h + 2 * m_h * m_w;
	  }
	  int cav()
	  {
		  return m_l * m_h * m_w;
	  }
	  //��Ա�����ж�
	  bool issameb(cube& c)
	  {
		  if (m_l == c.getl() && m_w == c.getw() && m_h == c.geth())
		  {
			  return true;
		  }
		  return false;
	  }
	  
private:
	int m_l;
	int m_h;
	int m_w;
};
//ȫ�ֺ����ж�
bool issame(cube& c2, cube& c3)
{
	if (c2.getl() == c3.getl() && c2.getw() == c3.getw() && c2.geth() == c3.geth())
	{
		return true;
	}
	return false;
}
//����Բ�Ĺ�ϵ
class point
{
public:void setx(int x)
{
	m_x = x;
}
	  int getx()
	  {
		  return m_x;
	  }
	  void sety(int y)
	  {
		  m_y = y;
	  }
	  int gety()
	  {
		  return m_y;
	  }
private:int m_x;int m_y;
};
class circle
{
public:
	void setr(int r)
	{
		m_r = r;
	}
	int getr()
	{
		return m_r;
	}
	void setcenter(point center)
	{
		m_center = center;
	}
	point getcenter()
	{
		return m_center;
	}
private:
	int m_r;
	point m_center;
};
void is(circle& c, point& p)
{
	int rd = c.getr() * c.getr();
	int d = (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) + (c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());
	if (rd == d)
	{
		cout << "����Բ��" << endl;
	}
	else if (d > rd)
	{
		cout << "����Բ��" << endl;
	}
	else cout << "����Բ��" << endl;
}
int main()
{
	ci c1;
	c1.r = 10;
	cout << "Բ���ܳ���" << c1.ca() << endl;
	student s1;
	s1.name = "������";
	s1.Id = 5;
	s1.show();
	cout << endl;
	person p1;
	p1.m_name = "������";
	cout << "������\t" << p1.m_name <<"���룺" << p1.getpass();//<<"����\t"<<p1.m_car
	cout << endl;
	cube c2;
	c2.setl(10);
	c2.setw(10);
	c2.seth(10);
	cout << "c2=" << c2.cas() << endl;
	cout << "c2=" << c2.cav() << endl;
	cube c3;
	c3.setl(10);
	c3.setw(10);
	c3.seth(10);
	//ȫ�ֺ����ж�
	bool ret = issame(c2, c3);
	if (ret)
	{
		cout << "ȫ�ֺ����ж�c2=c3" << endl;
	}
	else cout << "ȫ�ֺ����ж�c2!=c3" << endl;
	//��Ա�����ж�
	ret = c2.issameb(c3);
	if (ret)
	{
		cout << "��Ա�����ж�c2=c3" << endl;
	}
	else cout << "��Ա�����ж�c2!=c3" << endl;
	//����Բ
	circle cc;
	cc.setr(10);
	point center;
	center.setx(10);
	center.sety(0);
	cc.setcenter(center);
	//������
	point pp;
	pp.setx(10);
	pp.sety(10);
	is(cc, pp);
	system("pause");
	return 0;
}