#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"

#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();
	void Show_Menu();
	void ExitSystem();
	int m_EmpNum;//职工人数
	Worker** m_EmpArray;//员工数组指针
	void Add_Emp();//添加员工
	void save();
	bool m_FileIsEmpty;//判断文件是否为空
	int get_EmpNum();//统计文件中人数
	void init_Emp();//初始化员工
	void Show_Emp();//显示员工
	void Del_Emp();//删除职工
	int IsExist(int id);//判断是否存在
	void Mod_Emp();//修改员工
	void Find_Emp();//查找员工
	void Sort_Emp();//排序
	void Clean_File();
	~WorkerManager();
};