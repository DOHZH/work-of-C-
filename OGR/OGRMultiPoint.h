#pragma once
#include "OGRPoint.h"
#include "OGRGeometryCollection.h"
class OGRMultiPoint :
    public OGRGeometryCollection
{
public:
    OGRMultiPoint();
    //添加点元素
    void AddGeometry(OGRPoint);
    //根据id值删除
    void RemoveGeometry(int) override;
    //根据序号获取point。如果发生越界会返回一个空指针并报错
    OGRPoint* GetGeometry(int) const override;
    //更新元素：将序号位置的元素替换为新的点p
    void UpdateGeometry(int, OGRPoint p);
    //获取成员数量
    int GetNumGeometries() const override;

    //获取container:如果不是Point，将自动展成PointSet
    PointSet GetAllPoints() const override;
    //是否为空
    bool IsEmpty() const override;
    //获取外包矩形，外包矩形作为参数指针传递
    void GetMBR(OGREnvelope*) const override;
    //获取外包矩形，返回外包矩形。这种方法一定要用try进行异常捕获
    OGREnvelope GetMBR() const override;
    //复制
    OGRMultiPoint* Clone() override;
    void Clone(OGRMultiPoint*);

    //读取文件
    OGRErr ImportFromWkt(std::string) override;
    //输出文件
    OGRErr ExportToWkt(std::string) const override;
private:
    std::vector<OGRPoint> container;
};

