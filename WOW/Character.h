#pragma once
#include "global.h"
#include "City.h"
#include "Town.h"

class HeadQuarter;

class Character
{
public:
	Character();
	//出生信息
	std::string PrintBorn(Clock* clock);
	//移动。注意要单独处理iceman的移动
	virtual void Move(std::vector<City*> city_list);
	//输出移动信息
	std::string PrintMoveInfo(Clock* c);
	
	//是否存活
	bool IsAlived();
	//确认死亡
	void Killed();

	//进行攻击。单独处理dragon和wolf。
	virtual std::string Attack(Character* c, Clock* clock);


	//返回该角色的阵营
	Camp GetCamp();
	//夺取所在城市的生命源
	void GetHp();
	//向主城发送血量
	void SendHp();
	//获取奖励
	void ReceiveReward(int reward);

	//反击。单独处理ninja和wolf
	virtual std::string CounterAttack(Character* c, Clock* clock);
	//承受敌人的攻击,进行生命结算。如果死了，就标记死亡。Lion对其重写
	virtual void Hold(int damage, Character* c = nullptr);

	//判断两个character是否相等
	bool Equal(Character* c);

	//打印获取生命元信息
	std::string PrintGetHp(Clock* clock);
	//打印占领信息
	std::string PrintFlag(Clock* clock);

	//获取职业信息
	Role GetRole();
	//获取编号
	int GetNo();
protected:
	City* loc_;//所在城市
	int loc_no_;//城市的相对位置
	int hp_;//血量
	int attack_;//攻击力
	Role role_;//职业角色
	HeadQuarter* camp_;//所属主城
	bool alive_;//判断是否存活
	int get_hp_;//夺取的血量
	int no_;//士兵总编号
	bool stopped = false;//判断是否继续向前

	//打印死亡信息
	std::string PrintDead(Character*c, Clock* clock);
	//打印攻击指令
	std::string PrintAttackInfo(Character* c, Clock* clock);
	//打印反击指令
	std::string PrintCounterAttackInfo(Character* c, Clock* clock);

	//抵达
	std::string PrintReach(Clock* clock);
};

