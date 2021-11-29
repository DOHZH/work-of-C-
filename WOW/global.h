#pragma once
#include <vector>
#include <string>

//�ı���Ϣ�Ľṹ��
struct TextInfo
{
	int hp = 0;//����ĳ�ʼ����ֵ
	int City_amount = 0;//����ĳ�������
	int T = 0;//�����ʱ������
	int ori_hp[5] = {0};
	int ori_attack[5] = {0};
};

//��Ӫö��
enum class Camp
{
	Neutral,
	Blue,
	Red
};
//��ɫְҵ��ö��
enum class Role
{
	Dragon,
	Ninja,
	Iceman,
	Lion,
	Wolf
};


//��Ӫö����ת�ַ�
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

//��ɫְҵö����ת�ַ�
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

//ȥ����λ�ո�
std::string trim(std::string& str);

//�ַ��з�
std::vector<std::string> DivideStr(std::string input, char mark);