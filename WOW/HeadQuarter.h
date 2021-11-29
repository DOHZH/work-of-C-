#pragma once
#include "City.h"
#include "Clock.h"
#include "global.h"

#include "Dragon.h"
#include "Iceman.h"
#include "Lion.h"
#include "Ninja.h"
#include "Wolf.h"

//�����б����ڴ洢פ���ڳ��е��ʿ����λ
typedef std::vector<Character*> CharacterList;

class HeadQuarter :
    public City
{
public:
    HeadQuarter();
    ~HeadQuarter();
    HeadQuarter(Camp camp_type, int hp[], int attack[], int hp_ori);

    //����ʿ��
    std::string ProduceCharacter(Clock* c);

    //����Ѫ��������Ϊ��������ͳ���
    void RewardHp(Character* c);
    //�ջ�Ѫ��
    void ReceiveHp(int gived_hp);

    //��ȡ��Ӫ��λ����
    CharacterList GetList();

    //���Ѫ��
    std::string PrintHp(Clock* c);

    //ռ���ܲ�
    std::string IsTaken(Clock* c);

    //��������ʿ��
    void KillCharacter(Character*);
    //ɱ������ʿ����delete new�Ķ���
    void KillAllCharacer();

    //��д�ж��Ƿ�Ϊ˾�
    bool IsHead() override;
private:
    int index_;//��ǵ�ǰ����������
    CharacterList unit_list_;//����Ӫ�����е�λ��ָ��
    Role production_order_[5];//����˳��
    int role_hp_[5];//Ѫ��
    int role_attack_[5];//ÿ����λ�Ĺ�����
    
    //��ȡ���˵�����
    int GetEnemy();
};

