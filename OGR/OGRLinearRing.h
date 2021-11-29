#pragma once
#include "OGRLineString.h"
//和LineString的方法一样，只不过处理长度等方法时要注意是一个环
class OGRLinearRing :
    public OGRLineString
{
public:
    OGRLinearRing();
	//获取长度
	double GetLength();
	//判断是否相交
	bool Intersects(OGRLineString*) const;
private:
	//计算当前长度
	void CalLineLength();
};

