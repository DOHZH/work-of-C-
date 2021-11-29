#pragma once

//��������ȫ�ֱ���
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <fstream>
#include <stack>
#include "divide_method.h"
#include "string_to_float.h"

//�������ͣ�

typedef struct MyPoint{ double x = 0.0f, y = 0.0f; bool status = false; } Point; //��������͡��ڲ������ֱ�Ϊ�������꣬�Ƿ�ֵ
typedef std::vector<Point> PointSet;//����㼯���͡����ֻ�ǵ㣬��ôֻ��һ��Ԫ��

enum class OGRErr{
	//PathErr��·������DataErr�����ݴ���ReadTrue���ļ���ȷ��ȡ
	ReadErr = 0,
	ReadTrue = 1,
	OutErr = 0,
	OutTrue = 1,
};//ö���࣬��������



//���ú�����

//����id������Ϊ�����OGR���ͣ�������ÿ����������з���
inline int CalId(int OGRtype) {
	time_t now = time(0);
	tm int_now;
	gmtime_s(&int_now, &now);
	srand(time(0));
	int id = OGRtype * 10000000 + int_now.tm_hour * 1000000 + int_now.tm_min * 10000 + int_now.tm_sec * 100 + (rand() % 100);
	return id;
}

//�����
inline void PrtintPoint(std::string& point_str, Point p)
{
	point_str += std::to_string(p.x) + " " + std::to_string(p.y);
}

//�����߶γ��ȣ�����Ϊ������
inline double CalLength(Point p1, Point p2) {
	double result = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return result;
}

/******************************************************************************
r=multiply(sp,ep,op),�õ�(sp-op)��(ep-op)�Ĳ��
r>0��ep��ʸ��opsp����ʱ�뷽��
r=0��opspep���㹲�ߣ�
r<0��ep��ʸ��opsp��˳ʱ�뷽��
*******************************************************************************/
inline double Multiply(Point sp, Point ep, Point op)
{
	return((sp.x - op.x) * (ep.y - op.y) - (ep.x - op.x) * (sp.y - op.y));
}