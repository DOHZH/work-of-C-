#include "Lion.h"
#include "HeadQuarter.h"

Lion::Lion(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no)
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

void Lion::Hold(int damage, Character* c)
{
	int ori_hp = hp_;
	hp_ -= damage;
	if (hp_ <= 0)
	{
		alive_ = false;
		c->ReceiveReward(ori_hp);
	}
}
