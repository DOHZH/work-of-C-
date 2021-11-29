#pragma once
#include <vector>
#include <iostream>
#include <list>
#include "global.h"
#include "Clock.h"

class Character;
//�����б����ڴ洢פ���ڳ��е��ʿ����λ
typedef std::vector<Character*> CharacterList;

class City
{
public:
	//��������ֵ
	void GenerateHP();
	//�л���Ӫ
	void ChangeCamp(Camp camp_type);
	//�ж��Ƿ�����˾�
	virtual bool IsHead();
	//��ȡ����Ԫ
	virtual int GiveHp();
	//��ȡ��Ӫ
	Camp GetCamp();
	//פ��ʿ��
	void StationCharacter(Character* c);
	//��ȡʿ������
	int GetCharacterNum();
	//ɾ��פ��ʿ��
	void DeleteCharacter(Character* c);
	//��ȡפ����ʿ��
	Character* GetCharacter(Camp c);
	//��ȡ���еı��
	int GetNo();
	//��ȡ��������
	std::string GetType();
	//����ս��
	std::string ProcessCombat(Clock* c, std::list<Character*>* overall);
	//����û��ս��ʱ�����
	std::string ProcessNonCombat(Clock* c);

protected:
	int hp_;//�ó��е������Ԫ
	Camp camp_;//�ó��е����Ӫ����
	CharacterList stationed_character_;//פ����ʿ��
	int no_;//���б�š����Ǿ�Ϊ0
	std::string type_;

private:
	void Add_HP(int added_hp);//��������ֵ
	int red_win_ = 0;
	int blue_win_ = 0;
};

