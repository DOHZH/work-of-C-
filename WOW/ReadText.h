#pragma once
#include "global.h"

class ReadText
{
public:
	ReadText(std::string path);
	
	std::vector<TextInfo> GetContainer();
private:
	//һ���м���
	int amount_;
	std::vector<TextInfo> info_container_;

	//�ַ�ת����������д����Ϊtrue������Ϊfalse
	bool StrToNum(std::string str, int* result);
};

