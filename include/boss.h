#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Worker.h"

class Boss :public Worker
{
public:
	Boss(string name, int id, int did);

	virtual void showInfo();//显示个人信息
	virtual string showDeptName();
};