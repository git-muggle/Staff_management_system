#include "employee.h"


Employee::Employee(string name, int id, int did)
{
	this->w_name = name;
	this->w_id = id;
	this->w_DeptId = did;
}

void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->w_id
		<< "\tְ��������" << this->w_name
		<< "\t��λ��" << this->showDeptName()
		<< "\t��λְ����ɾ�����������" << endl;
}

string Employee::showDeptName()
{

	return string("Ա��");
}
