#pragma once
#include <vector>
#include <iostream>
#include <list>
#include "global.h"
#include "Clock.h"

class Character;
//人物列表，用于存储驻扎在城市点的士兵单位
typedef std::vector<Character*> CharacterList;

class City
{
public:
	//生产生命值
	void GenerateHP();
	//切换阵营
	void ChangeCamp(Camp camp_type);
	//判断是否属于司令部
	virtual bool IsHead();
	//获取生命元
	virtual int GiveHp();
	//获取阵营
	Camp GetCamp();
	//驻扎士兵
	void StationCharacter(Character* c);
	//获取士兵数量
	int GetCharacterNum();
	//删除驻留士兵
	void DeleteCharacter(Character* c);
	//获取驻扎的士兵
	Character* GetCharacter(Camp c);
	//获取城市的编号
	int GetNo();
	//获取城市类型
	std::string GetType();
	//处理战斗
	std::string ProcessCombat(Clock* c, std::list<Character*>* overall);
	//处理没有战斗时的情况
	std::string ProcessNonCombat(Clock* c);

protected:
	int hp_;//该城市点的生命元
	Camp camp_;//该城市点的阵营所属
	CharacterList stationed_character_;//驻留的士兵
	int no_;//城市编号。主城均为0
	std::string type_;

private:
	void Add_HP(int added_hp);//增加生命值
	int red_win_ = 0;
	int blue_win_ = 0;
};

