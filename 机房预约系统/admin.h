#include<iostream>
using namespace std;
#include"identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"machine_room.h"




class Admin :public Identity
{
public:
	Admin();

	Admin(string name, string password);

	virtual void open_menu();

	void adminmenu(Identity*& admin);

	void a_add_account();  // 添加账号

	void a_view_account(); // 查看账号

	void a_view_room();  // 查看机房信息

	void a_empty_appointment();  // 清空预约

	void a_exit_register();  // 退出登录

	void a_init(); // 初始化容器

	vector<Student>vs;  // 建立存储学生容器

	vector<Teacher>vt;  // 建立存储老师容器

	bool a_check_repeat(int id,int number);  // 检查是否有重复的ID，达到去重的目的

	vector<room>vr;  // 建立存储机房的信息容器

	void a_init_room();  // 初始化机房信息

};