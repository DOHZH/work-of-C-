#pragma once
#include<string>
#include<vector>
#include<iostream>

//��Ķ�������ع���ʵ��
class Point
{
public:
	Point();
	//����Ϊ��������Ϣ���ǲ����б�������һ�ָ�ֵ����Ҫ����������������Ϣ�ĵ���Ϣ����
	Point(float, float);
	//����Ϊ�õ�ı������͵�������Ϣ
	Point(std::string, std::vector<float>);
	
	//�Ĳ�����set��ָ�����Ϊ��������
	void Set(std::vector<float>);
	//�Ĳ�����move����
	void Move(std::vector<float>);
	//�Ĳ�������������������ΪҪȡ������
	void Name(std::string);

	//�жϲ���
	bool Judge(Point);

	//��ȡx����Ϣ
	float GetX();
	//��ȡy����Ϣ
	float GetY();
	//��ȡ��ı�����
	std::string GetVarName();
	//��ȡ�������
	std::string GetName();

	//�鿴�õ��Ƿ�Ϊ�յ�
	bool Empty();

	//��ӡ�����Ϣ
	std::string Print();
private:
	//�õ�ı���������add point a1����õ��var_nameΪa1
	std::string var_name;
	//�õ�����ơ����ڸĲ����е�nameָ�ֵ����ʼΪ��
	std::string name;
	//�õ�ĵ���Ϣ����һ����ά������
	std::vector<float> point_set;

};

