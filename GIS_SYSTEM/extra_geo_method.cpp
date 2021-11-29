#include "extra_geo_method.h"
void Add(std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 4)
	{
		std::cout << "第" << index << "行错误，检查add指令是否错误\n";
		return;
	}
	else
	{
		if (point_list.empty())
		{
			std::vector<float> point_seq_num = Convert(command[3]);
			if (point_seq_num.size() != 2)
			{
				std::cout << "第" << index << "行错误，坐标输入不合格，添加失败\n";
			}
			else
			{
				Point p(command[2], point_seq_num);
				point_list.push_back(p);
			}
			
		}
		else
		{
			//首先检查该点是否已经存在
			for (int i = 0; i < point_list.size(); ++i)
			{
				if (point_list[i].GetVarName() == command[2])
				{
					std::cout << "第" << index << "行错误，已经存在该点\n";
					return;
				}
			}

			std::vector<float> point_seq_num = Convert(command[3]);
			if (point_seq_num.size() != 2)
			{
				std::cout << "第" << index << "行错误，坐标输入不合格，添加失败\n";
			}
			else
			{
				Point p(command[2], point_seq_num);
				point_list.push_back(p);
				std::cout << "添加点" << command[2] << "\n";
			}
		}
	}
}

void Add(std::vector <Polyline>& polyline_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 4)
	{
		std::cout << "第" << index << "行错误，检查add指令是否错误\n";
		return;
	}

	//首先检查该点是否已经存在
	for (int i = 0; i < polyline_list.size(); ++i)
	{
		if (polyline_list[i].GetVarName() == command[2])
		{
			std::cout << "第" << index << "行错误，已经存在该点\n";
			return;
		}
	}

	std::vector<float> polyline_seq_num = Convert(command[3]);
	if (polyline_seq_num.size()%2 != 0)
	{
		std::cout << "第" << index << "行错误，坐标输入不合格，添加失败\n";
	}
	else
	{
		Polyline p(command[2], polyline_seq_num);
		polyline_list.push_back(p);
		std::cout << "添加折线" << command[2] << "\n";
	}
}

void Add(std::vector <Ring>& ring_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 4)
	{
		std::cout << "第" << index << "行错误，检查add指令是否错误\n";
		return;
	}

	//首先检查该点是否已经存在
	for (int i = 0; i < ring_list.size(); ++i)
	{
		if (ring_list[i].GetVarName() == command[2])
		{
			std::cout << "第" << index << "行错误，已经存在该点\n";
			return;
		}
	}

	std::vector<float> ring_seq_num = Convert(command[3]);
	if (ring_seq_num.size() % 2 != 0)
	{
		std::cout << "第" << index << "行错误，坐标输入不合格，添加失败\n";
	}
	else
	{
		Ring p(command[2], ring_seq_num);
		ring_list.push_back(p);
		std::cout << "添加环" << command[2] << "\n";
	}
}

void Add(std::vector <Polygon>& polygon_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 5)
	{
		std::cout << "第" << index << "行错误，检查add指令是否错误\n";
		return;
	}

	//首先检查该点是否已经存在
	for (int i = 0; i < polygon_list.size(); ++i)
	{
		if (polygon_list[i].GetVarName() == command[2])
		{
			std::cout << "第" << index << "行错误，已经存在该点\n";
			return;
		}
	}

	std::vector<float> ring_seq_num = Convert(command[4]);
	if (ring_seq_num.size() % 2 != 0)
	{
		std::cout << "第" << index << "行错误，坐标输入不合格，添加失败\n";
	}
	else
	{
		Polygon p(command[2], ring_seq_num);
		polygon_list.push_back(p);
		std::cout << "添加多边形" << command[2] << "\n";
	}
}

void Delete(std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 3)
	{
		std::cout << "第" << index << "行错误，检查del指令是否错误\n";
		return;
	}
	else
	{
		if (point_list.empty())
		{
			std::cout << "第" << index << "行错误，point集为空\n";
			return;
		}
		else
		{
			bool have_point = 0;//跟踪状态，主要跟踪point_list中是否有我们要删除的点
			for (int i = 0; i < point_list.size(); ++i)
			{
				if (point_list[i].GetVarName() == command[2])
				{
					point_list.erase(point_list.begin() + i);
					std::cout << "删除point " << command[2] << "\n";
					have_point = 1;
					return;
				}
			}

			if (!have_point)
			{
				std::cout << "第" << index << "行错误，变量" << command[2] << "不存在\n";
				return;
			}
		}
	}
}

void Delete(std::vector <Polyline>& polyline_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 3)
	{
		std::cout << "第" << index << "行错误，检查del指令是否错误\n";
		return;
	}
	else
	{
		if (polyline_list.empty())
		{
			std::cout << "第" << index << "行错误，point集为空\n";
			return;
		}
		else
		{
			bool have_point = 0;//跟踪状态，主要跟踪polyline_list中是否有我们要删除的点
			for (int i = 0; i < polyline_list.size(); ++i)
			{
				if (polyline_list[i].GetVarName() == command[2])
				{
					polyline_list.erase(polyline_list.begin() + i);
					std::cout << "删除polyline " <<command[2]<<"\n";
					have_point = 1;
					return;
				}
			}

			if (!have_point)
			{
				std::cout << "第" << index << "行错误，变量" << command[2] << "不存在\n";
				return;
			}

			
		}
	}
}

void Delete(std::vector <Ring>& ring_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 3)
	{
		std::cout << "第" << index << "行错误，检查del指令是否错误\n";
		return;
	}
	else
	{
		if (ring_list.empty())
		{
			std::cout << "第" << index << "行错误，point集为空\n";
			return;
		}
		else
		{
			bool have_point = 0;//跟踪状态，主要跟踪polyline_list中是否有我们要删除的点
			for (int i = 0; i < ring_list.size(); ++i)
			{
				if (ring_list[i].GetVarName() == command[2])
				{
					ring_list.erase(ring_list.begin() + i);
					std::cout << "删除ring " << command[2] << "\n";
					have_point = 1;
					return;
				}
			}

			if (!have_point)
			{
				std::cout << "第" << index << "行错误，变量" << command[2] << "不存在\n";
				return;
			}


		}
	}
}

void Delete(std::vector <Polygon>& polygon_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 3)
	{
		std::cout << "第" << index << "行错误，检查del指令是否错误\n";
		return;
	}
	else
	{
		if (polygon_list.empty())
		{
			std::cout << "第" << index << "行错误，point集为空\n";
			return;
		}
		else
		{
			bool have_point = 0;//跟踪状态，主要跟踪polyline_list中是否有我们要删除的点
			for (int i = 0; i < polygon_list.size(); ++i)
			{
				if (polygon_list[i].GetVarName() == command[2])
				{
					polygon_list.erase(polygon_list.begin() + i);
					std::cout << "删除polygon " << command[2] << "\n";
					have_point = 1;
					return;
				}
			}

			if (!have_point)
			{
				std::cout << "第" << index << "行错误，变量" << command[2] << "不存在\n";
				return;
			}


		}
	}
}

void Set(std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	int point_index = 0;
	bool have_p = 0;//跟踪是否有点，如果有变为1
	//先检查是否长度正常
	if (command.size() != 5)
	{
		std::cout << "第" << index << "行有错，检查参数是否错误\n";
		return;
	}

	for (int i = 0; i < point_list.size(); ++i)
	{
		if (point_list[i].GetVarName() == command[2])
		{
			point_index = i;
			have_p = 1;
			break;
		}
	}

	if (!have_p)
	{
		std::cout << "第" << index << "行有错，" << command[2] << "不存在\n";
		return;
	}
	else
	{
		if (command[3] == "set")
		{
			//修改点坐标信息
			std::vector<float> point_num = Convert(command[4]);
			if (point_num.size() != 2)
			{
				std::cout << "第" << index << "行有错，" << command[4] << "，有输入错误\n";
				return;
			}
			else
			{
				point_list[point_index].Set(point_num);
			}
		}
		else if (command[3] == "move")
		{
			//移动点
			std::vector<float> move_num = Convert(command[4]);
			if (move_num.size() != 2)
			{
				std::cout << "第" << index << "行有错，" << command[4] << "，有输入错误\n";
				return;
			}
			else
			{
				point_list[point_index].Move(move_num);
			}
		}
		else if (command[3] == "name")
		{
			//给点命名
			point_list[point_index].Name(command[4]);
		}
		else
		{
			std::cout << "第" << index << "行有错，没有" << command[3] << "指令\n";
			return;
		}
	}

}

void Set(std::vector <Polyline>& polyline_list, const std::vector<std::string> command, const int index)
{
	int poly_index = 0;//要操作的折线序号
	bool have_p = 0;//跟踪是否有点，如果有变为1

	for (int i = 0; i < polyline_list.size(); ++i)
	{
		if (polyline_list[i].GetVarName() == command[2])
		{
			poly_index = i;
			have_p = 1;
			break;
		}
	}

	if (!have_p)
	{
		std::cout << "第" << index << "行有错，" << command[2] << "不存在\n";
		return;
	}
	else
	{
		if (command[3] == "set")
		{
			//先检查是否长度正常
			if (command.size() != 6)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}

			//修改点坐标信息
			std::vector<float> point_num = Convert(command[5]);//存储点坐标信息
			int point_index = -1;//记录编号
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "第" << index << "行有错，序号" << command[4] << "，有输入错误\n";
				return;
			}

			if (point_num.size() != 2)
			{
				std::cout << "第" << index << "行有错，坐标" << command[5] << "，有输入错误\n";
				return;
			}
			else
			{
				if (polyline_list[poly_index].Set(point_index, point_num))
				{
					return;
				}
				else
				{
					std::cout << "第" << index << "行有错，可能是序号" << command[4] << "越界\n";
					return;
				}
			}
		}
		else if (command[3] == "move")
		{
			//先检查是否长度正常
			if (command.size() != 6)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}

			//移动点
			std::vector<float> move_num = Convert(command[5]);
			int point_index = -1;//记录编号
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "第" << index << "行有错，序号" << command[4] << "，有输入错误\n";
				return;
			}

			if (move_num.size() != 2)
			{
				std::cout << "第" << index << "行有错，" << command[5] << "，有输入错误\n";
				return;
			}
			else
			{
				if (polyline_list[poly_index].Move(point_index, move_num))
				{
					return;
				}
				else
				{
					std::cout << "第" << index << "行有错，可能是序号" << command[4] << "越界\n";
					return;
				}
			}
		}
		else if (command[3] == "del")
		{
			//先检查是否长度正常
			if (command.size() != 5)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}
			//删除点
			int point_index = -1;//记录编号
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "第" << index << "行有错，序号" << command[4] << "，有输入错误\n";
				return;
			}

			if (polyline_list[poly_index].Delete(point_index))
			{
				return;
			}
			else
			{
				std::cout << "第" << index << "行有错，可能是序号" << command[4] << "越界\n";
				return;
			}
		}
		else if (command[3] == "set_length")
		{
			
			//先检查是否长度正常
			if (command.size() != 5)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}
			//设置长度
			polyline_list[poly_index].SetLength(command[4]);
		}
		else if (command[3] == "name")
		{
			
			//先检查是否长度正常
			if (command.size() != 5)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}
			//设置名称
			polyline_list[poly_index].SetName(command[4]);
		}
		else
		{
			std::cout << "第" << index << "行有错，没有" << command[3] << "指令\n";
		}
	}
}

void Set(std::vector <Ring>& ring_list, const std::vector<std::string> command, const int index)
{
	int ring_index = 0;//要操作的折线序号
	bool have_p = 0;//跟踪是否有点，如果有变为1

	for (int i = 0; i < ring_list.size(); ++i)
	{
		if (ring_list[i].GetVarName() == command[2])
		{
			ring_index = i;
			have_p = 1;
			break;
		}
	}

	if (!have_p)
	{
		std::cout << "第" << index << "行有错，" << command[2] << "不存在\n";
		return;
	}
	else
	{
		if (command[3] == "set")
		{
			//先检查是否长度正常
			if (command.size() != 6)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}

			//修改点坐标信息
			std::vector<float> point_num = Convert(command[5]);//存储点坐标信息
			int point_index = -1;//记录编号
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "第" << index << "行有错，序号" << command[4] << "，有输入错误\n";
				return;
			}

			if (point_num.size() != 2)
			{
				std::cout << "第" << index << "行有错，坐标" << command[5] << "，有输入错误\n";
				return;
			}
			else
			{
				if (ring_list[ring_index].Set(point_index, point_num))
				{
					return;
				}
				else
				{
					std::cout << "第" << index << "行有错，可能是序号" << command[4] << "越界\n";
					return;
				}
			}
		}
		else if (command[3] == "move")
		{
			//移动点

			//先检查是否长度正常
			if (command.size() != 6)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}

			std::vector<float> move_num = Convert(command[5]);
			int point_index = -1;//记录编号
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "第" << index << "行有错，序号" << command[4] << "，有输入错误\n";
				return;
			}

			if (move_num.size() != 2)
			{
				std::cout << "第" << index << "行有错，" << command[5] << "，有输入错误\n";
				return;
			}
			else
			{
				if (ring_list[ring_index].Move(point_index, move_num))
				{
					return;
				}
				else
				{
					std::cout << "第" << index << "行有错，可能是序号" << command[4] << "越界\n";
					return;
				}
			}
		}
		else if (command[3] == "del")
		{
			//删除点

			//先检查是否长度正常
			if (command.size() != 5)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}

			int point_index = -1;//记录编号
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "第" << index << "行有错，序号" << command[4] << "，有输入错误\n";
				return;
			}

			if (ring_list[ring_index].Delete(point_index))
			{
				return;
			}
			else
			{
				std::cout << "第" << index << "行有错，可能是序号" << command[4] << "越界\n";
				return;
			}
		}
		else if (command[3] == "set_length")
		{
			//设置长度

			//先检查是否长度正常
			if (command.size() != 5)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}
			ring_list[ring_index].SetLength(command[4]);
		}
		else if (command[3] == "set_area")
		{
			//设置长度

			//先检查是否长度正常
			if (command.size() != 5)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}

			ring_list[ring_index].SetArea(command[4]);
		}
		else if (command[3] == "name")
		{
			//设置名称

			//先检查是否长度正常
			if (command.size() != 5)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}

			ring_list[ring_index].SetName(command[4]);
		}
		else
		{
			std::cout << "第" << index << "行有错，没有" << command[3] << "指令\n";
		}
	}
}

void Set(std::vector <Polygon>& polygon_list, const std::vector<std::string> command, const int index)
{
	int poly_index;//存储我们要操作的多边形
	bool have_poly = 0;//标记是否有我们要找的多边形

	for (int i = 0; i < polygon_list.size(); ++i)
	{
		if (polygon_list[i].GetVarName() == command[2])
		{
			poly_index = i;
			have_poly = 1;
			break;
		}
	}

	if (!have_poly)
	{
		std::cout << "第" << index << "行有错，" << command[2] << "不存在\n";
		return;
	}
	else
	{
		if (command[3] == "inner")
		{
			if (command.size() != 5)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}

			std::vector<float> point_num = Convert(command[4]);//存储点坐标信息
			if (point_num.size() % 2 == 0)
			{
				polygon_list[poly_index].Set(point_num);
				return;
			}
			else
			{
				std::cout << "第" << index << "行有错，检查输入的坐标序列是否成对\n";
				return;
			}
		}
		else if (command[3] == "set")
		{
			//修改点坐标信息，包含outer 和inner
			if (command.size() != 7)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}

			std::vector<float> point_num = Convert(command[6]);//存储点坐标信息
			int point_index = -1;//记录编号
			if (StringToFloat(command[5]).str_status)
			{
				point_index = StringToFloat(command[5]).result;
			}
			else
			{
				std::cout << "第" << index << "行有错，序号" << command[5] << "，有输入错误\n";
				return;
			}

			if (point_num.size() != 2)
			{
				std::cout << "第" << index << "行有错，坐标" << command[6] << "，有输入错误\n";
				return;
			}
			else
			{
				if (command[4] == "outer")
				{
					if (polygon_list[poly_index].SetOuter(point_index, point_num))
					{
						return;
					}
					else
					{
						std::cout << "第" << index << "行有错，可能是序号" << command[5] << "越界\n";
						return;
					}
				}
				else if (command[4] == "inner")
				{
					if (polygon_list[poly_index].SetInner(point_index, point_num))
					{
						return;
					}
					else
					{
						std::cout << "第" << index << "行有错，可能是序号" << command[5] << "越界\n";
						return;
					}
				}
				else
				{
					std::cout << "第" << index << "行有错，指令" << command[4] << "不存在\n";
				}

			}
		}
		else if (command[3] == "move")
		{
			//移动点
			if (command.size() != 7)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}

			std::vector<float> move_num = Convert(command[6]);
			int point_index = -1;//记录编号
			if (StringToFloat(command[5]).str_status)
			{
				//如果输入的是小数，只取整数位
				point_index = StringToFloat(command[5]).result;
			}
			else
			{
				std::cout << "第" << index << "行有错，序号" << command[5] << "，有输入错误\n";
				return;
			}

			if (move_num.size() != 2)
			{
				std::cout << "第" << index << "行有错，" << command[6] << "，有输入错误\n";
				return;
			}
			else
			{
				if (command[4] == "outer")
				{
					if (polygon_list[poly_index].MoveOuter(point_index, move_num))
					{
						return;
					}
					else
					{
						std::cout << "第" << index << "行有错，可能是序号" << command[5] << "越界\n";
						return;
					}
				}
				else if (command[4] == "inner")
				{
					if (polygon_list[poly_index].MoveInner(point_index, move_num))
					{
						return;
					}
					else
					{
						std::cout << "第" << index << "行有错，可能是序号" << command[5] << "越界\n";
						return;
					}
				}
				else
				{
					std::cout << "第" << index << "行有错，指令" << command[4] << "不存在\n";
				}
			}
		}
		else if (command[3] == "del")
		{
			//删除点
			if (command.size() != 6)
			{
				std::cout << "第" << index << "行有错，检查参数是否错误\n";
				return;
			}
			int point_index = -1;//记录编号
			if (StringToFloat(command[5]).str_status)
			{
				point_index = StringToFloat(command[5]).result;
			}
			else
			{
				std::cout << "第" << index << "行有错，序号" << command[5] << "，有输入错误\n";
				return;
			}

			if (command[4] == "outer")
			{
				if (polygon_list[poly_index].DeleteOuter(point_index))
				{
					return;
				}
				else
				{
					std::cout << "第" << index << "行有错，可能是序号" << command[5] << "越界\n";
					return;
				}

			}
			else if (command[4] == "inner")
			{
				if (polygon_list[poly_index].DeleteInner(point_index))
				{
					return;
				}
				else
				{
					std::cout << "第" << index << "行有错，可能是序号" << command[5] << "越界\n";
					return;
				}
			}
			else
			{
				std::cout << "第" << index << "行有错，指令" << command[4] << "不存在\n";
			}
		}
		else if (command[3] == "set_length")
		{
			//设置长度
			polygon_list[poly_index].SetLength(command[4]);
		}
		else if (command[3] == "set_area")
		{
			//设置长度
			polygon_list[poly_index].SetArea(command[4]);
		}
		else if (command[3] == "name")
		{
			//设置名称
			polygon_list[poly_index].SetName(command[4]);
		}
		else
		{
			std::cout << "第" << index << "行有错，没有" << command[3] << "指令\n";
		}
	}
}

int Judge(std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 5 && command[3] != "equal")
	{
		//对于点集来说，相等必须伴有参数equal，因此整条命令长度为五个字符段
		std::cout << "第" << index << "行错误，是指令错误\n";
		return 2;
	}
	else
	{
		Point p1;
		Point p2;
		bool have_p1 = 0;//跟踪p1是否存在
		bool have_p2 = 0;//跟踪p2是否存在
		for (int i = 0; i < point_list.size(); ++i)
		{
			if (point_list[i].GetVarName() == command[2])
			{
				p1 = point_list[i];
				have_p1 = 1;

			}
			if (point_list[i].GetVarName() == command[4])
			{
				p2 = point_list[i];
				have_p2 = 1;
			}

			if (have_p1 && have_p2)
			{
				break;
			}
		}

		if (!have_p1)
		{
			std::cout << "第" << index << "行有误：";
			std::cout << command[2] << "不存在";
			std::cout << "\n";
			return 2;
		}
		if (!have_p2)
		{
			std::cout << "第" << index << "行有误：";
			std::cout << command[4] << "不存在";
			std::cout << "\n";
			return 2;
		}
		else
		{
			if (p1.Judge(p2))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
	}
}

int Judge(std::vector<Ring>& ring_list, std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 5 && command[3] != "cover")
	{
		//对于点集来说，相等必须伴有参数equal，因此整条命令长度为五个字符段
		std::cout << "第" << index << "行错误，是指令错误\n";
		return 2;
	}
	else
	{
		Ring r;
		Point p;
		bool have_r = 0;//跟踪环r是否存在
		bool have_p = 0;//跟踪点p是否存在
		for (int i = 0; i < point_list.size(); ++i)
		{
			if (point_list[i].GetVarName() == command[4])
			{
				p = point_list[i];
				have_p = 1;
				break;
			}
		}

		for (int i = 0; i < ring_list.size(); ++i)
		{
			if (ring_list[i].GetVarName() == command[2])
			{
				r = ring_list[i];
				have_r = 1;
				break;
			}
		}
		if (!have_p)
		{
			std::cout << "第" << index << "行有误：";
			std::cout << command[4] << "不存在";
			std::cout << "\n";
			return 2;
		}

		if (!have_r)
		{
			std::cout << "第" << index << "行有误：";
			std::cout << command[2] << "不存在";
			std::cout << "\n";
			return 2;
		}

		else
		{
			if (r.Judge(p))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

	}
}

int Judge(std::vector <Polygon>& polygon_list, std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 5 && command[3] != "cover")
	{
		//对于点集来说，相等必须伴有参数equal，因此整条命令长度为五个字符段
		std::cout << "第" << index << "行错误，是指令错误\n";
		return 2;
	}
	else
	{
		Ring r;
		Point p;
		bool have_r = 0;//跟踪环r是否存在
		bool have_p = 0;//跟踪点p是否存在
		for (int i = 0; i < point_list.size(); ++i)
		{
			if (point_list[i].GetVarName() == command[4])
			{
				p = point_list[i];
				have_p = 1;
				break;
			}
		}

		for (int i = 0; i < polygon_list.size(); ++i)
		{
			if (polygon_list[i].GetVarName() == command[2])
			{
				r = polygon_list[i].GetOuter();
				have_r = 1;
				break;
			}
		}
		if (!have_p)
		{
			std::cout << "第" << index << "行有误：";
			std::cout << command[4] << "不存在";
			std::cout << "\n";
			return 2;
		}
		if (!have_r)
		{
			std::cout << "第" << index << "行有误：";
			std::cout << command[2] << "不存在";
			std::cout << "\n";
			return 2;
		}


		else
		{
			if (r.Judge(p))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

	}
}

std::vector<float> Convert(std::string command)
{
	std::vector<float> float_result;//存储转化结果
	std::vector<std::string> divide_result = DivideStr(command, ',');//切分点序列
	for (int i = 0; i < divide_result.size(); ++i)
	{
		Fresult convert_result = StringToFloat(divide_result[i]);//字符串转浮点数
		if (convert_result.str_status)
		{
			float_result.push_back(convert_result.result);
		}
		else
		{
			std::cout << divide_result[i] << "有问题，导致转化失败\n";
		}
	}
	return float_result;
}