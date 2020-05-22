#pragma once
#include<iostream>
using namespace std;


//每个身份都需要进行验证之后，进入子菜单
//学生需要输入：学号、姓名、登录密码
//老师需要输入：职工号、姓名、登录密码
//管理员需要输入：管理员姓名、登录密码


// 利用多态实现每个身份进入之后的登录
class Identity
{
public:
	virtual void open_menu() = 0;
	
	string m_name;   
	string m_password;
};