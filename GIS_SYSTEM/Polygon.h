#pragma once
#include <vector>
#include <string>

#include "Ring.h"

//����εĶ�������ز�����������һ���ڻ�
class Polygon
{
public:
	Polygon();
	//����Ϊ����������ƣ��㼯
	Polygon(std::string var_str, std::vector<float> point_set);

	//�Ĳ����������ڻ�������Ϊ�ڻ��������С�����ǰ��֤���гɶ�
	void Set(std::vector<float> point_info);
	//�Ĳ������޸��⻷������Ϊ��Ҫ�޸ĵĵ��������Ҫ�ĳɵ�����
	bool SetOuter(int no, std::vector<float> point_info);
	//�Ĳ������ƶ��⻷�ĵ㣬����Ϊ��Ҫ�޸ĵĵ��������Ҫ�ƶ���������
	bool MoveOuter(int no, std::vector<float> point_info);
	//�Ĳ�����ɾ���⻷�ĵ㣬����Ϊ��Ҫ�޸ĵĵ��������Ҫ�ƶ���������
	bool DeleteOuter(int no);
	//�Ĳ�����ɾ��
	bool SetInner(int no, std::vector<float> point_info);
	//�Ĳ������ƶ��⻷�ĵ㣬����Ϊ��Ҫ�޸ĵĵ��������Ҫ�ƶ���������
	bool MoveInner(int no, std::vector<float> point_info);
	//�Ĳ�����ɾ���⻷�ĵ㣬����Ϊ��Ҫ�޸ĵĵ��������Ҫ�ƶ���������
	bool DeleteInner(int no);
	//�Ĳ��������ó���.����Ϊʵ�ʳ���
	void SetLength(std::string L);
	//�Ĳ������������������Ϊʵ�����
	void SetArea(std::string a);
	//�Ĳ������������֡�����Ϊʵ������
	void SetName(std::string n);

	//�жϲ���:����Ϊ��p���鿴p�Ƿ��ڶ�����ڲ�
	bool Judge(Point p);

	//��ȡ������
	std::string GetVarName();
	//��ȡ�ⲿ��
	Ring GetOuter();
	//��ȡ����
	std::string GetLength();

	//��ӡ
	std::string Print();
private:
	Ring outer;//�ⲿ��
	Ring inner;//�ڲ���
	std::string var_name;//������
	std::string name;//����
	std::string	length;//������Ϣ
	std::string area;//�����Ϣ
};

