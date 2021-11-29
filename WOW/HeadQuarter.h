#pragma once
#include "City.h"
#include "Clock.h"
#include "global.h"

#include "Dragon.h"
#include "Iceman.h"
#include "Lion.h"
#include "Ninja.h"
#include "Wolf.h"

//人物列表，用于存储驻扎在城市点的士兵单位
typedef std::vector<Character*> CharacterList;

class HeadQuarter :
    public City
{
public:
    HeadQuarter();
    ~HeadQuarter();
    HeadQuarter(Camp camp_type, int hp[], int attack[], int hp_ori);

    //生产士兵
    std::string ProduceCharacter(Clock* c);

    //奖励血量。参数为城市数组和长度
    void RewardHp(Character* c);
    //收获血量
    void ReceiveHp(int gived_hp);

    //获取阵营单位序列
    CharacterList GetList();

    //输出血量
    std::string PrintHp(Clock* c);

    //占领总部
    std::string IsTaken(Clock* c);

    //处理死亡士兵
    void KillCharacter(Character*);
    //杀死所有士兵（delete new的对象）
    void KillAllCharacer();

    //重写判断是否为司令部
    bool IsHead() override;
private:
    int index_;//标记当前生产的总数
    CharacterList unit_list_;//该阵营中所有单位的指针
    Role production_order_[5];//生产顺序
    int role_hp_[5];//血量
    int role_attack_[5];//每个单位的攻击力
    
    //获取敌人的数量
    int GetEnemy();
};

