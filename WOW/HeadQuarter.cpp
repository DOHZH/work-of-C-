#include "HeadQuarter.h"
#include "Character.h"


HeadQuarter::HeadQuarter()
{
}

HeadQuarter::~HeadQuarter()
{
	KillAllCharacer();
	std::cout << "delete所有的new对象\n";
}

HeadQuarter::HeadQuarter(Camp camp_type, int hp[], int attack[], int hp_ori)
{
	hp_ = hp_ori;
	camp_ = camp_type;
	index_ = 0;
	no_ = 0;
	type_ = "headquarter";
	if (camp_type == Camp::Red)
	{
		production_order_[0] = Role::Iceman;
		role_hp_[0] = hp[2];
		role_attack_[0] = attack[2];

		production_order_[1] = Role::Lion;
		role_hp_[1] = hp[3];
		role_attack_[1] = attack[3];

		production_order_[2] = Role::Wolf;
		role_hp_[2] = hp[4];
		role_attack_[2] = attack[4];

		production_order_[3] = Role::Ninja;
		role_hp_[3] = hp[1];
		role_attack_[3] = attack[1];

		production_order_[4] = Role::Dragon;
		role_hp_[4] = hp[0];
		role_attack_[4] = attack[0];

	}
	else if (camp_type == Camp::Blue)
	{
		production_order_[0] = Role::Lion;
		role_hp_[0] = hp[3];
		role_attack_[0] = attack[3];

		production_order_[1] = Role::Dragon;
		role_hp_[1] = hp[0];
		role_attack_[1] = attack[0];

		production_order_[2] = Role::Ninja;
		role_hp_[2] = hp[1];
		role_attack_[2] = attack[1];

		production_order_[3] = Role::Iceman;
		role_hp_[3] = hp[2];
		role_attack_[3] = attack[2];

		production_order_[4] = Role::Wolf;
		role_hp_[4] = hp[4];
		role_attack_[4] = attack[4];
	}
}

std::string HeadQuarter::ProduceCharacter(Clock* c)
{
	int num = index_ % 5;
	int hp = role_hp_[num];
	if (hp_ < hp)
		return "";
	else
	{
		hp_ -= hp;
		Role type = production_order_[num];
		int attack = role_attack_[num];

		if (type == Role::Dragon)
		{
			unit_list_.push_back(new Dragon(type, hp, attack, this, index_ + 1, this, 0));
		}
		else if (type == Role::Iceman)
		{
			unit_list_.push_back(new Iceman(type, hp, attack, this, index_ + 1, this, 0));
		}
		else if (type == Role::Lion)
		{
			
			unit_list_.push_back(new Lion(type, hp, attack, this, index_ + 1, this, 0));
		}
		else if (type == Role::Ninja)
		{
			unit_list_.push_back(new Ninja(type, hp, attack, this, index_ + 1, this, 0));
		}
		else
		{
			unit_list_.push_back(new Wolf(type, hp, attack, this, index_ + 1, this, 0));
		}
		
		std::string result = c->PrintTime() + " " + GetCampStr(unit_list_.back() -> GetCamp()) +" " +GetRoleStr(unit_list_.back()->GetRole()) + " " + std::to_string(index_+1) +" born\n";
		std::cout << result;
		index_ += 1;
		return result;
	}
}

void HeadQuarter::RewardHp(Character* c)
{
	if (hp_ >= 8)
	{
		c->ReceiveReward(8);
		hp_ -= 8;
	}
}

void HeadQuarter::ReceiveHp(int gived_hp)
{
	hp_ += gived_hp;
}

std::string HeadQuarter::PrintHp(Clock* c)
{
	std::string result = "";
	result = c->PrintTime() + " " + std::to_string(hp_) + " elements in " + GetCampStr(camp_) 
		+ " headquarter\n";
	return result;
}

std::string HeadQuarter::IsTaken(Clock* c)
{
	std::string re = "";
	if (GetEnemy() >= 2)
	{
		re = c->PrintTime() + " " + GetCampStr(camp_) + " headquarter was taken\n";
	}
	return re;
}

void HeadQuarter::KillCharacter(Character* c)
{
	for (int i = 0; i < unit_list_.size(); ++i)
	{
		if (!(unit_list_[i]->IsAlived()))
		{
			delete unit_list_[i];
			unit_list_.erase(unit_list_.begin() + i);
			break;
		}
	}

}

void HeadQuarter::KillAllCharacer()
{
	for (int i = 0; i < unit_list_.size(); ++i)
	{
		delete unit_list_[i];
	}
}

bool HeadQuarter::IsHead()
{
	return true;
}

int HeadQuarter::GetEnemy()
{
	int result = 0;
	for (int i = 0; i < stationed_character_.size(); ++i)
	{
		if (stationed_character_[i]->GetCamp() != camp_)
			result += 1;
	}

	return result;
}

CharacterList HeadQuarter::GetList()
{
	return unit_list_;
}

