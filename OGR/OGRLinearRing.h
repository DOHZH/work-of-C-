#pragma once
#include "OGRLineString.h"
//��LineString�ķ���һ����ֻ���������ȵȷ���ʱҪע����һ����
class OGRLinearRing :
    public OGRLineString
{
public:
    OGRLinearRing();
	//��ȡ����
	double GetLength();
	//�ж��Ƿ��ཻ
	bool Intersects(OGRLineString*) const;
private:
	//���㵱ǰ����
	void CalLineLength();
};

