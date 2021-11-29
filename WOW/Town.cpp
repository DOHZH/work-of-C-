#include "Town.h"
Town::Town()
{
}
Town::Town(int no)
{
	hp_ = 0;
	camp_ = Camp::Neutral;
	no_ = no;
	type_ = "city";
}

int Town::GiveHp()
{
    int hp_r = hp_;
	hp_ = 0;
    return hp_r;
}
