#pragma once
#include "OGRGeometry.h"
class OGRPoint :
    public OGRGeometry
{
public:
    //初始化，没有参数的情况
    OGRPoint();
    //参数为横纵坐标
    OGRPoint(double x, double y);
    //初始化，有参数的情况，参数为point
    OGRPoint(Point);
    //获取X，使用前请用try捕获异常
    double X() const;
    //获取y，使用前使用try捕获异常
    double Y() const;
    //OGRPoint转Point
    Point ToPoint() const;
    //针对GeoMetry的重写
    
    //是否为空
    bool IsEmpty() const override;
    //获取外包矩形
    void GetMBR(OGREnvelope*) const override;
    OGREnvelope GetMBR() const override;
    //复制对象
    void Clone(OGRPoint*);
    OGRPoint* Clone() override;

    //读取文件。参数为文件路径。如果文件有多个点，那么我们只认为最后一个点是用户想要输入的
    OGRErr ImportFromWkt(std::string) override;
    //输出文件。参数为文件路径
    OGRErr ExportToWkt(std::string) const override;
};

