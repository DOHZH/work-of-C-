#include "ReadText.h"
#include <fstream>
#include <iostream>

ReadText::ReadText(std::string path)
{
	std::ifstream myfile;
	myfile.open(path);
	if (!myfile.is_open())
	{
		std::cout << "�ļ���ȡʧ������·���Ƿ���ȷ\n";
	}
	else
	{
		std::string temp = "";
		int row = 1;//��¼�����ǵڼ���
		TextInfo result_text;//��¼�����
		bool stop = false;//��������˴��󣬳���ֹͣ
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
						std::cout << "��" << row << "���д���\n";
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
						std::cout << "��" << row << "���д���\n";
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
						std::cout << "��" << row << "���д���\n";
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
	unsigned long num = 0;//��������������һ����Ҫ�������float��Χ����ֵ�����������Χ�����ǽ��б�����
	bool stop = false;

	const char* cstr = str.c_str();//�ַ���ָ��

	//�ж��Ƿ�Ϊ��ָ����߿��ַ�
	if ((cstr != NULL) && (*cstr != '\0'))
	{
		//�жϳ��˷���λ֮�⣬�Ƿ�ȫ����Ȼ����С����ҲҪ�ų���
		//�������
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
				//stringת����
				num = num * 10 + ((double)*cstr - '0');
				cstr++;

				//����32bit����
				if (num <= INT_MAX && num >= 0)
				{
					*result = (int)num;
				}
				else
				{
					//������Χ,����Խ�籨��
					stop = true;
					return stop;
				}

			}
			else
			{
				//������ڷ�����,���ڴ�������
				stop = true;
				return stop;
			}
		}
	}
	else
	{
		//�ַ�Ϊ���ַ���ֱ�ӷ���״̬����
		stop = true;
	}

	return stop;
}
