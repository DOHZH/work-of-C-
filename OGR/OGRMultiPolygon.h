#pragma once
#include "OGRGeometryCollection.h"
#include "OGRPolygon.h"
class OGRMultiPolygon :
    public OGRGeometryCollection
{
public:
    OGRMultiPolygon();

	//�Ƿ�Ϊ��
	bool IsEmpty() const override;
	//��ȡcontainer:�������Point�����Զ�չ��PointSet
	PointSet GetAllPoints() const override;
	//��ȡ������Σ����������Ϊ����ָ�봫��
	virtual void GetMBR(OGREnvelope*) const override;
	//��ȡ������Σ�����������Ρ����ַ���һ��Ҫ��try�����쳣����
	virtual OGREnvelope GetMBR() const override;
	//����
	OGRMultiPolygon* Clone();
	void Clone(OGRMultiPolygon*);
	//��ȡ���ܳ�
	double GetPerimeter();
	//��ȡ�����
	double GetArea();

	//��ȡ�ļ�
	virtual OGRErr ImportFromWkt(std::string) override;
	//����ļ�
	virtual OGRErr ExportToWkt(std::string) const override;

	//��ӳ�Ա
	virtual void AddGeometry(OGRPolygon);
	//ɾ����Ա
	virtual void RemoveGeometry(int index) override;
	//��ȡ��Ա
	virtual OGRPolygon* GetGeometry(int index) const override;
	//���³�Ա
	virtual void UpdateGeometry(int index, OGRPolygon geo);
	//��ȡ��Ա����
	virtual int GetNumGeometries() const override;
	//������ϵ
	bool Contains(OGRPoint*);
	bool Contains(OGRLineString*);
	bool Contains(OGRPolygon*);

	std::vector<OGRPolygon> container;
};

