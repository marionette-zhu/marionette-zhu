#include"boss.h"
boss::boss(int id, string name, int did)
{
	this->m_id = id;
	this->m_deptid = did;
	this->m_name = name;
}
//显示个人信息
void boss::showinfo()
{
	cout << "显示职工编号：" << this->m_id
		<< "\t职工名字：" << this->m_name
		<< "\t岗位：" << this->getdeptname()
		<< "\t岗位职责：管理公司大小事务" << endl;
}
//显示岗位
string boss::getdeptname()
{
	return string("总裁");
}