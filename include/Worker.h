#pragma once
#include <iostream>
using namespace std;
#include <string>

class Worker
{
public:
	string w_name;
	int w_id;
	int w_DeptId;//������Ϣ

	virtual void showInfo() = 0;//��ʾ������Ϣ
	virtual string showDeptName() = 0;
};

