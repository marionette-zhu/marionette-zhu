#include"boss.h"
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_deptid = did;
	this->m_name = name;
}
//��ʾ������Ϣ
void boss::showinfo()
{
	cout << "��ʾְ����ţ�" << this->m_id
		<< "\tְ�����֣�" << this->m_name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ�𣺹���˾��С����" << endl;
}
//��ʾ��λ
string boss::getdeptname()
{
	return string("�ܲ�");
}