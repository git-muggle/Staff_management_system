#include "manager.h"

Manager::Manager(string name, int id, int did)
{
	this->w_name = name;
	this->w_id = id;
	this->w_DeptId = did;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->w_id
		<< "\tְ��������" << this->w_name
		<< "\t��λ��" << this->showDeptName()
		<< "\t��λְ������ϰ彻�������񣬲����š��·�����" << endl;
}

string Manager::showDeptName()
{
	return string("����");
}
