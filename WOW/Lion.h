#pragma once
#include "Character.h"

class HeadQuarter;
class Lion :
    public Character
{
public:
    Lion(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no);
    //�����е�character�Ǻ��Լ�����ս�����ˡ����Lion���ˣ���ת�Ƹ���Ѫ��
    void Hold(int damage, Character* c = nullptr) override;
};

