#pragma once;
#include<iostream>
using namespace std;
#include"identity.h"
#include"FILE.h"
#include"machine_room.h"
#include<vector>


//ÿ����ݶ���Ҫ������֤֮�󣬽����Ӳ˵�
//ѧ����Ҫ���룺ѧ�š���������¼����
//��ʦ��Ҫ���룺ְ���š���������¼����
//����Ա��Ҫ���룺����Ա��������¼����

class Student:public Identity
{
public:
	Student();

	Student(int sid,string name,string password);

	virtual void open_menu();  // ѧ����ݵ�¼

	void studentmenu(Identity*& student);

	void s_apply_appointment();  // ����ԤԼ

	void s_view_myself_appointment();   // �鿴�����ԤԼ

	void s_view_all_appointment();  // �鿴���е�ԤԼ

	void s_cancel_myself_appointment(); // ȡ������ԤԼ

	void s_exit_register();  // �˳���¼

	int m_sid;

	vector<room>vr; // �洢������Ϣ������

	void s_init_room(); // ��ʼ��������Ϣ



};