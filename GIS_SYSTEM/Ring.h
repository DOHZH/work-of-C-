#pragma once
#include <string>
#include "Polyline.h"

//���Ķ�������ع��ܣ���Ϊ�����뻷�ĸ߶������ԣ��ʴ˼̳�Polyline�������set��move����������д
class Ring :
    public Polyline
{
public:
    Ring();
    //����ΪRing�ı������͵㼯�����û�б�����������""
    Ring(std::string var_str, std::vector<float> point_input);

    //����area
    void SetArea(std::string);

    //��ΪҪ������㣬���Խ�������д
    //�޸ĵ��������Ϣ��no:Ϊѡ������ţ�point_info:����Ϣ��
    //������û��Խ�磬�򷵻�true������Ϊfalse
    bool Set(int no, std::vector<float> point_info);

    //�ƶ�������no:Ϊѡ������ţ�point_info:�ƶ���Ϣ��
    //������û��Խ�磬�򷵻�true������Ϊfalse
    bool Move(int no, std::vector<float> move_info);

    //ɾ��ָ��λ�õĵ�
    bool Delete(int no);

    //�жϲ�����
    //return:����ֵtrueΪ���ڲ���falseΪ�����ڲ�
    bool Judge(Point);

    //��ȡ�㼯
    std::vector<Point> GetPointSetR();
    //��ȡvar_name
    std::string GetVarNameR();
    //��ȡname
    std::string GetNameR();
    //��ȡ����
    std::string GetLengthR();

    //��ӡ��Ϣ
    std::string Print();
private:
    std::string area;//���
    std::vector<Point> point_set_r;//Ring�ĵ㼯
};

