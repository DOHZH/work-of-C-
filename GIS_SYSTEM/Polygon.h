#pragma once
#include <vector>
#include <string>

#include "Ring.h"

//多边形的定义与相关操作，允许有一个内环
class Polygon
{
public:
	Polygon();
	//参数为：多边形名称，点集
	Polygon(std::string var_str, std::vector<float> point_set);

	//改操作：设置内环。参数为内环坐标序列。输入前保证序列成对
	void Set(std::vector<float> point_info);
	//改操作：修改外环，参数为需要修改的点序号与需要改成的坐标
	bool SetOuter(int no, std::vector<float> point_info);
	//改操作：移动外环的点，参数为需要修改的点序号与需要移动的坐标量
	bool MoveOuter(int no, std::vector<float> point_info);
	//改操作：删除外环的点，参数为需要修改的点序号与需要移动的坐标量
	bool DeleteOuter(int no);
	//改操作：删除
	bool SetInner(int no, std::vector<float> point_info);
	//改操作：移动外环的点，参数为需要修改的点序号与需要移动的坐标量
	bool MoveInner(int no, std::vector<float> point_info);
	//改操作：删除外环的点，参数为需要修改的点序号与需要移动的坐标量
	bool DeleteInner(int no);
	//改操作：设置长度.参数为实际长度
	void SetLength(std::string L);
	//改操作：设置面积。参数为实际面积
	void SetArea(std::string a);
	//改操作：设置名字。参数为实际名字
	void SetName(std::string n);

	//判断操作:参数为点p，查看p是否在多边形内部
	bool Judge(Point p);

	//获取变量名
	std::string GetVarName();
	//获取外部环
	Ring GetOuter();
	//获取长度
	std::string GetLength();

	//打印
	std::string Print();
private:
	Ring outer;//外部环
	Ring inner;//内部环
	std::string var_name;//变量名
	std::string name;//名称
	std::string	length;//长度信息
	std::string area;//面积信息
};

