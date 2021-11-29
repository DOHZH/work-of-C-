#pragma once
#include <string>

class Clock
{
public:
	Clock();

	//增加时间(分钟)，默认增加十分钟
	void AddTime(unsigned int added_time=10);

	//输出时刻，返回值为字符类型
	std::string PrintTime();

private:
	unsigned int hour_;//时
	unsigned int minute_;//分
};

