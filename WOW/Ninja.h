#pragma once
#include "Character.h"

class HeadQuarter;
class Ninja :
    public Character
{
public:
    Ninja(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no);
    //因为武士不会反击，所以要重写反击函数
    std::string CounterAttack(Character* c, Clock* clock) override;
};

