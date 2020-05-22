#include"order.h"
#include<fstream>
#include"FILE.h"


order::order()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;// = "����ѡ�����:";
	string time; //= "ʱ��ѡ�����";
	string roomid;// = "����ѡ�����";
	string studentid; //= "ѧ��ѧ��";
	string studentname;// = "ѧ������";
	string status; //= "ԤԼ״̬";
	

	this->o_size = 1;

	while (ifs>> date &&ifs>> time &&ifs>> roomid &&ifs>> studentid &&ifs>> studentname &&ifs>> status)
	{

		//cout << date << endl;
		//cout << time << endl;
		//cout << roomid << endl;
		//cout << studentid << endl;
		//cout << studentname << endl;
		//cout << status << endl;

		string key;
		string value;
		map<string, string>m;

		int pos = date.find(":"); // �ָ�ð��ǰ��ð�ŵ����ݣ��ֱ���Ϊkeyֵ��valueֵ

		if (pos!=-1)
		{
			key = date.substr(0, pos);  // ��ȡ�ַ��������Ľ�ȡ��ȡ������д�ļ�ʱд��Ӣ��
			value = date.substr(pos+1, date.size() - pos-1);
			m.insert(make_pair(key,value));
		}

		 pos = time.find(":");
		if (pos !=-1)
		{
			key = time.substr(0, pos);
			value = time.substr(pos + 1, time.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		 pos = roomid.find(":");
		if (pos != -1)
		{
			key = roomid.substr(0, pos);
			value = roomid.substr(pos + 1, roomid.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		 pos = studentid.find(":");
		if (pos != -1)
		{
			key = studentid.substr(0, pos);
			value = studentid.substr(pos + 1, studentid.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		 pos = studentname.find(":");
		if (pos != -1)
		{
			key = studentname.substr(0, pos);
			value = studentname.substr(pos + 1, studentname.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		 pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos-1);
			m.insert(make_pair(key, value));
		}

		this->m_order.insert(make_pair(this->o_size, m));
		this->o_size++;

	}
	ifs.close();

	// ����
	for (map<int,map<string,string>>::iterator it=m_order.begin();it!=m_order.end();it++)
	{
		cout << "ԤԼ��Ϣ��" << it->first << "���� " << endl;
		for (map<string,string>::iterator it1=it->second.begin();it1!=it->second.end();it1++)
		{
			cout << it1->first << ":"<<endl<<it1->second << endl;
		}

	}
}


void order::updateorder()
{
	if (this->o_size==0)
	{
		return;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);  // ��д�ļ��ķ�ʽ��ȡ��Ϣ������ɾ������

	for (int i = 0; i < this->o_size; i++)   // �����Ҵ�ӡ����
	{
		ofs << "date:" << this->m_order[i]["date"] << " ";
		ofs <<"time:"<< this->m_order[i]["time"] << " ";
		ofs <<"roomid:" <<this->m_order[i]["roomid"] << " ";
		ofs <<"studentid:"<<this->m_order[i]["studentid"] << " ";
		ofs <<"studentname:"<< this->m_order[i]["studentname"] << " ";
		ofs <<"status:"<< this->m_order[i]["status"] << " ";
		ofs << endl;
	}
	ofs.close();
}