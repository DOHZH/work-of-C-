#include "global.h"
#include "Character.h"
#include "HeadQuarter.h"
#include "Town.h"
#include "ReadText.h"
#include <fstream>
#include <list>


int main()
{
	//读取文件
	ReadText Info("input.txt");
	std::vector<TextInfo> InfoList = Info.GetContainer();
	std::string result = "";
	std::ofstream outfile;
	outfile.open("output.txt", std::ios::in | std::ios::trunc);

	for (int i = 0; i < InfoList.size(); ++i)
	{
		outfile << "Case:" + std::to_string(i+1) + "\n";//最后的输出结果
		Clock OverallClock;
		//这里是进行单位变量的生成
		HeadQuarter BlueHead(Camp::Blue, InfoList[i].ori_hp, InfoList[i].ori_attack, InfoList[i].hp);
		HeadQuarter RedHead(Camp::Red, InfoList[i].ori_hp, InfoList[i].ori_attack, InfoList[i].hp);
		int time_max = InfoList[i].T;
		int city_amount = InfoList[i].City_amount;
		std::vector<Town> town_list(city_amount);//城市列表
		for (int i = 0; i < city_amount; ++i)
		{
			town_list[i] = Town(i+1);
		}

		//蓝军的路线
		std::vector<City*> BlueTrace(city_amount+2);
		for (int i = 0; i < city_amount + 2; ++i)
		{
			if (i == city_amount+1)
			{
				BlueTrace[i] = &(RedHead);
			}
			else if (i == 0)
			{
				BlueTrace[i] = &(BlueHead);
			}
			else
			{
				BlueTrace[i] = &(town_list[city_amount - i]);
			}
		}

		//红军的路线
		std::vector<City*> RedTrace(city_amount + 2);
		for (int i = 0; i < city_amount + 2; ++i)
		{
			if (i == city_amount+1)
			{
				RedTrace[i] = &BlueHead;
			}
			else if (i == 0)
			{
				RedTrace[i] = &(RedHead);
			}
			else
			{
				RedTrace[i] = &(town_list[i - 1]);
			}
		}

		bool defeat = false;
		result = "";

		CharacterList OverAllCharacter;
		std::list<Character*> overall_list;

		while (time_max >= 0 && !defeat)
		{
			result = "";
			//0:00，进行生产单位
			std::string red_pro = RedHead.ProduceCharacter(&OverallClock);
			result += red_pro;

			std::string blue_pro = BlueHead.ProduceCharacter(&OverallClock);
			result += blue_pro;

			OverallClock.AddTime();
			time_max -= 10;
			if (time_max <= 0)
			{
				outfile << result;
				break;
			}

			if (red_pro != "")
				overall_list.push_back(RedHead.GetList().back());

			if (blue_pro != "")
				overall_list.push_back(BlueHead.GetList().back());
			//0:10，所有武士前进
			std::list<Character*>::iterator it;
			for (it = overall_list.begin(); it != overall_list.end(); ++it)
			{
				if ((*it)->GetCamp() == Camp::Red)
				{
					(*it)->Move(RedTrace);
					std::string imp_str  = (*it)->PrintMoveInfo(&OverallClock);
					result += imp_str;
					std::cout << imp_str;
					if (!defeat)
					{
						std::string blue_taken = BlueHead.IsTaken(&OverallClock);
						std::cout << blue_taken;
						result += blue_taken;
						if (blue_taken != "")
							defeat = true;
					}
				}
				else if ((*it)->GetCamp() == Camp::Blue)
				{
					(*it)->Move(BlueTrace);
					std::string imp_str = (*it)->PrintMoveInfo(&OverallClock);
					result += imp_str;
					std::cout << imp_str;
					if (!defeat)
					{
						std::string red_taken = RedHead.IsTaken(&OverallClock);
						result += red_taken;
						std::cout << red_taken;
						if (red_taken != "")
							defeat = true;
					}
				}
			}
			
			if (defeat)
			{
				outfile << result;
				break;
			}
			OverallClock.AddTime();
			time_max -= 10;
			if (time_max <= 0)
			{
				outfile << result;
				break;
			}

			//0:20，城市生产生命元
			for (int i = 0; i < town_list.size(); ++i)
			{
				town_list[i].GenerateHP();
			}
			OverallClock.AddTime();
			time_max -= 10;
			if (time_max <= 0)
			{
				outfile << result;
				break;
			}

			//0:30,武士取走生命元
			for (int i = 0; i < town_list.size(); ++i)
			{
				result += town_list[i].ProcessNonCombat(&OverallClock);
			}
			OverallClock.AddTime();
			time_max -= 10;
			if (time_max <= 0)
			{
				outfile << result;
				break;
			}

			//0:40，对战
			for (int i = 0; i < town_list.size(); ++i)
			{
				result += town_list[i].ProcessCombat(&OverallClock, &overall_list);
			}
			
			OverallClock.AddTime();
			time_max -= 10;
			if (time_max <= 0)
			{
				outfile << result;
				break;
			}

			//0:50。报告生命元数量
			result += RedHead.PrintHp(&OverallClock);
			result += BlueHead.PrintHp(&OverallClock);
			std::cout << RedHead.PrintHp(&OverallClock);
			std::cout << BlueHead.PrintHp(&OverallClock);
			OverallClock.AddTime();
			time_max -= 10;
			if (time_max <= 0)
			{
				outfile << result;
				break;
			}
			outfile << result;
		}

	}
	outfile.close();
}