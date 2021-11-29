#pragma once
#include "OGRCurve.h"
#include "Line.h"
#include "OGRPolygon.h"

class Polygon;

class OGRLineString :
    public OGRCurve
{
public:
	OGRLineString();
	//�Ƿ�Ϊ��
	bool IsEmpty() const override;
	//��ȡ������Σ����������Ϊ����ָ�봫��
	void GetMBR(OGREnvelope*) const override;
	//��ȡ������Σ�����������Ρ����ַ���һ��Ҫ��try�����쳣����
	OGREnvelope GetMBR() const override;
	//���ƶ���
	void Clone(OGRLineString*);
	OGRLineString* Clone() override;

	//��ȡ�ļ�
	OGRErr ImportFromWkt(std::string) override;
	//����ļ�
	OGRErr ExportToWkt(std::string) const override;
	//��ȡ����
	double GetLength() override;
	//�ж��Ƿ��ཻ
	bool Intersects(OGRLineString*) const;
	double Intersects(OGRPolygon*) const;

private:
	void CalLineLength();
};

