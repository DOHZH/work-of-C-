#include "Ninja.h"
#include "HeadQuarter.h"

Ninja::Ninja(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no)
{
	hp_ = hp;
	get_hp_ = 0;
	role_ = role;
	camp_ = camp;
	attack_ = attack;
	no_ = no;
	loc_no_ = loc_no;
	loc_ = city;
	alive_ = true;
}

std::string Ninja::CounterAttack(Character* c, Clock* clock)
{
    return "";
}
