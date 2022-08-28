#include "workerManager.h"
#include "Worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
#include <iostream>

int main()
{
	//Worker* worker = NULL;
	//worker = new Employee("����",101,1);
	//worker->showInfo();
	//delete worker;

	//Worker* manager = NULL;
	//manager = new Manager("����", 100, 2);
	//manager->showInfo();
	//delete manager;

	//Worker* boss = NULL;
	//boss = new Boss("����", 1, 0);
	//boss->showInfo();
	//delete boss;

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "����ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�
			wm.ExitSystem();
			break;
		case 1://����
			wm.Add_Emp();
			break;
		case 2://��ʾ
			wm.Show_Emp();
			break;
		case 3://ɾ��
			wm.Del_Emp();
			break;
		case 4://�޸�
			wm.Mod_Emp();
			break;
		case 5://����
			wm.Find_Emp();
			break;
		case 6://����
			wm.Sort_Emp();
			break;
		case 7://���
			wm.Clean_File();
			break;
		}
	}

	system("pause");
	return 0;
}