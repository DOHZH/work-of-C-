#pragma once
#include <vector>
#include <string>

//文本信息的结构体
struct TextInfo
{
	int hp = 0;//该组的初始生命值
	int City_amount = 0;//该组的城市数量
	int T = 0;//该组的时间上限
	int ori_hp[5] = {0};
	int ori_attack[5] = {0};
};

//阵营枚举
enum class Camp
{
	Neutral,
	Blue,
	Red
};
//角色职业的枚举
enum class Role
{
	Dragon,
	Ninja,
	Iceman,
	Lion,
	Wolf
};


//阵营枚举类转字符
inline std::string GetCampStr(Camp c) {
	std::string type = "";
	switch (c)
	{
	case Camp::Neutral:
		type = "neutral";
		break;
	case Camp::Blue:
		type = "blue";
		break;
	case Camp::Red:
		type = "red";
		break;
	}

	return type;
}

//角色职业枚举类转字符
inline std::string GetRoleStr(Role r) {
	std::string type = "";
	switch (r)
	{
	case Role::Dragon:
		type = "dragon";
		break;
	case Role::Iceman:
		type = "iceman";
		break;
	case Role::Lion:
		type = "lion";
		break;
	case Role::Ninja:
		type = "ninja";
		break;
	case Role::Wolf:
		type = "wolf";
		break;
	}

	return type;
}

//去除首位空格
std::string trim(std::string& str);

//字符切分
std::vector<std::string> DivideStr(std::string input, char mark);