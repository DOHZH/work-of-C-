#include "OGRMultiPolygon.h"

OGRMultiPolygon::OGRMultiPolygon()
{
	type_index = 7;
	id = CalId(type_index);
	type = "OGRMultiPolygon";
}

bool OGRMultiPolygon::IsEmpty() const
{
	return container.empty();
}

PointSet OGRMultiPolygon::GetAllPoints() const
{
	PointSet p;
	for (int i = 0; i < container.size(); ++i)
	{
		PointSet p_imp = container[i].GetAllPoints();
		for (int j = 0; j < p_imp.size(); ++j)
		{
			p.push_back(p_imp[j]);
		}
	}
	return p;
}

void OGRMultiPolygon::GetMBR(OGREnvelope* e) const
{
	if (IsEmpty())
	{
		throw  "点集合" + std::to_string(id) + "为空集\n";
	}
	PointSet p = GetAllPoints();
	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;
	for (int i = 0; i < p.size(); ++i)
	{
		double x = p[i].x;
		double y = p[i].y;
		if (x < minx)
			minx = x;

		if (x > maxx)
			maxx = x;

		if (y < miny)
			miny = y;

		if (y > maxy)
			maxy = y;
	}

	e->max_x = maxx;
	e->min_x = minx;
	e->max_y = maxy;
	e->min_y = miny;
}

OGREnvelope OGRMultiPolygon::GetMBR() const
{
	if (IsEmpty())
	{
		throw  "点集合" + std::to_string(id) + "为空集\n";
	}
	PointSet p = GetAllPoints();
	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;
	for (int i = 0; i < p.size(); ++i)
	{
		double x = p[i].x;
		double y = p[i].y;
		if (x < minx)
			minx = x;

		if (x > maxx)
			maxx = x;

		if (y < miny)
			miny = y;

		if (y > maxy)
			maxy = y;
	}

	OGREnvelope e;
	e.max_x = maxx;
	e.min_x = minx;
	e.max_y = maxy;
	e.min_y = miny;

	return e;
}

OGRMultiPolygon* OGRMultiPolygon::Clone()
{
	OGRMultiPolygon l;
	l.container = container;
	OGRMultiPolygon* result = &l;
	return result;
}

void OGRMultiPolygon::Clone(OGRMultiPolygon* l)
{
	container = l->container;
}

double OGRMultiPolygon::GetPerimeter()
{
	double l = 0;
	for (int i = 0; i < container.size(); ++i)
		l += container[i].GetPerimeter();
	return l;
}

double OGRMultiPolygon::GetArea()
{
	double l = 0;
	for (int i = 0; i < container.size(); ++i)
		l += container[i].GetArea();
	return l;
}

OGRErr OGRMultiPolygon::ImportFromWkt(std::string path)
{
	std::ifstream myfile;
	myfile.open(path);
	if (!myfile.is_open())
	{
		myfile.close();
		throw "路径错误：" + path + "不存在";
		return OGRErr::ReadErr;
	}
	std::string temp = "";

	while (std::getline(myfile, temp))
	{
		temp = trim(temp);
		std::string sub = "MultiPolygon ";//需要删除的子串内容
		DeleteSub(temp, sub, sub.size());

		std::stack<char> signal_stack;
		std::stack<char> num_stack;
		Point p;
		PointSet p_set;
		std::string num_str = "";//数字的字符形式

		container.clear();
		OGRPolygon poly;
		for (int i = 0; i < temp.size(); ++i)
		{
			if (temp[i] == '(')
			{
				signal_stack.push(temp[i]);
				continue;
			}
			else if (temp[i] == ')')
			{
				//如果下一个是逗号，说明当前polygon还没有结束
				if (temp[i + 1] == ',')
				{
					while (signal_stack.top() != '(')
					{
						num_stack.push(signal_stack.top());
						signal_stack.pop();
					}
					signal_stack.pop();

					while (!num_stack.empty())
					{
						num_str.push_back(num_stack.top());
						num_stack.pop();
					}

					if (num_str != "")
					{
						std::vector<std::string> temp_divide = DivideStr(num_str, ',');
						if (temp_divide.size() < 3)
						{
							myfile.close();
							throw "文件" + path + "信息错误";
							return OGRErr::ReadErr;
						}
						poly.hole_index.push_back(temp_divide.size());
						for (int j = 0; j < temp_divide.size(); ++j)
						{
							std::vector<std::string> temp2_divide = DivideStr(temp_divide[j], ' ');
							if (temp2_divide.size() != 2)
							{
								myfile.close();
								throw "文件" + path + "信息错误";
								return OGRErr::ReadErr;
							}
							Fresult x_fin = StringToFloat(temp2_divide[0]), y_fin = StringToFloat(temp2_divide[1]);
							if (x_fin.str_status && y_fin.str_status)
							{
								Point p = { x_fin.result, y_fin.result, true };
								poly.container.push_back(p);
							}
							else
							{
								myfile.close();
								throw "转化失败：" + path + "文件中的坐标存在错误";
								return OGRErr::ReadErr;
							}
						}

						num_str = "";
					}
					++i;
				}
				
				if (temp[i + 1] == ')')
				{
					while (signal_stack.top() != '(')
					{
						num_stack.push(signal_stack.top());
						signal_stack.pop();
					}
					signal_stack.pop();

					while (!num_stack.empty())
					{
						num_str.push_back(num_stack.top());
						num_stack.pop();
					}

					if (num_str != "")
					{
						std::vector<std::string> temp_divide = DivideStr(num_str, ',');
						if (temp_divide.size() < 3)
						{
							myfile.close();
							throw "文件" + path + "信息错误";
							return OGRErr::ReadErr;
						}
						poly.hole_index.push_back(temp_divide.size());
						for (int j = 0; j < temp_divide.size(); ++j)
						{
							std::vector<std::string> temp2_divide = DivideStr(temp_divide[j], ' ');
							if (temp2_divide.size() != 2)
							{
								myfile.close();
								throw "文件" + path + "信息错误";
								return OGRErr::ReadErr;
							}
							Fresult x_fin = StringToFloat(temp2_divide[0]), y_fin = StringToFloat(temp2_divide[1]);
							if (x_fin.str_status && y_fin.str_status)
							{
								Point p = { x_fin.result, y_fin.result, true };
								poly.container.push_back(p);
							}
							else
							{
								myfile.close();
								throw "转化失败：" + path + "文件中的坐标存在错误";
								return OGRErr::ReadErr;
							}
						}

						num_str = "";
					}
					if (!poly.container.empty() && !poly.hole_index.empty()) {

						std::vector<OGRPolygon> poly_container;
						for (int j = 0; j < poly.hole_index.size(); ++j)
						{
							PointSet p_0;
							for (int i = 0; i < poly.hole_index[0]; ++i)
							{
								p_0.push_back(poly.container[i]);
							}
							OGRPolygon poly_1(p_0);
							poly_container.push_back(poly_1);
						}

						if (!poly.CheckConcave())
						{
							std::cout << "多边形不是凸多边形";
							poly.container.clear();
							poly.hole_index.clear();
							myfile.close();
							throw "可能文件" + path + "多边形不是凸多边形";
							return OGRErr::ReadErr;
						}

						if (!poly.CheckRing(poly_container, 0))
						{
							myfile.close();
							throw "可能文件" + path + "多边形不是凸多边形";
							return OGRErr::ReadErr;
						}

						poly.Update();
					}
					else
					{
						myfile.close();
						throw "转化失败：" + path + "文件中的坐标存在错误";
						return OGRErr::ReadErr;
					}
					container.push_back(poly);
			
					poly.Clear();
					++i;
					if (temp[i + 1] == ',')
					{
						++i;
					}
				}
			}
			else
			{
				signal_stack.push(temp[i]);
			}
		}
		myfile.close();
		return OGRErr::ReadTrue;
	}

	myfile.close();
	throw "可能文件" + path + "是空文件";
	return OGRErr::ReadErr;
}

OGRErr OGRMultiPolygon::ExportToWkt(std::string path) const
{
	std::ofstream outfile;
	outfile.open(path, std::ios::trunc | std::ios::out);

	if (!IsEmpty())
	{
		std::string result = "MultiPoint (";
		for (int i = 0; i < container.size(); ++i)
		{
			OGRPolygon poly = container[i];
			result += "(";
			int index = 0;//记录当前是第几个点
			for (int j = 0; j < poly.hole_index.size(); ++j)
			{
				int amount = poly.hole_index[j];
				result += "(";
				int stop = index + amount;//几何图形的截止序号
				for (index; index < stop; ++index)
				{
					PrtintPoint(result, poly.container[index]);
					if (index < stop - 1)
						result += ",";
				}

				if (i == poly.hole_index.size() - 1)
					result += ")";
				else
				{
					result += "),";
				}
			}
			result += ")";

			if (i != container.size() - 1)
				result += ",";
		}
		result += ")";

		outfile << result;

		return OGRErr::OutTrue;
	}
	else
	{
		throw type + std::to_string(id) + "点集为空";
		return OGRErr::OutErr;
	}
	outfile.close();
}

void OGRMultiPolygon::AddGeometry(OGRPolygon p)
{
	container.push_back(p);
}

void OGRMultiPolygon::RemoveGeometry(int index)
{
	if (index > container.size() - 1 || index < 0)
	{
		std::cout << "没有找到对应元素";
	}
	else
	{
		container.erase(container.begin() + index);
	}
}

OGRPolygon* OGRMultiPolygon::GetGeometry(int index) const
{
	if (index > container.size() - 1 || index < 0)
	{
		std::cout << "没有找到对应元素";
		return nullptr;
	}
	else
	{
		OGRPolygon p = container[index];
		OGRPolygon* result = &p;
		return result;
	}
}

void OGRMultiPolygon::UpdateGeometry(int index, OGRPolygon geo)
{
	if (index > container.size() - 1 || index < 0)
	{
		std::cout << "没有找到对应元素";
	}
	else
	{
		container[index] = geo;
	}
}

int OGRMultiPolygon::GetNumGeometries() const
{
	return container.size();
}

bool OGRMultiPolygon::Contains(OGRPoint* p)
{
	for (int i = 0; i < container.size(); ++i)
	{
		if (!container[i].Contains(p))
			return false;
	}
	return true;
}

bool OGRMultiPolygon::Contains(OGRLineString* l)
{
	for (int i = 0; i < container.size(); ++i)
	{
		if (!container[i].Contains(l))
			return false;
	}
	return true;
}

bool OGRMultiPolygon::Contains(OGRPolygon* p)
{
	for (int i = 0; i < container.size(); ++i)
	{
		if (!container[i].Contains(p))
			return false;
	}
	return true;
}
