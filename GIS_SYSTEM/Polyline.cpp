#include "Polyline.h"

Polyline::Polyline()
{
	var_name = "";
	name = "";
}

Polyline::Polyline(std::string var_str, std::vector<float> point_list)
{
	var_name = var_str;
	for (int i = 0; i < point_list.size();i += 2)
	{
		Point p(point_list[i], point_list[i + 1]);
		point_set.push_back(p);
	}
}

bool Polyline::Set(int no, std::vector<float> point_info)
{
	if (no > point_set.size() - 1 && no<0)
	{
		return false;
	}
	else
	{
		point_set[no].Set(point_info);
		return true;
	}
}

bool Polyline::Move(int no, std::vector<float> move_info)
{
	if (no > point_set.size() - 1 && no < 0)
	{
		return false;
	}
	else
	{
		point_set[no].Move(move_info);
		return true;
	}
}

bool Polyline::Delete(int no)
{
	if (no > point_set.size() - 1 && no < 0)
	{
		return false;
	}
	else
	{
		point_set.erase(point_set.begin()+no);
		return true;
	}
}

void Polyline::SetLength(std::string L)
{
	length = L;
}

void Polyline::SetName(std::string name_str)
{
	name = name_str;
}

std::string Polyline::GetVarName()
{
	return var_name;
}

std::string Polyline::GetName()
{
	return name;
}

std::vector<Point> Polyline::GetPointSet()
{
	return point_set;
}

std::string Polyline::GetLength()
{
	return length;
}

std::string Polyline::Print()
{
	std::string result = "polyline ";
	result = result + var_name + " [";
	for (int i = 0; i < point_set.size(); ++i)
	{
		result = result + "[" + std::to_string(point_set[i].GetX()) + "," + std::to_string(point_set[i].GetY()) + "]";
		if (i != point_set.size() - 1)
		{
			result += ",";
		}
	}
	result = result + "], name=";
	if (name == "")
	{
		result += "NULL";
	}
	else
	{
		result += name;
	}

	result += ", length=";
	if (length == "")
	{
		result += "NULL";
	}
	else
	{
		result += length;
	}
	result += "\n";
	return result;
}

void Polyline::AddPoint(Point p)
{
	point_set.push_back(p);
}
