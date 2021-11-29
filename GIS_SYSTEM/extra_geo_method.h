#pragma once

//本文件中的函数主要是用来处理四种操作对象的增删改查操作
#include <string>
#include "divide_method.h"
#include "string_to_float.h"
#include "Point.h"
#include "Polyline.h"
#include "Ring.h"
#include "Polygon.h"

//添加类函数家族。我们使用重载技术保持一致

//添加点：参数为点集、对应指令序列以及目前行数
void Add(std::vector<Point> &point_list, const std::vector<std::string> command, const int index);
//添加折线，参数为需要折线集合，对应的指令序列与目前的行数
void Add(std::vector <Polyline> &polyline_list, const std::vector<std::string> command, const int index);
//添加环，参数为需要环集合，对应的指令序列与目前的行数
void Add(std::vector <Ring> &ring_list, const std::vector<std::string> command, const int index);
//添加多边形，参数为需要的多边形集合，对应的指令序列与目前的行数
void Add(std::vector <Polygon> &polygon_list, const std::vector<std::string> command, const int index);

//删除类家族

//删除点，参数为点集、对应指令序列以及目前行数
void Delete(std::vector<Point> &point_list, const std::vector<std::string> command, const int index);
//删除折线，参数为需要折线集合，对应的指令序列与目前的行数
void Delete(std::vector <Polyline> &polyline_list, const std::vector<std::string> command, const int index);
//删除环，参数为需要环集合，对应的指令序列与目前的行数
void Delete(std::vector <Ring> &ring_list, const std::vector<std::string> command, const int index);
//删除环，参数为需要环集合，对应的指令序列与目前的行数
void Delete(std::vector <Polygon> &polygon_list, const std::vector<std::string> command, const int index);

//set类家族

//对点的set操作，参数为点集、对应指令序列以及目前行数
void Set(std::vector<Point> &point_list, const std::vector<std::string> command, const int index);
//对线的set操作，参数为需要折线集合，对应的指令序列与目前的行数
void Set(std::vector <Polyline> &polyline_list, const std::vector<std::string> command, const int index);
//对环的set操作，参数为需要折线集合，对应的指令序列与目前的行数
void Set(std::vector <Ring> &ring_list, const std::vector<std::string> command, const int index);
//对多边形的set操作，参数为需要多边形集合，对应的指令序列与目前的行数
void Set(std::vector <Polygon> &polygon_list, const std::vector<std::string> command, const int index);

//判断类家族

//判断点相等，参数为点列表，指令序列和当前所在行。返回值为int，2表示指令本身错误，1表示两个点相等，0表示两个点不相等
int Judge(std::vector<Point> &point_list, const std::vector<std::string> command, const int index);
//判断点是否在环内，参数为环列表，点列表，指令序列和当前所在行。返回值为int，2表示指令本身错误，1表示两个点相等，0表示两个点不相等
int Judge(std::vector<Ring> &ring_list, std::vector<Point>& point_list, const std::vector<std::string> command, const int index);
//判断点是否在环内，参数为环列表，点列表，指令序列和当前所在行。返回值为int，2表示指令本身错误，1表示两个点相等，0表示两个点不相等
int Judge(std::vector <Polygon> &polygon_list, std::vector<Point>& point_list, const std::vector<std::string> command, const int index);

//转化函数，来自extra_geo_method
//点序列从字符转向浮点数
std::vector<float> Convert(std::string);