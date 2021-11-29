#include "Clock.h"

Clock::Clock()
{
	hour_ = 0;
	minute_ = 0;
}

void Clock::AddTime(unsigned int added_time)
{
	unsigned int new_minute = minute_ + added_time;
	if (new_minute >= 60)
	{
		hour_ += new_minute / 60;
		minute_ = new_minute % 60;
	}
	else
	{
		minute_ = new_minute;
	}
}

std::string Clock::PrintTime()
{
	std::string str = "";
	if (hour_ < 10)
	{
		str += "00";
	}
	else if (hour_ < 100 && hour_ >= 10)
	{
		str += "0";
	}
	str += std::to_string(hour_);
	str += ":";

	if (minute_ < 10)
		str += "0";
	
	str += std::to_string(minute_);
	return str;
}
