#pragma once
#include "Character.h"

class HeadQuarter;
class Lion :
    public Character
{
public:
    Lion(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no);
    //参数中的character是和自己发生战斗的人。如果Lion死了，会转移给他血量
    void Hold(int damage, Character* c = nullptr) override;
};

