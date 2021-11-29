#pragma once
#include "global.h"
#include "City.h"
#include "Town.h"

class HeadQuarter;

class Character
{
public:
	Character();
	//������Ϣ
	std::string PrintBorn(Clock* clock);
	//�ƶ���ע��Ҫ��������iceman���ƶ�
	virtual void Move(std::vector<City*> city_list);
	//����ƶ���Ϣ
	std::string PrintMoveInfo(Clock* c);
	
	//�Ƿ���
	bool IsAlived();
	//ȷ������
	void Killed();

	//���й�������������dragon��wolf��
	virtual std::string Attack(Character* c, Clock* clock);


	//���ظý�ɫ����Ӫ
	Camp GetCamp();
	//��ȡ���ڳ��е�����Դ
	void GetHp();
	//�����Ƿ���Ѫ��
	void SendHp();
	//��ȡ����
	void ReceiveReward(int reward);

	//��������������ninja��wolf
	virtual std::string CounterAttack(Character* c, Clock* clock);
	//���ܵ��˵Ĺ���,�����������㡣������ˣ��ͱ��������Lion������д
	virtual void Hold(int damage, Character* c = nullptr);

	//�ж�����character�Ƿ����
	bool Equal(Character* c);

	//��ӡ��ȡ����Ԫ��Ϣ
	std::string PrintGetHp(Clock* clock);
	//��ӡռ����Ϣ
	std::string PrintFlag(Clock* clock);

	//��ȡְҵ��Ϣ
	Role GetRole();
	//��ȡ���
	int GetNo();
protected:
	City* loc_;//���ڳ���
	int loc_no_;//���е����λ��
	int hp_;//Ѫ��
	int attack_;//������
	Role role_;//ְҵ��ɫ
	HeadQuarter* camp_;//��������
	bool alive_;//�ж��Ƿ���
	int get_hp_;//��ȡ��Ѫ��
	int no_;//ʿ���ܱ��
	bool stopped = false;//�ж��Ƿ������ǰ

	//��ӡ������Ϣ
	std::string PrintDead(Character*c, Clock* clock);
	//��ӡ����ָ��
	std::string PrintAttackInfo(Character* c, Clock* clock);
	//��ӡ����ָ��
	std::string PrintCounterAttackInfo(Character* c, Clock* clock);

	//�ִ�
	std::string PrintReach(Clock* clock);
};

