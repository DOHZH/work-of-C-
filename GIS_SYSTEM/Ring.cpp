#include "Ring.h"

Ring::Ring():Polyline()
{
	area = "";
}


Ring::Ring(std::string var_str, std::vector<float> point_input):Polyline(var_str, point_input)
{
	area = "";
	std::vector<Point> point_set_polyline = GetPointSet();
	for (int i = 0; i < point_set_polyline.size(); ++i)
	{
		point_set_r.push_back(point_set_polyline[i]);
	}
	point_set_r.push_back(point_set_r[0]);
}

void Ring::SetArea(std::string a)
{
	area = a;
}

bool Ring::Set(int no, std::vector<float> point_info)
{
	if (no > point_set_r.size() - 2 && no < 0)
	{
		return false;
	}
	else
	{
		//如果设置的是起点，应该同步更新
		point_set_r[no].Set(point_info);
		if (no == 0)
		{
			point_set_r[point_set_r.size() - 1] = point_set_r[0];
		}
		
		return true;
	}
}

bool Ring::Move(int no, std::vector<float> move_info)
{
	if (no > point_set_r.size() - 2 && no < 0)
	{
		return false;
	}
	else
	{
		point_set_r[no].Move(move_info);
		if (no == 0)
		{
			point_set_r[point_set_r.size() - 1] = point_set_r[0];
		}
		return true;
	}
}

bool Ring::Delete(int no)
{
	if (no > point_set_r.size() - 2 && no < 0)
	{
		return false;
	}
	else
	{
		point_set_r.erase(point_set_r.begin() + no);
		if (no == 0)
		{
			point_set_r[point_set_r.size() - 1] = point_set_r[0];
		}
		return true;
	}
}

bool Ring::Judge(Point p)
{
	bool inside = false;
	int n_count = point_set_r.size() - 1;//边数
	int n_cross = 0;//点的射线与多边形交点个数
	for (int i = 0; i < n_count; ++i)
	{
		Point p1 = point_set_r[i];
		Point p2 = point_set_r[(i + 1) % n_count];

		if (p1.GetY() == p2.GetY())
		{
			continue;
		}
		if (p.GetY() < std::min(p1.GetY(), p2.GetY()))
		{
			continue;
		}
		if (p.GetY() > std::max(p1.GetY(), p2.GetY()))
		{
			continue;
		}

		float x = (p.GetX() - p1.GetY()) * (p2.GetX() - p1.GetX()) / (p2.GetY() - p1.GetY()) + p1.GetX();

		if (x > p.GetX())
		{
			++n_cross;
		}
	}

	if ((n_cross % 2) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

std::vector<Point> Ring::GetPointSetR()
{
	return point_set_r;
}

std::string Ring::GetVarNameR()
{
	return GetName();
}

std::string Ring::GetNameR()
{
	return GetName();
}

std::string Ring::GetLengthR()
{
	return GetLength();
}

std::string Ring::Print()
{
	std::string result = "ring ";
	result = result + GetVarName() + " [";
	for (int i = 0; i < point_set_r.size(); ++i)
	{
		result = result + "[" + std::to_string(point_set_r[i].GetX()) + "," + std::to_string(point_set_r[i].GetY()) + "]";
		if (i != point_set_r.size() - 1)
		{
			result += ",";
		}
	}
	result = result + "], name=";
	if (GetName() == "")
	{
		result += "NULL";
	}
	else
	{
		result += GetName();
	}
	result += ", length=";
	if (GetLength() == "")
	{
		result += "NULL";
	}
	else
	{
		result += GetLength();
	}
	result += ", area=";
	if (area == "")
	{
		result += "NULL";
	}
	else
	{
		result += area;
	}

	result += "\n";
	return result;
}
