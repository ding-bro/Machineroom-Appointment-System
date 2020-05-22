#pragma once
#include<iostream>
using namespace std;
#include<map>


class order
{
public:
	order();

	void updateorder();  // 更新预约记录

	map<int, map<string, string>>m_order;   // map记录预约信息容器
	// 一条预约信息有六条分支信息，都是成对出现
	// map<string,string>代表分支信息里的string属性和(string) value值
	// map<int>代表预约信息的条数
	// 把多条预约信息存入，map容器嵌套map容器

	int o_size;

};