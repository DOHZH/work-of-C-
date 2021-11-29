#pragma once
#include <vector>
#include <string>
#include "Point.h"

//���ߵĶ�������ع���ʵ��
class Polyline
{
public:
	Polyline();
	//����Ϊ�������͵������
	Polyline(std::string var_str, std::vector<float> point_set);

	//�޸ĵ��������Ϣ��no:Ϊѡ������ţ�point_info:����Ϣ��
	//������û��Խ�磬�򷵻�true������Ϊfalse
	bool Set(int no, std::vector<float> point_info);

	//�ƶ�������no:Ϊѡ������ţ�point_info:�ƶ���Ϣ��
	//������û��Խ�磬�򷵻�true������Ϊfalse
	bool Move(int no, std::vector<float> move_info);

	//ɾ��ָ��λ�õĵ�
	bool Delete(int no);

	//ָ�����ߵ���ʵ���ȡ�����Ϊ����
	void SetLength(std::string L);

	//��������������Ϊ�ַ�������
	void SetName(std::string name_str);

	//��ȡ��������
	std::string GetVarName();
	//��ȡ����
	std::string GetName();
	//��ȡ�����꼯��
	std::vector<Point> GetPointSet();
	//��ȡ����
	std::string GetLength();

	//��ӡ��Ϣ
	std::string Print();
protected:
	//��㼯���ֶ����һ������
	void AddPoint(Point);

private:
	std::vector<Point> point_set;//�����꼯��
	std::string var_name;//������
	std::string name;//����
	std::string	length;//������Ϣ
};

