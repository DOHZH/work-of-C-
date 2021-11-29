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
	//是否为空
	bool IsEmpty() const override;
	//获取外包矩形，外包矩形作为参数指针传递
	void GetMBR(OGREnvelope*) const override;
	//获取外包矩形，返回外包矩形。这种方法一定要用try进行异常捕获
	OGREnvelope GetMBR() const override;
	//复制对象
	void Clone(OGRLineString*);
	OGRLineString* Clone() override;

	//读取文件
	OGRErr ImportFromWkt(std::string) override;
	//输出文件
	OGRErr ExportToWkt(std::string) const override;
	//获取长度
	double GetLength() override;
	//判断是否相交
	bool Intersects(OGRLineString*) const;
	double Intersects(OGRPolygon*) const;

private:
	void CalLineLength();
};

