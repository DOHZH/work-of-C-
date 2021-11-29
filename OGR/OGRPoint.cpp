#include "OGRPoint.h"
OGRPoint::OGRPoint()
{
	type_index = 1;
	id = CalId(type_index);
	type = "OGRPoint";
	Point p;
	container.push_back(p);
}

OGRPoint::OGRPoint(double x, double y)
{
	type_index = 1;
	id = CalId(type_index);
	type = "OGRPoint";
	Point p = { x, y, true};
	container.push_back(p);
}

OGRPoint::OGRPoint(Point p)
{
	type_index = 1;
	id = id = CalId(type_index);
	type = "OGRPoint";
	container.push_back(p);
}

double OGRPoint::X() const
{
	if (container[0].status)
		return container[0].x;
	else
	{
		throw "�����û���������Ϣ";
	}
}

double OGRPoint::Y() const
{
	if (container[0].status)
		return container[0].y;
	else
	{
		throw "�����û���������Ϣ";
	}
}

Point OGRPoint::ToPoint() const
{
	Point p = container[0];
	return p;
}

bool OGRPoint::IsEmpty() const
{
	if (container.empty() || !container[0].status)
		return true;

	return false;
}

void OGRPoint::GetMBR(OGREnvelope* e) const
{
	if (IsEmpty())
	{
		std::cout << "��" << id << "Ϊ�ռ�\n";
		return;
	}

	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;

	double x = container[0].x;
	double y = container[0].y;
	if (x < minx)
		minx = x;

	if (x > maxx)
		maxx = x;

	if (y < miny)
		miny = y;

	if (y > maxy)
		maxy = y;

	e->max_x = maxx;
	e->min_x = minx;
	e->max_y = maxy;
	e->min_y = miny;
}

OGREnvelope OGRPoint::GetMBR() const
{
	if (IsEmpty())
	{
		throw  "��" + std::to_string(id) + "Ϊ�ռ�\n";
	}

	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;

	double x = container[0].x;
	double y = container[0].y;
	if (x < minx)
		minx = x;

	if (x > maxx)
		maxx = x;

	if (y < miny)
		miny = y;

	if (y > maxy)
		maxy = y;

	OGREnvelope e;
	e.max_x = maxx;
	e.min_x = minx;
	e.max_y = maxy;
	e.min_y = miny;
	return e;
}

void OGRPoint::Clone(OGRPoint* new_p)
{
	container = new_p->container;
}

OGRPoint* OGRPoint::Clone()
{
	OGRPoint* p = new OGRPoint;
	p->container = container;
	return p;
}

OGRErr OGRPoint::ImportFromWkt(std::string path)
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
		std::vector<std::string> temp_divide = DivideStr(temp, ' ');
		if (temp_divide[0] != "Point")
		{
			myfile.close();
			throw "�ļ�" + path + "��Ϣ����";
			return OGRErr::ReadErr;
		}

		std::string x = temp_divide[1], y = temp_divide[2];
		x.erase(remove(x.begin(), x.end(), '('), x.end());
		y.erase(remove(y.begin(), y.end(), ')'), y.end());
		
		Fresult x_fin = StringToFloat(x), y_fin = StringToFloat(y);
		if (x_fin.str_status && y_fin.str_status)
		{
			Point p = {x_fin.result, y_fin.result, true};
			container[0] = p;
			myfile.close();
			return OGRErr::ReadTrue;
		}
		else
		{
			myfile.close();
			throw "ת��ʧ�ܣ�" + path + "�ļ��е�������ڴ���";
			return OGRErr::ReadErr;
		}
	}

	myfile.close();
	throw "�����ļ�" + path + "�ǿ��ļ�";
	return OGRErr::ReadErr;
}

OGRErr OGRPoint::ExportToWkt(std::string path) const
{
	std::ofstream outfile;
	outfile.open(path, std::ios::trunc | std::ios::out);
	
	if (!IsEmpty())
	{
		std::string result = "Point (";
		PrtintPoint(result, container[0]);
		result += ")";
		outfile << result;
		outfile.close();
		return OGRErr::OutTrue;
	}
	else
	{
		outfile.close();
		throw type + std::to_string(id) + "�㼯Ϊ��";
		return OGRErr::OutErr;
	}

	
}
