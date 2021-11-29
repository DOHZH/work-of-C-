#pragma once

//包含所有全局变量
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <fstream>
#include <stack>
#include "divide_method.h"
#include "string_to_float.h"

//公用类型：

typedef struct MyPoint{ double x = 0.0f, y = 0.0f; bool status = false; } Point; //定义点类型。内部参数分别为横纵坐标，是否赋值
typedef std::vector<Point> PointSet;//定义点集类型。如果只是点，那么只有一个元素

enum class OGRErr{
	//PathErr：路径错误；DataErr：数据错误；ReadTrue：文件正确读取
	ReadErr = 0,
	ReadTrue = 1,
	OutErr = 0,
	OutTrue = 1,
};//枚举类，报错类型



//公用函数：

//生成id。参数为输入的OGR类型，类型在每个类进行自行分类
inline int CalId(int OGRtype) {
	time_t now = time(0);
	tm int_now;
	gmtime_s(&int_now, &now);
	srand(time(0));
	int id = OGRtype * 10000000 + int_now.tm_hour * 1000000 + int_now.tm_min * 10000 + int_now.tm_sec * 100 + (rand() % 100);
	return id;
}

//输出点
inline void PrtintPoint(std::string& point_str, Point p)
{
	point_str += std::to_string(p.x) + " " + std::to_string(p.y);
}

//计算线段长度：参数为两个点
inline double CalLength(Point p1, Point p2) {
	double result = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return result;
}

/******************************************************************************
r=multiply(sp,ep,op),得到(sp-op)和(ep-op)的叉积
r>0：ep在矢量opsp的逆时针方向；
r=0：opspep三点共线；
r<0：ep在矢量opsp的顺时针方向
*******************************************************************************/
inline double Multiply(Point sp, Point ep, Point op)
{
	return((sp.x - op.x) * (ep.y - op.y) - (ep.x - op.x) * (sp.y - op.y));
}