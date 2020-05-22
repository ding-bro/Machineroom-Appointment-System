#include<iostream>
using namespace std;
#include<stdlib.h>  // system 不明确
#include"machine_room.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"admin.h"
#include"FILE.h"
#include<fstream>



/*
①：
身份简介：
	分别有三种身份使用该程序
		学生代表：申请使用机房
		教师：审核学生的预约申请
		管理员：给学生、教师创建账号

②：
机房简介：
	机房总共有3间
		1号机房---最大容量20人
		2号机房---最多容量50人
		3号机房---最多容量100人

③：
申请简介：
	申请的订单每周由管理员进行清空
	学生可以预约未来一周内的机房使用，预约的日期为周一至周五。预约时需要选择预约时段(上午、下午)
	教师来审核预约，依据实际情况审核预约通过或者不通过

④
系统具体需求：
	首先进入登录界面，可选登录身份有：
		学生代表
		老师
		管理员
		退出

	每个身份都需要进行验证之后，进入子菜单
		学生需要输入：学号、姓名、登录密码
		老师需要输入：职工号、姓名、登录密码
		管理员需要输入：管理员姓名、登录密码

	学生具体功能：
		申请预约---预约机房              // 选择日期 选择时段 选择机房 生成记录至文件
		查看自身预约---查看自己的预约状态   // 显示自己的预约信息
		查看所有预约---查看所有的预约信息以及预约状态  // 查看所有的预约信息
		取消预约---取消自身的预约，预约成功或审核中的预约均可取消  // 根据按键取消自己的某一条预约信息
		注销登录---退出登录

	教师具体功能：
		查看所有预约---查看全部预约信息和预约状态
		审核预约---对学生的预约进行审核   // 审核学生的预约信息
		注销登录---退出登录

	管理员具体功能：
		添加账号---添加学生或者教师的账号，需要检测学生编号或者教师的职工号是否重复   
		查看账号---可以选择查看学生或教师的全部信息
		查看机房---查看所有机房的信息   (机房信息固定)
		清空预约---清空所有的预约记录
		注销登录---退出登录
*/



// 登录函数
void LoginIn(string filename,int number)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在！！！" << endl;
		ifs.close();
		return;
	}

	char d;
	ifs >> d;
	if (ifs.eof())
	{
		cout << "文件内部数据为空！请先添加数据" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}
	ifs.putback(d);  // 注意！！ 读完之后要将char数据放回来


	int id;
	string name;
	string password;
	string ip;

	if (number==1)
	{
		cout << "请输入您的学号！" << endl;
		cin >> id;
	}
	else if (number==2)
	{
		cout << "请输入您的职工号！" << endl;
		cin >> id;
	}

	if (number==1)
	{
		ip = "学生";
	}
	else if (number==2)
	{
		ip = "老师";
	}
	else
	{
		ip = "管理员";
	}

	cout << "请输入您的"<<ip<<"用户名！！！" << endl;
	cin >> name;

	cout << "请输入您的密码！！！" << endl;
	cin >> password;

	if (number==1)
	{
		int sid;
		string sname;
		string spassword;

		while (ifs >> sid && ifs >> sname && ifs >> spassword ) // 读取学生文件里的数据
		{
			if (id== sid &&name== sname &&password== spassword )  // 如果用户输入的数据与文件里的数据一致，验证通过
			{
				cout << "验证成功！！！" << endl;
				system("pasue");
				system("cls");

				person = new Student(id, name, password);  // 存入学生数据

				Student s;
				s.studentmenu(person);

				//Identity* s = new Student;
				//s->open_menu();   // 进去学生身份的子菜单

				//Student s1;

				//int s_select = 0;
				//cin >> s_select;
				//switch (s_select)
				//{
				//case 1:
				//	break;
				//case 2:
				//	break;
				//case 3:
				//	break;
				//case 4:
				//	break;
				//case 5:
				//	s1.s_exit_register();
				//	break;
				//default:
				//	cout << endl;
				//	cout << "请输入有效的按键!!!!!!" << endl;
				//	cout << endl;
				//	system("pause");
				//	system("cls");
				//	break;;
				//	
				//}

			}
			else
			{
				cout << "输入信息验证错误！！！" << endl;
			}
		}
	}
	else if (number==2)
	{
		int tid;
		string tname;
		string tpassword;

		while (ifs >> tid && ifs >> tname && ifs >> tpassword)
		{
			if (id == tid && name == tname && password == tpassword)
			{
				cout << "验证成功！！！" << endl;
				system("pasue");
				system("cls");

				person = new Teacher(id, name, password);

				Teacher t;
				t.teachermenu(person);

				//Identity* t = new Teacher;
				//t->open_menu();    // 进入老师身份的子菜单

				//Teacher t;
				

			//	int t_select = 0;
			//	cin >> t_select;
			//	switch (t_select)
			//	{
			//	case 1:
			//		break;
			//	case 2:
			//		break;
			//	case 3:
			//		t1.t_exit_register();
			//		break;
			//	default:
			//		cout << endl;
			//		cout << "请输入有效的按键!!!!!!" << endl;
			//		cout << endl;
			//		system("pause");
			//		system("cls");
			//		break;
			//	}

			//	//return;
			}
			else
			{
				cout << "输入信息验证错误！！！" << endl;
			}

		}

	}
	else if (number == 3)
	{
		string aname;
		string apassword;

		while (ifs >> aname && ifs >> apassword)
		{
			if (name == aname && password == apassword)
			{
				cout << "验证成功！！！" << endl;
				system("pasue");
				system("cls");

				person = new Admin(name, password);

				Admin a;
				a.adminmenu(person);

				//Identity* a = new Admin;
				//a->open_menu();   // 进入管理员身份的子菜单

				//Admin a1;

				//int a_select = 0;
				//cin >> a_select;
				//switch (a_select)
				//{
				//case 1:
				//	a1.a_add_account();
				//	break;
				//case 2:
				//	a1.a_view_account();
				//	break;
				//case 3:
				//	break;
				//case 4:
				//	break;
				//case 5:
				//	a1.a_exit_register();
				//	break;
				//default:
				//	cout << endl;
				//	cout << "请输入有效的按键!!!!!!" << endl;
				//	cout << endl;
				//	system("pause");
				//	system("cls");
				//	break;
				//}
			}
			else
			{
				cout << "输入信息验证错误！！！" << endl;
			}
		}
	}
	else
	{
		cout << "验证登录失败" << endl;
	}
	system("pause");
	system("cls");
	return;
}




int main()
{
	while (true)
	{
		Identity* s = new Student;
		Identity* t = new Teacher;
		Identity* a = new Admin;

		room r;
		r.show_menu();

		int r_select = 0;
		cin >> r_select;
		switch (r_select)
		{
		case 1:// 学生身份打开
		LoginIn(STUDENT_FILE, 1);
		break;

		/*{
			s->open_menu(); 

			int s_select = 0;
			cin >> s_select;
			switch (s_select)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				cout << endl;
				cout << "请输入有效的按键!!!!!!" << endl;
				cout << endl;
				system("pause");
				system("cls");
				break;
			}
			break;
		}*/

		case 2: // 老师身份打开
		LoginIn(TEACHER_FILE, 2);
		break;

		//{
		//	t->open_menu();
		//	int t_select = 0;
		//	cin >> t_select;
		//	switch (t_select)
		//	{
		//	case 1:
		//		break;
		//	case 2:
		//		break;
		//	case 3:
		//		break;
		//	default:
		//		cout << "请输入有效的按键!!!!!!" << endl;
		//		cout << endl;
		//		system("pause");
		//		system("cls");
		//		break;
		//	}
		//	break;
		//}

		case 3: // 管理员身份打开
		LoginIn(ADMIN_FILE, 3);
		break;

		/*{
			a->open_menu();
			int a_select = 0;
			cin >> a_select;
			switch (a_select)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				cout << "请输入有效的按键!!!!!!" << endl;
				cout << endl;
				system("pause");
				system("cls");
				break;
			}
			break;
		}*/

		case 4:
			r.exit_system();
			break;
		default:
			cout << endl;
			cout << "请输入有效的按键!!!!!!" << endl;
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}