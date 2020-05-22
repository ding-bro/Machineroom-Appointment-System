#include"teacher.h"
#include"student.h"
#include"order.h"
#include<vector>



Teacher::Teacher()
{


}

Teacher::Teacher(int id,string name,string password)
{



}

void Teacher::open_menu()
{
	cout << "请选择功能按键！！" << endl;
	cout << endl;
	cout << "	----------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << "	|				   1.查看所有预约" << "                                |" << endl;
	cout << endl;
	cout << "	|				   2.审核预约" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   3.注销登录" << "                                    |" << endl;
	cout << endl;
	cout << "	----------------------------------------------------------------------------------" << endl;
}

void Teacher::teachermenu(Identity *&teacher)
{
	while (true)
	{
		teacher->open_menu();

		Teacher* t = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			t->t_view_all_appointment();
		}
		else if (select == 2)
		{
			t->t_verify_appointment();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Teacher::t_view_all_appointment()
{
	//Student s;
	//s.s_view_all_appointment();
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
		cout << i + 1 << "、" << endl;
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
		else if(o.m_order[i]["status"]=="-1")
		{
			status += "审核为通过！！！";
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

void Teacher::t_verify_appointment()
{
	order o;
	if (o.o_size==0)
	{
		cout << "无预约记录！！！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约信息如下: " << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < o.o_size; i++)
	{
		if (o.m_order[i]["status"]=="1")  // 预约状态为1的是待审核
		{
			v.push_back(i);  // 将信息放入容器中

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
			cout << status << endl;
		}
	}

	cout << "请输入审核信息序号！！！" << "0代表返回" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select>=0&&select<=v.size())
		{
			if (select == 0)
			{
				cout << "返回成功！！！" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "请输入审核结果的选项！！！" << endl;
				cout << "1.审核通过" << endl;
				cout << "2.审核不通过" << endl;

				cin >> ret;
				if (ret==1)
				{
					o.m_order[v[select - 1]]["status"] == "2";  // 审核通过将status置为2
				}
				else
				{
					o.m_order[v[select - 1]]["status"] == "-1"; // 审核不通过将status置为-1
				}
				o.updateorder();
				cout << "审核完毕！！！" << endl;
				break;
			}
		}
		cout << "请输入正确的选项！！！" << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::t_exit_register()
{
	cout << "退出成功！！！" << endl;
	system("pause");
	system("cls");
}