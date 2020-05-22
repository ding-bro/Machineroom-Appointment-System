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
	cout << "��ѡ���ܰ�������" << endl;
	cout << endl;
	cout << "	----------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << "	|				   1.�鿴����ԤԼ" << "                                |" << endl;
	cout << endl;
	cout << "	|				   2.���ԤԼ" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   3.ע����¼" << "                                    |" << endl;
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
			cout << "ע���ɹ�" << endl;
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
		cout << "��ԤԼ��¼������" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 1; i < o.o_size; i++)  // ʵ���i��1��ʼ,��Ȼ���ӡһ�ο���Ϣ
	{
		cout << i + 1 << "��" << endl;
		cout << "ԤԼ����: ��" << o.m_order[i]["date"] << endl;
		cout << "ԤԼʱ��: " << (o.m_order[i]["time"] == "1" ? "����" : "����") << endl;// time���==1 ���磬��������
		cout << "ԤԼ�������: " << o.m_order[i]["roomid"] << "�Ż���" << endl;;
		cout << "ѧ��ѧ��: " << o.m_order[i]["studentid"] << endl;
		cout << "ѧ������: " << o.m_order[i]["studentname"] << endl;
		string status = "ԤԼ״̬: ";
		if (o.m_order[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (o.m_order[i]["status"] == "2")
		{
			status += "������";
		}
		else if(o.m_order[i]["status"]=="-1")
		{
			status += "���Ϊͨ��������";
		}
		else
		{
			status += "�����ȡ��";
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
		cout << "��ԤԼ��¼������" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��Ϣ����: " << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < o.o_size; i++)
	{
		if (o.m_order[i]["status"]=="1")  // ԤԼ״̬Ϊ1���Ǵ����
		{
			v.push_back(i);  // ����Ϣ����������

			cout << index++ << "��" << endl;
			cout << "ԤԼ����: ��" << o.m_order[i]["date"] << endl;
			cout << "ԤԼʱ��: " << (o.m_order[i]["time"] == "1" ? "����" : "����") << endl;// time���==1 ���磬��������
			cout << "ԤԼ�������: " << o.m_order[i]["roomid"] << "�Ż���" << endl;;
			cout << "ѧ��ѧ��: " << o.m_order[i]["studentid"] << endl;
			cout << "ѧ������: " << o.m_order[i]["studentname"] << endl;
			string status = "״̬: ";
			if (o.m_order[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}
	}

	cout << "�����������Ϣ��ţ�����" << "0������" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select>=0&&select<=v.size())
		{
			if (select == 0)
			{
				cout << "���سɹ�������" << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				cout << "��������˽����ѡ�����" << endl;
				cout << "1.���ͨ��" << endl;
				cout << "2.��˲�ͨ��" << endl;

				cin >> ret;
				if (ret==1)
				{
					o.m_order[v[select - 1]]["status"] == "2";  // ���ͨ����status��Ϊ2
				}
				else
				{
					o.m_order[v[select - 1]]["status"] == "-1"; // ��˲�ͨ����status��Ϊ-1
				}
				o.updateorder();
				cout << "�����ϣ�����" << endl;
				break;
			}
		}
		cout << "��������ȷ��ѡ�����" << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::t_exit_register()
{
	cout << "�˳��ɹ�������" << endl;
	system("pause");
	system("cls");
}