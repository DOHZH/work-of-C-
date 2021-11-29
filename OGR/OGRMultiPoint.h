#pragma once
#include "OGRPoint.h"
#include "OGRGeometryCollection.h"
class OGRMultiPoint :
    public OGRGeometryCollection
{
public:
    OGRMultiPoint();
    //��ӵ�Ԫ��
    void AddGeometry(OGRPoint);
    //����idֵɾ��
    void RemoveGeometry(int) override;
    //������Ż�ȡpoint���������Խ��᷵��һ����ָ�벢����
    OGRPoint* GetGeometry(int) const override;
    //����Ԫ�أ������λ�õ�Ԫ���滻Ϊ�µĵ�p
    void UpdateGeometry(int, OGRPoint p);
    //��ȡ��Ա����
    int GetNumGeometries() const override;

    //��ȡcontainer:�������Point�����Զ�չ��PointSet
    PointSet GetAllPoints() const override;
    //�Ƿ�Ϊ��
    bool IsEmpty() const override;
    //��ȡ������Σ����������Ϊ����ָ�봫��
    void GetMBR(OGREnvelope*) const override;
    //��ȡ������Σ�����������Ρ����ַ���һ��Ҫ��try�����쳣����
    OGREnvelope GetMBR() const override;
    //����
    OGRMultiPoint* Clone() override;
    void Clone(OGRMultiPoint*);

    //��ȡ�ļ�
    OGRErr ImportFromWkt(std::string) override;
    //����ļ�
    OGRErr ExportToWkt(std::string) const override;
private:
    std::vector<OGRPoint> container;
};

