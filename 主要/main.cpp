#include "workerManager.h"
#include "Worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
#include <iostream>

int main()
{
	//Worker* worker = NULL;
	//worker = new Employee("张三",101,1);
	//worker->showInfo();
	//delete worker;

	//Worker* manager = NULL;
	//manager = new Manager("李四", 100, 2);
	//manager->showInfo();
	//delete manager;

	//Worker* boss = NULL;
	//boss = new Boss("王五", 1, 0);
	//boss->showInfo();
	//delete boss;

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "输入选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出
			wm.ExitSystem();
			break;
		case 1://增加
			wm.Add_Emp();
			break;
		case 2://显示
			wm.Show_Emp();
			break;
		case 3://删除
			wm.Del_Emp();
			break;
		case 4://修改
			wm.Mod_Emp();
			break;
		case 5://查找
			wm.Find_Emp();
			break;
		case 6://排序
			wm.Sort_Emp();
			break;
		case 7://清空
			wm.Clean_File();
			break;
		}
	}

	system("pause");
	return 0;
}