#pragma once
#include "global.h"
#include "OGREnvelope.h"


class OGRGeometry
{
public:
	//��ȡcontainer:�������Point�����Զ�չ��PointSet
	virtual PointSet GetAllPoints() const;
	//��ȡ���ε�����
	std::string GetGeometryType();
	//�Ƿ�Ϊ��
	virtual bool IsEmpty() const = 0;
	//��ȡ������Σ����������Ϊ����ָ�봫��
	virtual void GetMBR(OGREnvelope*) const = 0;
	//��ȡ������Σ�����������Ρ����ַ���һ��Ҫ��try�����쳣����
	virtual OGREnvelope GetMBR() const = 0;
	//�ж���ȣ�����Ϊ��Ҫ�ж���ȵļ���ͼ��
	bool Equals(OGRGeometry*) const;
	//���и���
	virtual OGRGeometry* Clone() = 0;
	//��ȡȫ��ID
	int GetID();

	//��ȡ�ļ�
	virtual OGRErr ImportFromWkt(std::string) = 0;
	//����ļ�
	virtual OGRErr ExportToWkt(std::string) const= 0;

	std::string type;//����
	int type_index;//�������
	int id;//idֵ
	PointSet container;//�㼯���������ڴ�ŵ㼯�����ֻ��һ����һͼ�Σ���ôֻ��һ��Ԫ��
};

