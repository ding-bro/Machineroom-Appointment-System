#include"machine_room.h"

void room::show_menu()
{
	cout << endl;
	cout << "-----------------------------------------欢迎来到机房预约系统---------------------------------------" << endl;
	cout << "                ----------------------------制作者:丁奕能-----------------------------" << endl;
	cout << endl;
	cout << "请选择功能：" << endl;
	cout << "请输入数字按键！！！" << endl;
	cout << endl;
	cout << "	**********************************************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << endl;
	cout << "	|				   1.学生代表" <<"                                    |" <<endl;
	cout << endl;
	cout << endl;
	cout << "	|				   2.老师" <<"                                        |" << endl;
	cout << endl;
	cout << endl;
	cout << "	|				   3.管理员" << "                                      |" << endl;
	cout << endl;
	cout << endl;
	cout << "	|				   4.退出系统" << "                                    |" << endl;
	cout << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << "	**********************************************************************************" << endl;

}

void room::exit_system()
{
	cout << endl;
	cout << "成功退出系统，欢迎下次使用！" << endl;
	cout << endl;
	exit(0);
}