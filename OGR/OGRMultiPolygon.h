#pragma once
#include "OGRGeometryCollection.h"
#include "OGRPolygon.h"
class OGRMultiPolygon :
    public OGRGeometryCollection
{
public:
    OGRMultiPolygon();

	//是否为空
	bool IsEmpty() const override;
	//获取container:如果不是Point，将自动展成PointSet
	PointSet GetAllPoints() const override;
	//获取外包矩形，外包矩形作为参数指针传递
	virtual void GetMBR(OGREnvelope*) const override;
	//获取外包矩形，返回外包矩形。这种方法一定要用try进行异常捕获
	virtual OGREnvelope GetMBR() const override;
	//复制
	OGRMultiPolygon* Clone();
	void Clone(OGRMultiPolygon*);
	//获取总周长
	double GetPerimeter();
	//获取总面积
	double GetArea();

	//读取文件
	virtual OGRErr ImportFromWkt(std::string) override;
	//输出文件
	virtual OGRErr ExportToWkt(std::string) const override;

	//添加成员
	virtual void AddGeometry(OGRPolygon);
	//删除成员
	virtual void RemoveGeometry(int index) override;
	//获取成员
	virtual OGRPolygon* GetGeometry(int index) const override;
	//更新成员
	virtual void UpdateGeometry(int index, OGRPolygon geo);
	//获取成员数量
	virtual int GetNumGeometries() const override;
	//包含关系
	bool Contains(OGRPoint*);
	bool Contains(OGRLineString*);
	bool Contains(OGRPolygon*);

	std::vector<OGRPolygon> container;
};

