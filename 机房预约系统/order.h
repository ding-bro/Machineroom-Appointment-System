#pragma once
#include<iostream>
using namespace std;
#include<map>


class order
{
public:
	order();

	void updateorder();  // ����ԤԼ��¼

	map<int, map<string, string>>m_order;   // map��¼ԤԼ��Ϣ����
	// һ��ԤԼ��Ϣ��������֧��Ϣ�����ǳɶԳ���
	// map<string,string>�����֧��Ϣ���string���Ժ�(string) valueֵ
	// map<int>����ԤԼ��Ϣ������
	// �Ѷ���ԤԼ��Ϣ���룬map����Ƕ��map����

	int o_size;

};