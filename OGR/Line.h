#pragma once
#include "global.h"

//线段类
class Line
{
public:
	//给定x与y求线段
	Line(double x1, double y1, double x2, double y2);
	//得到点1
	Point P1();
	//得到点2
	Point P2();
	//求k
	double K();
	//求b
	double B();
	//是否为垂直线段
	bool IsVertical();

	//判断两线关系。如果平行或交点不在线段上，返回0；如果交点在线段上，返回1
	bool Relation(Line*);

private:
	double k;
	double b;
	Point p1;
	Point p2;
	bool is_vertical;
};

