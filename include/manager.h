#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Worker.h"

class Manager :public Worker
{
public:
	Manager(string name, int id, int did);

	virtual void showInfo();//��ʾ������Ϣ
	virtual string showDeptName();
};