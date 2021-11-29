#pragma once
#include "global.h"

//�߶���
class Line
{
public:
	//����x��y���߶�
	Line(double x1, double y1, double x2, double y2);
	//�õ���1
	Point P1();
	//�õ���2
	Point P2();
	//��k
	double K();
	//��b
	double B();
	//�Ƿ�Ϊ��ֱ�߶�
	bool IsVertical();

	//�ж����߹�ϵ�����ƽ�л򽻵㲻���߶��ϣ�����0������������߶��ϣ�����1
	bool Relation(Line*);

private:
	double k;
	double b;
	Point p1;
	Point p2;
	bool is_vertical;
};

