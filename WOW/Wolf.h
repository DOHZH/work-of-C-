#pragma once
#include "Character.h"

class HeadQuarter;
class Wolf :
    public Character
{
public:
    Wolf(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no);
    //重写攻击函数；主要是为了计算攻击翻倍
    std::string Attack(Character* c, Clock* clock) override;

private:
    int killed_;
};

