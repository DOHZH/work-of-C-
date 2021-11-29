#include "ReadText.h"
#include <fstream>
#include <iostream>

ReadText::ReadText(std::string path)
{
	std::ifstream myfile;
	myfile.open(path);
	if (!myfile.is_open())
	{
		std::cout << "文件读取失败请检查路径是否正确\n";
	}
	else
	{
		std::string temp = "";
		int row = 1;//记录现在是第几行
		TextInfo result_text;//记录结果用
		bool stop = false;//如果出现了错误，程序停止
		while (getline(myfile, temp) && !stop)
		{
			temp = trim(temp);
			if (row == 1)
			{
				stop = StrToNum(temp, &amount_);
			}
			else
			{
				if ((row - 1) % 3 == 1)
				{
					std::vector<std::string> result = DivideStr(temp, ' ');
					if (result.size() != 3)
					{
						std::cout << "第" << row << "行有错误\n";
						stop = true;
					}
					else
					{
						bool stop_1 = StrToNum(result[0], &(result_text.hp));
						bool stop_2 = StrToNum(result[1], &(result_text.City_amount));
						bool stop_3 = StrToNum(result[2], &(result_text.T));
						stop = stop_1 && stop_2 && stop_3;
					}
				}
				if ((row - 1) % 3 == 2)
				{
					std::vector<std::string> result = DivideStr(temp, ' ');
					if (result.size() != 5)
					{
						std::cout << "第" << row << "行有错误\n";
						stop = true;
					}
					else
					{
						bool stop_1 = StrToNum(result[0], &(result_text.ori_hp[0]));
						bool stop_2 = StrToNum(result[1], &(result_text.ori_hp[1]));
						bool stop_3 = StrToNum(result[2], &(result_text.ori_hp[2]));
						bool stop_4 = StrToNum(result[3], &(result_text.ori_hp[3]));
						bool stop_5 = StrToNum(result[4], &(result_text.ori_hp[4]));

						stop = stop_1 && stop_2 && stop_3 && stop_4 && stop_5;
					}
				}
				if ((row - 1) % 3 == 0)
				{
					std::vector<std::string> result = DivideStr(temp, ' ');
					if (result.size() != 5)
					{
						std::cout << "第" << row << "行有错误\n";
						stop = true;
					}
					else
					{
						bool stop_1 = StrToNum(result[0], &(result_text.ori_attack[0]));
						bool stop_2 = StrToNum(result[1], &(result_text.ori_attack[1]));
						bool stop_3 = StrToNum(result[2], &(result_text.ori_attack[2]));
						bool stop_4 = StrToNum(result[3], &(result_text.ori_attack[3]));
						bool stop_5 = StrToNum(result[4], &(result_text.ori_attack[4]));

						stop = stop_1 && stop_2 && stop_3 && stop_4 && stop_5;
					}

					info_container_.push_back(result_text);
					TextInfo new_text;
					result_text = new_text;
				}
			}
			row += 1;
		}

	}
	myfile.close();
}

std::vector<TextInfo> ReadText::GetContainer()
{
	return info_container_;
}

bool ReadText::StrToNum(std::string str, int* result)
{
	unsigned long num = 0;//储存输出结果。这一步主要处理符合float范围的数值，如果超出范围，我们进行报错处理
	bool stop = false;

	const char* cstr = str.c_str();//字符串指针

	//判断是否为空指针或者空字符
	if ((cstr != NULL) && (*cstr != '\0'))
	{
		//判断除了符号位之外，是否全是自然数（小数点也要排除）
		//处理符号
		if (*cstr == '+')
		{
			cstr++;
		}
		else if (*cstr >= '0' && *cstr <= '9')
		{
		}
		else
		{
			stop = true;
			return stop;
		}

		while (*cstr != '\0' && !stop)
		{

			if (*cstr >= '0' && *cstr <= '9')
			{
				//string转数字
				num = num * 10 + ((double)*cstr - '0');
				cstr++;

				//处理32bit数据
				if (num <= INT_MAX && num >= 0)
				{
					*result = (int)num;
				}
				else
				{
					//超出范围,进行越界报错
					stop = true;
					return stop;
				}

			}
			else
			{
				//如果存在非数字,属于错误输入
				stop = true;
				return stop;
			}
		}
	}
	else
	{
		//字符为空字符，直接返回状态错误
		stop = true;
	}

	return stop;
}
