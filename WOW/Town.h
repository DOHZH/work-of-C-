#pragma once
#include "City.h"
class Town :
    public City
{
public:
    Town();
    //输入城市的编号
    Town(int no);
    //重写，给出该城市的生命元
    int GiveHp() override;
};

