#pragma once
#include "OGRGeometryCollection.h"
#include "OGRLineString.h"
class OGRMultiLineString :
    public OGRGeometryCollection
{
public:
    OGRMultiLineString();

    //获取container:如果不是Point，将自动展成PointSet
    PointSet GetAllPoints() const override;
    //获取长度
    double Getlength();
    //是否为空
    bool IsEmpty() const override;
    //获取外包矩形，外包矩形作为参数指针传递
    void GetMBR(OGREnvelope*) const override;
    //获取外包矩形，返回外包矩形。这种方法一定要用try进行异常捕获
    OGREnvelope GetMBR() const override;
    //复制
    OGRMultiLineString* Clone() override;
    void Clone(OGRMultiLineString*);

    //读取文件
    OGRErr ImportFromWkt(std::string) override;
    //输出文件
    OGRErr ExportToWkt(std::string) const override;
    //添加成员
    void AddGeometry(OGRLineString);
    //删除成员
    void RemoveGeometry(int index) override;
    //获取成员
    OGRGeometry* GetGeometry(int index) const override;
    //更新元素：将序号位置的元素替换为新的线l
    void UpdateGeometry(int, OGRLineString l);
    //获取成员数量
    int GetNumGeometries() const override;

    std::vector<OGRLineString> container;
};

