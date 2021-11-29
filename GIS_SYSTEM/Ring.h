#pragma once
#include <string>
#include "Polyline.h"

//环的定义与相关功能，因为折线与环的高度相似性，故此继承Polyline，并针对set与move函数进行重写
class Ring :
    public Polyline
{
public:
    Ring();
    //参数为Ring的变量名和点集，如果没有变量名，输入""
    Ring(std::string var_str, std::vector<float> point_input);

    //设置area
    void SetArea(std::string);

    //因为要处理起点，所以进行了重写
    //修改点的坐标信息。no:为选定的序号；point_info:点信息。
    //如果序号没有越界，则返回true；否则为false
    bool Set(int no, std::vector<float> point_info);

    //移动操作。no:为选定的序号；point_info:移动信息。
    //如果序号没有越界，则返回true；否则为false
    bool Move(int no, std::vector<float> move_info);

    //删除指定位置的点
    bool Delete(int no);

    //判断操作。
    //return:返回值true为在内部，false为不在内部
    bool Judge(Point);

    //获取点集
    std::vector<Point> GetPointSetR();
    //获取var_name
    std::string GetVarNameR();
    //获取name
    std::string GetNameR();
    //获取长度
    std::string GetLengthR();

    //打印信息
    std::string Print();
private:
    std::string area;//面积
    std::vector<Point> point_set_r;//Ring的点集
};

