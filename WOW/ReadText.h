#pragma once
#include "global.h"

class ReadText
{
public:
	ReadText(std::string path);
	
	std::vector<TextInfo> GetContainer();
private:
	//一共有几组
	int amount_;
	std::vector<TextInfo> info_container_;

	//字符转整数。如果有错，输出为true，否则为false
	bool StrToNum(std::string str, int* result);
};

