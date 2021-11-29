#pragma once
#include "OGRGeometry.h"
class OGRPoint :
    public OGRGeometry
{
public:
    //��ʼ����û�в��������
    OGRPoint();
    //����Ϊ��������
    OGRPoint(double x, double y);
    //��ʼ�����в��������������Ϊpoint
    OGRPoint(Point);
    //��ȡX��ʹ��ǰ����try�����쳣
    double X() const;
    //��ȡy��ʹ��ǰʹ��try�����쳣
    double Y() const;
    //OGRPointתPoint
    Point ToPoint() const;
    //���GeoMetry����д
    
    //�Ƿ�Ϊ��
    bool IsEmpty() const override;
    //��ȡ�������
    void GetMBR(OGREnvelope*) const override;
    OGREnvelope GetMBR() const override;
    //���ƶ���
    void Clone(OGRPoint*);
    OGRPoint* Clone() override;

    //��ȡ�ļ�������Ϊ�ļ�·��������ļ��ж���㣬��ô����ֻ��Ϊ���һ�������û���Ҫ�����
    OGRErr ImportFromWkt(std::string) override;
    //����ļ�������Ϊ�ļ�·��
    OGRErr ExportToWkt(std::string) const override;
};

