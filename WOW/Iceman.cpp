#include "Iceman.h"
#include "HeadQuarter.h"

Iceman::Iceman(Role role, int hp, int attack, HeadQuarter* camp, int no, City* city, int loc_no)
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
	step_ = 0;
}

void Iceman::Move(std::vector<City*> city_list)
{
	if (loc_->IsHead() && loc_->GetCamp() != camp_->GetCamp())
		return;

	loc_->DeleteCharacter(this);
	loc_ = city_list[loc_no_ + 1];
	loc_no_ += 1;
	if (step_ == 2)
	{
		//std::cout << GetCampStr(camp_->GetCamp()) + " iceman" + std::to_string(no_)+ " get 9 point damage\n";
		if (hp_ > 9)
		{
			hp_ -= 9;
		}
		else
		{
			hp_ = 1;
		}
		attack_ += 20;
		step_ = 0;
	}
	else
	{
		step_ += 1;
	}
	loc_->StationCharacter(this);
}
