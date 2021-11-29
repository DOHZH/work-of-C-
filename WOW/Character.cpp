#include "Character.h"
#include "HeadQuarter.h"
bool Character::IsAlived()
{
	if (hp_ <= 0)
	{
		alive_ = false;
	}
	return alive_;
}

void Character::Killed()
{
	camp_->KillCharacter(this);
}

void Character::Move(std::vector<City*> city_list)
{
	if (loc_->IsHead() && loc_->GetCamp() != camp_->GetCamp())
	{
		return;
	}
	loc_->DeleteCharacter(this);
	loc_ = city_list[loc_no_ + 1];
	loc_no_ += 1;
	loc_->StationCharacter(this);
}

std::string Character::PrintMoveInfo(Clock* c)
{
	std::string result = "";

	if (loc_->IsHead())
	{
		if (!stopped)
		{
			stopped = true;
			result += PrintReach(c);
		}
	}
	else
	{
		result = c->PrintTime() + " " + GetCampStr(camp_->GetCamp()) + " " + GetRoleStr(role_) + " " + std::to_string(no_) + " marched to " + loc_->GetType() + " " + std::to_string(loc_->GetNo())
			+ " with " + std::to_string(hp_) + " elements and force " + std::to_string(attack_) + "\n";
	}
	return result;
}

Camp Character::GetCamp()
{
	return camp_->GetCamp();
}

void Character::GetHp()
{
	get_hp_ = loc_->GiveHp();
}

void Character::SendHp()
{
	camp_->ReceiveHp(get_hp_);
	get_hp_ = 0;
}

void Character::ReceiveReward(int reward)
{
	hp_ += reward;
}

std::string Character::Attack(Character* c, Clock* clock)
{
	std::string re = "";
	c->Hold(attack_, this);
	re += PrintAttackInfo(c,clock);
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
	
	return re;
}

std::string Character::PrintAttackInfo(Character* c, Clock* clock)
{
	std::string re = "";
	re = clock->PrintTime() + " " + GetCampStr(camp_->GetCamp()) + " " + GetRoleStr(role_) +
		" " + std::to_string(no_) + " attacked " + GetCampStr(c->camp_->GetCamp()) + " " +
		GetRoleStr(c->role_) + " " + std::to_string(c->no_) + " in City " +
		std::to_string(loc_->GetNo()) + " with " + std::to_string(hp_) +
		" elements and force " + std::to_string(attack_) + "\n";
	return re;
}

std::string Character::PrintCounterAttackInfo(Character* c, Clock* clock)
{
	std::string re = "";
	re = clock->PrintTime() + " " + GetCampStr(camp_->GetCamp()) + " " + GetRoleStr(role_) +
		" " + std::to_string(no_) + " fought back against " + GetCampStr(c->camp_->GetCamp()) + " " +
		GetRoleStr(c->role_) + " " + std::to_string(c->no_) + " in City " +
		std::to_string(loc_->GetNo()) + "\n";
	return re;
}

std::string Character::PrintGetHp(Clock* clock)
{
	std::string re = "";
	re = clock->PrintTime() + " " + GetCampStr(camp_->GetCamp()) + " " + GetRoleStr(role_) +
		" " + std::to_string(no_) + " earned " + std::to_string(get_hp_) + " elements for his headquarter\n";
	return re;
}

std::string Character::PrintFlag(Clock* clock)
{
	std::string re = "";
	re = clock->PrintTime() + " " + GetCampStr(camp_->GetCamp())
		+ " flag raised in city " + std::to_string(loc_->GetNo()) + "\n";
	return re;
}

Role Character::GetRole()
{
	return role_;
}

int Character::GetNo()
{
	return no_;
}

std::string Character::PrintReach(Clock* clock)
{
	std::string re = "";
	re = clock->PrintTime() + " " + GetCampStr(camp_->GetCamp())
		+ " " + GetRoleStr(role_) + " " + std::to_string(no_) + " reached "
		+ GetCampStr(loc_->GetCamp()) + " headquarter with " + std::to_string(hp_)
		+ " elements and force " + std::to_string(attack_) + "\n";
	return re;
}

std::string Character::CounterAttack(Character* c, Clock* clock)
{
	std::string re = "";
	c->Hold(attack_/2, this);
	re += PrintCounterAttackInfo(c,clock);
	if (!c->IsAlived())
	{
		re += PrintDead(c, clock);
		camp_->RewardHp(this);
		GetHp();
		re += PrintGetHp(clock);
		SendHp();
	}
	return re;
	
}

void Character::Hold(int damage, Character* c)
{
	hp_ -= damage;
	if (hp_ <= 0)
		alive_ = false;
}

bool Character::Equal(Character* c)
{
	if (camp_->GetCamp() == c->GetCamp() && role_ == c->GetRole() && no_ == c->GetNo())
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string Character::PrintDead(Character* c, Clock* clock)
{
	std::string re = "";
	re = clock->PrintTime() + " " + GetCampStr(c->camp_->GetCamp()) + " " + GetRoleStr(c->role_) + " "
		+ " " + std::to_string(c->no_) + " was killed in city " + std::to_string(loc_->GetNo()) + "\n";
	return re;
}

Character::Character()
{
}

std::string Character::PrintBorn(Clock* clock)
{
	std::string result = "";
	result = clock->PrintTime() + " " + GetCampStr(camp_->GetCamp()) + " " + GetRoleStr(role_) + " " + std::to_string(no_) + " born\n";
	return result;
}
