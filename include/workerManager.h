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
	int m_EmpNum;//ְ������
	Worker** m_EmpArray;//Ա������ָ��
	void Add_Emp();//���Ա��
	void save();
	bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��
	int get_EmpNum();//ͳ���ļ�������
	void init_Emp();//��ʼ��Ա��
	void Show_Emp();//��ʾԱ��
	void Del_Emp();//ɾ��ְ��
	int IsExist(int id);//�ж��Ƿ����
	void Mod_Emp();//�޸�Ա��
	void Find_Emp();//����Ա��
	void Sort_Emp();//����
	void Clean_File();
	~WorkerManager();
};