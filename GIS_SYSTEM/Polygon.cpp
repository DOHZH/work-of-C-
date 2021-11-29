#include "Polygon.h"

Polygon::Polygon()
{
	var_name = "";
	name = "";
	length = "";
	area = "";
}

Polygon::Polygon(std::string var_str, std::vector<float> point_set)
{
	var_name = var_str;
	name = "";
	length = "";
	area = "";
	outer = Ring("", point_set);
}

void Polygon::Set(std::vector<float> point_info)
{
	inner = Ring("", point_info);
}

bool Polygon::SetOuter(int no, std::vector<float> point_info)
{
	return outer.Set(no, point_info);
}

bool Polygon::MoveOuter(int no, std::vector<float> point_info)
{
	return outer.Move(no,point_info);
}

bool Polygon::DeleteOuter(int no)
{
	return outer.Delete(no);
}

bool Polygon::SetInner(int no, std::vector<float> point_info)
{
	return inner.Set(no,point_info);
}

bool Polygon::MoveInner(int no, std::vector<float> point_info)
{
	return inner.Move(no,point_info);
}

bool Polygon::DeleteInner(int no)
{
	return inner.Delete(no);
}

void Polygon::SetLength(std::string L)
{
	length = L;
}

void Polygon::SetArea(std::string a)
{
	area = a;
}

void Polygon::SetName(std::string n)
{
	name = n;
}

bool Polygon::Judge(Point p)
{
	int n_cross = 0;//点的射线与多边形交点个数

	//检查外环即可，因为内环是岛
	std::vector<Point> point_set = outer.GetPointSet();
	int n_count = point_set.size() - 1;//边数
	for (int i = 0; i < n_count; ++i)
	{
		Point p1 = point_set[i];
		Point p2 = point_set[(i + 1) % n_count];

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

std::string Polygon::GetVarName()
{
	return var_name;
}

Ring Polygon::GetOuter()
{
	return outer;
}

std::string Polygon::GetLength()
{
	return length;
}

std::string Polygon::Print()
{
	std::string result = "polygon ";
	result = result + GetVarName() + " outer=[";
	std::vector<Point> point_set = outer.GetPointSet();
	for (int i = 0; i < point_set.size(); ++i)
	{
		result = result + "[" + std::to_string(point_set[i].GetX()) + "," + std::to_string(point_set[i].GetY()) + "]";
		if (i != point_set.size() - 1)
		{
			result += ",";
		}
	}
	result = result + "], inner=[";
	point_set = outer.GetPointSet();
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
