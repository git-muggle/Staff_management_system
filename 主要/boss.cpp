#include "boss.h"

Boss::Boss(string name, int id, int did)
{
	this->w_name = name;
	this->w_id = id;
	this->w_DeptId = did;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->w_id
		<< "\tְ��������" << this->w_name
		<< "\t��λ��" << this->showDeptName()
		<< "\t��λְ�����칫˾����" << endl;
}

string Boss::showDeptName()
{
	return string("�ϰ�");
}
