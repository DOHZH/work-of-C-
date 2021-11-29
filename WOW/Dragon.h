#pragma once
#include "Character.h"

class HeadQuarter;

class Dragon :
    public Character
{
public:
    Dragon(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no);
protected:
    std::string Attack(Character* c, Clock* clock) override;
private:
    std::string Cheer(Clock*c);
};

