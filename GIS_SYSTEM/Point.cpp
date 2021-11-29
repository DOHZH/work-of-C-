#include "Point.h"

Point::Point()
{
	var_name = "";
	name = "";
	point_set.push_back(0.0f);
	point_set.push_back(0.0f);
}

Point::Point(float x, float y)
{
	var_name = "";
	name = "";
	point_set.push_back(x);
	point_set.push_back(y);
}

Point::Point(std::string var, std::vector<float> point_info)
{
	var_name = var;
	name = "";
	point_set.push_back(point_info[0]);
	point_set.push_back(point_info[1]);
}

void Point::Set(std::vector<float> p)
{
	point_set[0] = p[0];
	point_set[1] = p[1];
}

void Point::Move(std::vector<float> p)
{
	point_set[0] += p[0];
	point_set[1] += p[1];
}

void Point::Name(std::string str)
{
	name = str;
}

bool Point::Judge(Point p1)
{
	if (p1.GetX() == point_set[0] && p1.GetY() == point_set[1])
	{
		return true;
	}
	else
	{
		return false;
	}
}

float Point::GetX()
{
	return point_set[0];
}

float Point::GetY()
{
	return point_set[1];
}

std::string Point::GetVarName()
{
	return var_name;
}

std::string Point::GetName()
{
	return name;
}

bool Point::Empty()
{
	if (var_name == "" && point_set.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

std::string Point::Print()
{
	std::string result = "point ";
	result = result + var_name + " ";
	result = result + "[" + std::to_string(point_set[0]) + "," + std::to_string(point_set[1]) + "], ";
	result = result + "name=";
	if (name == "")
	{
		result += "NULL";
	}
	else
	{
		result += name;
	}
	result += "\n";
	return result;
}
