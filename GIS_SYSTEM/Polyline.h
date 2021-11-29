#pragma once
#include <vector>
#include <string>
#include "Point.h"

//折线的定义与相关功能实现
class Polyline
{
public:
	Polyline();
	//参数为变量名和点的序列
	Polyline(std::string var_str, std::vector<float> point_set);

	//修改点的坐标信息。no:为选定的序号；point_info:点信息。
	//如果序号没有越界，则返回true；否则为false
	bool Set(int no, std::vector<float> point_info);

	//移动操作。no:为选定的序号；point_info:移动信息。
	//如果序号没有越界，则返回true；否则为false
	bool Move(int no, std::vector<float> move_info);

	//删除指定位置的点
	bool Delete(int no);

	//指定折线的现实长度。参数为长度
	void SetLength(std::string L);

	//命名函数。参数为字符型名称
	void SetName(std::string name_str);

	//获取变量名称
	std::string GetVarName();
	//获取名称
	std::string GetName();
	//获取点坐标集合
	std::vector<Point> GetPointSet();
	//获取长度
	std::string GetLength();

	//打印信息
	std::string Print();
protected:
	//向点集合手动添加一个坐标
	void AddPoint(Point);

private:
	std::vector<Point> point_set;//点坐标集合
	std::string var_name;//变量名
	std::string name;//名称
	std::string	length;//长度信息
};

