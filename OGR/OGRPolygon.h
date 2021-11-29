#pragma once
#include "OGRSurface.h"
#include "OGRPoint.h"

//几何类，允许带洞。container中第一个PointSet是最外圈几何，后面的元素都是洞。
//因此我们不允许超过第一个Poinset范围的几何图形进入这个类中

extern class OGRLineString str;

class OGRPolygon :
    public OGRSurface
{
public:
	OGRPolygon();
	//参数为PointSet和一个序号表的地址。序号表记录每个子多边形是几个点。
	//比如说一个矩形套一个矩形，那么序号表为{4, 4}
	//如果没有洞，传入一个
	OGRPolygon(PointSet, std::vector<int>* index_signal = nullptr);
	//针对OGRGeometry基类的重写
	//是否为空
	bool IsEmpty() const override;
	//获取外包矩形，外包矩形作为参数指针传递
	void GetMBR(OGREnvelope*) const override;
	//获取外包矩形，返回外包矩形
	OGREnvelope GetMBR() const override;
	//复制对象
	void Clone(OGRPolygon*);
	OGRPolygon* Clone() override;

	//读取文件
	OGRErr ImportFromWkt(std::string) override;
	//输出文件
	OGRErr ExportToWkt(std::string) const override;

	//重写OGRSurface的函数
	//获取面积
	double GetArea() override;
	//获取周长
	double GetPerimeter() override;

	//自有函数
	//检测是否相交
	bool Intersects(OGRPolygon*);
	bool Intersects(OGRLineString*);

	//检测点是否包含。
	bool Contains(OGRPoint*);
	bool Contains(OGRLineString*);
	bool Contains(OGRPolygon*);


	std::vector<int> hole_index;//带洞索引。如果有洞才添加元素，否则为空

	//清空当前的container和hole_index。不要随意使用
	void Clear();

	//一些函数，主要是一些零碎的检测
	
	//检测是不是包含点
	bool ContainP(Point);

	//检测是不是凸多边形
	bool CheckConcave();

	//检测图形是否是分离的
	bool IsDisjoint(OGRPolygon*);
	bool IsDisjoint(OGRLineString*);

	//检测所有简单四边形相交与否;你要检测的集合以及开始的序号
	bool CheckRing(std::vector<OGRPolygon>, int);

	//更新信息当前周长与面积信息
	void Update();

private:
	//计算每个子图的周长。参数为子图序号
	double CalPerimeterDivide(int num);
	//计算所有周长
	void CalPerimeter();

	//计算面积
	void CalArea();
};

