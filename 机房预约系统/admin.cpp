#include"admin.h"
#include<fstream>
#include"FILE.h"
#include<algorithm>
#include<vector>


Admin::Admin()
{


}

Admin::Admin(string name, string password)
{
	this->m_name = name;   // ��ʼ����Ϣ
	this->m_password = password;

	this->a_init(); // һ��ʼ��ʼ������

	this->a_init_room();
}

void Admin::open_menu()
{
	cout << "��ѡ���ܰ�������" << endl;
	cout << endl;
	cout << "	----------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << "	|				   1.����˺�" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   2.�鿴�˺�" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   3.�鿴����" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   4.���ԤԼ" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   5.ע����¼" << "                                    |" << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << "	----------------------------------------------------------------------------------" << endl;

}

void Admin::a_init()
{
	vs.clear();  // �������
	vt.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_sid&& ifs >> s.m_name&& ifs >> s.m_password) // ��ȡ�ļ��е���Ϣ
	{
		vs.push_back(s);  // ��ѧ����Ϣ���뵱ǰѧ��������
	}
	cout << "��ǰѧ������Ϊ" << vs.size() << endl;
	ifs.close();


	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_tid&& ifs >> t.m_name&& ifs >> t.m_password)
	{
		vt.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ" << vt.size() << endl;
	ifs.close();
}

void Admin::adminmenu(Identity *&admin)
{
	while (true)
	{
		admin->open_menu();

		Admin* a = (Admin*)admin; // ǿתΪ����ָ��
		int select = 0;

		cin >> select;

		if (select==1)
		{
			a->a_add_account();
		}
		else if (select==2)
		{
			a->a_view_account();
		}
		else if (select==3)
		{
			a->a_view_room();
		}
		else if (select==4)
		{
			a->a_empty_appointment();
		}
		else
		{
			delete admin;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Admin::a_add_account()
{
	// ����˺�-- - ���ѧ�����߽�ʦ���˺ţ���Ҫ���ѧ����Ż��߽�ʦ��ְ�����Ƿ��ظ�

	cout << "��������Ҫ����˺ŵĶ���" << endl;
	cout << "1.ѧ��" << endl;
	cout << "2.��ʦ" << endl;

	string filename;
	string input;
	ofstream ofs;

	string error;

	int select = 0;
	cin >> select;

	if (select==1)
	{
		filename = STUDENT_FILE;
		input = "������ѧ��ѧ�ţ�";
		error = "ѧ��ѧ���ظ������������룡����";
	}
	else if (select==2)
	{
		filename = TEACHER_FILE;
		input = "��������ʦְ���ţ�";
		error = "��ʦְ�����ظ������������룡����";
	}
	else
	{
		cout << "���������������ȷ��ѡ��" << endl;
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string password;
	
	cout << input << endl;
	while (true)
	{
		cin >> id;
		bool ret =this-> a_check_repeat(id, select);
		if (ret)
		{
			cout << error << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룡" << endl;
	cin >> password;


	ofs << id << " " << name << " " << password << " " << endl;
	cout << "��ӳɹ�������" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->a_init();
}

bool Admin::a_check_repeat(int id, int number) // numberΪ1,2�ţ�ѧ��������ʦ
{
	if (number == 1)  // ѧ��
	{
		for (vector<Student>::iterator it = vs.begin(); it != vs.end(); it++)
		{
			if (id == it->m_sid) // ��������id��������洢ѧ����idһ�£�˵�����ظ�
			{
				return true;  // ���ظ��ķ���true
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vt.begin(); it != vt.end(); it++)
		{
			if (id == it->m_tid)
			{
				return true;
			}
		}
	}

	return false;  // û���ظ��ķ���false
}

void printstudent(Student &s) // ������ӡ�º���
{
	cout <<"ѧ�ţ� "<<s.m_sid<<"���֣� " << s.m_name<<" "<<"���룺 " << s.m_password << endl;  // ??
}

void printteacher(Teacher& t)
{
	cout << "ְ���ţ� " << t.m_tid<< "���֣� " << t.m_name <<" "<< "���룺 " << t.m_password << endl;  // ??
}

void Admin::a_view_account()
{
	cout << "�����밴��������" << endl;
	cout << "1.�鿴ѧ����ݵ�ȫ����Ϣ" << endl;
	cout << "2.�鿴��ʦ��ݵ�ȫ����Ϣ" << endl;

	int select = 0;
	cin >> select;
	ifstream ifs;

	if (select == 1)
	{
		for_each(vs.begin(),vs.end(), printstudent);
	}
	else
	{
		for_each(vt.begin(), vt.end(), printteacher);
	}
	system("pause");
	system("cls");
}

void Admin::a_init_room()
{
	ifstream ifs;
	ifs.open(ROOM_FILE, ios::in);

	room r;
	while (ifs >> r.m_rid&& ifs >> r.m_max)
	{
		vr.push_back(r);
	}
	cout << "��ǰ��������Ϊ�� " << vr.size() << endl;
	ifs.close();
}

void printroom(room&r)
{
	cout << "������ţ�" << r.m_rid <<" "<< "���������������� " << r.m_max <<"̨"<< endl;
	cout << endl;
}

void Admin::a_view_room()
{
	ifstream ifs;
	ifs.open(ROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "������Ϣ�ļ������ڣ�����" << endl;
		return;
	}

	char d;
	ifs >> d;
	if (ifs.eof())
	{
		cout << "�����ڲ���ϢΪ�գ�����" << endl;
		return;
	}
	ifs.putback(d);

	for_each(vr.begin(), vr.end(), printroom);
	
	system("pause");
	system("cls");
}

void Admin::a_empty_appointment()
{
	cout << "�Ƿ����ԤԼ������" << endl;
	cout << "1.��" << endl;
	cout << "2.��" << endl;
	ofstream ofs;
	int select = 0;
	cin >> select;
	while (true)
	{
		if (select == 1)
		{
			ofs.open(ORDER_FILE, ios::trunc);
			cout << "���ԤԼ��Ϣ�ɹ�������" << endl;
			cout << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "��" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Admin::a_exit_register()
{
	cout << "�˳��ɹ�������" << endl;
	system("pause");
	system("cls");
}



