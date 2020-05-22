#include"order.h"
#include<fstream>
#include"FILE.h"


order::order()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;// = "日期选择序号:";
	string time; //= "时段选择序号";
	string roomid;// = "机房选择序号";
	string studentid; //= "学生学号";
	string studentname;// = "学生姓名";
	string status; //= "预约状态";
	

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

		int pos = date.find(":"); // 分割冒号前和冒号的数据，分别置为key值和value值

		if (pos!=-1)
		{
			key = date.substr(0, pos);  // 截取字符串，中文截取读取不出，写文件时写入英文
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

	// 遍历
	for (map<int,map<string,string>>::iterator it=m_order.begin();it!=m_order.end();it++)
	{
		cout << "预约信息第" << it->first << "条： " << endl;
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
	ofs.open(ORDER_FILE, ios::out | ios::trunc);  // 以写文件的方式读取信息，并做删除操作

	for (int i = 0; i < this->o_size; i++)   // 遍历且打印数据
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