#pragma once
#include "OGRGeometry.h"
class OGRCurve :
    public OGRGeometry
{
public:
    OGRCurve();

	//是否为空
	virtual bool IsEmpty() const = 0;
	//获取外包矩形，外包矩形作为参数指针传递
	virtual void GetMBR(OGREnvelope*) const = 0;
	//获取外包矩形，返回外包矩形。这种方法一定要用try进行异常捕获
	virtual OGREnvelope GetMBR() const = 0;
	//复制
	OGRCurve* Clone() = 0;

	//读取文件
	virtual OGRErr ImportFromWkt(std::string) = 0;
	//输出文件
	virtual OGRErr ExportToWkt(std::string) const = 0;

    //获取长度
    virtual double GetLength() = 0;
    double length;
};

