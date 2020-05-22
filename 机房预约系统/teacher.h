#pragma once
#include<iostream>
using namespace std;
#include"identity.h"


class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int tid,string name, string password);

	virtual void open_menu(); // 老师身份登录

	void teachermenu(Identity*& teacher);

	void t_view_all_appointment();

	void t_verify_appointment();  // 审核预约

	void t_exit_register();

	int m_tid;
};