#pragma once
#include "Character.h"

class HeadQuarter;
class Iceman :
    public Character
{
public:
    Iceman(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no);
    //�����ƶ�����д
    void Move(std::vector<City*> city_list) override;
private:
    int step_;//��¼�Ƿ�������2��
};

