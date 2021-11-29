#pragma once
#include<string>
#include<vector>
#include<iostream>

//点的定义与相关功能实现
class Point
{
public:
	Point();
	//参数为点坐标信息，是不带有变量名的一种赋值，主要是用作其他几何信息的点信息储存
	Point(float, float);
	//参数为该点的变量名和点坐标信息
	Point(std::string, std::vector<float>);
	
	//改操作：set子指令，参数为横纵坐标
	void Set(std::vector<float>);
	//改操作：move命令
	void Move(std::vector<float>);
	//改操作：命名变量。参数为要取的名字
	void Name(std::string);

	//判断操作
	bool Judge(Point);

	//获取x点信息
	float GetX();
	//获取y点信息
	float GetY();
	//获取点的变量名
	std::string GetVarName();
	//获取点的名字
	std::string GetName();

	//查看该点是否为空点
	bool Empty();

	//打印点的信息
	std::string Print();
private:
	//该点的变量名。如add point a1，则该点的var_name为a1
	std::string var_name;
	//该点的名称。是在改操作中的name指令赋值，初始为空
	std::string name;
	//该点的点信息，是一个二维的向量
	std::vector<float> point_set;

};

