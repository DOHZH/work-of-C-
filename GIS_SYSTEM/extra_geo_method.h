#pragma once

//���ļ��еĺ�����Ҫ�������������ֲ����������ɾ�Ĳ����
#include <string>
#include "divide_method.h"
#include "string_to_float.h"
#include "Point.h"
#include "Polyline.h"
#include "Ring.h"
#include "Polygon.h"

//����ຯ�����塣����ʹ�����ؼ�������һ��

//��ӵ㣺����Ϊ�㼯����Ӧָ�������Լ�Ŀǰ����
void Add(std::vector<Point> &point_list, const std::vector<std::string> command, const int index);
//������ߣ�����Ϊ��Ҫ���߼��ϣ���Ӧ��ָ��������Ŀǰ������
void Add(std::vector <Polyline> &polyline_list, const std::vector<std::string> command, const int index);
//��ӻ�������Ϊ��Ҫ�����ϣ���Ӧ��ָ��������Ŀǰ������
void Add(std::vector <Ring> &ring_list, const std::vector<std::string> command, const int index);
//��Ӷ���Σ�����Ϊ��Ҫ�Ķ���μ��ϣ���Ӧ��ָ��������Ŀǰ������
void Add(std::vector <Polygon> &polygon_list, const std::vector<std::string> command, const int index);

//ɾ�������

//ɾ���㣬����Ϊ�㼯����Ӧָ�������Լ�Ŀǰ����
void Delete(std::vector<Point> &point_list, const std::vector<std::string> command, const int index);
//ɾ�����ߣ�����Ϊ��Ҫ���߼��ϣ���Ӧ��ָ��������Ŀǰ������
void Delete(std::vector <Polyline> &polyline_list, const std::vector<std::string> command, const int index);
//ɾ����������Ϊ��Ҫ�����ϣ���Ӧ��ָ��������Ŀǰ������
void Delete(std::vector <Ring> &ring_list, const std::vector<std::string> command, const int index);
//ɾ����������Ϊ��Ҫ�����ϣ���Ӧ��ָ��������Ŀǰ������
void Delete(std::vector <Polygon> &polygon_list, const std::vector<std::string> command, const int index);

//set�����

//�Ե��set����������Ϊ�㼯����Ӧָ�������Լ�Ŀǰ����
void Set(std::vector<Point> &point_list, const std::vector<std::string> command, const int index);
//���ߵ�set����������Ϊ��Ҫ���߼��ϣ���Ӧ��ָ��������Ŀǰ������
void Set(std::vector <Polyline> &polyline_list, const std::vector<std::string> command, const int index);
//�Ի���set����������Ϊ��Ҫ���߼��ϣ���Ӧ��ָ��������Ŀǰ������
void Set(std::vector <Ring> &ring_list, const std::vector<std::string> command, const int index);
//�Զ���ε�set����������Ϊ��Ҫ����μ��ϣ���Ӧ��ָ��������Ŀǰ������
void Set(std::vector <Polygon> &polygon_list, const std::vector<std::string> command, const int index);

//�ж������

//�жϵ���ȣ�����Ϊ���б�ָ�����к͵�ǰ�����С�����ֵΪint��2��ʾָ������1��ʾ��������ȣ�0��ʾ�����㲻���
int Judge(std::vector<Point> &point_list, const std::vector<std::string> command, const int index);
//�жϵ��Ƿ��ڻ��ڣ�����Ϊ���б����б�ָ�����к͵�ǰ�����С�����ֵΪint��2��ʾָ������1��ʾ��������ȣ�0��ʾ�����㲻���
int Judge(std::vector<Ring> &ring_list, std::vector<Point>& point_list, const std::vector<std::string> command, const int index);
//�жϵ��Ƿ��ڻ��ڣ�����Ϊ���б����б�ָ�����к͵�ǰ�����С�����ֵΪint��2��ʾָ������1��ʾ��������ȣ�0��ʾ�����㲻���
int Judge(std::vector <Polygon> &polygon_list, std::vector<Point>& point_list, const std::vector<std::string> command, const int index);

//ת������������extra_geo_method
//�����д��ַ�ת�򸡵���
std::vector<float> Convert(std::string);