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
	this->m_name = name;   // 初始化信息
	this->m_password = password;

	this->a_init(); // 一开始初始化容器

	this->a_init_room();
}

void Admin::open_menu()
{
	cout << "请选择功能按键！！" << endl;
	cout << endl;
	cout << "	----------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << "	|				   1.添加账号" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   2.查看账号" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   3.查看机房" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   4.清空预约" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   5.注销登录" << "                                    |" << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << "	----------------------------------------------------------------------------------" << endl;

}

void Admin::a_init()
{
	vs.clear();  // 清空容器
	vt.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_sid&& ifs >> s.m_name&& ifs >> s.m_password) // 读取文件中的信息
	{
		vs.push_back(s);  // 将学生信息放入当前学生容器中
	}
	cout << "当前学生数量为" << vs.size() << endl;
	ifs.close();


	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_tid&& ifs >> t.m_name&& ifs >> t.m_password)
	{
		vt.push_back(t);
	}
	cout << "当前教师数量为" << vt.size() << endl;
	ifs.close();
}

void Admin::adminmenu(Identity *&admin)
{
	while (true)
	{
		admin->open_menu();

		Admin* a = (Admin*)admin; // 强转为父类指针
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
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Admin::a_add_account()
{
	// 添加账号-- - 添加学生或者教师的账号，需要检测学生编号或者教师的职工号是否重复

	cout << "请输入您要添加账号的对象！" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;

	string filename;
	string input;
	ofstream ofs;

	string error;

	int select = 0;
	cin >> select;

	if (select==1)
	{
		filename = STUDENT_FILE;
		input = "请输入学生学号！";
		error = "学生学号重复，请重新输入！！！";
	}
	else if (select==2)
	{
		filename = TEACHER_FILE;
		input = "请输入老师职工号！";
		error = "老师职工号重复，请重新输入！！！";
	}
	else
	{
		cout << "输入错误！请输入正确的选项" << endl;
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

	cout << "请输入姓名！" << endl;
	cin >> name;

	cout << "请输入密码！" << endl;
	cin >> password;


	ofs << id << " " << name << " " << password << " " << endl;
	cout << "添加成功！！！" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->a_init();
}

bool Admin::a_check_repeat(int id, int number) // number为1,2号，学生或者老师
{
	if (number == 1)  // 学生
	{
		for (vector<Student>::iterator it = vs.begin(); it != vs.end(); it++)
		{
			if (id == it->m_sid) // 如果输入的id与容器里存储学生的id一致，说明是重复
			{
				return true;  // 有重复的返回true
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

	return false;  // 没有重复的返回false
}

void printstudent(Student &s) // 容器打印仿函数
{
	cout <<"学号： "<<s.m_sid<<"名字： " << s.m_name<<" "<<"密码： " << s.m_password << endl;  // ??
}

void printteacher(Teacher& t)
{
	cout << "职工号： " << t.m_tid<< "名字： " << t.m_name <<" "<< "密码： " << t.m_password << endl;  // ??
}

void Admin::a_view_account()
{
	cout << "请输入按键！！！" << endl;
	cout << "1.查看学生身份的全部信息" << endl;
	cout << "2.查看老师身份的全部信息" << endl;

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
	cout << "当前机房数量为： " << vr.size() << endl;
	ifs.close();
}

void printroom(room&r)
{
	cout << "机房序号：" << r.m_rid <<" "<< "机房最大机器容量： " << r.m_max <<"台"<< endl;
	cout << endl;
}

void Admin::a_view_room()
{
	ifstream ifs;
	ifs.open(ROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "机房信息文件不存在！！！" << endl;
		return;
	}

	char d;
	ifs >> d;
	if (ifs.eof())
	{
		cout << "机房内部信息为空！！！" << endl;
		return;
	}
	ifs.putback(d);

	for_each(vr.begin(), vr.end(), printroom);
	
	system("pause");
	system("cls");
}

void Admin::a_empty_appointment()
{
	cout << "是否清空预约？？？" << endl;
	cout << "1.是" << endl;
	cout << "2.否" << endl;
	ofstream ofs;
	int select = 0;
	cin >> select;
	while (true)
	{
		if (select == 1)
		{
			ofs.open(ORDER_FILE, ios::trunc);
			cout << "清空预约信息成功！！！" << endl;
			cout << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "否" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Admin::a_exit_register()
{
	cout << "退出成功！！！" << endl;
	system("pause");
	system("cls");
}



