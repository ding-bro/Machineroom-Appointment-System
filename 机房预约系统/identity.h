#pragma once
#include<iostream>
using namespace std;


//ÿ����ݶ���Ҫ������֤֮�󣬽����Ӳ˵�
//ѧ����Ҫ���룺ѧ�š���������¼����
//��ʦ��Ҫ���룺ְ���š���������¼����
//����Ա��Ҫ���룺����Ա��������¼����


// ���ö�̬ʵ��ÿ����ݽ���֮��ĵ�¼
class Identity
{
public:
	virtual void open_menu() = 0;
	
	string m_name;   
	string m_password;
};