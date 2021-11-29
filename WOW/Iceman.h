#pragma once
#include "Character.h"

class HeadQuarter;
class Iceman :
    public Character
{
public:
    Iceman(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no);
    //关于移动的重写
    void Move(std::vector<City*> city_list) override;
private:
    int step_;//记录是否是走了2步
};

