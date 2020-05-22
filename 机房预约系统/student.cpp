#include"Student.h"
#include<fstream>
#include"order.h"
#include<vector>
#include<stdlib.h>

Student::Student()
{


}

Student::Student(int id,string name,string password)
{
	this->m_sid = id;
	this->m_name = name;
	this->m_password = password;

	this->s_init_room();
}

void Student::s_init_room()
{
	ifstream ifs;
	ifs.open(ROOM_FILE, ios::in);

	room r;
	while (ifs>> r.m_rid && ifs>> r.m_max)
	{
		vr.push_back(r);
	}
	cout << "当前机房数量为： " << vr.size() << endl;
	ifs.close();
}

void Student::open_menu()
{
	cout << "请选择功能按键！！" << endl;
	cout << endl;
	cout << "	----------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << "	|				   1.申请预约" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   2.查看自身预约" << "                                |" << endl;
	cout << endl;
	cout << "	|				   3.查看所有预约" << "                                |" << endl;
	cout << endl;
	cout << "	|				   4.取消预约" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   5.注销登录" << "                                    |" << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << "	----------------------------------------------------------------------------------" << endl;
}

void Student::studentmenu(Identity*& student)
{
	while (true)
	{
		student->open_menu(); // student是父类指针

		Student* s = (Student*)student; // 创建一个子类指针，并且强转为子类指针，操作子类里的对象
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			s->s_apply_appointment();
		}
		else if (select == 2)
		{
			s->s_view_myself_appointment();
		}
		else if (select == 3)
		{
			s->s_view_all_appointment();
		}
		else if (select == 4)
		{
			s->s_cancel_myself_appointment();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void Student::s_apply_appointment()
{
	while (true)
	{
		cout << "请选择日期： " << endl;
		cout << "1.周一" << endl;
		cout << "2.周二" << endl;
		cout << "3.周三" << endl;
		cout << "4.周四" << endl;
		cout << "5.周五" << endl;
		int date = 0;
		cin >> date;
		if (date > 5 | date < 1)
		{
			cout << "请输入有效的日期按键！！！" << endl;
			system("pause");
			system("cls");
			break;
		}

		cout << "请选择时段： " << endl;
		cout << "1.上午" << endl;
		cout << "2.下午" << endl;
		int time = 0;
		cin >> time;
		if (time > 2 | time < 1)
		{
			cout << "请输入有效的时段按键！！！" << endl;
			system("pause");
			system("cls");
			break;;
		}
	
		cout << "请选择机房: " << endl;
		cout << "1.一号机房" << endl;
		cout << "2.二号机房" << endl;
		cout << "3.三号机房" << endl;
		int machine = 0;
		cin >> machine;
		if (machine > 3 | machine < 1)
		{
			cout << "请输入正确的机房按键！！！" << endl;
			system("pause");
			system("cls");
			break;
		}

		string date1;
		string time1;
		//string status;// = "预约状态：";
		if (date==1)
		{
			date1 = "周一";
		}
		else if (date == 2)
		{
			date1 = "周二";
		}
		else if (date == 3)
		{
			date1 = "周三";
		}
		else if (date == 4)
		{
			date1 = "周四";
		}
		else if (date == 6)
		{
			date1 = "周五";
		}

		if (time==1)
		{
			time1 = "上午";
		}
		else if (time==2)
		{
			time1 = "下午";
		}

		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::app);
		//ofs << "日期选择序号： " << date1 << endl;
		//ofs << "时段选择序号： " << time1 << endl;
		//ofs << "机房选择序号： " << machine <<"号"<< endl;
		//ofs << "学生学号： " << this->m_sid << endl;
		//ofs << "学生姓名： " << this->m_name << endl;
		//ofs << status << "1"<<endl;							中文截取读取不出，写文件时写入英文
	
		ofs << "date:" << date << " ";
		ofs << "time:" << time << " ";
		ofs << "roomid:" << machine << " ";
		ofs << "studentid:" << this->m_sid << " ";
		ofs << "studentname:" << this->m_name << " ";
		ofs << "status:" << "1" << " ";
		ofs << endl;
		ofs.close();
		break;
	}
	cout << "预约成功，教师审核中！！！" << endl;
	system("pause");
	system("cls");
}

void Student::s_view_myself_appointment()
{
	order(); // 显示数据
	order o;
	if (o.o_size==0)
	{
		cout << "无预约记录！！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < o.o_size; i++)
	{
		// 用学号来判断是否是自身的预约
		if (atoi(o.m_order[i]["studentid"].c_str())==this->m_sid) // 用atoi，c_str方法将string类型转为C语言风格的int类型
		{
			cout << "预约日期: 周" << o.m_order[i]["date"] << endl;
			cout << "预约时段: " << (o.m_order[i]["time"] == "1" ? "上午" : "下午") << endl;// time如果==1 上午，否则下午
			cout << "预约机房序号: " << o.m_order[i]["roomid"] <<"号机房"<< endl;;
			cout << "学生学号: " << o.m_order[i]["studentid"] << endl;
			cout << "学生姓名: " << o.m_order[i]["studentname"] << endl;
			string status = "预约状态: ";
			if (o.m_order[i]["status"]=="1")
			{
				status += "审核中";
			}
			else if (o.m_order[i]["status"]=="2")
			{
				status += "审核完成";
			}
			else if (o.m_order[i]["status"] == "-1")
			{
				status += "审核未通过";
			}
			else 
			{
				status += "审核已取消";
			}
			cout << status << endl;
			cout << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

void Student::s_view_all_appointment()
{
	//order(); // 显示数据
	order o;
	if (o.o_size == 0)
	{
		cout << "无预约记录！！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 1; i < o.o_size; i++)  // 实验得i从1开始,不然会打印一次空消息
	{
		cout << "预约日期: 周" << o.m_order[i]["date"] << endl;
		cout << "预约时段: " << (o.m_order[i]["time"] == "1" ? "上午" : "下午") << endl;// time如果==1 上午，否则下午
		cout << "预约机房序号: " << o.m_order[i]["roomid"] << "号机房" << endl;;
		cout << "学生学号: " << o.m_order[i]["studentid"] << endl;
		cout << "学生姓名: " << o.m_order[i]["studentname"] << endl;
		string status = "预约状态: ";
		if (o.m_order[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (o.m_order[i]["status"] == "2")
		{
			status += "审核完成";
		}
		else if (o.m_order[i]["status"] == "-1")
		{
			status += "审核未通过";
		}
		else
		{
			status += "审核已取消";
		}
		cout << status << endl;
		cout << endl;
	}
	system("pause");
	system("cls");
	return;
}

void Student::s_cancel_myself_appointment()
{
	order o;
	if (o.o_size==0)
	{
		cout << "订单文件中无数据！！！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "您正在进行取消预约记录的操作！！！！" << endl;

	vector<int>v;  // 创建存放自身信息的容器
	int index = 1;  // 创建预约信息的下标  下标从1开始

	for (int i = 0; i < o.o_size; i++)
	{
		if (atoi(o.m_order[i]["studentid"].c_str()) == this->m_sid)  // 同理将字符串转换为C语言风格的int类型作比较
		{
			if (o.m_order[i]["status"] == "1" || o.m_order[i]["status"] == "2")  // 将status预约状态作为选择媒介进行取消操作
			{
				v.push_back(i); // 将信息放入容器中

				cout << index++ << "、" << endl;
				cout << "预约日期: 周" << o.m_order[i]["date"] << endl;
				cout << "预约时段: " << (o.m_order[i]["time"] == "1" ? "上午" : "下午") << endl;// time如果==1 上午，否则下午
				cout << "预约机房序号: " << o.m_order[i]["roomid"] << "号机房" << endl;;
				cout << "学生学号: " << o.m_order[i]["studentid"] << endl;
				cout << "学生姓名: " << o.m_order[i]["studentname"] << endl;
				string status = "状态: ";
				if (o.m_order[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (o.m_order[i]["status"] == "2")
				{
					status += "审核完成";
				}
				else if (o.m_order[i]["status"] == "-1")
				{
					status += "审核未通过";
				}
				else
				{
					status += "审核已取消";
				}
				cout << status << endl;
				cout << endl;
			}
		}
	}

	cout << "请输入您要取消记录的序号！！！" <<"按键0代表返回！！！"<< endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select>0 && select<=v.size())  // 输入的值小于等于容器大小值
		{
			if (select == 0)
			{
				cout << "返回成功！！！" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				o.m_order[v[select - 1]]["status"] = "0";  // 在文件中的下表是从1开始，而在vector容器中的下标是从0开始
				// 所以select-1是为了准确定位容器中要删除的预约信息的位置,并且当两条信息意外一样时，也可以定位

				o.updateorder(); // ????? bug  文件中多重写了一次(未解决)
				cout << "已取消预约！！！" << endl;
				break;
			}
		}
		cout << "请输入正确的序号！！！" << endl;
	}
	system("pause");
	system("cls");
}

void Student::s_exit_register()
{
	cout << "退出成功！！！" << endl;
	system("pause");
	system("cls");
}
