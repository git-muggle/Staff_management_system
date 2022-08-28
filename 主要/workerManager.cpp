#include "workerManager.h"
#include "boss.h"
#include "manager.h"
#include "employee.h"

WorkerManager::WorkerManager()
{
	//��ͬ������г�ʼ��
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2���ļ����ڣ���������û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ�����Ҳ�У���Ҫ��ʼ������
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е�����,�浽������
	this->init_Emp();

	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "������ " << this->m_EmpArray[i]->w_name
	//		<< "ְ����ţ� " << this->m_EmpArray[i]->w_id
	//		<< "���ű�ţ� " << this->m_EmpArray[i]->w_DeptId << endl;
	//}

	//this->m_EmpNum = 0;
	//this->m_EmpArray = NULL;
}

void WorkerManager::Show_Menu()
{
	cout << "********************************************"<< endl;
	cout << "***************��ӭʹ��ְ������ϵͳ*********"<< endl;
	cout << "***************0.�˳��������***************"<< endl;
	cout << "***************1.����ְ����Ϣ***************"<< endl;
	cout << "***************2.��ʾְ����Ϣ***************"<< endl;
	cout << "***************3.ɾ����ְְ��***************"<< endl;
	cout << "***************4.�޸�ְ����Ϣ***************"<< endl;
	cout << "***************5.����ְ����Ϣ***************"<< endl;
	cout << "***************6.���ձ������***************"<< endl;
	cout << "***************7.��������ĵ�***************"<< endl;
	cout << "********************************************"<< endl;
	cout << endl;

}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "��������ӵ�ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//������+������
		Worker** newSpace = new Worker * [newSize];
		//��ԭ���ռ������ݣ��������¿ռ���
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

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
		
			cout << "�������" << i + 1 << "����ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//��ӳɹ�����
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//���浽�ļ���
		this->save();
	}
	else
	{
		cout << "������������" << endl;
	}

	//����������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�

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
		//ͳ������
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
		if (did == 1)//��ְͨ��
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
		cout << "�����ݿɷ���" << endl;
	}

	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
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
		cout << "û�пɹ�ɾ��������" << endl;
	}

	else
	{
		//����ְ�����ɾ��
		cout << "��������Ҫɾ��ְ����ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)
		{
			//for (int i = 0; i < this->m_EmpNum; i++)
			//{
			//	if (this->m_EmpArray[i]->w_id != index)
			//	{
			//		cout << "����Ѱ��" << endl;
			//	}

			//	else if(this->m_EmpArray[i]->w_id == index)
			//	{
			//		cout << "���ҵ�������ɾ��" << endl;
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
			this->m_EmpNum--;//����ɾ��������
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}

		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}

	//������� ����
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
		cout << "�޿��޸�����" << endl;
	}

	else
	{
		cout << "������Ա�����" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newID;

			cout << "��������������" << endl;
			cin >> newName;
			cout << "�������λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

			//��������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			//���浽�ļ���
			this->save();
		}
	
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}

	//������� ����
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�޿ɲ�������" << endl;
	}

	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//�����
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			//�����ж��Ƿ�鵽�ı�־
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->w_name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< this->m_EmpArray[i]->w_id
						<< "��ְ����Ϣ���£�" << endl;

					flag = true;
					//������ʾ��Ϣ�ӿ�
					this->m_EmpArray[i]->showInfo();
				}
			}

			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}

		}

		else
		{
			cout << "����ѡ������" << endl;
		}	
	}
	//������� ����
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�޿���������" << endl;
		system("pause");
		system("cls");
	}

	else
	{
		cout << "����������ķ�ʽ" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;//������Сֵ�����ֵ�±�
			for (int j = i+1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->w_id > this->m_EmpArray[j]->w_id)
					{
						minOrMax = j;
					}
				}

				else//����
				{
					if (this->m_EmpArray[minOrMax]->w_id < this->m_EmpArray[j]->w_id)
					{
						minOrMax = j;
					}
				}
			}

			//�ж�һ��ʼ�϶� ��Сֵ�����ֵ �ǲ��� �������Сֵ�����ֵ ������� ��������
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "����ɹ���������Ϊ��" << endl;
		this->save();//�����������
		this->Show_Emp();
	}
}

void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

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

			//ɾ������������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
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
