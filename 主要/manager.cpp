#include "manager.h"

Manager::Manager(string name, int id, int did)
{
	this->w_name = name;
	this->w_id = id;
	this->w_DeptId = did;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->w_id
		<< "\t职工姓名：" << this->w_name
		<< "\t岗位：" << this->showDeptName()
		<< "\t岗位职责：完成老板交代的任务，并安排、下发任务" << endl;
}

string Manager::showDeptName()
{
	return string("经理");
}
