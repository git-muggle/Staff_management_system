#include "workerManager.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"

WorkerManager::WorkerManager()
{
	//不同情况进行初始化
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2、文件存在，但是数据没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，数据也有，需要初始化属性
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据,存到数组中
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "姓名： " << this->m_EmpArray[i]->w_name
	//		<< "职工编号： " << this->m_EmpArray[i]->w_id
	//		<< "部门编号： " << this->m_EmpArray[i]->w_DeptId << endl;
	//}

	//this->m_EmpNum = 0;
	//this->m_EmpArray = NULL;
}

void WorkerManager::Show_Menu()
{
	cout << "********************************************"<< endl;
	cout << "***************欢迎使用职工管理系统*********"<< endl;
	cout << "***************0.退出管理程序***************"<< endl;
	cout << "***************1.增加职工信息***************"<< endl;
	cout << "***************2.显示职工信息***************"<< endl;
	cout << "***************3.删除离职职工***************"<< endl;
	cout << "***************4.修改职工信息***************"<< endl;
	cout << "***************5.查找职工信息***************"<< endl;
	cout << "***************6.按照编号排序***************"<< endl;
	cout << "***************7.清空所有文档***************"<< endl;
	cout << "********************************************"<< endl;
	cout << endl;

}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加的职工数量：" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//旧人数+新人数
		Worker** newSpace = new Worker * [newSize];
		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
		
			cout << "请输入第" << i + 1 << "个新职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(name, id, dSelect);
				break;
			case 2:
				worker = new Manager(name, id, dSelect);
				break;
			case 3:
				worker = new Boss(name, id, dSelect);
				break;
			}
			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		//添加成功提醒
		cout << "成功添加" << addNum << "名新职工" << endl;

		//保存到文件中
		this->save();
	}
	else
	{
		cout << "输入数据有误" << endl;
	}

	//按任意键后清屏，回到上级目录
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->w_name << " "
			<< this->m_EmpArray[i]->w_id << " "
			<< this->m_EmpArray[i]->w_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	
	int num = 0;
	while (ifs >> name&&ifs >> id&& ifs >> did)
	{
		//统计人数
		num++;
	}
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> name && ifs >> id && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)//普通职工
		{
			worker = new Employee(name, id, did);
		}

		else if (did == 2)
		{
			worker = new Manager(name, id, did);
		}

		else
		{
			worker = new Boss(name, id, did);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "无数据可访问" << endl;
	}

	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "没有可供删除的数据" << endl;
	}

	else
	{
		//按照职工编号删除
		cout << "请输入想要删除职工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)
		{
			//for (int i = 0; i < this->m_EmpNum; i++)
			//{
			//	if (this->m_EmpArray[i]->w_id != index)
			//	{
			//		cout << "正在寻找" << endl;
			//	}

			//	else if(this->m_EmpArray[i]->w_id == index)
			//	{
			//		cout << "已找到，正在删除" << endl;
			//		int j = i;
			//		i = m_EmpNum - 1;
			//		for (j; j < this->m_EmpNum ; j++)
			//		{
			//			this->m_EmpArray[j] = this->m_EmpArray[j + 1];
			//		}
			//	}
			//}

			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新删除后数据
			//数据同步更新到文件中
			this->save();
			cout << "删除成功！" << endl;
		}

		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}

	//按任意键 清屏
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->w_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "无可修改数据" << endl;
	}

	else
	{
		cout << "请输入员工编号" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newID;

			cout << "请输入新姓名：" << endl;
			cin >> newName;
			cout << "请输入岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newName, newID, dSelect);
				break;
			case 2:
				worker = new Manager(newName, newID, dSelect);
				break;
			case 3:
				worker = new Boss(newName, newID, dSelect);
				break;
			default:
				break;
			}

			//更新数据
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			//保存到文件中
			this->save();
		}
	
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}

	//按任意键 清屏
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "无可查找数据" << endl;
	}

	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//按编号
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			//加上判断是否查到的标志
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->w_name == name)
				{
					cout << "查找成功，职工编号为："
						<< this->m_EmpArray[i]->w_id
						<< "号职工信息如下：" << endl;

					flag = true;
					//调用显示信息接口
					this->m_EmpArray[i]->showInfo();
				}
			}

			if (flag == false)
			{
				cout << "查找失败，查无此人！" << endl;
			}

		}

		else
		{
			cout << "输入选项有误！" << endl;
		}	
	}
	//按任意键 清屏
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "无可排序数据" << endl;
		system("pause");
		system("cls");
	}

	else
	{
		cout << "请输入排序的方式" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;//申明最小值或最大值下标
			for (int j = i+1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->w_id > this->m_EmpArray[j]->w_id)
					{
						minOrMax = j;
					}
				}

				else//降序
				{
					if (this->m_EmpArray[minOrMax]->w_id < this->m_EmpArray[j]->w_id)
					{
						minOrMax = j;
					}
				}
			}

			//判断一开始认定 最小值或最大值 是不是 计算的最小值或最大值 如果不是 交换数据
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "排序成功！排序结果为：" << endl;
		this->save();//排序后结果保存
		this->Show_Emp();
	}
}

void WorkerManager::Clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//删除堆区的数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");

}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
