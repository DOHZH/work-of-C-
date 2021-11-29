#pragma once
#include "OGRSurface.h"
#include "OGRPoint.h"

//�����࣬���������container�е�һ��PointSet������Ȧ���Σ������Ԫ�ض��Ƕ���
//������ǲ���������һ��Poinset��Χ�ļ���ͼ�ν����������

extern class OGRLineString str;

class OGRPolygon :
    public OGRSurface
{
public:
	OGRPolygon();
	//����ΪPointSet��һ����ű�ĵ�ַ����ű��¼ÿ���Ӷ�����Ǽ����㡣
	//����˵һ��������һ�����Σ���ô��ű�Ϊ{4, 4}
	//���û�ж�������һ��
	OGRPolygon(PointSet, std::vector<int>* index_signal = nullptr);
	//���OGRGeometry�������д
	//�Ƿ�Ϊ��
	bool IsEmpty() const override;
	//��ȡ������Σ����������Ϊ����ָ�봫��
	void GetMBR(OGREnvelope*) const override;
	//��ȡ������Σ������������
	OGREnvelope GetMBR() const override;
	//���ƶ���
	void Clone(OGRPolygon*);
	OGRPolygon* Clone() override;

	//��ȡ�ļ�
	OGRErr ImportFromWkt(std::string) override;
	//����ļ�
	OGRErr ExportToWkt(std::string) const override;

	//��дOGRSurface�ĺ���
	//��ȡ���
	double GetArea() override;
	//��ȡ�ܳ�
	double GetPerimeter() override;

	//���к���
	//����Ƿ��ཻ
	bool Intersects(OGRPolygon*);
	bool Intersects(OGRLineString*);

	//�����Ƿ������
	bool Contains(OGRPoint*);
	bool Contains(OGRLineString*);
	bool Contains(OGRPolygon*);


	std::vector<int> hole_index;//��������������ж������Ԫ�أ�����Ϊ��

	//��յ�ǰ��container��hole_index����Ҫ����ʹ��
	void Clear();

	//һЩ��������Ҫ��һЩ����ļ��
	
	//����ǲ��ǰ�����
	bool ContainP(Point);

	//����ǲ���͹�����
	bool CheckConcave();

	//���ͼ���Ƿ��Ƿ����
	bool IsDisjoint(OGRPolygon*);
	bool IsDisjoint(OGRLineString*);

	//������м��ı����ཻ���;��Ҫ���ļ����Լ���ʼ�����
	bool CheckRing(std::vector<OGRPolygon>, int);

	//������Ϣ��ǰ�ܳ��������Ϣ
	void Update();

private:
	//����ÿ����ͼ���ܳ�������Ϊ��ͼ���
	double CalPerimeterDivide(int num);
	//���������ܳ�
	void CalPerimeter();

	//�������
	void CalArea();
};

