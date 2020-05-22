#pragma once;
#include<iostream>
using namespace std;
#include"identity.h"
#include"FILE.h"
#include"machine_room.h"
#include<vector>


//每个身份都需要进行验证之后，进入子菜单
//学生需要输入：学号、姓名、登录密码
//老师需要输入：职工号、姓名、登录密码
//管理员需要输入：管理员姓名、登录密码

class Student:public Identity
{
public:
	Student();

	Student(int sid,string name,string password);

	virtual void open_menu();  // 学生身份登录

	void studentmenu(Identity*& student);

	void s_apply_appointment();  // 申请预约

	void s_view_myself_appointment();   // 查看自身的预约

	void s_view_all_appointment();  // 查看所有的预约

	void s_cancel_myself_appointment(); // 取消自身预约

	void s_exit_register();  // 退出登录

	int m_sid;

	vector<room>vr; // 存储机房信息的容器

	void s_init_room(); // 初始化机房信息



};