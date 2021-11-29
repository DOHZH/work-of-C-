#include "City.h"
#include "Character.h"

void City::GenerateHP()
{
	Add_HP(10);
}

void City::ChangeCamp(Camp camp_type)
{
	camp_ = camp_type;
}

bool City::IsHead()
{
	return false;
}

int City::GiveHp()
{
	return hp_;
}

Camp City::GetCamp()
{
	return camp_;
}

void City::StationCharacter(Character* c)
{
	stationed_character_.push_back(c);
}

int City::GetCharacterNum()
{
	return stationed_character_.size();
}

void City::DeleteCharacter(Character* c)
{
	for (int i = 0; i < stationed_character_.size(); ++i)
	{
		if (c->Equal(stationed_character_[i]))
		{
			stationed_character_.erase(stationed_character_.begin() + i);
			return;
		}
	}
}

Character* City::GetCharacter(Camp c)
{
	for (int i = 0; i < stationed_character_.size(); ++i)
	{
		if (stationed_character_[i]->GetCamp() == c)
		{
			return stationed_character_[i];
		}
	}
}

int City::GetNo()
{
	return no_;
}

std::string City::GetType()
{
	return type_;
}

std::string City::ProcessCombat(Clock* c, std::list<Character*>* overall)
{
	std::string re = "";
	if (stationed_character_.size() < 2)
	{
		return re;
	}

	Character* red = nullptr;
	Character* blue = nullptr;

	if (stationed_character_[0]->GetCamp() == Camp::Blue)
	{
		red = stationed_character_[1];
		blue = stationed_character_[0];
	}
	else
	{
		red = stationed_character_[0];
		blue = stationed_character_[1];
	}

	if (camp_ == Camp::Red)
	{
		re += red->Attack(blue, c);
	}
	else if (camp_ == Camp::Blue)
	{
		re += blue->Attack(red,c);
	}
	else
	{
		if (no_ % 2 == 0)
		{
			re += red->Attack(blue,c);
		}
		else
		{
			re += blue->Attack(red,c);
		}
	}

	std::list<Character*>::iterator it;
	if (!(red->IsAlived()) || !(blue->IsAlived()))
	{
		for (it = overall->begin(); it != overall->end(); ++it)
		{
			if (!((*it)->IsAlived()))
			{
				overall->erase(it);
				break;
			}

		}
	}

	if (red->IsAlived() && !(blue->IsAlived()))
	{
		red_win_ += 1;
		blue_win_ = 0;
	}
	else if (!red->IsAlived() && blue->IsAlived())
	{
		blue_win_ += 1;
		red_win_ = 0;
	}
	else
	{
		//双方没有伤亡，连胜纪录归零
		blue_win_ = 0;
		red_win_ = 0;
	}

	if (blue_win_ == 2)
	{
		ChangeCamp(Camp::Blue);
		re += blue->PrintFlag(c);
	}
	else if (red_win_ == 2)
	{
		ChangeCamp(Camp::Red);
		re += red->PrintFlag(c);
	}

	if (!(red->IsAlived()))
	{
		for (int i = 0; i < stationed_character_.size(); ++i)
		{
			
			if (stationed_character_[i]->GetCamp() == Camp::Red)
			{
				stationed_character_.erase(stationed_character_.begin() + i);
				break;
			}
		}
		red->Killed();
	}

	if (!(blue->IsAlived()))
	{
		for (int i = 0; i < stationed_character_.size(); ++i)
		{
			if (stationed_character_[i]->GetCamp() == Camp::Blue)
			{
				stationed_character_.erase(stationed_character_.begin() + i);
				break;
			}
		}
		blue->Killed();
	}
	std::cout << re;
	return re;
}

std::string City::ProcessNonCombat(Clock* c)
{
	std::string re = "";
	if (stationed_character_.size() >= 2)
		return re;

	if (stationed_character_.empty())
		return re;
	else
	{
		stationed_character_[0]->GetHp();
		re += stationed_character_[0]->PrintGetHp(c);
		stationed_character_[0]->SendHp();
		std::cout << re;
		return re;
	}
}

void City::Add_HP(int added_hp)
{
	hp_ += added_hp;
}
