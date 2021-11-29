#include "Dragon.h"
#include "HeadQuarter.h"

Dragon::Dragon(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no)
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

std::string Dragon::Attack(Character* c, Clock* clock)
{
	std::string re = "";
	c->Hold(attack_, this);
	re += PrintAttackInfo(c, clock);
	if (!c->IsAlived())
	{
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

	if (IsAlived())
		re += Cheer(clock);
	return re;
}

std::string Dragon::Cheer(Clock* c)
{
	std::string re = c->PrintTime() + " " + GetCampStr(loc_->GetCamp()) + " "
		+ GetRoleStr(role_) + " " + std::to_string(no_) 
		+ " yelled in city " + std::to_string(loc_->GetNo()) + "\n";
	return re;
}
