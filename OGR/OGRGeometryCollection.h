#pragma once
#include "OGRGeometry.h"

class OGRGeometryCollection :
    public OGRGeometry
{
public:
	//�Ƿ�Ϊ��
	virtual bool IsEmpty() const = 0;
	//��ȡ������Σ����������Ϊ����ָ�봫��
	virtual void GetMBR(OGREnvelope*) const = 0;
	//��ȡ������Σ�����������Ρ����ַ���һ��Ҫ��try�����쳣����
	virtual OGREnvelope GetMBR() const = 0;
    //����
    OGRGeometryCollection* Clone() = 0;

	//��ȡ�ļ�
	virtual OGRErr ImportFromWkt(std::string) = 0;
	//����ļ�
	virtual OGRErr ExportToWkt(std::string) const = 0;
    //ɾ����Ա
    virtual void RemoveGeometry(int index) = 0;
    //��ȡ��Ա
    virtual OGRGeometry* GetGeometry(int index) const = 0;
    //��ȡ��Ա����
    virtual int GetNumGeometries() const = 0;
};

