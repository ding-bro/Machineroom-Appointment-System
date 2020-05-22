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

	void a_add_account();  // ����˺�

	void a_view_account(); // �鿴�˺�

	void a_view_room();  // �鿴������Ϣ

	void a_empty_appointment();  // ���ԤԼ

	void a_exit_register();  // �˳���¼

	void a_init(); // ��ʼ������

	vector<Student>vs;  // �����洢ѧ������

	vector<Teacher>vt;  // �����洢��ʦ����

	bool a_check_repeat(int id,int number);  // ����Ƿ����ظ���ID���ﵽȥ�ص�Ŀ��

	vector<room>vr;  // �����洢��������Ϣ����

	void a_init_room();  // ��ʼ��������Ϣ

};