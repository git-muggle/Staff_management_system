#pragma once
#include <iostream>
using namespace std;
#include <string>

class Worker
{
public:
	string w_name;
	int w_id;
	int w_DeptId;//部门信息

	virtual void showInfo() = 0;//显示个人信息
	virtual string showDeptName() = 0;
};

