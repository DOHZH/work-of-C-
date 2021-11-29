#pragma once
#include "OGRGeometryCollection.h"
#include "OGRLineString.h"
class OGRMultiLineString :
    public OGRGeometryCollection
{
public:
    OGRMultiLineString();

    //��ȡcontainer:�������Point�����Զ�չ��PointSet
    PointSet GetAllPoints() const override;
    //��ȡ����
    double Getlength();
    //�Ƿ�Ϊ��
    bool IsEmpty() const override;
    //��ȡ������Σ����������Ϊ����ָ�봫��
    void GetMBR(OGREnvelope*) const override;
    //��ȡ������Σ�����������Ρ����ַ���һ��Ҫ��try�����쳣����
    OGREnvelope GetMBR() const override;
    //����
    OGRMultiLineString* Clone() override;
    void Clone(OGRMultiLineString*);

    //��ȡ�ļ�
    OGRErr ImportFromWkt(std::string) override;
    //����ļ�
    OGRErr ExportToWkt(std::string) const override;
    //��ӳ�Ա
    void AddGeometry(OGRLineString);
    //ɾ����Ա
    void RemoveGeometry(int index) override;
    //��ȡ��Ա
    OGRGeometry* GetGeometry(int index) const override;
    //����Ԫ�أ������λ�õ�Ԫ���滻Ϊ�µ���l
    void UpdateGeometry(int, OGRLineString l);
    //��ȡ��Ա����
    int GetNumGeometries() const override;

    std::vector<OGRLineString> container;
};

