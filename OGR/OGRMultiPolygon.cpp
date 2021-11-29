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
		throw  "�㼯��" + std::to_string(id) + "Ϊ�ռ�\n";
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
		throw  "�㼯��" + std::to_string(id) + "Ϊ�ռ�\n";
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
		throw "·������" + path + "������";
		return OGRErr::ReadErr;
	}
	std::string temp = "";

	while (std::getline(myfile, temp))
	{
		temp = trim(temp);
		std::string sub = "MultiPolygon ";//��Ҫɾ�����Ӵ�����
		DeleteSub(temp, sub, sub.size());

		std::stack<char> signal_stack;
		std::stack<char> num_stack;
		Point p;
		PointSet p_set;
		std::string num_str = "";//���ֵ��ַ���ʽ

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
				//�����һ���Ƕ��ţ�˵����ǰpolygon��û�н���
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
							throw "�ļ�" + path + "��Ϣ����";
							return OGRErr::ReadErr;
						}
						poly.hole_index.push_back(temp_divide.size());
						for (int j = 0; j < temp_divide.size(); ++j)
						{
							std::vector<std::string> temp2_divide = DivideStr(temp_divide[j], ' ');
							if (temp2_divide.size() != 2)
							{
								myfile.close();
								throw "�ļ�" + path + "��Ϣ����";
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
								throw "ת��ʧ�ܣ�" + path + "�ļ��е�������ڴ���";
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
							throw "�ļ�" + path + "��Ϣ����";
							return OGRErr::ReadErr;
						}
						poly.hole_index.push_back(temp_divide.size());
						for (int j = 0; j < temp_divide.size(); ++j)
						{
							std::vector<std::string> temp2_divide = DivideStr(temp_divide[j], ' ');
							if (temp2_divide.size() != 2)
							{
								myfile.close();
								throw "�ļ�" + path + "��Ϣ����";
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
								throw "ת��ʧ�ܣ�" + path + "�ļ��е�������ڴ���";
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
							std::cout << "����β���͹�����";
							poly.container.clear();
							poly.hole_index.clear();
							myfile.close();
							throw "�����ļ�" + path + "����β���͹�����";
							return OGRErr::ReadErr;
						}

						if (!poly.CheckRing(poly_container, 0))
						{
							myfile.close();
							throw "�����ļ�" + path + "����β���͹�����";
							return OGRErr::ReadErr;
						}

						poly.Update();
					}
					else
					{
						myfile.close();
						throw "ת��ʧ�ܣ�" + path + "�ļ��е�������ڴ���";
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
	throw "�����ļ�" + path + "�ǿ��ļ�";
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
			int index = 0;//��¼��ǰ�ǵڼ�����
			for (int j = 0; j < poly.hole_index.size(); ++j)
			{
				int amount = poly.hole_index[j];
				result += "(";
				int stop = index + amount;//����ͼ�εĽ�ֹ���
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
		throw type + std::to_string(id) + "�㼯Ϊ��";
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
		std::cout << "û���ҵ���ӦԪ��";
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
		std::cout << "û���ҵ���ӦԪ��";
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
		std::cout << "û���ҵ���ӦԪ��";
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
