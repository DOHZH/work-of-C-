#pragma once
#include "global.h"
#include "OGREnvelope.h"


class OGRGeometry
{
public:
	//获取container:如果不是Point，将自动展成PointSet
	virtual PointSet GetAllPoints() const;
	//获取几何的类型
	std::string GetGeometryType();
	//是否为空
	virtual bool IsEmpty() const = 0;
	//获取外包矩形，外包矩形作为参数指针传递
	virtual void GetMBR(OGREnvelope*) const = 0;
	//获取外包矩形，返回外包矩形。这种方法一定要用try进行异常捕获
	virtual OGREnvelope GetMBR() const = 0;
	//判断相等，参数为需要判断相等的集合图形
	bool Equals(OGRGeometry*) const;
	//进行复制
	virtual OGRGeometry* Clone() = 0;
	//获取全局ID
	int GetID();

	//读取文件
	virtual OGRErr ImportFromWkt(std::string) = 0;
	//输出文件
	virtual OGRErr ExportToWkt(std::string) const= 0;

	std::string type;//类型
	int type_index;//类型序号
	int id;//id值
	PointSet container;//点集容器，用于存放点集。如果只有一个单一图形，那么只有一个元素
};

