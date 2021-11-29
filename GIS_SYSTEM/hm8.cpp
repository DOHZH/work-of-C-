#include <fstream>
#include <iostream>
#include <string>
#include <vector>


#include "extra_geo_method.h"

void main()
{
	std::ifstream myfile;
	std::ofstream outfile;
	while (1) 
	{
		myfile.open("input.txt");
		if (!myfile.is_open()) 
		{
			std::cout << "�ļ���ȡʧ�ܣ���������Ϊinput.txtû�зŵ�Ŀ¼�¡�����1ʹ�����������";
			std::string running_status;
			std::getline(std::cin, running_status);
			if (running_status != "1") 
			{
				break;
			}
			
		}
		else 
		{
			break;
		}
		std::cin.clear();
	}
	
	std::cout << "��ȡ�ļ���.....\n";
	std::string temp = "";

	//�洢�������ͱ������б�
	std::vector <Point> point_list;
	std::vector <Polyline> polyline_list;
	std::vector <Ring> ring_list;
	std::vector <Polygon> polygon_list;

	int index = 0;//��¼��ǰ����
	outfile.open("output.txt", std::ios::trunc | std::ios::out);
	while (std::getline(myfile, temp)) 
	{
		index += 1;
		temp = trim(temp);
		std::vector<std::string> command = DivideStr(temp, ' ');
		if (command[1] == "point") 
		{
			if (command[0] == "add")
			{
				Add(point_list, command, index);
			}
			else if (command[0] == "del")
			{
				Delete(point_list, command, index);
			}
			else if (command[0] == "judge")
			{
				if (Judge(point_list, command, index) == 1)
				{
					outfile << "Ture\n";
				}
				else if (Judge(point_list, command, index) == 0)
				{
					outfile << "False\n";
				}
			}
			else if (command[0] == "set")
			{
				Set(point_list, command, index);
			}
			else
			{
				std::cout << "��" << index << "�У�������"<<command[0]<<"����ָ��\n";
			}

		}
		else if (command[1] == "polyline")
		{
			if (command[0] == "add")
			{
				Add(polyline_list, command, index);
			}
			else if (command[0] == "del")
			{
				Delete(polyline_list, command, index);
			}
			else if (command[0] == "judge")
			{
				std::cout << "��" <<index <<"�д���polyline������judge���ָ���������\n";
			}
			else if (command[0] == "set")
			{
				Set(polyline_list, command, index);
			}
			else
			{
				std::cout << "��" << index << "�У�������" << command[0] << "����ָ��\n";
			}
		}
		else if (command[1] == "ring")
		{
			if (command[0] == "add")
			{
				Add(ring_list, command, index);
			}
			else if (command[0] == "del")
			{
				Delete(ring_list, command, index);
			}
			else if (command[0] == "judge")
			{
				if (Judge(ring_list, point_list, command, index) == 1)
				{
					outfile << "True\n";
				}
				else if (Judge(ring_list, point_list, command, index) == 0)
				{
					outfile << "False\n";
				}
			}
			else if (command[0] == "set")
			{
				Set(ring_list, command, index);
			}
			else
			{
				std::cout << "��" << index << "�У�������" << command[0] << "����ָ��\n";
			}

		}
		else if (command[1] == "polygon")
		{
			if (command[0] == "add")
			{
				Add(polygon_list, command, index);
			}
			else if (command[0] == "del")
			{
				Delete(polygon_list, command, index);
			}
			else if (command[0] == "judge")
			{
				if (Judge(polygon_list, point_list, command, index) == 1)
				{
					outfile << "True\n";
				}
				else if (Judge(polygon_list, point_list, command, index) == 0)
				{
					outfile << "False\n";
				}
			}
			else if (command[0] == "set")
			{
				Set(polygon_list, command, index);
			}
			else
			{
				std::cout << "��" << index << "�У�������" << command[0] << "����ָ��\n";
			}

		}
		else
		{
			std::cout << "��" << index << "�У�������" << command[1] << "����ָ��\n";
		}
	}
	
	if (!point_list.empty())
	{
		for (int i = 0; i < point_list.size(); ++i)
		{
			outfile << point_list[i].Print();
		}
	}

	if (!polyline_list.empty())
	{
		for (int i = 0; i < polyline_list.size(); ++i)
		{
			outfile << polyline_list[i].Print();
		}
	}

	if (!ring_list.empty())
	{
		for (int i = 0; i < ring_list.size(); ++i)
		{
			outfile << ring_list[i].Print();
		}
	}

	if (!polygon_list.empty())
	{
		for (int i = 0; i < polygon_list.size(); ++i)
		{
			outfile << polygon_list[i].Print();
		}
	}

	outfile.close();
	myfile.close();
}