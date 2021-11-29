#include "Wolf.h"
#include "HeadQuarter.h"

Wolf::Wolf(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no)
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
	killed_ = 1;
}

std::string Wolf::Attack(Character* c, Clock* clock)
{
	std::string re = "";
	c->Hold(attack_);
	re += PrintAttackInfo(c, clock);
	if (!c->IsAlived())
	{
		killed_ += 1;
		if (killed_ % 2 == 0)
		{
			hp_ = hp_ * 2;
			attack_ = attack_ * 2;
		}
		re += PrintDead(c, clock);
		camp_->RewardHp(this);
		GetHp();
		re += PrintGetHp(clock);
		SendHp();
	}
	else
	{
		re += c->CounterAttack(this, clock);
	}

	return re;
}