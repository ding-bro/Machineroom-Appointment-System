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
	cout << "��ǰ��������Ϊ�� " << vr.size() << endl;
	ifs.close();
}

void Student::open_menu()
{
	cout << "��ѡ���ܰ�������" << endl;
	cout << endl;
	cout << "	----------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << "	|				   1.����ԤԼ" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   2.�鿴����ԤԼ" << "                                |" << endl;
	cout << endl;
	cout << "	|				   3.�鿴����ԤԼ" << "                                |" << endl;
	cout << endl;
	cout << "	|				   4.ȡ��ԤԼ" << "                                    |" << endl;
	cout << endl;
	cout << "	|				   5.ע����¼" << "                                    |" << endl;
	cout << endl;
	cout << "	|                                                                                |" << endl;
	cout << endl;
	cout << "	----------------------------------------------------------------------------------" << endl;
}

void Student::studentmenu(Identity*& student)
{
	while (true)
	{
		student->open_menu(); // student�Ǹ���ָ��

		Student* s = (Student*)student; // ����һ������ָ�룬����ǿתΪ����ָ�룬����������Ķ���
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
			cout << "ע���ɹ�" << endl;
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
		cout << "��ѡ�����ڣ� " << endl;
		cout << "1.��һ" << endl;
		cout << "2.�ܶ�" << endl;
		cout << "3.����" << endl;
		cout << "4.����" << endl;
		cout << "5.����" << endl;
		int date = 0;
		cin >> date;
		if (date > 5 | date < 1)
		{
			cout << "��������Ч�����ڰ���������" << endl;
			system("pause");
			system("cls");
			break;
		}

		cout << "��ѡ��ʱ�Σ� " << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		int time = 0;
		cin >> time;
		if (time > 2 | time < 1)
		{
			cout << "��������Ч��ʱ�ΰ���������" << endl;
			system("pause");
			system("cls");
			break;;
		}
	
		cout << "��ѡ�����: " << endl;
		cout << "1.һ�Ż���" << endl;
		cout << "2.���Ż���" << endl;
		cout << "3.���Ż���" << endl;
		int machine = 0;
		cin >> machine;
		if (machine > 3 | machine < 1)
		{
			cout << "��������ȷ�Ļ�������������" << endl;
			system("pause");
			system("cls");
			break;
		}

		string date1;
		string time1;
		//string status;// = "ԤԼ״̬��";
		if (date==1)
		{
			date1 = "��һ";
		}
		else if (date == 2)
		{
			date1 = "�ܶ�";
		}
		else if (date == 3)
		{
			date1 = "����";
		}
		else if (date == 4)
		{
			date1 = "����";
		}
		else if (date == 6)
		{
			date1 = "����";
		}

		if (time==1)
		{
			time1 = "����";
		}
		else if (time==2)
		{
			time1 = "����";
		}

		ofstream ofs;
		ofs.open(ORDER_FILE, ios::out | ios::app);
		//ofs << "����ѡ����ţ� " << date1 << endl;
		//ofs << "ʱ��ѡ����ţ� " << time1 << endl;
		//ofs << "����ѡ����ţ� " << machine <<"��"<< endl;
		//ofs << "ѧ��ѧ�ţ� " << this->m_sid << endl;
		//ofs << "ѧ�������� " << this->m_name << endl;
		//ofs << status << "1"<<endl;							���Ľ�ȡ��ȡ������д�ļ�ʱд��Ӣ��
	
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
	cout << "ԤԼ�ɹ�����ʦ����У�����" << endl;
	system("pause");
	system("cls");
}

void Student::s_view_myself_appointment()
{
	order(); // ��ʾ����
	order o;
	if (o.o_size==0)
	{
		cout << "��ԤԼ��¼������" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < o.o_size; i++)
	{
		// ��ѧ�����ж��Ƿ��������ԤԼ
		if (atoi(o.m_order[i]["studentid"].c_str())==this->m_sid) // ��atoi��c_str������string����תΪC���Է���int����
		{
			cout << "ԤԼ����: ��" << o.m_order[i]["date"] << endl;
			cout << "ԤԼʱ��: " << (o.m_order[i]["time"] == "1" ? "����" : "����") << endl;// time���==1 ���磬��������
			cout << "ԤԼ�������: " << o.m_order[i]["roomid"] <<"�Ż���"<< endl;;
			cout << "ѧ��ѧ��: " << o.m_order[i]["studentid"] << endl;
			cout << "ѧ������: " << o.m_order[i]["studentname"] << endl;
			string status = "ԤԼ״̬: ";
			if (o.m_order[i]["status"]=="1")
			{
				status += "�����";
			}
			else if (o.m_order[i]["status"]=="2")
			{
				status += "������";
			}
			else if (o.m_order[i]["status"] == "-1")
			{
				status += "���δͨ��";
			}
			else 
			{
				status += "�����ȡ��";
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
	//order(); // ��ʾ����
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
		else if (o.m_order[i]["status"] == "-1")
		{
			status += "���δͨ��";
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

void Student::s_cancel_myself_appointment()
{
	order o;
	if (o.o_size==0)
	{
		cout << "�����ļ��������ݣ�����" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "�����ڽ���ȡ��ԤԼ��¼�Ĳ�����������" << endl;

	vector<int>v;  // �������������Ϣ������
	int index = 1;  // ����ԤԼ��Ϣ���±�  �±��1��ʼ

	for (int i = 0; i < o.o_size; i++)
	{
		if (atoi(o.m_order[i]["studentid"].c_str()) == this->m_sid)  // ͬ���ַ���ת��ΪC���Է���int�������Ƚ�
		{
			if (o.m_order[i]["status"] == "1" || o.m_order[i]["status"] == "2")  // ��statusԤԼ״̬��Ϊѡ��ý�����ȡ������
			{
				v.push_back(i); // ����Ϣ����������

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
				else if (o.m_order[i]["status"] == "2")
				{
					status += "������";
				}
				else if (o.m_order[i]["status"] == "-1")
				{
					status += "���δͨ��";
				}
				else
				{
					status += "�����ȡ��";
				}
				cout << status << endl;
				cout << endl;
			}
		}
	}

	cout << "��������Ҫȡ����¼����ţ�����" <<"����0�����أ�����"<< endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select>0 && select<=v.size())  // �����ֵС�ڵ���������Сֵ
		{
			if (select == 0)
			{
				cout << "���سɹ�������" << endl;
				system("pause");
				system("cls");
				break;
			}
			else
			{
				o.m_order[v[select - 1]]["status"] = "0";  // ���ļ��е��±��Ǵ�1��ʼ������vector�����е��±��Ǵ�0��ʼ
				// ����select-1��Ϊ��׼ȷ��λ������Ҫɾ����ԤԼ��Ϣ��λ��,���ҵ�������Ϣ����һ��ʱ��Ҳ���Զ�λ

				o.updateorder(); // ????? bug  �ļ��ж���д��һ��(δ���)
				cout << "��ȡ��ԤԼ������" << endl;
				break;
			}
		}
		cout << "��������ȷ����ţ�����" << endl;
	}
	system("pause");
	system("cls");
}

void Student::s_exit_register()
{
	cout << "�˳��ɹ�������" << endl;
	system("pause");
	system("cls");
}
