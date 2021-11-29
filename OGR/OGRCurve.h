#pragma once
#include "OGRGeometry.h"
class OGRCurve :
    public OGRGeometry
{
public:
    OGRCurve();

	//�Ƿ�Ϊ��
	virtual bool IsEmpty() const = 0;
	//��ȡ������Σ����������Ϊ����ָ�봫��
	virtual void GetMBR(OGREnvelope*) const = 0;
	//��ȡ������Σ�����������Ρ����ַ���һ��Ҫ��try�����쳣����
	virtual OGREnvelope GetMBR() const = 0;
	//����
	OGRCurve* Clone() = 0;

	//��ȡ�ļ�
	virtual OGRErr ImportFromWkt(std::string) = 0;
	//����ļ�
	virtual OGRErr ExportToWkt(std::string) const = 0;

    //��ȡ����
    virtual double GetLength() = 0;
    double length;
};

