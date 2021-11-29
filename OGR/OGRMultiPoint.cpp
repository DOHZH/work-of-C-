#include "OGRMultiPoint.h"

OGRMultiPoint::OGRMultiPoint()
{
	type_index = 5;
	id = CalId(type_index);
	type = "OGRMultiPoint";
}

void OGRMultiPoint::AddGeometry(OGRPoint p)
{
	container.push_back(p);
}

void OGRMultiPoint::RemoveGeometry(int index)
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

OGRPoint* OGRMultiPoint::GetGeometry(int index) const
{
	if (index > container.size() - 1 || index < 0)
	{
		std::cout << "没有找到对应元素";
		return nullptr;
	}
	else
	{
		OGRPoint p = container[index];
		return &p;
	}
}

void OGRMultiPoint::UpdateGeometry(int index, OGRPoint p)
{
	if (index > container.size() - 1 || index < 0)
	{
		std::cout << "没有找到对应元素";
	}
	else
	{
		container[index] = p;
	}
}

int OGRMultiPoint::GetNumGeometries() const
{
	return container.size();
}

PointSet OGRMultiPoint::GetAllPoints() const
{
	PointSet p;
	for (int i = 0; i < container.size(); ++i)
	{
		p.push_back(container[i].ToPoint());
	}
	return p;
}

bool OGRMultiPoint::IsEmpty() const
{
	return container.empty();
}

void OGRMultiPoint::GetMBR(OGREnvelope* e) const
{
	if (IsEmpty())
	{
		throw  "点集合" + std::to_string(id) + "为空集\n";
	}

	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;
	for (int i = 0; i < container.size(); ++i)
	{
		double x = container[i].X();
		double y = container[i].Y();
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

OGREnvelope OGRMultiPoint::GetMBR() const
{
	if (IsEmpty())
	{
		throw  "点集合" + std::to_string(id) + "为空集\n";
	}

	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;
	for (int i = 0; i < container.size(); ++i)
	{
		double x = container[i].X();
		double y = container[i].Y();
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

OGRMultiPoint* OGRMultiPoint::Clone()
{
	OGRMultiPoint* p = new OGRMultiPoint;
	p->container = container;
	return p;
}

void OGRMultiPoint::Clone(OGRMultiPoint* p)
{
	container = p->container;
}

OGRErr OGRMultiPoint::ImportFromWkt(std::string path)
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
		std::string sub = "MultiPoint ";//需要删除的子串内容
		DeleteSub(temp, sub, sub.size());

		std::stack<char> signal_stack;
		std::stack<char> num_stack;//中转的栈
		Point p;
		PointSet p_set;
		std::string num_str = "";//数字的字符形式

		container.clear();
		for (int i = 0; i < temp.size(); ++i)
		{
			if (temp[i] != ')')
			{
				signal_stack.push(temp[i]);
			}
			else if (temp[i] == ')')
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
					std::vector<std::string> temp2_divide = DivideStr(num_str, ' ');
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
						OGRPoint p_1(p);
						container.push_back(p);
					}
					else
					{
						myfile.close();
						throw "转化失败：" + path + "文件中的坐标存在错误";
						return OGRErr::ReadErr;
					}

					num_str = "";
				}

				if (temp[i + 1] == ',')
					i += 1;
			}
		}
		myfile.close();
		return OGRErr::ReadTrue;
	}
	myfile.close();
	throw "可能文件" + path + "是空文件";
	return OGRErr::ReadErr;
}

OGRErr OGRMultiPoint::ExportToWkt(std::string path) const
{
	std::ofstream outfile;
	outfile.open(path, std::ios::trunc | std::ios::out);

	if (!IsEmpty())
	{
		std::string result = "MultiPoint (";
		for (int i = 0; i < container.size(); ++i)
		{
			result += "(";
			PrtintPoint(result, container[i].ToPoint());
			result += ")";

			if (i != container.size() - 1)
				result += ",";
		}
		result += ")";

		outfile << result;
		outfile.close();
		return OGRErr::OutTrue;
	}
	else
	{
		outfile.close();
		throw type + std::to_string(id) + "点集为空";
		return OGRErr::OutErr;
	}

}


