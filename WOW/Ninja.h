#pragma once
#include "Character.h"

class HeadQuarter;
class Ninja :
    public Character
{
public:
    Ninja(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no);
    //��Ϊ��ʿ���ᷴ��������Ҫ��д��������
    std::string CounterAttack(Character* c, Clock* clock) override;
};

