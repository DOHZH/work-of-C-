#pragma once
#include "City.h"
class Town :
    public City
{
public:
    Town();
    //������еı��
    Town(int no);
    //��д�������ó��е�����Ԫ
    int GiveHp() override;
};

