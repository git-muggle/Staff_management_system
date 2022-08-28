#include "employee.h"


Employee::Employee(string name, int id, int did)
{
	this->w_name = name;
	this->w_id = id;
	this->w_DeptId = did;
}

void Employee::showInfo()
{
	cout << "职工编号：" << this->w_id
		<< "\t职工姓名：" << this->w_name
		<< "\t岗位：" << this->showDeptName()
		<< "\t岗位职责：完成经理交代的任务" << endl;
}

string Employee::showDeptName()
{

	return string("员工");
}
