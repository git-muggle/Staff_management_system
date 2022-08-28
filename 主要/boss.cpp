#include "boss.h"

Boss::Boss(string name, int id, int did)
{
	this->w_name = name;
	this->w_id = id;
	this->w_DeptId = did;
}

void Boss::showInfo()
{
	cout << "职工编号：" << this->w_id
		<< "\t职工姓名：" << this->w_name
		<< "\t岗位：" << this->showDeptName()
		<< "\t岗位职责：总领公司事务" << endl;
}

string Boss::showDeptName()
{
	return string("老板");
}
