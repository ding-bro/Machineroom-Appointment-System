#pragma once
#include<iostream>
using namespace std;
#include"identity.h"


class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int tid,string name, string password);

	virtual void open_menu(); // ��ʦ��ݵ�¼

	void teachermenu(Identity*& teacher);

	void t_view_all_appointment();

	void t_verify_appointment();  // ���ԤԼ

	void t_exit_register();

	int m_tid;
};